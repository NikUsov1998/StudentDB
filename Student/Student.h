#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

struct Student	// структура из ТЗ содержит: ФИО, Пол, Дату рождения, Рост, Выпускной балл    
{				// разница между классом и структурой в модификаторах прав доступа
	/// <summary>
	/// Конструктор по умолчанию
	/// </summary>
	Student();
	/// <summary>
	/// конструктор с параметрами
	/// </summary>
	/// <param name="FIO"></param>
	/// <param name="sex"></param>
	/// <param name="birthday"></param>
	/// <param name="height"></param>
	/// <param name="examScore"></param>
	Student(std::string FIO, std::string sex, std::string birthday, double height, int examScore);

private:				// Поля класса должны быть private, во избежание ошибок (инкапсуляция)
	std::string FIO;	// Поля
	std::string sex;
	std::string bitrhday;
	double height;
	int examScore;

//******************* Методы описанные в ТЗ******************************
public:
	/// <summary>
	/// Вывод 1 студента
	/// </summary>
	void Print();
	/// <summary>
	/// Вывод всех студентов
	/// </summary>
	/// <param name="ArrayOfStudents"></param>
	void Print(std::vector<Student>& ArrayOfStudents);
	/// <summary>
	/// Запись в файл
	/// </summary>
	/// <param name="ArrayOfStudents"></param>
	void WriteToFile(std::vector<Student>& ArrayOfStudents);
	/// <summary>
	/// Читать из файла
	/// </summary>
	void ReadFromFile(std::vector<Student>& ArrayOfStudents);

	//***********************Геттеры и сеттеры********************************
	// по хорошему геттер и сеттер должен быть у каждого приватного поля, но делал по необходимости для экономии времени
	// использовал для отладки
	std::string GetBirthday();
	void SetBirthday(int Day, int Month, int Year);
};