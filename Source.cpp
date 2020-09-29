#include<iostream>
#include<string>
#include"Greske.h"
#include"lista.h"
#include"datum.h"
#include"vozilo.h"
#include"automobil.h"
using namespace std;

int main()
{
	try {
		Datum datum1{ 11, 12, 2012 };
		Datum datum2{ 2, 2, 1999 };
		Datum datum3 = datum1 < datum2;
		Vozilo vozilo1("Tesla", Datum(12, 4, 2013), 3);
		Automobil automobil1("Toyota",33,datum1, Automobil::KUPE);
		cout << datum1 << endl;
		cout << vozilo1 << endl;
		cout << automobil1 << endl;
		cout << datum3 << endl;
		cout << automobil1.brojPutnika();
	}
	catch (GlosUnosDatuma g) { cout << g << endl; }
}