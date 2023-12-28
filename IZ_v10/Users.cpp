#include "Users.h"


Users::Users()
{
	//значения по умолчанию
	phone_number = "нет данных";
	service_code = -1;
	using_date[0] = 0;
	using_date[1] = 0;
	using_date[2] = 0;
	using_time[0] = 0;
	using_time[1] = 0;
	using_time[2] = 0;
	interval = "нет данных";
}

void Users::file_reading(string path, int index)
{
	//чтение из файла аналогично функции file_reading в файле ClintBase.cpp

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


bool Users::check_date() //проверка даты
{
	//определение даты запуска программы
	struct tm newtime;
	time_t now = time(0);
	localtime_s(&newtime, &now);
	int year = newtime.tm_year + 1900; //год

	//проверка
	if (using_date[2] == year) {  //если услуга использована в этом году
																
		if (1 <= using_date[1] <=3) {//если использована в первом квартале			
			return true;	//возвращаем true
		}
	}
	else return false;	// иначе - false
}
