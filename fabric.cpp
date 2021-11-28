#include "fabric.h"

Base* createObj(string name)
{
	if (name == "Автомобиль")
		return new Car();
	if (name == "Самолет")
		return new Plane();
	if (name == "Поезд")
		return new Train();
	string err = "Тип объекта не распознан";
	throw err;
}