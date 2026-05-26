#ifndef REGISTRY_SAVENIUK_H
#define REGISTRY_SAVENIUK_H

#include <iostream>
#include <fstream>
#include "struct_type_project_5.h"

// Очистка динамической памяти списка
void clearList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Добавление новой записи в конец списка
void addEntity(Node*& head) {
    Node* newNode = new Node;
    newNode->next = nullptr;

    std::cout << "\n--- ВВЕДЕННЯ ДАНИХ НОВОГО СУБ'ЄКТА ---\n";
    std::cout << "Код закладу в ЄДЕБО: ";
    std::cin >> newNode->data.edeboCode;
    std::cin.ignore();

    std::cout << "Повне найменування: ";
    std::cin.getline(newNode->data.fullName, 256);

    std::cout << "Коротка назва: ";
    std::cin.getline(newNode->data.shortName, 100);

    std::cout << "Повне найменування (англ.): ";
    std::cin.getline(newNode->data.englishName, 256);

    std::cout << "Форма власності: ";
    std::cin.getline(newNode->data.ownershipForm, 100);

    std::cout << "Найменування органу управління: ";
    std::cin.getline(newNode->data.governingBody, 256);

    std::cout << "Найменування посади керівника: ";
    std::cin.getline(newNode->data.managerPosition, 150);

    std::cout << "Прізвище керівника: ";
    std::cin.getline(newNode->data.managerLastName, 100);

    std::cout << "Ім'я керівника: ";
    std::cin.getline(newNode->data.managerFirstName, 100);

    std::cout << "По батькові керівника: ";
    std::cin.getline(newNode->data.managerPatronymic, 100);

    std::cout << "Місцезнаходження (юридична адреса): ";
    std::cin.getline(newNode->data.address, 256);

    std::cout << "Телефон / факс: ";
    std::cin.getline(newNode->data.phone, 50);

    std::cout << "Електронна пошта: ";
    std::cin.getline(newNode->data.email, 150);

    std::cout << "Веб-сайт: ";
    std::cin.getline(newNode->data.website, 150);

    std::cout << "ОЦ «Крим-Україна» (так/ні): ";
    std::cin.getline(newNode->data.isCrimeaCenter, 20);

    std::cout << "ОЦ «Донбас-Україна» (так/ні): ";
    std::cin.getline(newNode->data.isDonbasCenter, 20);

    std::cout << "Військова кафедра (так/ні): ";
    std::cin.getline(newNode->data.hasMilitaryDepartment, 20);

    std::cout << "Рік заснування: ";
    std::cin >> newNode->data.establishmentYear;
    std::cin.ignore();

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
    std::cout << "Запис успішно додано до оперативної пам'яті!\n";
}

// Поиск по коду ЕДЕБО
void searchByCode(Node* head) {
    if (head == nullptr) {
        std::cout << "Реєстр порожній.\n";
        return;
    }

    int searchCode;
    std::cout << "Введіть код ЄДЕБО для пошуку: ";
    std::cin >> searchCode;
    std::cin.ignore();

    Node* current = head;
    bool found = false;

    while (current != nullptr) {
        if (current->data.edeboCode == searchCode) {
            found = true;
            std::cout << "\n========================================\n"
                      << "РЕЗУЛЬТАТ ПОШУКУ:\n"
                      << "========================================\n"
                      << "Код в ЄДЕБО:       " << current->data.edeboCode << "\n"
                      << "Повне найменування:" << current->data.fullName << "\n"
                      << "Коротка назва:     " << current->data.shortName << "\n"
                      << "Назва (англ.):     " << current->data.englishName << "\n"
                      << "Форма власності:   " << current->data.ownershipForm << "\n"
                      << "Орган управління:  " << current->data.governingBody << "\n"
                      << "Посада керівника:  " << current->data.managerPosition << "\n"
                      << "Керівник (ПІБ):    " << current->data.managerLastName << " "
                                               << current->data.managerFirstName << " "
                                               << current->data.managerPatronymic << "\n"
                      << "Адреса:            " << current->data.address << "\n"
                      << "Телефон / факс:    " << current->data.phone << "\n"
                      << "Електронна пошта:  " << current->data.email << "\n"
                      << "Веб-сайт:          " << current->data.website << "\n"
                      << "ОЦ Крим-Україна:   " << current->data.isCrimeaCenter << "\n"
                      << "ОЦ Донбас-Україна: " << current->data.isDonbasCenter << "\n"
                      << "Військова кафедра: " << current->data.hasMilitaryDepartment << "\n"
                      << "Рік заснування:    " << current->data.establishmentYear << "\n"
                      << "----------------------------------------\n";
            break;
        }
        current = current->next;
    }

    if (!found) {
        std::cout << "Заклад із кодом " << searchCode << " не знайдено.\n";
    }
}

// Удаление записи по коду ЕДЕБО
void deleteEntity(Node*& head) {
    if (head == nullptr) {
        std::cout << "Реєстр порожній.\n";
        return;
    }

    int deleteCode;
    std::cout << "Введіть код ЄДЕБО для вилучення: ";
    std::cin >> deleteCode;
    std::cin.ignore();

    Node* current = head;
    Node* previous = nullptr;
    bool found = false;

    while (current != nullptr) {
        if (current->data.edeboCode == deleteCode) {
            found = true;
            if (previous == nullptr) {
                head = current->next;
            } else {
                previous->next = current->next;
            }
            delete current;
            std::cout << "Заклад з кодом " << deleteCode << " успішно вилучено.\n";
            break;
        }
        previous = current;
        current = current->next;
    }

    if (!found) {
        std::cout << "Заклад з кодом " << deleteCode << " не знайдено.\n";
    }
}

// Сохранение списка в БИНАРНЫЙ файл
void saveToBinary(Node* head, const char* filename) {
    std::ofstream binFile(filename, std::ios::binary | std::ios::trunc);
    if (!binFile.is_open()) {
        std::cout << "Помилка відкриття бінарного файлу для запису!\n";
        return;
    }

    Node* current = head;
    while (current != nullptr) {
        binFile.write(reinterpret_cast<char*>(&current->data), sizeof(EducationalEntity));
        current = current->next;
    }
    binFile.close();
}

// Загрузка списка из БИНАРНОГО файла
void loadFromBinary(Node*& head, const char* filename) {
    std::ifstream binFile(filename, std::ios::binary);
    if (!binFile.is_open()) {
        return; // Если файла ещё нет, просто выходим (первый запуск)
    }

    clearList(head);

    EducationalEntity tempEntity;
    Node* tail = nullptr;

    while (binFile.read(reinterpret_cast<char*>(&tempEntity), sizeof(EducationalEntity))) {
        Node* newNode = new Node;
        newNode->data = tempEntity;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    binFile.close();
}

// Вывод реестра (Экран ИЛИ Текстовый файл со всеми 18 полями)
void displayRegistry(Node* head) {
    if (head == nullptr) {
        std::cout << "Реєстр порожній.\n";
        return;
    }

    int mode;
    std::cout << "Оберіть спосіб виведення даних:\n1. На екран консолі\n2. У текстовий файл (registry_report.txt)\nВибір: ";
    std::cin >> mode;
    std::cin.ignore();

    if (mode == 2) {
        std::ofstream txtFile("registry_report.txt");
        if (!txtFile.is_open()) {
            std::cout << "Помилка створення текстового звіту!\n";
            return;
        }

        Node* current = head;
        int index = 1;
        while (current != nullptr) {
            txtFile << "======================================================================\n"
                    << "ЗАКЛАД ОСВІТИ № " << index++ << "\n"
                    << "======================================================================\n"
                    << "1. Код закладу в ЄДЕБО:       " << current->data.edeboCode << "\n"
                    << "2. Повне найменування:        " << current->data.fullName << "\n"
                    << "3. Коротка назва:             " << current->data.shortName << "\n"
                    << "4. Повне найменування (англ): " << current->data.englishName << "\n"
                    << "5. Form власності:           " << current->data.ownershipForm << "\n"
                    << "6. Орган управління:          " << current->data.governingBody << "\n"
                    << "7. Посада керівника:          " << current->data.managerPosition << "\n"
                    << "8. Прізвище керівника:        " << current->data.managerLastName << "\n"
                    << "9. Ім'я керівника:            " << current->data.managerFirstName << "\n"
                    << "10. По батькові керівника:    " << current->data.managerPatronymic << "\n"
                    << "11. Місцезнаходження (адреса):" << current->data.address << "\n"
                    << "12. Телефон / факс:           " << current->data.phone << "\n"
                    << "13. Електронна пошта:         " << current->data.email << "\n"
                    << "14. Веб-сайт:                 " << current->data.website << "\n"
                    << "15. ОЦ «Крим-Україна»:        " << current->data.isCrimeaCenter << "\n"
                    << "16. ОЦ «Донбас-Україна»:      " << current->data.isDonbasCenter << "\n"
                    << "17. Військова кафедра:        " << current->data.hasMilitaryDepartment << "\n"
                    << "18. Рік заснування:           " << current->data.establishmentYear << "\n\n";
            current = current->next;
        }
        txtFile << "======================================================================\n"
                << "Всього записів у звіті: " << index - 1 << "\n";

        txtFile.close();
        std::cout << "Звіт успішно збережено у файл 'registry_report.txt'!\n";
    }
    else {
        Node* current = head;
        int index = 1;
        while (current != nullptr) {
            std::cout << "\n------------------ ЗАКЛАД № " << index++ << " ------------------\n"
                      << "Код в ЄДЕБО:       " << current->data.edeboCode << "\n"
                      << "Назва:             " << current->data.fullName << "\n"
                      << "Коротка назва:     " << current->data.shortName << "\n"
                      << "Керівник (ПІБ):    " << current->data.managerLastName << " " << current->data.managerFirstName << "\n"
                      << "Рік заснування:    " << current->data.establishmentYear << "\n"
                      << "--------------------------------------------------------\n";
            current = current->next;
        }
    }
}

#endif // REGISTRY_SAVENIUK_H
