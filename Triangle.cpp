#include "Triangle.h"

void Triangle::SetA(Angle A)
{
	this->A.Angle::SetGrades(A.GetGrades());
	this->A.Angle::SetMinutes(A.GetMinutes());
}
void Triangle::SetB(Angle B)
{
	this->B.Angle::SetGrades(B.GetGrades());
	this->B.Angle::SetMinutes(B.GetMinutes());
}
void Triangle::SetC(Angle C)
{
	this->C.Angle::SetGrades(C.GetGrades());
	this->C.Angle::SetMinutes(C.GetMinutes());
}

void Triangle::Set_a(double value) { a = value; }
void Triangle::Set_b(double value) { b = value; }
void Triangle::Set_c(double value) { c = value; }

Angle& Triangle::GetA() { return A; }
Angle& Triangle::GetB() { return B; }
Angle& Triangle::GetC() { return C; }

double Triangle::Get_a() const { return a; }
double Triangle::Get_b() const { return b; }
double Triangle::Get_c() const { return c; }

ostream& operator << (ostream& out, const Triangle& A)
{
	out << string(A);
	return out;
}
istream& operator >> (istream& in, Triangle& X)
{
	cout << "Angle A: " << endl;
	in >> X.A;
	cout << "Angle B: " << endl;
	in >> X.B;
	cout << "Angle C: " << endl;
	in >> X.C;

	cout << "\nEnter a side 'a' : "; in >> X.a;
	cout << "Enter a side 'b' : "; in >> X.b;
	cout << "Enter a side 'c' : "; in >> X.c;

	return in;
}
Triangle::operator string() const
{
	stringstream ss;
	ss << "Angle A Grades is equal to " << A.GetGrades() << endl;
	ss << "Angle A minutes is equal to " << A.GetMinutes() << endl;

	ss << "Angle B Grades is equal to " << B.GetGrades() << endl;
	ss << "Angle B Minutes is equal to " << B.GetMinutes() << endl;

	ss << "Angle C Grades is equal to " << C.GetGrades() << endl;
	ss << "Angle C Minutes is equal to " << C.GetMinutes() << endl;

	ss << "\nSide a is equal to " << a << endl;
	ss << "Side b is equal to " << b << endl;
	ss << "Side c is equal to " << c << endl;

	return ss.str();
}

double Triangle::Square() const
{
	double p = Perimeter() / 2.;
	return sqrt(p * (p - Get_a()) * (p - Get_b()) * (p - Get_c()));
}
double Triangle::Perimeter() const { return Get_a() + Get_b() + Get_c(); }
double Triangle::Altitude(int tmp) const
{
	switch (tmp)
	{
	case 1:
		return (2 * Square()) / (Get_a() * 1.);
	case 2:
		return (2 * Square()) / (Get_b() * 1.);
	case 3:
		return (2 * Square()) / (Get_c() * 1.);
	}
}
void Triangle::TypeOFTriangle()
{
	if ((Get_a() == Get_b()) && (Get_b() == Get_c()))
		cout << "Equilateral triangle" << endl; //������������
	else if ((Get_a() == Get_b() && Get_a() != Get_c()) ||
		(Get_a() == Get_c() && Get_a() != Get_b()) ||
		(Get_c() == Get_b() && Get_c() != Get_a()))
		cout << "Isosceles triangle" << endl;//������������
	else if (A.to360() == 90 || B.to360() == 90 || C.to360() == 90)
		cout << "Rectangular triangle" << endl;//�����������
	else if (A.to360() > 90 || B.to360() > 90 || C.to360() > 90)
		cout << "Obtuse triangle" << endl;// ���������� 
	else if (A.to360() < 90 && B.to360() < 90 && C.to360() < 90)
		cout << "Oxygon" << endl;// ������������
}
void Triangle::Equalizetriangle(int tmp)
{
	switch (tmp)
	{
	case 1:
		Set_b((Get_a() * B.getSin()) / (A.getSin() * 1.));
		Set_c((Get_a() * C.getSin()) / (A.getSin() * 1.));
		break;
	case 2:
		Set_a((Get_b() * A.getSin()) / (B.getSin() * 1.));
		Set_c((Get_b() * C.getSin()) / (B.getSin() * 1.));
		break;
	case 3:
		Set_a((Get_c() * A.getSin()) / (C.getSin() * 1.));
		Set_b((Get_c() * B.getSin()) / (C.getSin() * 1.));
		break;
	}
}