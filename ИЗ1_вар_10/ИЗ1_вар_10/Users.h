#pragma once
#include "Clients.h"
//класс UsingService является наследником от класса ClientBase
class Users :
    public Clients
{
private:
    //переменные-члены класса
    string phone_number;
    int service_code;
    int using_date[3];
    int using_time[3];
    string interval;

public:
    Users(); //конструктор класса 

    //функции для доступа к соответствующим переменным-членам класса
    string get_phone_number() { return phone_number; }
    int get_service_code() { return service_code; }
    int* get_using_date() { return using_date; }
    int* get_using_time() { return using_time; }
    string get_interval() { return interval; }

    //функция проверяет, использовал ли клиент услугу в предыдущем месяце
    //если НЕ использовал возвращает - true
    //иначе - false
    bool check_date();

    //чтение файла и вывод на консоль
    void file_reading(string path, int index);
};


