#include "AeroFlot.h"
#include "Manager.h"
#include <iostream>
#include <Windows.h>
using namespace std;

int main() {
    //корректная работа с русским языком
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Manager manager;//создаем объект менеджера
    int choice_1 = 0;

    while (choice_1 != 3) {
        cout << "-------------МЕНЮ----------------\n\n" << endl;
        cout << "1 - Задание 1 - АЭРОФЛОТ\n2 - Задание 2 - \n3 - Завершить\n";
        cin >> choice_1;

        switch (choice_1) {
        case 1: {
            //выбрали первое задание
            int choice_2 = 0;
            do {
                system("cls");
                cout << "-------------МЕНЮ----------------\n\n" << endl;
                cout << "1 - Добавить рейс\n2 - Удалить рейс\n3 - Редактировать рейс\n4 - Посмотреть все рейсы\n5 - Найти рейс\n6 - Рейсы самолетов\n7 - Выйти\n";
                cin >> choice_2;


                switch (choice_2) {
                case 1: {
                    //добавление рейса
                    AeroFlot flight;//объект класса
                    cin >> flight;//заполняем элемент с использованием перегрузки
                    manager.AddFlight(flight);
                    manager.SortArray();
                    break;
                }
                case 2: {
                    //сначала находим нужный рейс
                    string search;
                    size_t index;
                    cin.ignore(); // Убираем лишний символ новой строки из предыдущего ввода
                    cout << "Введите пункт назначения\n";
                    getline(cin, search);
                    //cin >> search;
                    index = manager.SearchFlight(search);
                    manager.RemoveFlight(index);
                    manager.SortArray();
                    break;
                }
                case 3: {
                    //сначала находим нужную запись
                    string search;
                    size_t index;
                    cout << "Введите пункт назначения\n";
                    cin >> search;
                    index = manager.SearchFlight(search);
                    manager.EditFlight(index);
                    manager.SortArray();
                    break;
                }
                case 4: {
                    //вывод на экран
                    manager.PrintAll();
                    system("pause");
                    break;
                }
                case 5: {
                    //поиск записи
                    string search;
                    cout << "Введите пункт назначения\n";
                    cin >> search;
                    manager.SearchSimple(search);
                    break;
                }
                case 6: {
                    //поиск по самолетам
                    string search2;
                    cin.ignore();
                    cout << "Введите тип самолета\n";
                    getline(cin, search2);
                    //cin >> search2;
                    cout << "РЕЙСЫ САМОЛЕТОВ " << search2 << endl;
                    manager.SearchType(search2);
                    break;
                }
                }
            } while (choice_2 != 6);
            break;
        }
        }
    }

    return 1;
}