#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab5.1I/Angle.h"
#include "../Lab5.1I/Angle.cpp"
#include "../Lab5.1I/Object.h"
#include "../Lab5.1I/Object.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest51I
{
	TEST_CLASS(UnitTest51I)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Angle A(90, 0), B(180, 0);
			Assert::AreEqual(round(A.getSin()), 1.);
			Assert::AreEqual(round(B.getSin()), 0.);
		}
	};
}
