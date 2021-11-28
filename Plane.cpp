#include "Plane.h"

Plane::Plane(std::string _type, std::string _name, double _volumeWeid, double _width,
	double _lengt, double _height, Marray<std::string> _towns)
	:Base("Самолет"), type(_type), name(_name), volumeWeid(_volumeWeid), width(_width),
	lengt(_lengt), height(_height), towns(_towns)
{
	cout << "Вызван конструктор Plane" << endl;
}

Plane::Plane(const Plane& plane) :
	Base(plane), type(plane.type), name(plane.name), volumeWeid(plane.volumeWeid), width(plane.width),
	lengt(plane.lengt), height(plane.height), towns(plane.towns)
{
	cout << "Вызван конструктор копирования Plane" << endl;
}

void Plane::inputFromConsole() {
	std::cout << "Введите данные о самолете: " << std::endl;
	inputData("Введите тип: ", type);
	inputData("Введите наименование: ", name);
	inputData("Введите объем груза: ", volumeWeid, 0.0, double(INT32_MAX));
	inputData("Введите длину груза: ", lengt, 0.0, double(INT32_MAX));
	inputData("Введите ширину груза: ", width, 0.0, double(INT32_MAX));
	inputData("Введите высоту груза: ", height, 0.0, double(INT32_MAX));
	inputTownsFromConsole();
}

void Plane::inputFromFile(std::ifstream& file, std::string& tmpS) {

	string err = "Файл не может быть корректно прочитан";
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
	cout << "Тип: " << type << std::endl;
	cout << "Имя: " << name << std::endl;
	cout << "Объем груза: " << volumeWeid << std::endl;
	cout << "Длина груза: " << lengt << std::endl;
	cout << "Ширина груза: " << width << std::endl;
	cout << "высота груза: " << height << std::endl;
	if (towns.getSize() > 0) {
		cout << "Список городов: " << std::endl;
		for (int i = 0; i < towns.getSize(); i++)
			cout << "Город " << i + 1 << " = " << towns[i] << std::endl;
	}
	else
		cout << "Список городов пуст" << std::endl;
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

		std::cout << "1. Изменить тип" << std::endl;
		std::cout << "2. Изменить наименование" << std::endl;
		std::cout << "3. Изменить объем перевозимого груза" << std::endl;
		std::cout << "4. Изменить длину груза" << std::endl;
		std::cout << "5. Изменить ширину груза" << std::endl;
		std::cout << "6. Изменить высоту груза" << std::endl;
		std::cout << "7. Изменить список городов" << std::endl;
		std::cout << "8. Вывести данные на экран" << std::endl;
		std::cout << "0. Сохранить изменения" << std::endl;
		std::cout << "Выберете пункт меню: ";

		int method = safeInput(0, 8);
		switch (method)
		{
		case 1:
			inputData("Введите тип: ", tmpString);
			setType(tmpString);
			break;
		case 2:
			inputData("Введите наименование: ", tmpString);
			setName(tmpString);
			break;
		case 3:
			inputData("Введите объем перевозимого груза: ", tmpDouble, 0.0, double(INT32_MAX));
			setVolumeWeid(tmpDouble);
			break;
		case 4:
			inputData("Введите длину груза: ", tmpDouble, 0.0, double(INT32_MAX));
			setLengt(tmpDouble);
			break;
		case 5:
			inputData("Введите ширину груза: ", tmpDouble, 0.0, double(INT32_MAX));
			setWidth(tmpDouble);
			break;
		case 6:
			inputData("Введите высоту груза: ", tmpDouble, 0.0, double(INT32_MAX));
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
	inputData("Введите количество городов в маршруте: ", countTowns, 0, INT32_MAX);
	for (int i = 0; i < countTowns; i++) {
		std::string townName;
		inputData("Введите название города " + std::to_string(i + 1) + ": ", townName);
		towns.add(townName);
	}
}