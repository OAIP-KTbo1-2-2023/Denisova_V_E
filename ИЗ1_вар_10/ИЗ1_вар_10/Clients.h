#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//�������� ����� Clients ��� ������ �� ������� ��������
class Clients
{
private:
    //����������-����� ������
    
    string fio;
    string phone_number;
    int date_begin[3];
    int date_end[3];
    int debt;
    string credit;

public:
    Clients();   //����������� ������

    //������� ��� ������� � ��������������� ����������-������ ������
   
    string get_fio() { return fio; };
    string get_phone_number() { return phone_number; };
    int get_debt() { return debt; }

    /*file_reading - ������ ������ �� �����
    ���������:
    path - ��� ����� ��� ������
    index - ���������� ����� ������, ������� ����� ���������
    */
    void file_reading(string path, int index);

    /*
    StrToDateOrTime - ������� ������ � ������ ���� ��� �������
    ���������:
    string arg - �������� ������
    int* result - ��� �������������� ������� ��� ������
    */
    void StrToDateOrTime(string arg, int* result);

};

