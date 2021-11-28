#pragma once
#include "Base.h"
class Train :
	public Base
{
private:
	int yearRelease, countWagons;
	double volumeWeid;
	std::string name;
	Marray<std::string> towns;

	void inputTownsFromConsole();
public:
	Train(std::string _name = "Не задано", double _volumeWeid = 0.0, int _yearRelease = 0, int _countWagons = 0,
		Marray<std::string> _towns = Marray<std::string>());
	Train(const Train& train);
	~Train() { cout << "Вызван деструктор Train" << endl; }

	virtual void inputFromConsole();
	virtual void inputFromFile(std::ifstream& file, std::string& tmpS);
	virtual void printToConsole();
	virtual void printToFile(ostream& out);
	virtual void change();
	Train& operator=(const Train& train);

	int getYearRelease() { return yearRelease; }
	void setYearRelease(int _yearRelease) { yearRelease = _yearRelease; }

	int getCountWagons() { return countWagons; }
	void setCountWagons(int _countWagons) { countWagons = countWagons; }

	std::string getName() { return name; }
	void setName(std::string _name) { name = _name; }

	double getVolumeWeid() { return volumeWeid; }
	void setVolumeWeid(double _volumeWeid) { volumeWeid = _volumeWeid; }

	Marray<std::string> getRoute() { return towns; }
	void setRoute(Marray<std::string> _route) { towns = _route; }
};
