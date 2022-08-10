#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

struct Student	// ��������� �� �� ��������: ���, ���, ���� ��������, ����, ��������� ����    
{				// ������� ����� ������� � ���������� � ������������� ���� �������
	/// <summary>
	/// ����������� �� ���������
	/// </summary>
	Student();
	/// <summary>
	/// ����������� � �����������
	/// </summary>
	/// <param name="FIO"></param>
	/// <param name="sex"></param>
	/// <param name="birthday"></param>
	/// <param name="height"></param>
	/// <param name="examScore"></param>
	Student(std::string FIO, std::string sex, std::string birthday, double height, int examScore);

private:				// ���� ������ ������ ���� private, �� ��������� ������ (������������)
	std::string FIO;	// ����
	std::string sex;
	std::string bitrhday;
	double height;
	int examScore;

//******************* ������ ��������� � ��******************************
public:
	/// <summary>
	/// ����� 1 ��������
	/// </summary>
	void Print();
	/// <summary>
	/// ����� ���� ���������
	/// </summary>
	/// <param name="ArrayOfStudents"></param>
	void Print(std::vector<Student>& ArrayOfStudents);
	/// <summary>
	/// ������ � ����
	/// </summary>
	/// <param name="ArrayOfStudents"></param>
	void WriteToFile(std::vector<Student>& ArrayOfStudents);
	/// <summary>
	/// ������ �� �����
	/// </summary>
	void ReadFromFile(std::vector<Student>& ArrayOfStudents);

	//***********************������� � �������********************************
	// �� �������� ������ � ������ ������ ���� � ������� ���������� ����, �� ����� �� ������������� ��� �������� �������
	// ����������� ��� �������
	std::string GetBirthday();
	void SetBirthday(int Day, int Month, int Year);
};