#pragma once
#include <iostream>
#include <string>
using namespace std;

class AeroFlot{
private:
	string dest;//����� ����������
	int flNumb;//����� �����
	string type;//��� ��������

public:
	AeroFlot() : dest(""), flNumb(0), type("") {}
	AeroFlot(string& D, int N, string& T) : dest(D), flNumb(N), type(T) {}
	~AeroFlot() {}

	//�������, �������
	void setDest(string& D) { dest = D; };
	void setNumb(int N) { flNumb = N; };
	void setType(string& T) { type = T; };

	string getDest() const { return dest; };
	int getNumb() { return flNumb; };
	string getType() { return type; };

	//���������� ����������
	friend istream& operator>>(istream& is, AeroFlot& flight);
	friend ostream& operator<<(ostream& os, AeroFlot& flight);
};

