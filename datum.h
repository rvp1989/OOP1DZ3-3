#pragma once
#include<iostream>
#include<string>
#include"Greske.h"
#include"lista.h"
using namespace std;

class Datum
{
protected:
	int d, m, g;
	static int dani[2][12];
public:
	Datum(int dd = 28, int mm = 12, int gg = 2019);
	Datum(const Datum& dat)
	{

		d = dat.d;
		m = dat.m;
		g = dat.g;
	}
	Datum& operator=(const Datum& dat)
	{
		d = dat.d;
		m = dat.m;
		g = dat.g;
		return *this;
	}
	virtual ~Datum() {}
	friend bool operator<(const Datum& d1, const Datum& d2)
	{
		return d1.d < d2.d;
		d1.m < d2.m;
		d1.g < d2.g;
	}
	friend Datum operator-(const Datum& d1, const Datum& d2)
	{

		return d1.d - d2.d;
		d1.m - d2.m;
		d1.g - d2.g;
	}


	int operator[](string s)const;
	friend ostream& operator<<(ostream& it, const Datum& d);
};
Datum::Datum(int dd, int mm, int gg)
{
	if (isalpha(dd) and isalpha(mm) and isalpha(gg))
		throw GlosUnosDatuma();
	else
		d = dd;
	m = mm;
	g = gg;
}

int Datum::operator[](string s)const
{
	if (s == "dan")
		return d;
	if (s == "mesec")
		return m;
	if (s == "godina")
		return g;
}

ostream& operator<<(ostream& it, const Datum& d)
{
	return it << d.d << "." << d.m << "." << d.g << ".";
}