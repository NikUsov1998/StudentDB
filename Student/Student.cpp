#include "Student.h"
//*************************Конструкторы**********************************
Student::Student()
{
	FIO = "Ivanov Ivan Ivanovich";	// ФИО
	sex = "male";					// Пол Мужской
	bitrhday = "01.01.2000";		// Дата рождения в формате ДД.ММ.ГГГГ !!!ОБЯЗАТЕЛЬНО В ЭТОМ ФОРМАТЕ ЛОГИКУ ПРОВЕРКИ НА ПРАВИЛЬНОСТЬ ВВЕДЁННОЙ ДАТЫ НЕ УСПЕЛ ДОДЕЛАТЬ!!!
	height = 175.4;					// Рост
	examScore = 200;				// Выпускной балл
}
Student::Student(std::string FIO, std::string sex, std::string birthday, double height, int examScore)
{
	this->FIO = FIO;	//запись переданных параметров в поля объекта класса
	this->sex = sex;
	this->bitrhday = birthday;
	this->height = height;
	this->examScore = examScore;
}
//******************* Методы описанные в ТЗ******************************
void Student::Print()
{
	std::cout << this->FIO + "\t";
	std::cout << this->sex + "\t";
	std::cout << this->bitrhday + "\t";
	std::cout << std::to_string(this->height) + "\t";
	std::cout << std::to_string(this->examScore) + "\n";	
}
void Student::Print(std::vector<Student>& ArrayOfStudents)
{
	std::cout << "\nPrint list of all students:\n";
	for (auto& item : ArrayOfStudents)
	{
		std::cout << item.FIO + '\t' + item.sex + '\t' + item.bitrhday + '\t' + std::to_string(item.height) + '\t' + std::to_string(item.examScore) + '\n'; // формат записи в файл
	}
}
void Student::WriteToFile(std::vector<Student>& ArrayOfStudents)
{
	std::string outputFile = "Output.txt"; // Название файла вывода
	std::fstream fout;			// объект класса потока вывода файла
	fout.open(outputFile, std::ofstream::app);		// открывает файл
	if (!fout.is_open())		// проверка на открытие
	{
		std::cout << "Cannot open the output file!!!\n";
		return; // отмена работы на случай если файл повреждён
	}

	for (auto& item : ArrayOfStudents)
	{
		fout << item.FIO + '\t' + item.sex + '\t' + item.bitrhday + '\t' + std::to_string(item.height) + '\t' + std::to_string(item.examScore) + '\n'; // формат записи в файл
	}
	fout.close(); // поток зарывается для освобождения ресурсов компьютера
}
void Student::ReadFromFile(std::vector<Student>& students)
{
	std::string inputFile = "Input.txt"; // название файла ввода
	std::ifstream fin;	// объект класса потока ввода файла
	fin.open(inputFile); // открывает файл
	if (!fin.is_open()) // такая же проверка
	{
		std::cout << "Cannot open the input file!!!";
		return;
	}
	std::string str; // строка в которую будет записываться каждый 
	while (!fin.eof()) //цикл до конца файла
	{
		Student tmp;
		str = "";
		std::getline(fin, str); // получене строки
		std::string sentence = str;
		std::istringstream iss(sentence);
		std::vector<std::string> tokens;
		std::string token;
		while (std::getline(iss, token, '\t')) {	// парсинг даты формата ДД.ММ.ГГГГ на день месяц и год для дальнейшего сравнения, разделителем служит табуляция
			if (!token.empty())
				tokens.push_back(token);
		}
		tmp.FIO = tokens[0];
		tmp.sex = tokens[1];
		tmp.bitrhday = tokens[2];
		tmp.height = std::stod(tokens[3]);
		tmp.examScore = std::stoi(tokens[4]);
		students.push_back(tmp);
		std::cout << str << std::endl;
	}

	fin.close();
}
//***********************Геттеры и сеттеры********************************
std::string Student::GetBirthday()
{
	return this->bitrhday;
}
void Student::SetBirthday(int Day, int Month, int Year)
{
	std::string date = std::to_string(Day) + '.' + std::to_string(Month) + '.' + std::to_string(Year);
	this->bitrhday = date;
}