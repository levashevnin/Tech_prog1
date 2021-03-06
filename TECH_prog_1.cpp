#include "Keeper.h"
#include <iostream>
#include <fstream>
#include <Windows.h>

using namespace std;

const int MAX_BECUP_COUNT = 5;

void printMenu();
void addObject(Keeper& keeper);
void changeObject(Keeper& keeper);
void deleteObject(Keeper& keeper, Marray<Base*>& becup);
void recoverObject(Keeper& keeper, Marray<Base*>& becup);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Keeper keeper;
	Marray<Base*> becup;

	cout << "Ввести изначальные данные из файла?(1/0)" << endl;
	int method = safeInput(0, 1);
	try
	{
		if (method == 1)
			keeper.inputFromFile();
	}
	catch (string err)
	{
		cout << err << endl;
	}


	bool isExit = false;
	while (!isExit) {
		printMenu();
		method = safeInput(0, 6);
		switch (method)
		{
		case 1:
			addObject(keeper);
			break;
		case 2:
			changeObject(keeper);
			break;
		case 3:
			deleteObject(keeper, becup);
			break;
		case 4:
			keeper.printToConsole();
			break;
		case 5:
			keeper.printToFile();
			break;
		case 6:
			recoverObject(keeper, becup);
			break;
		case 0:
			isExit = true;
			break;
		}
	}
}

void printMenu() {
	cout << "1. Добавить объект" << endl;
	cout << "2. Изменить объект" << endl;
	cout << "3. Удалить объект" << endl;
	cout << "4. Вывести данные на экран" << endl;
	cout << "5. Сохранить в файл" << endl;
	cout << "6. Восстановить последние удаленные элементы" << endl;
	cout << "0. Выход" << endl;
	cout << "Выберете пункт меню: ";
}

void addObject(Keeper& keeper)
{
	cout << "Выберете объект для добавления" << endl;
	cout << "1. Автомобиль" << endl;
	cout << "2. Самолет" << endl;
	cout << "3. Поезд" << endl;
	int typeInt = safeInput(1, 3);
	string typeS;
	if (typeInt == 1)
		typeS = "Автомобиль";
	if (typeInt == 2)
		typeS = "Самолет";
	if (typeInt == 3)
		typeS = "Поезд";
	Base* object = createObj(typeS);
	object->inputFromConsole();
	keeper.add(object);
}

void changeObject(Keeper& keeper)
{
	if (keeper.getSize() == 0)
		cout << "Грузоперевозчик пуст. Нечего изменять" << endl;
	else
	{
		keeper.printToConsole();
		cout << "Выберете номер объекта для изменения: ";
		int number = safeInput(1, keeper.getSize());
		keeper[number - 1]->change();
	}
}

void deleteObject(Keeper& keeper, Marray<Base*>& becup)
{
	if (keeper.getSize() == 0)
		cout << "Грузоперевозчик пуст. Нечего удалять" << endl;
	else
	{
		keeper.printToConsole();
		cout << "Выберете номер объекта для удаления: ";
		int number = safeInput(1, keeper.getSize());
		if (becup.getSize() == MAX_BECUP_COUNT)
			becup.del(0);
		becup.add(keeper[number - 1]);
		keeper.del(number - 1);
	}
}

void recoverObject(Keeper& keeper, Marray<Base*>& becup) {
	if (becup.getSize() == 0)
		cout << "Список недавно удаленных элементов пуст. Нечего восстанавливать" << endl;
	else
	{
		cout << "Список объектов для восстановления: " << endl;
		for (int i = 0; i < becup.getSize(); i++) {
			cout << i + 1 << ". ";
			becup[i]->printToConsole();
		}
		cout << "Выберете номер объекта для восстановления: ";
		int number = safeInput(1, becup.getSize());
		keeper.add(becup[number - 1]);
		becup.del(number - 1);
	}
}