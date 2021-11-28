#pragma once
#include "Base.h"

class Plane :
	public Base
{
private:
	std::string type, name;
	Marray<std::string> towns;
	double volumeWeid, width, lengt, height;

	void inputTownsFromConsole();
public:

	Plane(std::string _type = "Не задано", std::string _name = "Не задано", double _volumeWeid = 0.0, double _width = 0.0,
		double _lengt = 0.0, double _height = 0.0, Marray<std::string> _towns = Marray<std::string>());
	Plane(const Plane& plane);
	~Plane() { cout << "Вызван деструктор Plane" << endl; }

	virtual void inputFromConsole();
	virtual void inputFromFile(std::ifstream& file, std::string& tmpS);
	virtual void printToConsole();
	virtual void printToFile(ostream& out);
	virtual void change();
	Plane& operator=(const Plane& plane);


	std::string getType() { return type; }
	void setType(std::string _type) { type = _type; }

	std::string getName() { return name; }
	void setName(std::string _name) { name = _name; }

	double getVolumeWeid() { return volumeWeid; }
	void setVolumeWeid(double _volumeWeid) { volumeWeid = _volumeWeid; }

	double getWidth() { return width; }
	void setWidth(double _width) { width = _width; }

	double getLengt() { return lengt; }
	void setLengt(double _lengt) { lengt = _lengt; }

	double getHeight() { return height; }
	void setHeight(double _height) { height = _height; }

	Marray<std::string> getTowns() { return towns; }
	void setTowns(Marray<std::string> _towns) { towns = _towns; }
};

