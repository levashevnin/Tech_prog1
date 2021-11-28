#pragma once
#include "fabric.h"

class Keeper
{
private:
	Marray<Base*> data;
public:
	Keeper();
	Keeper(Marray<Base*> data);
	Keeper(const Keeper& keeper);
	~Keeper() { cout << "Вызван деструктор Keeper" << endl; }

	void add(Base* base) { data.add(base); }
	void del(int index) { data.del(index); }
	Base* operator[](int index) { return data[index]; }
	void inputFromFile();
	void printToFile();
	void printToConsole();

	int getSize() { return data.getSize(); }
};
