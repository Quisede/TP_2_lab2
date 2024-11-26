#include "Manager.h"
#include <iostream>

Manager::Manager() : flights(new AeroFlot[10]), size(0), capacity(10) {}//����������� �� ���������
Manager::~Manager() { delete[] flights; } //����������� ������ �� ��� ������� ���������

void Manager::AddFlight(AeroFlot& record) {
	if (size == capacity) {
		//���� ������� ���������� ��������� = ���� ����� ��������� � �������, �� ���������� �����������
		Resize();
	}
	flights[size++] = record;//��������� ����� �������
}

void Manager::RemoveFlight(size_t index) {

}

void Manager::Resize() {
	//����������� ����������� � 2 ����
	size_t tmp = capacity * 2;//��������� ���������� � ����� ��������
	AeroFlot* tmpArray = new AeroFlot[tmp];//������� ��������� ������ � ����� ��������

	//������������ ��������
	for (size_t i = 0; i < size; i++) {
		tmpArray[i] = flights[i];
	}

	//������ ������ ����� �������
	delete[] flights;

	//���������
	flights = tmpArray;
	capacity = tmp;
}

void Manager::PrintAll() const {
	if (size == 0) {
		cout << "������ �� �������";
		return;
	}

	for (size_t i = 0; i < size; i++) {
		cout << flights[i] << endl;
	}
}