#pragma once
#include "helper.h"
#include "Marray.h"
#include <iostream>
#include <string>

class CarsTown
{
public:
	// �����
	std::string name;
	// ����� �������� � ���-�� �����
	double volumeWeid, wayHours;

	CarsTown(std::string _name = "�� ������", double _volumeWeid = 0.0, double _wayHours = 0.0);
	CarsTown(const CarsTown& carsTown);


	void inputFromConsole(int number);
	void inputFromFile(std::ifstream& file, std::string& tmpS);
	void printToConsole();
	void printToFile(std::ostream& out);
};

