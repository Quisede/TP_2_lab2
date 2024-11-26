#include "AeroFlot.h"
#include <iostream>
using namespace std;

istream& operator>>(istream& is, AeroFlot& flight) {
	cout << "������� ����� ����������:\n";
	is >> flight.dest;
	cout << "������� ����� �����:\n";
	is >> flight.flNumb;
	cout << "������� ��� ��������:\n";
	is >> flight.type;

	if (flight.flNumb <= 0 || flight.dest.empty() || flight.type.empty()) {
		throw "����������� ����!";
	}
}

ostream& operator<<(ostream& os, AeroFlot& flight) {
	os << "����� ����������:\n" << flight.dest
		<< "����� �����:\n" << flight.flNumb
		<< "��� ��������:\n" << flight.type;

	return os;
}