#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include "library.h"

int main()
{
    setlocale(LC_ALL, "rus");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Company company = InputCompany();
    Weapon weapon = InputWeapon(company);
    Soldier soldier = InputSoldier();
    Control operation = InputControl(weapon, soldier);
    Armory armory = InputArmory(weapon, soldier, operation);
    int exit = 0;
    do {
        system("cls");
        puts("Создан оружейный склад.");
        int choice;
        do {
            printf("Выберите действие:\n |1|Вывести оружейный склад\n |2|Добавить солдата\n |3|Добавить оружие\n |4|Добавить выдачу/сдачу оружия\n |5|Завершение программы\nВаш выбор: ");
            scanf("%d", &choice);
        } while (choice < 1 || choice >5);
        switch (choice) {
        case 1: 
            OutputArmory(armory);
            _getch();
            break;
        case 2: 
            armory = SoldierToArmory(armory, InputSoldier());
            OutputArmory(armory); break;
        case 3:
            armory = WeaponToArmory(armory, InputWeapon(InputCompany()));
            OutputArmory(armory); break;
        case 4:
            armory = OperationToArmory(armory, InputControl(InputWeapon(InputCompany()),InputSoldier()));
            OutputArmory(armory); break;
        case 5: exit = 1; break;
        }
    } while (exit== 0);
    return 0;

}