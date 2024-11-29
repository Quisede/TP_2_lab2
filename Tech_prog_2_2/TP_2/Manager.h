#pragma once
#include "AeroFlot.h"
#include <iostream>
using namespace std;

class Manager{
private:
	AeroFlot* flights;//указатель на массив объектов
	size_t size;//размер массива
	size_t capacity;//общая вместимость массива
public:
	Manager();
	~Manager();

	void AddFlight(AeroFlot& record);//добавление полета
	void RemoveFlight(size_t index);//удаление полета
	size_t SearchFlight(string& dest);//поиск полета
	void SearchSimple(string& dest);
	void EditFlight(size_t index);//редактирование записей
	void SortArray();//функция сортировки массива, которая расставит все данные в алфавитном порядке
	void SearchType(string& type);//поиск данных по типу самолета
	void Resize();//изменение общей вместимости массива (для оптимизации)
	void PrintAll() const;//печать всех рейсов
	size_t getSize() const;//геттер на текущий размер массива
};

