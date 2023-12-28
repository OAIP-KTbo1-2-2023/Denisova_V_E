#include "Users.h"


Users::Users()
{
	//�������� �� ���������
	phone_number = "��� ������";
	service_code = -1;
	using_date[0] = 0;
	using_date[1] = 0;
	using_date[2] = 0;
	using_time[0] = 0;
	using_time[1] = 0;
	using_time[2] = 0;
	interval = "��� ������";
}

void Users::file_reading(string path, int index)
{
	//������ �� ����� ���������� ������� file_reading � ����� ClintBase.cpp

	ifstream fin(path);
	if (!fin.is_open())
	{
		cout << "Error opening file: Users.txt";
		return;
	}

	string date, time, code;
	for (int i = 0; i <= index; i++)
	{
		fin >> phone_number;
		fin >> code;
		fin >> date;
		fin >> time;
		fin >> interval;
	}

	phone_number.pop_back();
	code.pop_back();
	service_code = stoi(code);


	time.pop_back();

	StrToDateOrTime(date, using_date);
	StrToDateOrTime(time, using_time);

	fin.close();
	return;
}


bool Users::check_date() //�������� ����
{
	//����������� ���� ������� ���������
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	int year = newtime.tm_year + 1900; //���

	//��������
	if (using_date[2] == year) {  //���� ������ ������������ � ���� ����
																
		if (1 <= using_date[1] <=3) {//���� ������������ � ������ ��������			
			return true;	//���������� true
		}
	}
	else return false;	// ����� - false
}
