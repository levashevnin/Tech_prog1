#include "Car.h"

Car::Car(std::string _mark, std::string _model, int _yearRelease, Marray<CarsTown> _towns)
	: Base("����������"), mark(_mark), model(_model), yearRelease(_yearRelease), towns(_towns)
{
	cout << "������ ����������� Car" << endl;
}

Car::Car(const Car& car)
	: Base(car), mark(car.mark), model(car.model), yearRelease(car.yearRelease), towns(car.towns)
{
	cout << "������ ����������� ����������� Car" << endl;
}

void Car::inputFromConsole() {
	std::cout << "������� ������ �� ����������: " << std::endl;
	inputData("������� �����: ", mark);
	inputData("������� ������: ", model);
	inputData("������� ��� �������: ", yearRelease, 0, INT32_MAX);
	inputTownsFromConsole();
}

void Car::inputFromFile(std::ifstream& file, std::string& tmpS) {

	string err = "���� �� ����� ���� ��������� ��������";
	if (!getline(file, tmpS))
		throw err;
	mark = tmpS;
	if (!getline(file, tmpS))
		throw err;
	model = tmpS;
	if (!getline(file, tmpS))
		throw err;
	yearRelease = (checkStringToInt(tmpS) ? stoi(tmpS) : 0);
	if (!getline(file, tmpS))
		throw err;
	int countTowns = (checkStringToInt(tmpS) ? stoi(tmpS) : 0);
	for (int i = 0; i < countTowns; i++) {
		CarsTown carsTown;
		carsTown.inputFromFile(file, tmpS);
		towns.add(carsTown);
	}
}

void Car::printToConsole() {
	Base::printToConsole();
	cout << "�����: " << mark << std::endl;
	cout << "������: " << model << std::endl;
	cout << "��� �������: " << yearRelease << std::endl;
	if (towns.getSize() > 0) {
		cout << "������ �������: " << std::endl;
		for (int i = 0; i < towns.getSize(); i++) {
			cout << i + 1 << ". ";
			towns[i].printToConsole();
		}

	}
	else
		cout << "������ ������� ����" << std::endl;
	cout << std::endl;
}

void Car::printToFile(std::ostream& out) {
	Base::printToFile(out);
	out << mark << std::endl;
	out << model << std::endl;
	out << yearRelease << std::endl;
	out << towns.getSize() << std::endl;
	for (int i = 0; i < towns.getSize(); i++)
		towns[i].printToFile(out);
}

void Car::change() {
	std::string tmpString;
	int tmpInt = 0;
	bool isExit = false;
	while (!isExit) {

		std::cout << "1. �������� ������" << std::endl;
		std::cout << "2. �������� �����" << std::endl;
		std::cout << "3. �������� ��� �������" << std::endl;
		std::cout << "4. �������� ������ �������" << std::endl;
		std::cout << "5. ������� ������ �� �����" << std::endl;
		std::cout << "0. ��������� ���������" << std::endl;
		std::cout << "�������� ����� ����: ";

		int method = safeInput(0, 5);
		switch (method)
		{
		case 1:
			inputData("������� ������: ", tmpString);
			setModel(tmpString);
			break;
		case 2:
			inputData("������� �����: ", tmpString);
			setMark(tmpString);
			break;
		case 3:
			inputData("������� ��� �������: ", tmpInt, 0, INT32_MAX);
			setYearRelease(tmpInt);
			break;
		case 4:
			towns.clear();
			inputTownsFromConsole();
			break;
		case 6:
			printToConsole();
			break;
		case 0:
			isExit = true;
			break;
		}
	}
}

Car& Car::operator=(const Car& car)
{
	if (this == &car)
		return *this;
	yearRelease = car.yearRelease;
	mark = car.mark;
	model = car.model;
	towns = car.towns;
	return *this;
}

void Car::inputTownsFromConsole() {
	int countTowns;
	inputData("������� ���������� �������: ", countTowns, 0, INT32_MAX);
	for (int i = 0; i < countTowns; i++) {
		CarsTown carsTown;
		carsTown.inputFromConsole(i + 1);
		towns.add(carsTown);
	}
}