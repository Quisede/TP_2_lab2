#include "Manager.h"
#include <iostream>

Manager::Manager() : flights(new AeroFlot[10]), size(0), capacity(10) {}//конструктор по умолчанию
Manager::~Manager() { delete[] flights; } //освобождаем память из под массива элементов

void Manager::AddFlight(AeroFlot& record) {
	if (size == capacity) {
		//если текущее количество элементов = макс числу элементов в массиве, то увеличваем вместимость
		Resize();
	}
	flights[size++] = record;//добавляем новый элемент
}

void Manager::RemoveFlight(size_t index) {

}

void Manager::Resize() {
	//увеличиваем вместимость в 2 раза
	size_t tmp = capacity * 2;//временная переменная с новым размером
	AeroFlot* tmpArray = new AeroFlot[tmp];//создаем временный массив с новым размером

	//перекопируем элементы
	for (size_t i = 0; i < size; i++) {
		tmpArray[i] = flights[i];
	}

	//старый массив можно удалить
	delete[] flights;

	//обновляем
	flights = tmpArray;
	capacity = tmp;
}

void Manager::PrintAll() const {
	if (size == 0) {
		cout << "Рейсов не найдено";
		return;
	}

	for (size_t i = 0; i < size; i++) {
		cout << flights[i] << endl;
	}
}