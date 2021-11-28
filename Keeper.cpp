#include "Keeper.h"

Keeper::Keeper() : data()
{
	cout << "Вызван конструктор Keeper" << endl;
}

Keeper::Keeper(Marray<Base*> data) : data(data)
{
	cout << "Вызван констукотр Keeper" << endl;
}

Keeper::Keeper(const Keeper& keeper) : data(keeper.data)
{
	cout << "Вызван констукотр копирования Keeper" << endl;
}

void Keeper::inputFromFile()
{
	string filename;
	if (processInputNameOfInputFile(filename)) {
		ifstream input(filename);

		string tmpS;
		int countRecord;
		if (!getline(input, tmpS))
		{
			input.close();
			string err = "Файл не может быть прочитан";
			throw err;
		}
		countRecord = (checkStringToInt(tmpS) ? stoi(tmpS) : 0);
		try
		{
			for (int i = 0; i < countRecord; i++)
			{
				string err = "Файл не может быть корректно прочитан";
				if (!getline(input, tmpS))
					throw err;
				Base* obj = createObj(tmpS);
				obj->inputFromFile(input, tmpS);
				data.add(obj);
			}
		}
		catch (string err)
		{
			input.close();
			throw err;
		}
		input.close();
	}
}

void Keeper::printToFile()
{
	string filename;
	if (processInputNameOfOutputFile(filename)) {
		ofstream output(filename);
		output << data.getSize() << endl;
		for (int i = 0; i < data.getSize(); i++)
			data[i]->printToFile(output);
		output.close();
	}
}

void Keeper::printToConsole()
{
	if (data.getSize() == 0)
		cout << "Грузоперевозчик пуст" << endl;
	else
	{
		cout << "Содержимое грузоперевозчика: " << endl;
		for (int i = 0; i < data.getSize(); i++)
		{
			cout << i + 1 << ". ";
			data[i]->printToConsole();
		}
	}
}