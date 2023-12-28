#include "Clients.h"


Clients::Clients()
{
	//� ������������ ��������� �������� �� ���������
	date_begin[0] = 0;
	date_begin[1] = 0;
	date_begin[2] = 0;

	date_end[0] = 0;
	date_end[1] = 0;
	date_end[2] = 0;

	fio = "��� ������";
	phone_number = "��� ������";

	debt = 0;
	credit = "��� ������";
}

void Clients::StrToDateOrTime(string arg, int* result)
{
	//result[0] - day or hours
	//result[1] - month or minutes
	//result[2] - year or seconds

	string tmp;	//��������� ������ ��� ����������� �������� �� ��������
	int index = 0;	//���������� ����� ������������ �������� �������
					// 0 - day or hours, 1 - month or minutes 2 - year or seconds

	//�������� �� �������� ������ �� ������� �� ���������� �������
	for (int i = 0; i < arg.length(); i++)
	{
		if (arg[i] != '.' && arg[i] != ':') tmp += arg[i]; //���� ������ �� �������� ������������ �� ��������� ��� �� ��������� ������
														  //(����������� ��� ���� - '.', ��� ������� - ':')

		//���� ��������� ������ ����� �������� ��� �����������, ��� ���� ����� �� ����� ������,��
		if (arg[i + 1] == '.' || arg[i + 1] == ':' || i == arg.length() - 1) {
			result[index] = stoi(tmp); //��������� tmp � int � ���������� � ������ �� ���������������� �������
			tmp = "";	//���������� ������
			index++;	//����������� ������ �� 1
		}
	}
}

//������ �����
void Clients::file_reading(string path, int index)
{
	ifstream fin(path); //��������� ���� ��� ������
	if (!fin.is_open())	//�������� �� ��������
	{
		cout << "Error opening file: Clients.txt";
		return;
	}

	//��������� ������ ��� ������ ���� ������ � ���� ����� ��������
	string date_1, date_2;
	string debt1;
	string n1, n2, n3;
	//����� ������� N-�� ������ �� ����� ���� ����������� N ��� 
	for (int i = 0; i <= index; i++)
	{
		//������ �������� ����� ������, ������ � ��������
		fin >> n1;
		fin >> n2;
		fin >> n3;
		fin >> phone_number;
		fin >> date_1;
		fin >> date_2;
		fin >> debt1;
		fin >> credit;
	}

	//������� ������� � ������ �����
	n3.pop_back();
	fio = n1 + ' ' + n2 + ' ' + n3;
	phone_number.pop_back();
	date_1.pop_back();
	date_2.pop_back();
	debt1.pop_back();
	debt = stoi(debt1);

	//��������� ��������� ���������� ���� � ���������� ������
	StrToDateOrTime(date_1, date_begin);
	StrToDateOrTime(date_2, date_end);

	fin.close(); //��������� ���� ����� ��������� ������
	return;
}


