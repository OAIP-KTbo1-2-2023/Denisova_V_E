#pragma once
#include "Clients.h"
//класс ServiceBase является наследником от класса ClientBase
class Services :
    public Clients
{
private:
    //переменные-члены класса
    string service_name;
    int service_code;
    float rate;
    string interval;

public:
    Services(); //конструктор класса

    //функции для доступа к соответствующим переменным-членам класса
    string get_service_name() { return service_name; }
    int get_service_code() { return service_code; }
    float get_rate() { return rate; }
    string get_interval() { return interval; }

    //чтение файла и вывод на консоль
    void file_reading(string path, int index);
    

};

