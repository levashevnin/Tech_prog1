#include "fabric.h"

Base* createObj(string name)
{
	if (name == "����������")
		return new Car();
	if (name == "�������")
		return new Plane();
	if (name == "�����")
		return new Train();
	string err = "��� ������� �� ���������";
	throw err;
}