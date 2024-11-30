#include "AeroFlot.h"
#include "FileReader.h"
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
    FileReader filereader;

    int choice_1 = 0;

    while (choice_1 != 3) {
        cout << "-------------МЕНЮ----------------\n\n" << endl;
        cout << "1 - Задание АЭРОФЛОТ\n2 - Задание ФАЙЛОВЫЕ И СТРОКОВЫЕ ПОТОКИ \n3 - Завершить\n";
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
                    system("cls");
                    AeroFlot flight;//объект класса
                    cin >> flight;//заполняем элемент с использованием перегрузки
                    manager.AddFlight(flight);
                    manager.SortArray();
                    break;
                }
                case 2: {
                    //сначала находим нужный рейс
                    system("cls");
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
                    system("cls");
                    string search;
                    size_t index;
                    cout << "Введите пункт назначения\n";
                    cin >> search;
                    system("cls");
                    index = manager.SearchFlight(search);
                    manager.EditFlight(index);
                    manager.SortArray();
                    break;
                }
                case 4: {
                    system("cls");
                    //вывод на экран
                    manager.PrintAll();
                    system("pause");
                    break;
                }
                case 5: {
                    //поиск записи
                    system("cls");
                    string search;
                    cout << "Введите пункт назначения\n";
                    cin >> search;
                    manager.SearchSimple(search);
                    break;
                }
                case 6: {
                    system("cls");
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
            } while (choice_2 != 7);
            break;
        }
        case 2: {
            //выбрали второе задание
            int choice_3 = 0;

            do {
                system("cls");
                cout << "-------------МЕНЮ----------------\n\n" << endl;
                cout << "1 - Прочитать строки из файла\n2 - Выйти\n";
                cin >> choice_3;


                switch (choice_3) {
                case 1: {
                    try {
                        //добавление рейса
                        system("cls");
                        string filename;
                        cout << "Введите название файла" << endl;
                        cin >> filename;
                        system("cls");
                        filereader.Read(filename);
                        filereader.Print();
                        system("pause");
                        system("cls");
                        break;
                    }
                    catch (const runtime_error& e) {
                        cerr << "Ошибка: " << e.what() << endl;
                        system("pause");
                        system("cls");
                        break;
                    }
                }
                }
            } while (choice_3 != 2);
            system("cls");
            break;
        }
        }
    }

    return 1;
}