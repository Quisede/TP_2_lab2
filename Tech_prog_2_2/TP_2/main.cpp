#include "AeroFlot.h"
#include "Manager.h"
#include <iostream>
#include <Windows.h>
using namespace std;

int main() {
    //���������� ������ � ������� ������
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Manager manager;//������� ������ ���������
    int choice_1 = 0;

    while (choice_1 != 3) {
        cout << "-------------����----------------\n\n" << endl;
        cout << "1 - ������� 1 - ��������\n2 - ������� 2 - \n3 - ���������\n";
        cin >> choice_1;

        switch (choice_1) {
        case 1: {
            //������� ������ �������
            int choice_2 = 0;
            do {
                system("cls");
                cout << "-------------����----------------\n\n" << endl;
                cout << "1 - �������� ����\n2 - ������� ����\n3 - ������������� ����\n4 - ���������� ��� �����\n5 - ����� ����\n6 - �����\n";
                cin >> choice_2;


                switch (choice_2) {
                case 1: {
                    //���������� �����
                    AeroFlot flight;//������ ������
                    cin >> flight;//��������� ������� � �������������� ����������
                    manager.AddFlight(flight);
                    break;
                }
                case 2: {
                    break;
                }
                case 3: {
                    //����� �� �����
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