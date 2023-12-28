#pragma once
#include "Clients.h"
//����� UsingService �������� ����������� �� ������ ClientBase
class Users :
    public Clients
{
private:
    //����������-����� ������
    string phone_number;
    int service_code;
    int using_date[3];
    int using_time[3];
    string interval;

public:
    Users(); //����������� ������ 

    //������� ��� ������� � ��������������� ����������-������ ������
    string get_phone_number() { return phone_number; }
    int get_service_code() { return service_code; }
    int* get_using_date() { return using_date; }
    int* get_using_time() { return using_time; }
    string get_interval() { return interval; }

    //������� ���������, ����������� �� ������ ������ � ���������� ������
    //���� �� ����������� ���������� - true
    //����� - false
    bool check_date();

    //������ ����� � ����� �� �������
    void file_reading(string path, int index);
};


