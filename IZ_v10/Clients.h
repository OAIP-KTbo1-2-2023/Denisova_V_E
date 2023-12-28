#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//основной класс Clients для работы со списком клиентов
class Clients
{
private:
    //переменные-члены класса
    
    string fio;
    string phone_number;
    int date_begin[3];
    int date_end[3];
    int debt;
    string credit;

public:
    Clients();   //конструктор класса

    //функции для доступа к соответствующим переменным-членам класса
   
    string get_fio() { return fio; };
    string get_phone_number() { return phone_number; };
    int get_debt() { return debt; }

    /*file_reading - чтение строки из файла
    параметры:
    path - имя файла для чтения
    index - порядковый номер строки, которую нужно прочитать
    */
    void file_reading(string path, int index);

    /*
    StrToDateOrTime - перевод строки в формат даты или времени
    параметры:
    string arg - исходная строка
    int* result - имя целочисленного массива для записи
    */
    void StrToDateOrTime(string arg, int* result);

};

