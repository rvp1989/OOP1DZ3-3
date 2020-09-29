#pragma once
#include<iostream>
#include<string>
#include"Greske.h"
using namespace std;


template<typename T>
class Lista
{
	struct Elem
	{
		T pod;
		Elem* sled;
		Elem(const T& p, Elem* s = nullptr)
			: pod(p), sled(s) {}
	};
	Elem* prvi, * posl;
	int br;
	mutable Elem* tek;
	void brisi();
public:
	Lista() { prvi = posl = tek = nullptr;br = 0; }
	Lista(const Lista& lst) = delete;
	Lista& operator=(const Lista& lst) = delete;
	~Lista() { brisi(); }
	Lista& dodaj(const T& t)
	{
		posl = (!prvi ? prvi : posl->sled) = new Elem(t);
		br++;
		return *this;
	}
	int broj()const { return br; }
	void naPrvi()const { tek = prvi; }
	void naSled()const
	{
		if (tek)
			tek = tek->sled;
	}
	bool imaTek()const { return tek != nullptr; }
	T& dohvPod()const
	{
		if (!tek)
			throw GnemaTek();
		return tek->pod;
	}
};

template<typename T>
void Lista<T>::brisi()
{
	while (prvi)
	{
		Elem* stari = prvi;
		prvi = prvi->sled;
		delete stari;
	}
	posl = tek = nullptr;
}