#include "Student.h"
//*************************������������**********************************
Student::Student()
{
	FIO = "Ivanov Ivan Ivanovich";	// ���
	sex = "male";					// ��� �������
	bitrhday = "01.01.2000";		// ���� �������� � ������� ��.��.���� !!!����������� � ���� ������� ������ �������� �� ������������ ���Ĩ���� ���� �� ����� ��������!!!
	height = 175.4;					// ����
	examScore = 200;				// ��������� ����
}
Student::Student(std::string FIO, std::string sex, std::string birthday, double height, int examScore)
{
	this->FIO = FIO;	//������ ���������� ���������� � ���� ������� ������
	this->sex = sex;
	this->bitrhday = birthday;
	this->height = height;
	this->examScore = examScore;
}
//******************* ������ ��������� � ��******************************
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
		std::cout << item.FIO + '\t' + item.sex + '\t' + item.bitrhday + '\t' + std::to_string(item.height) + '\t' + std::to_string(item.examScore) + '\n'; // ������ ������ � ����
	}
}
void Student::WriteToFile(std::vector<Student>& ArrayOfStudents)
{
	std::string outputFile = "Output.txt"; // �������� ����� ������
	std::fstream fout;			// ������ ������ ������ ������ �����
	fout.open(outputFile, std::ofstream::app);		// ��������� ����
	if (!fout.is_open())		// �������� �� ��������
	{
		std::cout << "Cannot open the output file!!!\n";
		return; // ������ ������ �� ������ ���� ���� ��������
	}

	for (auto& item : ArrayOfStudents)
	{
		fout << item.FIO + '\t' + item.sex + '\t' + item.bitrhday + '\t' + std::to_string(item.height) + '\t' + std::to_string(item.examScore) + '\n'; // ������ ������ � ����
	}
	fout.close(); // ����� ���������� ��� ������������ �������� ����������
}
void Student::ReadFromFile(std::vector<Student>& students)
{
	std::string inputFile = "Input.txt"; // �������� ����� �����
	std::ifstream fin;	// ������ ������ ������ ����� �����
	fin.open(inputFile); // ��������� ����
	if (!fin.is_open()) // ����� �� ��������
	{
		std::cout << "Cannot open the input file!!!";
		return;
	}
	std::string str; // ������ � ������� ����� ������������ ������ 
	while (!fin.eof()) //���� �� ����� �����
	{
		Student tmp;
		str = "";
		std::getline(fin, str); // �������� ������
		std::string sentence = str;
		std::istringstream iss(sentence);
		std::vector<std::string> tokens;
		std::string token;
		while (std::getline(iss, token, '\t')) {	// ������� ���� ������� ��.��.���� �� ���� ����� � ��� ��� ����������� ���������, ������������ ������ ���������
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
//***********************������� � �������********************************
std::string Student::GetBirthday()
{
	return this->bitrhday;
}
void Student::SetBirthday(int Day, int Month, int Year)
{
	std::string date = std::to_string(Day) + '.' + std::to_string(Month) + '.' + std::to_string(Year);
	this->bitrhday = date;
}