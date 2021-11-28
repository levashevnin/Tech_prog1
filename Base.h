#pragma once
#include "helper.h"
#include "Marray.h"
#include <string>

using namespace std;

class Base
{
private:
	// маркер
	string typeObj;
public:
	Base(string typeObj);
	Base(const Base& base);
	~Base() { cout << "Вызван деструктор Base" << endl; }

	virtual void inputFromConsole() = 0;
	virtual void inputFromFile(std::ifstream& file, std::string& tmpS) = 0;
	virtual void printToConsole();
	virtual void printToFile(ostream& out);
	// изменить данные об объекте:
	virtual void change() = 0;
	// узнать маркер
	string getTypeObj() { return typeObj; }
};

