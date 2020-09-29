#pragma once
#include<iostream>
#include<string>
#include"Greske.h"
#include"lista.h"
#include"datum.h"
#include"vozilo.h"

using namespace std;


class Automobil :public Vozilo
{
public:
	enum Tip { KUPE = 2, LIMUZI = 5 };
protected:
	int dnevnicaVozaca;
	Tip tip;
public:
	Automobil(string n, int c, Datum& d, Tip t)
		: Vozilo(n, d, c)
	{
		nazivModela = n;
		datum = d;
		brPutika = t;
		cenaIznajmljivanja = c;
		tip = t;
	}

	int cenaPoDanu(int cena)const override
	{
		if (!vozac)
			return (cena * 0.15) + cena;
	}
	friend ostream& operator<<(ostream& it, const Automobil& a)
	{
		a.pisi(it);
		return it;
	}


protected:
	virtual void pisi(ostream& it)const
	{
		static string tipovi[] = { "KUPE","LIMUZINA" };
		it << dohvModel() << "-" << brPutika << "-" << datum << "-" << tipovi[tip];
	}

};
