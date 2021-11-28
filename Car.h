#pragma once
#include "Base.h"
#include "CarsTown.h"

class Car :
	public Base
{

private:
	int yearRelease;
	std::string mark, model;
	Marray<CarsTown> towns;

	void inputTownsFromConsole();
public:
	Car(std::string _mark = "Не задано", std::string _model = "Не задано",
		int _yearRelease = 0.0, Marray<CarsTown> _towns = Marray<CarsTown>());
	Car(const Car& car);
	~Car() { cout << "Вызван деструктор Car" << endl; };

	virtual void inputFromConsole();
	virtual void inputFromFile(std::ifstream& file, std::string& tmpS);
	virtual void printToConsole();
	virtual void printToFile(ostream& out);
	// изменить данные об объекте:
	virtual void change();
	Car& operator=(const Car& car);
	
	std::string getMark() { return mark; }
	void setMark(std::string _mark) { mark = _mark; }

	std::string getModel() { return model; }
	void setModel(std::string _model) { model = _model; }

	int getYearRelease() { return yearRelease; }
	void setYearRelease(int _yearRelease) { yearRelease = _yearRelease; }

	Marray<CarsTown> getTowns() { return towns; }
	void setTowns(Marray<CarsTown> _towns) { towns = _towns; }
};

