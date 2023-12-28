#include "Clients.h"


Clients::Clients()
{
	//в конструкторе указываем значения по умолчанию
	date_begin[0] = 0;
	date_begin[1] = 0;
	date_begin[2] = 0;

	date_end[0] = 0;
	date_end[1] = 0;
	date_end[2] = 0;

	fio = "нет данных";
	phone_number = "нет данных";

	debt = 0;
	credit = "нет данных";
}

void Clients::StrToDateOrTime(string arg, int* result)
{
	//result[0] - day or hours
	//result[1] - month or minutes
	//result[2] - year or seconds

	string tmp;	//временная строка для копирования символов из исходной
	int index = 0;	//порядковый номер заполняемого элемента массива
					// 0 - day or hours, 1 - month or minutes 2 - year or seconds

	//проходим по исходной строке от первого до последнего символа
	for (int i = 0; i < arg.length(); i++)
	{
		if (arg[i] != '.' && arg[i] != ':') tmp += arg[i]; //если символ не является разделителем то добавляем его во временную строку
														  //(разделитель для даты - '.', для времени - ':')

		//если следующий символ после текущего это разделитель, или если дошли до конца строки,то
		if (arg[i + 1] == '.' || arg[i + 1] == ':' || i == arg.length() - 1) {
			result[index] = stoi(tmp); //переводим tmp в int и записываем в массив по соответствующему индексу
			tmp = "";	//опустошаем строку
			index++;	//увеличиваем индекс на 1
		}
	}
}

//чтение файла
void Clients::file_reading(string path, int index)
{
	ifstream fin(path); //открываем файл для чтения
	if (!fin.is_open())	//проверка на открытие
	{
		cout << "Error opening file: Clients.txt";
		return;
	}

	//временные строки для чтения даты начала и даты конца договора
	string date_1, date_2;
	string debt1;
	string n1, n2, n3;
	//чтобы считать N-ую строку из файла цикл выполняется N раз 
	for (int i = 0; i <= index; i++)
	{
		//строки читаются через пробел, вместе с запятыми
		fin >> n1;
		fin >> n2;
		fin >> n3;
		fin >> phone_number;
		fin >> date_1;
		fin >> date_2;
		fin >> debt1;
		fin >> credit;
	}

	//удаляем запятые с концов строк
	n3.pop_back();
	fio = n1 + ' ' + n2 + ' ' + n3;
	phone_number.pop_back();
	date_1.pop_back();
	date_2.pop_back();
	debt1.pop_back();
	debt = stoi(debt1);

	//переводим временные переменные даты в правильный формат
	StrToDateOrTime(date_1, date_begin);
	StrToDateOrTime(date_2, date_end);

	fin.close(); //закрываем файл после окончания чтения
	return;
}


