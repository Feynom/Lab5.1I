#pragma once
class Object
{
private:
	static unsigned int count;
public:
	Object();
	static unsigned int Count();
	~Object();
};

