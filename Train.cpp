#include "Train.h"

Train::Train(std::string _name, double _volumeWeid, int _yearRelease, int _countWagons, Marray<std::string> _towns)
	: Base("�����"), name(_name), volumeWeid(_volumeWeid), yearRelease(_yearRelease),
	countWagons(_countWagons), towns(_towns)
{
	cout << "������ ����������� Train" << endl;
}

Train::Train(const Train& train)
	: Base(train), name(train.name), volumeWeid(train.volumeWeid), yearRelease(train.yearRelease),
	countWagons(train.countWagons), towns(train.towns)
{
	cout << "������ ����������� ����������� Train" << endl;
}

void Train::inputFromConsole() {
	std::cout << "������� ������ � ������: " << std::endl;
	inputData("������� ������������: ", name);
	inputData("������� ����� �����: ", volumeWeid, 0.0, double(INT32_MAX));
	inputData("������� ��� �������: ", yearRelease, 0, INT32_MAX);
	inputData("������� ���������� �������: ", countWagons, 0, INT32_MAX);
	inputTownsFromConsole();
}

void Train::inputFromFile(std::ifstream& file, std::string& tmpS) {

	string err = "���� �� ����� ���� ��������� ��������";
	if (!getline(file, tmpS))
		throw err;
	name = tmpS;
	if (!getline(file, tmpS))
		throw err;
	volumeWeid = (checkStringToDouble(tmpS) ? stod(tmpS) : 0);
	if (!getline(file, tmpS))
		throw err;
	countWagons = (checkStringToInt(tmpS) ? stoi(tmpS) : 0);
	if (!getline(file, tmpS))
		throw err;
	yearRelease = (checkStringToInt(tmpS) ? stoi(tmpS) : 0);
	if (!getline(file, tmpS))
		throw err;
	int countTowns = (checkStringToInt(tmpS) ? stoi(tmpS) : 0);
	for (int i = 0; i < countTowns; i++) {
		if (!getline(file, tmpS))
			throw err;
		towns.add(tmpS);
	}
}

void Train::printToConsole() {
	Base::printToConsole();
	cout << "���: " << name << std::endl;
	cout << "����� �����: " << volumeWeid << std::endl;
	cout << "��� �������: " << yearRelease << std::endl;
	cout << "����� �������: " << countWagons << std::endl;
	if (towns.getSize() > 0) {
		cout << "������ �������: " << std::endl;
		for (int i = 0; i < towns.getSize(); i++)
			cout << "����� " << i + 1 << " = " << towns[i] << std::endl;
	}
	else
		cout << "������ ������� ����" << std::endl;
	cout << std::endl;
}

void Train::printToFile(std::ostream& out) {
	Base::printToFile(out);
	out << name << std::endl;
	out << volumeWeid << std::endl;
	out << yearRelease << std::endl;
	out << countWagons << std::endl;
	out << towns.getSize() << std::endl;
	for (int i = 0; i < towns.getSize(); i++)
		out << towns[i] << endl;
}

void Train::change() {
	std::string tmpString;
	double tmpDouble = 0.0;
	int tmpInt = 0;
	bool isExit = false;
	while (!isExit) {

		std::cout << "1. �������� ������������" << std::endl;
		std::cout << "2. �������� ��� �������" << std::endl;
		std::cout << "3. �������� ����� ������������ �����" << std::endl;
		std::cout << "4. �������� ���������� �������" << std::endl;
		std::cout << "5. �������� �������" << std::endl;
		std::cout << "6. ������� ������ �� �����" << std::endl;
		std::cout << "0. ��������� ���������" << std::endl;
		std::cout << "�������� ����� ����: ";

		int method = safeInput(0, 6);
		switch (method)
		{
		case 1:
			inputData("������� ������������: ", tmpString);
			setName(tmpString);
			break;
		case 2:
			inputData("������� ��� �������: ", tmpInt, 0, INT32_MAX);
			setYearRelease(tmpInt);
			break;
		case 3:
			inputData("������� ����� ������������ �����: ", tmpDouble, 0.0, double(INT32_MAX));
			setVolumeWeid(tmpDouble);
			break;
		case 4:
			inputData("������� ��������� �������: ", tmpInt, 0, INT32_MAX);
			setCountWagons(tmpInt);
			break;
		case 5:
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

Train& Train::operator=(const Train& train)
{
	if (this == &train)
		return *this;
	name = train.name;
	volumeWeid = train.volumeWeid;
	yearRelease = train.yearRelease;
	countWagons = train.countWagons;
	towns = train.towns;
	return *this;
}

void Train::inputTownsFromConsole() {
	int countTowns;
	inputData("������� ���������� ������� � ��������: ", countTowns, 0, INT32_MAX);
	for (int i = 0; i < countTowns; i++) {
		std::string townName;
		inputData("������� �������� ������ " + std::to_string(i + 1) + ": ", townName);
		towns.add(townName);
	}
}