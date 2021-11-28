#include "Train.h"

Train::Train(std::string _name, double _volumeWeid, int _yearRelease, int _countWagons, Marray<std::string> _towns)
	: Base("Поезд"), name(_name), volumeWeid(_volumeWeid), yearRelease(_yearRelease),
	countWagons(_countWagons), towns(_towns)
{
	cout << "Вызван конструктор Train" << endl;
}

Train::Train(const Train& train)
	: Base(train), name(train.name), volumeWeid(train.volumeWeid), yearRelease(train.yearRelease),
	countWagons(train.countWagons), towns(train.towns)
{
	cout << "Вызван конструктор копирования Train" << endl;
}

void Train::inputFromConsole() {
	std::cout << "Введите данные о поезде: " << std::endl;
	inputData("Введите наименование: ", name);
	inputData("Введите объем груза: ", volumeWeid, 0.0, double(INT32_MAX));
	inputData("Введите год выпуска: ", yearRelease, 0, INT32_MAX);
	inputData("Введите количество вагонов: ", countWagons, 0, INT32_MAX);
	inputTownsFromConsole();
}

void Train::inputFromFile(std::ifstream& file, std::string& tmpS) {

	string err = "Файл не может быть корректно прочитан";
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
	cout << "Имя: " << name << std::endl;
	cout << "Объем груза: " << volumeWeid << std::endl;
	cout << "Год выпуска: " << yearRelease << std::endl;
	cout << "Число вагонов: " << countWagons << std::endl;
	if (towns.getSize() > 0) {
		cout << "Список городов: " << std::endl;
		for (int i = 0; i < towns.getSize(); i++)
			cout << "Город " << i + 1 << " = " << towns[i] << std::endl;
	}
	else
		cout << "Список городов пуст" << std::endl;
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

		std::cout << "1. Изменить наименование" << std::endl;
		std::cout << "2. Изменить год выпуска" << std::endl;
		std::cout << "3. Изменить объем перевозимого груза" << std::endl;
		std::cout << "4. Изменить количество вагонов" << std::endl;
		std::cout << "5. Изменить маршрут" << std::endl;
		std::cout << "6. Вывести данные на экран" << std::endl;
		std::cout << "0. Сохранить изменения" << std::endl;
		std::cout << "Выберете пункт меню: ";

		int method = safeInput(0, 6);
		switch (method)
		{
		case 1:
			inputData("Введите наименование: ", tmpString);
			setName(tmpString);
			break;
		case 2:
			inputData("Введите год выпуска: ", tmpInt, 0, INT32_MAX);
			setYearRelease(tmpInt);
			break;
		case 3:
			inputData("Введите объем перевозимого груза: ", tmpDouble, 0.0, double(INT32_MAX));
			setVolumeWeid(tmpDouble);
			break;
		case 4:
			inputData("Введите количство вагонов: ", tmpInt, 0, INT32_MAX);
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
	inputData("Введите количество городов в маршруте: ", countTowns, 0, INT32_MAX);
	for (int i = 0; i < countTowns; i++) {
		std::string townName;
		inputData("Введите название города " + std::to_string(i + 1) + ": ", townName);
		towns.add(townName);
	}
}