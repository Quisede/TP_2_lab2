#pragma once
#include "AeroFlot.h"
#include <iostream>
using namespace std;

class Manager{
private:
	AeroFlot* flights;//��������� �� ������ ��������
	size_t size;//������ �������
	size_t capacity;//����� ����������� �������
public:
	Manager();
	~Manager();

	void AddFlight(AeroFlot& record);//���������� ������
	void RemoveFlight(size_t index);//�������� ������
	void Resize();//��������� ����� ����������� ������� (��� �����������)
	void PrintAll() const;//������ ���� ������
	size_t getSize() const;//������ �� ������� ������ �������
};

