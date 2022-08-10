#include "Student.h"
#include <iostream>
#include <sstream>
#include <vector>

void DataParser(std::string date, int& parsedDay, int& parsedMonth, int& parsedYear)// функция для парсинга строковой даты в 3 целочисленных значения для сравнения
{
	std::string sentence = date;
	std::istringstream iss(sentence);
	std::vector<std::string> tokens;
	std::string token;
	while (std::getline(iss, token, '.')) {	// парсинг даты формата ДД.ММ.ГГГГ на день месяц и год для дальнейшего сравнения, разделителем служит точка
		if (!token.empty())
			tokens.push_back(token);
	}
	parsedDay = std::stoi(tokens[0]);
	parsedMonth = std::stoi(tokens[1]);
	parsedYear = std::stoi(tokens[2]);
}

void YoungestStudentSearch(std::vector<Student>&ArrayOfStudents) // функция поиска принимает указатель на массив со студентами и размер этого массива
{
	int ArrayCapacity = ArrayOfStudents.size();
	if (!ArrayCapacity)
	{
		std::cout << "Empty array!";
		return;
	}
	Student youngestStud = ArrayOfStudents[0]; // в начале сортировки будем считать что самый молодой студент это первый
	std::string hisBirthday = youngestStud.GetBirthday();
	int currDay, currMonth, currYear = NULL;
	DataParser(hisBirthday, currDay, currMonth, currYear);

	for (int i = 0; i < ArrayCapacity; ++i) // цикл проверки
	{
		Student tmpStud = ArrayOfStudents[i];
		std::string tmpBirthday = tmpStud.GetBirthday();
		int tmpDay, tmpMonth, tmpYear = NULL;
		DataParser(tmpBirthday, tmpDay, tmpMonth, tmpYear);
		if (currYear < tmpYear)
		{
			youngestStud = ArrayOfStudents[i];
			std::string hisBirthday = youngestStud.GetBirthday();
			DataParser(hisBirthday, currDay, currMonth, currYear);
		}

		if (currYear <= tmpYear && currMonth < tmpMonth )
		{
			youngestStud = ArrayOfStudents[i];
			std::string hisBirthday = youngestStud.GetBirthday();
			DataParser(hisBirthday, currDay, currMonth, currYear);
		}
		if (currYear <= tmpYear && currDay < tmpDay && currMonth <= tmpMonth)
		{
			youngestStud = ArrayOfStudents[i];
			std::string hisBirthday = youngestStud.GetBirthday();
			DataParser(hisBirthday, currDay, currMonth, currYear);
		}	
	}

	std::cout << "\nYoungest student is:\n";
	youngestStud.Print();

}

void BithdaySort(std::vector<Student>& ArrayOfStudents)
{
	int ArrayCapacity = ArrayOfStudents.size();
	if (!ArrayCapacity)
	{
		std::cout << "Empty array!";
		return;
	}
	for (int i = 0; i < ArrayCapacity; ++i) // цикл проверки
	{
		Student& youngestStud = ArrayOfStudents[i];
		std::string hisBirthday = youngestStud.GetBirthday();
		int currDay, currMonth, currYear = NULL;
		DataParser(hisBirthday, currDay, currMonth, currYear);
		for (int j = i + 1; j < ArrayCapacity; ++j)
		{
			Student& secondStud = ArrayOfStudents[j];
			std::string tmpBirthday = secondStud.GetBirthday();
			int tmpDay, tmpMonth, tmpYear = NULL;
			DataParser(tmpBirthday, tmpDay, tmpMonth, tmpYear);
			if (currYear < tmpYear)
			{
				Student tmp = youngestStud;
				youngestStud = secondStud;
				secondStud = tmp;
				std::string hisBirthday = youngestStud.GetBirthday();
				DataParser(hisBirthday, currDay, currMonth, currYear);
			}

			if (currYear <= tmpYear && currMonth < tmpMonth)
			{
				Student tmp = youngestStud;
				youngestStud = secondStud;
				secondStud = tmp;
				std::string hisBirthday = youngestStud.GetBirthday();
				DataParser(hisBirthday, currDay, currMonth, currYear);
			}
			if (currYear <= tmpYear && currDay < tmpDay && currMonth <= tmpMonth)
			{
				Student tmp = youngestStud;
				youngestStud = secondStud;
				secondStud = tmp;
				std::string hisBirthday = youngestStud.GetBirthday();
				DataParser(hisBirthday, currDay, currMonth, currYear);
			}
		}
	}
}

int main()
{
	setlocale(LC_ALL, "ru");					// выставляет кодировку
	std::vector<Student> students{Student()};	// создаётся вектор(динамический массив) объектов класса студент для ввода вывода через файл
	students[0].ReadFromFile(students);			// чтение данных из файла		
	students.shrink_to_fit();					// освобождение памяти от хвоста вектора
	YoungestStudentSearch(students);			// передача вектора в функцию поиска самого молодого студента
	BithdaySort(students);						// передача вектора в функцию сортировки
	students[0].WriteToFile(students);			// запись в файл
	students[0].Print(students);
	std::cin;
}
