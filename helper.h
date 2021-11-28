#pragma once
#include <iostream>
#include <fstream>
#include <string>

template <typename T>
// проверка ввода(корректных значений)
T safeInput(T minInput, T maxInput) {
	while (true)
	{
		T method;
		std::cin >> method;
		// если введены некорректные
		if (std::cin.fail() || method < minInput || method > maxInput)
		{
			std::cin.clear();
			std::cout << "Неверный ввод.\nПовторите снова: ";
		}
		else
		{
			std::cin.ignore(32767, '\n');
			std::cin.clear();
			// если корректные, то записываем
			return method;
		}
		std::cin.ignore(32767, '\n');
	}
}

// ввод данных, требующих проверку на корректность
template <typename T>
void inputData(std::string help, T& data, T minValue, T maxValue) {
	std::cout << help;
	data = safeInput(minValue, maxValue);
}

// получает целое число от пользователя
bool checkStringToInt(std::string s);
// получает число с плав.точкой от пользователя
bool checkStringToDouble(std::string s);
// получает от польз. имя вводного файла
bool processInputNameOfInputFile(std::string& filename);
// получ. от польз. имя вых. файла:
bool processInputNameOfOutputFile(std::string& filename);
// ввод без проверки
void inputData(std::string help, std::string& data);