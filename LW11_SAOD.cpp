#include "menu.h"
#include "ABTstruct.h"
#include <iostream>


//Обработка произвольных двоичных деревьев

int main()
{
    setlocale(LC_ALL, "ru");
    srand(static_cast<unsigned int>(time(0)));
    int operation{ 0 }, searchData{ 0 }, countNodes{ 0 };

    while (true) {
        printMenu(1);
        enteringNumber(0, 7, operation);
        switch (operation)
        {
        case 0:
            return 0;
        case 1:
            if (RootABT == nullptr) {
                std::cout << "Сколько вершин в дереве >> ";
                enteringNumber(1, 100, countNodes);
                RootABT = addNodes(RootABT, countNodes);
            }
            else std::cout << "Дерево уже существует." << std::endl;
            printSymmetrical(RootABT, 0);
            break;
        case 2:
            if (RootABT == nullptr) {
                std::cout << "Дерево пусто" << std::endl;
                break;
            }
            searchNodeMenu();
            break;
        case 3:
            
            addNodeMenu();
            printSymmetrical(RootABT, 0);
            break;
        case 4:
            if (RootABT == nullptr) std::cout << "Дерево пусто" << std::endl;
            else printSymmetrical(RootABT, 0);
            break;
        case 5:
            if (RootABT == nullptr) std::cout << "Дерево пусто" << std::endl;
            else printAllVision();
            break;
        case 6:
            if (RootABT == nullptr) {
                std::cout << "Дерево пусто" << std::endl;
                break;
            }
            deleteABT(RootABT);
            std::cout << "Дерево уничтожено. " << std::endl;
            break;
        default:
            break;
        }
    }
}
