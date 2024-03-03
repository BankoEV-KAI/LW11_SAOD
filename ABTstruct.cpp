#include "ABTstruct.h"
#include "menu.h"

#include <iostream>
#include <cstdlib>

Node* RootABT;
Node* ParentVertexABT;
bool signSuccessSearh{ false };


Node* addNodes(Node* pCurrent, int count) {
    Node* pTemp;
    int countLeft, countRight;
    if (count == 0)
        return nullptr;
    else {
        countLeft = count / 2;
        countRight = count - countLeft - 1;
        pTemp = new Node;
        pTemp->data = rand() % 100 + 1;
        pTemp->left = addNodes(pTemp->left, countLeft);
        pTemp->right = addNodes(pTemp->right, countRight);
        pCurrent = pTemp;

        return pTemp;
    }
}

void printForward(Node* pCurrent, int levelABT) {
    if (pCurrent != NULL) {
        std::string str;
        for (int i = 0; i < levelABT; i++)
            str += "     ";
        std::cout << " " << str << pCurrent->data << "\n";

        printForward(pCurrent->left, levelABT + 1);
        printForward(pCurrent->right, levelABT + 1);
    }
}

void printSymmetrical(Node* pCurrent, int levelABT) {
    if (pCurrent != NULL) {
        printSymmetrical(pCurrent->left, levelABT + 1);

        std::string str;
        for (int i = 0; i < levelABT; i++)
            str += "     ";
        std::cout << " " << str << pCurrent->data << "\n";

        printSymmetrical(pCurrent->right, levelABT + 1);
    }
}

void printInverselySymmetrical(Node* pCurrent, int levelABT) {
    if (pCurrent != NULL) {
        printInverselySymmetrical(pCurrent->right, levelABT + 1);

        std::string str;
        for (int i = 0; i < levelABT; i++)
            str += "     ";
        std::cout << " " << str << pCurrent->data << "\n";

        printInverselySymmetrical(pCurrent->left, levelABT + 1);
    }
}

void deleteABT(Node* pCurrent) {
    if (pCurrent != NULL) {
        deleteABT(pCurrent->left);
        deleteABT(pCurrent->right);
        delete pCurrent;
    }
    RootABT = nullptr;
}

Stack* stack;

void initStack(Node* ABT) {
    stack = new Stack;
    stack->passedVertex = ABT;
    stack->levelABT = -1;
    stack->next = nullptr;
}

bool isEmpty() {
    return stack->levelABT < 0;
}

void printNonRecursiveSymmetrical() {
    initStack(RootABT);
    Node* pCurrentTree = RootABT;
    bool Stop = false;
    int levelABT = 0;

    while (!Stop) {
        while (pCurrentTree != NULL) {

            Stack* item = new Stack;
            item->levelABT = levelABT;
            item->passedVertex = pCurrentTree;
            item->next = stack;
            stack = item;
            pCurrentTree = stack->passedVertex;
            pCurrentTree = pCurrentTree->left;
            levelABT++;
        }
        if (isEmpty())
            Stop = true;
        else {
            levelABT = stack->levelABT;
            pCurrentTree = stack->passedVertex;
            std::string str = "";
            for (int i = 0; i < levelABT; i++)
                str += "     ";
            std::cout << " " << str << (pCurrentTree->data) << "\n";
            Stack* current = stack;
            stack = stack->next;
            delete current;

            pCurrentTree = pCurrentTree->right;
            levelABT++;
        }
    }
}


void searchNode(Node* pCurrent, int searchData) {
    if (!signSuccessSearh) {
        if (pCurrent != NULL) {
            if (pCurrent->data == searchData) {
                signSuccessSearh = true;
                ParentVertexABT = pCurrent;
            }
            else {
                searchNode(pCurrent->left, searchData);
                searchNode(pCurrent->right, searchData);
            }
        }
    }
    else return;
}
Node* addNode(Node* pTemp, int newData) {
    pTemp = new Node;
    pTemp->left = pTemp->right = NULL; //� ����� ������� ��� ��� ������ � ������� ��������
    pTemp->data = newData;
    return pTemp; //���������� ����� ���������� �����
}

void addNodeMenu() {
    int newData, parentData,baby;
    if (RootABT != nullptr) { 
        std::cout << "����� �������-�������� �������� ������� >> ";
        enteringNumber(1, 100, parentData);
        signSuccessSearh = false;
        searchNode(RootABT, parentData); 
        if (signSuccessSearh) {
            signSuccessSearh = false;
            if (ParentVertexABT->left == nullptr || ParentVertexABT->right == nullptr) {
                std::cout << "������ ������� �������� >>  ";
                enteringNumber(1, 100, newData);
            }
            if (ParentVertexABT->left == nullptr && ParentVertexABT->right == nullptr) {
                std::cout << "����� �������� 1 - ������ �������, 2 - ������� ������� >>";
                enteringNumber(1, 2, baby);
                baby == 1 ? ParentVertexABT->left = addNode(ParentVertexABT->left, newData) : ParentVertexABT->right = addNode(ParentVertexABT->right, newData);
                std::cout << "������� " << newData << " ��������� ��� " << (baby == 1 ? "����� " : "������ ") << "�������" << std::endl;
            }
            else if (ParentVertexABT->left == NULL) {
                ParentVertexABT->left = addNode(ParentVertexABT->left, newData);
                std::cout << "�������" << newData << " ��������� ��� ����� �������" << std::endl;
            }
            else if (ParentVertexABT->right == NULL) {
                ParentVertexABT->right = addNode(ParentVertexABT->right, newData);
                std::cout << "�������" << newData << " ��������� ��� ������ �������" << std::endl;
            }
            else {
                std::cout << "���������� ����������: ��� ������� ��� ����������." << std::endl;
                return;
            }
        }
        else std::cout << "�������-��������" << parentData << " �� ������� � ������" << std::endl;
    }
    else { 
        RootABT = new Node;
        std::cout << "������ �����. ����� ������ ������. ";
        enteringNumber(1, 100, newData);
        RootABT->left = RootABT->right = nullptr;
        RootABT->data = newData;
        std::cout << "������ ������ " << RootABT->data << " ������" << std::endl;
    }
}

void searchNodeMenu() {
    signSuccessSearh = false; int searchData{ 0 };
    enteringNumber(1, 100, searchData);
    searchNode(RootABT, searchData);
    std::cout << "������� " << searchData << (signSuccessSearh ? " ������ " : " �� ������ ") << " � ������ ������. " << std::endl;
}

void printAllVision() {
    std::cout << "��� � ������� ������� (9 ��) " << std::endl;
    printForward(RootABT, 0);
    std::cout << std::endl;
    std::cout << "��� � ������������ �������" << std::endl;
    std::cout << "����������� ����� (9 ��)" << std::endl;
    printSymmetrical(RootABT, 0);
    std::cout << std::endl;
    std::cout << "������������� ����� (10 ��)" << std::endl;
    printNonRecursiveSymmetrical();
    std::cout << std::endl;
    std::cout << "��� � ������-������������ ������� (9 ��)" << std::endl;
    printInverselySymmetrical(RootABT, 0);
    std::cout << std::endl;
}