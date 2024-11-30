#include "FileReader.h"
#include <string>

FileReader::FileReader() : array(nullptr), size(3) {
	array = new string[size];
}//конструктор по умолчанию
FileReader::~FileReader() { delete[] array; } //освобождаем память из под массива элементов

void FileReader::Read(string filename) {
	ifstream file(filename);

	if (!file.is_open()) {
		throw runtime_error("Не удалось открыть файл для чтения."); }
	cout << "Файл найден и успешно открыт" << endl;

	array[size];
	size_t i = 0;
	while (getline(file, s)) {
		array[i] = s;
		i++;
	}
}

void FileReader::Print() {
	cout << "Строки из файла" << endl;
	for (size_t i = size; i > 0; i--) {
		cout << array[i-1] << endl;
	}
}