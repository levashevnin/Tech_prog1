#pragma once
#include "helper.h"
#include "Marray.h"
#include <string>

using namespace std;

class Base
{
private:
	// ������
	string typeObj;
public:
	Base(string typeObj);
	Base(const Base& base);
	~Base() { cout << "������ ���������� Base" << endl; }

	virtual void inputFromConsole() = 0;
	virtual void inputFromFile(std::ifstream& file, std::string& tmpS) = 0;
	virtual void printToConsole();
	virtual void printToFile(ostream& out);
	// �������� ������ �� �������:
	virtual void change() = 0;
	// ������ ������
	string getTypeObj() { return typeObj; }
};

