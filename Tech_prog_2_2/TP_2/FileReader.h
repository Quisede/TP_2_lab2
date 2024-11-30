#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class FileReader
{
private:
	string s;//строка для считывания
	string* array;//массив строк
	size_t size;//размерность массива

public:
	FileReader();
	~FileReader();

	void Read(string filename);
	void Print();
};

