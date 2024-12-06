#include "Manager.h"
#include <iostream>

Manager::Manager() : flights(new AeroFlot[10]), size(0), capacity(10) {}//конструктор по умолчанию
Manager::~Manager() { delete[] flights; } //освобождаем память из под массива элементов

void Manager::AddFlight(AeroFlot& record) {
	if (!IsFlightNumberUnique(record.getNumb())) {
		cout << "Рейс с таким номером уже существует!\nРейс не добавлен, попробуйте снова!\n" << endl;
		system("pause");
		system("cls");
		return;
	}

	if (size == capacity) {
		//если текущее количество элементов = макс числу элементов в массиве, то увеличваем вместимость
		Resize();
	}
	flights[size++] = record;//добавляем новый элемент
}

void Manager::RemoveFlight(size_t index) {
	if (index < 0 || index >= size) {
		cout << "Некорректный индекс элемент" << endl;
		return;
	}

	//смещаем элементы
	for (size_t i = index; i < size - 1; i++) {
		flights[i] = flights[i + 1];
	}

	size--;//уменьшаем кол-во элементов массива
}

size_t Manager::SearchFlight(string& dest) {
	size_t tmp = -1;
	for (size_t i = 0; i < size; i++) {
		if (flights[i].getDest() == dest) {
			//значит нашли совпадение
			tmp = i;
			cout << "       НОМЕР ЗАПИСИ: " << tmp << endl;
			cout << flights[i] << endl;
		}
	}

	//если ничего не нашли
	if (tmp == -1) {
		cout << "Ничего не найдено" << endl;
		return tmp;
	}

	cout << "Введите номер искомой записи:" << endl;
	cin >> tmp;

	system("pause");
	system("cls");
	return tmp;
}

void Manager::SearchSimple(string& dest) {
	size_t tmp = -1;
	for (size_t i = 0; i < size; i++) {
		if (flights[i].getDest() == dest) {
			//значит нашли совпадение
			tmp = i;
			cout << "       НОМЕР ЗАПИСИ: " << tmp << endl;
			cout << flights[i] << endl;
		}
	}

	//если ничего не нашли
	if (tmp == -1) {
		cout << "Ничего не найдено" << endl;
	}

	system("pause");
}

void Manager::EditFlight(size_t index) {
	if (index < 0 || index >= size) {
		cout << "Некорректный индекс элемент" << endl;
		return;
	}

	int answer = 0;
	cout << "Что вы хотите изменить?: " << endl;
	cout << "1 - Пункт назначения\n2 - Номер рейса\n3 - Тип самолета\n";

	cin >> answer;

	system("cls");

	string tmp;
	int tmp2;

	while(answer != 4) {
		if (answer == 1) {
			//значит выбрали изменение пункта назначения
			cout << "Введи новый пункт назначения\n";
			cin.ignore(); // Убираем лишний символ новой строки из предыдущего ввода
			getline(cin, tmp);
			//cin >> tmp;
			flights[index].setDest(tmp);
			cout << "Редактирование выполнено успешно" << endl;
			system("pause");
			break;
		}
		else if (answer == 2) {
			//значит выбрали номер рейса
			cout << "Введи новый номер рейса\n";
			cin >> tmp2;
			flights[index].setNumb(tmp2);
			cout << "Редактирование выполнено успешно" << endl;
			system("pause");
			break;
		}
		else if (answer == 3) {
			//значит выбрали тип самолета
			cout << "Введи новый тип самолета\n";
			cin.ignore(); // Убираем лишний символ новой строки из предыдущего ввода
			getline(cin, tmp);
			//cin >> tmp;
			flights[index].setType(tmp);
			cout << "Редактирование выполнено успешно" << endl;
			system("pause");
			break;
		}
		else {
			cout << "Некорректный ввод" << endl;
			break;
		}
	}
}

void Manager::SortArray() {
	//сортировка производится по названиям пунктов назначений
	for (size_t i = 1; i < size; i++) {
		AeroFlot key = flights[i];
		int j = i - 1;

		while (j >= 0 && flights[j].getDest() > key.getDest()) {
			flights[j + 1] = flights[j];
			j--;
		}
		flights[j + 1] = key;
	}
}

void Manager::SearchType(string& type) {
	size_t tmp = -1;
	for (size_t i = 0; i < size; i++) {
		if (flights[i].getType() == type) {
			//значит нашли совпадение
			tmp = i;
			cout << "       НОМЕР ЗАПИСИ: " << tmp << endl;
			cout << flights[i] << endl;
		}
	}

	//если ничего не нашли
	if (tmp == -1) {
		cout << "Ничего не найдено" << endl;
	}

	system("pause");
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

bool Manager::IsFlightNumberUnique(int flightNumber) const {
	for (size_t i = 0; i < size; i++) {
		if (flights[i].getNumb() == flightNumber) {
			return false; // Номер рейса уже существует
		}
	}
	return true; // Номер уникален
}