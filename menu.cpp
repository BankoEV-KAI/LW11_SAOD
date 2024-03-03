#include "menu.h"
#include <iostream>

void enteringNumber(int rangeStart, int rangeStop, int& value) {
    while (true) {
        std::cout << "Введите число от " << rangeStart << " до " << rangeStop << " >> ";
        std::cin >> value;

        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Некорректный ввод. ";
        }
        else if (value >= rangeStart && value <= rangeStop) {
            return;
        }
        else {
            std::cout << "Некорректное число. ";
        }
    }
}

void printMenu(int operation) {
    switch (operation)
    {
    case 1:
        std::cout << "1. Создание дерева (произвольное заполнение)" << std::endl
            << "2. Поиск вершины с заданной иннф частью" << std::endl
            << "3. Добавление потомка" << std::endl
            << "4. Вывывод дерева (симметрично)" << std::endl
            << "5. Вывывод дерева (всех видов)" << std::endl
            << "6. Уничтожение всего дерева" << std::endl
            << "0. Завершение программы" << std::endl
            << std::endl;
        break;
    case 2:
        std::cout << "1. Вывод в ПРЯМОМ порядке" << std::endl
            << "2. Вывод СИММЕТРИЧНОМ (рекурсивно) порядке" << std::endl
            << "3. Вывод СИММЕТРИЧНОМ (нерекурсивно) порядке" << std::endl
            << "4. Вывод в ОБРАТНО-СИММЕТРИЧНОМ пордяке" << std::endl
            << "0. Назад." << std::endl
            << std::endl;
        break;
    default:
        break;
    }
}