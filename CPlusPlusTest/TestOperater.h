#pragma once
#include <stdio.h>
class A
{
public:
	A() = default;
	A(int _i) :mint(_i) {}
	int* operator ->()
	{
		return &mint;
	}
	int mint;
};
class B
{
public:
	B() = default;
	B(int _b) :mA(_b) {}
	A* operator ->()
	{
		return &mA;
	}

	A mA;
};

class C
{
public:
	B& operator ->()
	{
		return mB;
	}

	B mB;
};

class D
{
public:
	B* operator ->()
	{
		return &mB;
	}

	B mB;
};

class V3
{
public:
	float x, y, z;
};
class TestOperater
{
public :
	void Test()
	{
		A a;
		a.mint = 10;
		B b;
		b.mA = { 11 };
		C c;
		c.mB = { 12 };
		D d;
		d.mB = { 13 };

		printf("c.mB.mA.mint ----%d\n", c.mB.mA.mint);
		printf(" c->mint -----%d\n", c->mint);
		printf(" d->mA.mint-----%d\n", d->mA.mint);
		printf("(&a)->mint -----%d\n", (&a)->mint);

		const int iOffset = (int)(&((V3*)nullptr)->y);
		printf("iOffset ------%d\n", iOffset);
		const int cLanguageOffset = offsetof(V3, y);
		printf("cLanguageOffset--- %d\n", cLanguageOffset);
	}
};
