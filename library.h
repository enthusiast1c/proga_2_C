#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

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
    Soldier human;
};

struct Armory {
    Weapon* weapons;
    Soldier* soldiers;
    Control* operations;
    char* military;
};

