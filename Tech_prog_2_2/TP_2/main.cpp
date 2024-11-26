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
                cout << "1 - Добавить рейс\n2 - Удалить рейс\n3 - Редактировать рейс\n4 - Посмотреть все рейсы\n5 - Найти рейс\n6 - Выйти\n";
                cin >> choice_2;


                switch (choice_2) {
                case 1: {
                    //добавление рейса
                    AeroFlot flight;//объект класса
                    cin >> flight;//заполняем элемент с использованием перегрузки
                    manager.AddFlight(flight);
                    break;
                }
                case 2: {
                    break;
                }
                case 3: {
                    //вывод на экран
                    manager.PrintAll();
                    system("pause");
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