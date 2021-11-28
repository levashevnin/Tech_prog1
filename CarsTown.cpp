#include "CarsTown.h"

CarsTown::CarsTown(std::string _name, double _volumeWeid, double _wayHours)
	: name(_name), volumeWeid(_volumeWeid), wayHours(_wayHours) {}

CarsTown::CarsTown(const CarsTown& carsTown)
	: name(carsTown.name), volumeWeid(carsTown.volumeWeid), wayHours(carsTown.wayHours) {}

void CarsTown::inputFromConsole(int number) {
	inputData("������� �������� ������ " + std::to_string(number) + ": ", name);
	inputData("������� ����� ����� ��� ������ " + std::to_string(number) + ": ", volumeWeid, 0.0, double(INT32_MAX));
	inputData("������� ����� � ���� ��� ������ " + std::to_string(number) + ": ", wayHours, 0.0, double(INT32_MAX));
}

void CarsTown::inputFromFile(std::ifstream& file, std::string& tmpS) {
	std::string err = "���� �� ����� ���� ��������� ��������";
	if (!getline(file, tmpS))
		throw err;
	name = tmpS;
	if (!getline(file, tmpS))
		throw err;
	volumeWeid = (checkStringToDouble(tmpS) ? stod(tmpS) : 0);
	if (!getline(file, tmpS))
		throw err;
	wayHours = (checkStringToDouble(tmpS) ? stod(tmpS) : 0);
}

void CarsTown::printToConsole() {
	std::cout << "��������: " << name << std::endl;
	std::cout << "  ����� � ����: " << wayHours << std::endl;
	std::cout << "  ����� �����: " << volumeWeid << std::endl;
}

void CarsTown::printToFile(std::ostream& out) {
	out << name << std::endl;
	out << wayHours << std::endl;
	out << volumeWeid << std::endl;
}