#include "AeroFlot.h"
#include <iostream>
using namespace std;

istream& operator>>(istream& is, AeroFlot& flight) {
	cout << "Введите пункт назначения:\n";
	is >> flight.dest;
	cout << "Введите номер рейса:\n";
	is >> flight.flNumb;
	cout << "Введите тип самолета:\n";
	is >> flight.type;

	if (flight.flNumb <= 0 || flight.dest.empty() || flight.type.empty()) {
		throw "Неравильный ввод!";
	}
}

ostream& operator<<(ostream& os, AeroFlot& flight) {
	os << "Пункт назначения:\n" << flight.dest
		<< "Номер рейса:\n" << flight.flNumb
		<< "Тип самолета:\n" << flight.type;

	return os;
}