#include "Plane.h"

Plane::Plane(std::string _type, std::string _name, double _volumeWeid, double _width,
	double _lengt, double _height, Marray<std::string> _towns)
	:Base("�������"), type(_type), name(_name), volumeWeid(_volumeWeid), width(_width),
	lengt(_lengt), height(_height), towns(_towns)
{
	cout << "������ ����������� Plane" << endl;
}

Plane::Plane(const Plane& plane) :
	Base(plane), type(plane.type), name(plane.name), volumeWeid(plane.volumeWeid), width(plane.width),
	lengt(plane.lengt), height(plane.height), towns(plane.towns)
{
	cout << "������ ����������� ����������� Plane" << endl;
}

void Plane::inputFromConsole() {
	std::cout << "������� ������ � ��������: " << std::endl;
	inputData("������� ���: ", type);
	inputData("������� ������������: ", name);
	inputData("������� ����� �����: ", volumeWeid, 0.0, double(INT32_MAX));
	inputData("������� ����� �����: ", lengt, 0.0, double(INT32_MAX));
	inputData("������� ������ �����: ", width, 0.0, double(INT32_MAX));
	inputData("������� ������ �����: ", height, 0.0, double(INT32_MAX));
	inputTownsFromConsole();
}

void Plane::inputFromFile(std::ifstream& file, std::string& tmpS) {

	string err = "���� �� ����� ���� ��������� ��������";
	if (!getline(file, tmpS))
		throw err;
	type = tmpS;
	if (!getline(file, tmpS))
		throw err;
	name = tmpS;
	if (!getline(file, tmpS))
		throw err;
	volumeWeid = (checkStringToDouble(tmpS) ? stod(tmpS) : 0);
	if (!getline(file, tmpS))
		throw err;
	lengt = (checkStringToDouble(tmpS) ? stod(tmpS) : 0);
	if (!getline(file, tmpS))
		throw err;
	width = (checkStringToDouble(tmpS) ? stod(tmpS) : 0);
	if (!getline(file, tmpS))
		throw err;
	height = (checkStringToDouble(tmpS) ? stod(tmpS) : 0);
	if (!getline(file, tmpS))
		throw err;
	int countTowns = (checkStringToInt(tmpS) ? stoi(tmpS) : 0);
	for (int i = 0; i < countTowns; i++) {
		if (!getline(file, tmpS))
			throw err;
		towns.add(tmpS);
	}
}

void Plane::printToConsole() {
	Base::printToConsole();
	cout << "���: " << type << std::endl;
	cout << "���: " << name << std::endl;
	cout << "����� �����: " << volumeWeid << std::endl;
	cout << "����� �����: " << lengt << std::endl;
	cout << "������ �����: " << width << std::endl;
	cout << "������ �����: " << height << std::endl;
	if (towns.getSize() > 0) {
		cout << "������ �������: " << std::endl;
		for (int i = 0; i < towns.getSize(); i++)
			cout << "����� " << i + 1 << " = " << towns[i] << std::endl;
	}
	else
		cout << "������ ������� ����" << std::endl;
	cout << std::endl;
}

void Plane::printToFile(std::ostream& out) {
	Base::printToFile(out);
	out << type << std::endl;
	out << name << std::endl;
	out << volumeWeid << std::endl;
	out << lengt << std::endl;
	out << width << std::endl;
	out << height << std::endl;
	out << towns.getSize() << std::endl;
	for (int i = 0; i < towns.getSize(); i++)
		out << towns[i] << endl;
}

void Plane::change() {
	std::string tmpString;
	double tmpDouble = 0.0;
	bool isExit = false;
	while (!isExit) {

		std::cout << "1. �������� ���" << std::endl;
		std::cout << "2. �������� ������������" << std::endl;
		std::cout << "3. �������� ����� ������������ �����" << std::endl;
		std::cout << "4. �������� ����� �����" << std::endl;
		std::cout << "5. �������� ������ �����" << std::endl;
		std::cout << "6. �������� ������ �����" << std::endl;
		std::cout << "7. �������� ������ �������" << std::endl;
		std::cout << "8. ������� ������ �� �����" << std::endl;
		std::cout << "0. ��������� ���������" << std::endl;
		std::cout << "�������� ����� ����: ";

		int method = safeInput(0, 8);
		switch (method)
		{
		case 1:
			inputData("������� ���: ", tmpString);
			setType(tmpString);
			break;
		case 2:
			inputData("������� ������������: ", tmpString);
			setName(tmpString);
			break;
		case 3:
			inputData("������� ����� ������������ �����: ", tmpDouble, 0.0, double(INT32_MAX));
			setVolumeWeid(tmpDouble);
			break;
		case 4:
			inputData("������� ����� �����: ", tmpDouble, 0.0, double(INT32_MAX));
			setLengt(tmpDouble);
			break;
		case 5:
			inputData("������� ������ �����: ", tmpDouble, 0.0, double(INT32_MAX));
			setWidth(tmpDouble);
			break;
		case 6:
			inputData("������� ������ �����: ", tmpDouble, 0.0, double(INT32_MAX));
			setHeight(tmpDouble);
			break;
		case 7:
			towns.clear();
			inputTownsFromConsole();
			break;
		case 8:
			printToConsole();
			break;
		case 0:
			isExit = true;
			break;
		}
	}
}

Plane& Plane::operator=(const Plane& plane)
{
	if (this == &plane)
		return *this;
	type = plane.type;
	name = plane.name;
	volumeWeid = plane.volumeWeid;
	width = plane.width;
	lengt = plane.lengt;
	height = plane.height;
	towns = plane.towns;
	return *this;
}

void Plane::inputTownsFromConsole() {
	int countTowns;
	inputData("������� ���������� ������� � ��������: ", countTowns, 0, INT32_MAX);
	for (int i = 0; i < countTowns; i++) {
		std::string townName;
		inputData("������� �������� ������ " + std::to_string(i + 1) + ": ", townName);
		towns.add(townName);
	}
}