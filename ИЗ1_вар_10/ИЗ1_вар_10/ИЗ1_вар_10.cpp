/*
ИЗ1
Задание состоит в разработке программы,
которая считывает  настроечные параметры и формирует отчет по
имеющимся данным в файлах. Отчет записывается в текстовый файл.


Вариант 10:
Задание:
Найти список не использовались услуг в 1м квартале
*/

//подключаем библиотеки
#include <iostream>
#include <fstream>      //файловый ввод/вывод
#include <string>
#include <list>         //для работы со списками


//подключаем заголовочные файлы классов
#include "Clients.h"
#include "Service.h"
#include "Users.h"

using namespace std;

int main()
{

    //считываем фио из файла с параметрами
    ifstream fin("param.txt");  //открываем файл для чтения
    if (!fin.is_open()) {           //проверяем файл на открытие
        cout << "Error opening file: param.txt" << endl;    //если не открылася выводим ошибку
        return 0;                                               //и выходим из программы
    }

    string param_clients[5]; //строковый массив с именами клиентов из файла с параметрами

    for (int i = 0; i < 5; i++)
    {
        getline(fin, param_clients[i]); //читаем массив параметров из файла построчно
    }
    fin.close();        //закрываем файл

    //устанавливаем количество элементов в списках
    //в зависимости от количества строк в каждом файле
    int clients_count = 10;
    int services_count = 10;
    int using_count = 14;

    //создаем списки объектов классов
    list<Clients> base1;   //список клиентов из файла Clients.txt
    list<Services> base2;
    list<Users> base3;   //список использованных услуг из файла Users.txt

    //временные объекты классов для чтения из файла
    Clients tmp1;
    Services tmp2;
    Users tmp3;


    //читаем из файла список клиентов
    for (int i = 0; i < clients_count; i++)
    {
        tmp1.file_reading("clients.txt", i); //читаем i-ую строку из файла во временную переменную
        base1.push_back(tmp1);              //добавляем заполненную переменную в конец списка
    }

    //читаем из файла список клиентов
    for (int i = 0; i < services_count; i++)
    {
        tmp2.file_reading("services.txt", i); //читаем i-ую строку из файла во временную переменную
        base2.push_back(tmp2);              //добавляем заполненную переменную в конец списка
    }

    //читаем из файла список использованных услуг
    for (int i = 0; i < using_count; i++)
    {
        tmp3.file_reading("servicesclient.txt", i);
        base3.push_back(tmp3);
    }
    
    string param_numbers[5]; //создаем массив в котором будут номера соответствующих клиентов из файла с параметрами
    for (auto i = base1.begin(); i != base1.end(); i++)//записываем эти номера в массив
    {
        tmp1 = *i;
        for (int i = 0; i < 5; i++)
        {
            if (tmp1.get_fio() == param_clients[i]) //если имя совпадает
            {
                param_numbers[i] = tmp1.get_phone_number(); //запоминаем номер
                break;
            }
        }
        
    }

    bool check_date; //переменная, в которой будет результат проверки даты

    list<Users> pred_results; //промежуточный список из НЕПОДХОДЯЩИХ записей из списка использованных услуг
    list<string> results;     //список для записи окончательных результатов

    //сперва проходим по списку и копируем в промежуточный список записи
    //в которых номер клиента совпадает с одним из параметров и дата использования - 1 квартал текущего года:
    
    for (auto i = base3.begin(); i != base3.end(); i++){ //проходим по списку использованных услуг
        tmp3 = *i; //копируем текущий элемент во временную переменную

        check_date = tmp3.check_date(); //проверяем дату
        for (int k = 0; k < 5; k++) //перебираем номера клиентов из параметров
        {
            //если номер совпадает и дата  использования - 1 квартал текущего года:
            if (tmp3.get_phone_number() == param_numbers[k] && check_date == true)
            {
                pred_results.push_back(tmp3); //копируем запись в промежуточный список
                break;  //переходим сразу к следующей записи, не перебирая остальные номера
            }

        }
    }
   
    //проходим по списку услуг из файла service.txt
   for (auto j = base2.begin(); j != base2.end(); j++)
   {
       tmp2 = *j;           //копируем текущий элемент во временную переменную
       bool flag = true;    //флаг определяет, подходит ли нам запись или нет

       //проверяем, если код услуги совпадает с кодом услуги из промежуточного списка
       for (auto i = pred_results.begin(); i != pred_results.end(); i++)
       {
           tmp3 = *i;

           if (tmp2.get_service_code() == tmp3.get_service_code()) //если совпадает
           {
               flag = false;    //то запись нам не подходит
           }
       }
       if (flag == true) //если запись нам подходит, в список результатов добавляем наименование этой услуги
       {
           results.push_back(tmp2.get_service_name());
       }

   }

   //вывод результатов
   ofstream fout("report.txt");

   for (auto i = results.begin(); i != results.end(); i++)
   {
       cout << *i << endl; //в консоль
       fout << *i << endl; //в файл
   }
   fout.close();

   return 0;     //конец программы
}

