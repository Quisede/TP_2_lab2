#include "AeroFlot.h"
#include <iostream>
using namespace std;

istream& operator>>(istream& is, AeroFlot& flight) {
    cout << "Введите пункт назначения:\n";
    is.ignore(); // Убираем лишний символ новой строки из предыдущего ввода
    getline(is, flight.dest);

    cout << "Введите номер рейса:\n";
    is >> flight.flNumb;

    cout << "Введите тип самолета:\n";
    is.ignore(); // Убираем символ новой строки после ввода номера рейса
    getline(is, flight.type);

    // Проверяем корректность ввода
    if (flight.flNumb <= 0 || flight.dest.empty() || flight.type.empty()) {
        throw "Неправильный ввод!";
    }

    return is;
}

ostream& operator<<(ostream& os, AeroFlot& flight) {
	os << "Пункт назначения:\n" << flight.dest << endl
		<< "Номер рейса:\n" << flight.flNumb << endl
		<< "Тип самолета:\n" << flight.type << endl << "\n";

	return os;
}