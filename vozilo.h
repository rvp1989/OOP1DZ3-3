#pragma once
#include<iostream>
#include<string>
#include"Greske.h"
#include"lista.h"
#include"datum.h"

using namespace std;


class Vozilo
{
protected:
	string nazivModela;
	Datum datum;
	int cenaIznajmljivanja;
	int brPutika;
	int vozac = 1;
public:
	Vozilo(string n, const Datum& d, int c)
	{
		nazivModela = n;
		datum = d;
		brPutika = 0;
		cenaIznajmljivanja = c;
	}
	Vozilo(const Vozilo&) = delete;
	Vozilo& operator=(const Vozilo&) = delete;
	string dohvModel()const { return nazivModela; }
	virtual Datum datumProizvodnje(Datum& dat) { return datum; }
	int brojPutnika()const { return brPutika + vozac; }
	virtual int cenaPoDanu(int cena)const { return cenaIznajmljivanja; }
	virtual bool dohvvozac(int vozac)const
	{
		if (!vozac)
			return false;
		else
			return true;
	}
protected:
	friend ostream& operator<<(ostream& it, const Vozilo& v)
	{
		return it << v.nazivModela << "-" << v.brojPutnika() << "-" << v.datum;
	}
};