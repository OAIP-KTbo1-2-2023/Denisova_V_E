#pragma once
#include "Clients.h"
//����� ServiceBase �������� ����������� �� ������ ClientBase
class Services :
    public Clients
{
private:
    //����������-����� ������
    string service_name;
    int service_code;
    float rate;
    string interval;

public:
    Services(); //����������� ������

    //������� ��� ������� � ��������������� ����������-������ ������
    string get_service_name() { return service_name; }
    int get_service_code() { return service_code; }
    float get_rate() { return rate; }
    string get_interval() { return interval; }

    //������ ����� � ����� �� �������
    void file_reading(string path, int index);
    

};

