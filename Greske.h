#pragma once
#include<iostream>
#include<string>

using namespace std;
class GnemaTek
{
	friend ostream& operator<<(ostream& it, const GnemaTek&)
	{
		return it << "***GRESKA:NEMA TEKUCEG ELEM***";
	}
};

class GpreDatum2
{
	friend ostream& operator<<(ostream& it, const GpreDatum2&)
	{
		return it << "***GRESKA:DATUM1 PRE DATUM2***";
	}
};

class GlosUnosDatuma
{
	friend ostream& operator<<(ostream& it, const GlosUnosDatuma&)
	{
		return it << "***GRESKA:LOS UNOS DATUMA***";
	}
};