#pragma once
#include <iostream>
#include <fstream>
#include <string>

template <typename T>
// �������� �����(���������� ��������)
T safeInput(T minInput, T maxInput) {
	while (true)
	{
		T method;
		std::cin >> method;
		// ���� ������� ������������
		if (std::cin.fail() || method < minInput || method > maxInput)
		{
			std::cin.clear();
			std::cout << "�������� ����.\n��������� �����: ";
		}
		else
		{
			std::cin.ignore(32767, '\n');
			std::cin.clear();
			// ���� ����������, �� ����������
			return method;
		}
		std::cin.ignore(32767, '\n');
	}
}

// ���� ������, ��������� �������� �� ������������
template <typename T>
void inputData(std::string help, T& data, T minValue, T maxValue) {
	std::cout << help;
	data = safeInput(minValue, maxValue);
}

// �������� ����� ����� �� ������������
bool checkStringToInt(std::string s);
// �������� ����� � ����.������ �� ������������
bool checkStringToDouble(std::string s);
// �������� �� �����. ��� �������� �����
bool processInputNameOfInputFile(std::string& filename);
// �����. �� �����. ��� ���. �����:
bool processInputNameOfOutputFile(std::string& filename);
// ���� ��� ��������
void inputData(std::string help, std::string& data);