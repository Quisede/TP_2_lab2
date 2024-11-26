#pragma once
#include <iostream>
#include <string>
using namespace std;

class AeroFlot{
private:
	string dest;//пункт назначения
	int flNumb;//номер рейса
	string type;//тип самолета

public:
	AeroFlot() : dest(""), flNumb(0), type("") {}
	AeroFlot(string& D, int N, string& T) : dest(D), flNumb(N), type(T) {}
	~AeroFlot() {}

	//сеттеры, геттеры
	void setDest(string& D) { dest = D; };
	void setNumb(int N) { flNumb = N; };
	void setType(string& T) { type = T; };

	string getDest() const { return dest; };
	int getNumb() { return flNumb; };
	string getType() { return type; };

	//перегрузка операторов
	friend istream& operator>>(istream& is, AeroFlot& flight);
	friend ostream& operator<<(ostream& os, AeroFlot& flight);
};

