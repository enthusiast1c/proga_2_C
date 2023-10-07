#pragma once
#include <iostream>
#include <stdio.h>
#include <conio.h>
#define Len 30
#define LenDate 10

// Структуры
struct Company {
    char* name;
    char* found_date;
    char* address;
};

struct Weapon {
    char* name;
    Company company;
    int rel_year;
};

struct Soldier {
    char* name;
    char* draft_date;
    char* address;
};

struct Control {
    char* operation;
    char* date;
    Weapon weapon;
    Soldier soldier;
};

struct Armory {
    Weapon* weapons;
    Soldier* soldiers;
    Control* operations;
    char* military;
};

void clean()  //Очистка потока
{
    while (getchar() != '\n');
}

// Основные функции
/*-----------------------------------------------------------------------------*/
//Инициализация структур
Company InitCompany(char* name, char* found_date, char* address) { // инициализация компании
    Company buf;
    if (strlen(name) == 0 || strlen(address) == 0) {
        exit(-1);
    }
    else if (strlen(found_date) != LenDate) {
        puts("Некорректная дата");
        exit(-1);
    }
    else {
        if (found_date[0] < '0' || found_date[0] > '3' || found_date[1] < '0' || (found_date[1] > '1' && found_date[0] > '2') || found_date[1] > '9' || found_date[2] != '.' || found_date[3] < '0' || found_date[3] > '1' || found_date[4] < '0' || (found_date[4] > '0' && found_date[3] > '2') || found_date[4] > '9' || found_date[5] != '.' || found_date[6] < '0' || found_date[6] > '9' || found_date[7] < '0' || found_date[7] > '9' || found_date[8] < '0' || found_date[8] > '9' || found_date[9] < '0' || found_date[9] > '9') {
            puts("Ошибка в дате");
            exit(-1);
        }
        else {
            buf.name = name;
            buf.found_date = found_date;
            buf.address = address;
        }
    }
    return buf;
}

Soldier InitSoldier(char* name, char* draft_date, char* address) {
    Soldier buf;

    if (strlen(name) == 0 || strlen(draft_date) != LenDate || strlen(address) == 0) {
        exit(-1);
    }
    else {
        buf.name = name;
        buf.draft_date = draft_date;
        buf.address = address;
    }
    return buf;
}

Weapon InitWeapon(char* name, Company company, int rel_year) {
    Weapon buf;

    if (strlen(name) == 0 || rel_year < 1000) {
        exit(-1);
    }
    else {
        buf.name = name;
        buf.company = company;
        buf.rel_year = rel_year;
    }
    return buf;
}

Control InitControl(char* operation, char* date, Weapon weapon, Soldier soldier) {
    Control buf;

    if (strlen(operation) == 0 || strlen(date) != LenDate) {
        exit(-1);
    }
    else {
        buf.weapon = weapon;
        buf.soldier = soldier;
        buf.operation = operation;
        buf.date = date;
    }

    return buf;
}

Armory InitArmory(Weapon weapon, Soldier soldier, Control operation, char* military) {
    if (strlen(military) == 0) {
        exit(-1);
    }
    else {
        Armory buf;
        buf.military = military;
        buf.weapons[0] = weapon;
        buf.soldiers[0] = soldier;
        buf.operations[0] = operation;

        return buf;
    }
}

//Ввод структур
Company InputCompany() { // ввод компании
    char* name = (char*)calloc(Len, sizeof(char));
    char* found_date = (char*)calloc(LenDate, sizeof(char));
    char* address = (char*)calloc(Len, sizeof(char));

    puts("Введите название компании:");
    gets_s(name, Len);
    do {
        do {
            puts("Введите дату основания в формате DD.MM.YYYY:");
            gets_s(found_date, 200);
        } while (found_date[0] < '0' || found_date[0] > '3' || found_date[1] < '0' || (found_date[1] > '1' && found_date[0] > '2') || found_date[1] > '9' || found_date[2] != '.' || found_date[3] < '0' || found_date[3] > '1' || found_date[4] < '0' || (found_date[4] > '0' && found_date[3] > '2') || found_date[4] > '9' || found_date[5] != '.' || found_date[6] < '0' || found_date[6] > '9' || found_date[7] < '0' || found_date[7] > '9' || found_date[8] < '0' || found_date[8] > '9' || found_date[9] < '0' || found_date[9] > '9');
    } while (strlen(found_date) != 10);
    puts("Введите адрес компании:");
    gets_s(address, Len);

    Company buf = InitCompany(name, found_date, address);
    return buf;
}

Soldier InputSoldier() { // ввод солдата 
    char* name = (char*)calloc(Len, sizeof(char));
    char* draft_date = (char*)calloc(LenDate, sizeof(char));
    char* address = (char*)calloc(Len, sizeof(char));

    puts("Введите имя солдата");
    gets_s(name, Len);
    do {
        do {
            puts("Введите дату призыва солдата в формате DD.MM.YYYY:");
            gets_s(draft_date, 200);
        } while (draft_date[0] < '0' || draft_date[0] > '3' || draft_date[1] < '0' || (draft_date[1] > '1' && draft_date[0] > '2') || draft_date[1] > '9' || draft_date[2] != '.' || draft_date[3] < '0' || (draft_date[3] == '1' && draft_date[4] > '2') || draft_date[3] > '1' || draft_date[4] < '0' || (draft_date[4] > '0' && draft_date[3] > '2') || draft_date[4] > '9' || draft_date[5] != '.' || draft_date[6] < '0' || draft_date[6] > '9' || draft_date[7] < '0' || draft_date[7] > '9' || draft_date[8] < '0' || draft_date[8] > '9' || draft_date[9] < '0' || draft_date[9] > '9');
    } while (strlen(draft_date) != 10);
    puts("Введите адрес прописки солдата:");
    gets_s(address, Len);

    Soldier buf = InitSoldier(name, draft_date, address);
    return buf;
}

Weapon InputWeapon(Company company) {
    int rel_year;
    char* name = (char*)calloc(Len, sizeof(char));

    puts("Введите модель оружия:");
    gets_s(name, Len);
    puts("Введите год выпуска:");
    do {
        scanf("%d", &rel_year);
        if (rel_year < 1000) {
            puts("Повторите попытку.");
        }
    } while (rel_year < 1000);
    clean();

    Weapon buf = InitWeapon(name, company, rel_year);
    return buf;
}

Control InputControl(Weapon weapon, Soldier soldier) {
    char* operation = (char*)calloc(Len, sizeof(char));
    char* date = (char*)calloc(LenDate, sizeof(char));

    puts("Введите тип совершённой операции:");
    gets_s(operation, Len);
    puts("Введите дату совершения операции:");
    gets_s(date, LenDate);

    Control buf = InitControl(operation, date, weapon, soldier);
    return buf;
}

Armory InputArmory(Weapon weapon, Soldier soldier, Control operation) {
    char* military = (char*)calloc(Len, sizeof(char));

    puts("Введите адрес склада:");
    gets_s(military, Len);

    Armory buf = InitArmory(weapon, soldier, operation, military);
    return buf;
}

//Вывод структур
void OutputCompany(Company company) {// вывод информации о компании
    puts("Информация о компании:");
    puts(company.name);
    puts(company.found_date);
    puts(company.address);
}