#include <iostream>
#include <windows.h>
#include "registry_saveniuk.h"

int main() {
    // Исправление кодировки консоли для ввода и вывода украинских символов (CP1251)
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Node* registryHead = nullptr;
    const char* dbFilename = "registry_data.bin";

    // Автоматическая загрузка базы данных при старте программы
    loadFromBinary(registryHead, dbFilename);

    int choice;
    do {
        std::cout << "\n=== МЕНЮ КЕРУВАННЯ РЕЄСТРОМ ===\n";
        std::cout << "1. Вивести реєстр (екран / файл)\n";
        std::cout << "2. Додати новий запис до реєстру\n";
        std::cout << "3. Пошук запису за кодом ЄДЕБО\n";
        std::cout << "4. Вилучити запис з реєстру\n";
        std::cout << "5. Вихід з програми (з автозбереженням)\n";
        std::cout << "Ваш вибір: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:
                displayRegistry(registryHead);
                break;
            case 2:
                addEntity(registryHead);
                break;
            case 3:
                searchByCode(registryHead);
                break;
            case 4:
                deleteEntity(registryHead);
                break;
            case 5:
                // Автоматическое сохранение при выходе
                saveToBinary(registryHead, dbFilename);
                clearList(registryHead);
                std::cout << "Дані успішно збережено. До побачення!\n";
                break;
            default:
                std::cout << "Неправильний вибір! Спробуйте ще раз.\n";
        }
    } while (choice != 5);

    return 0;
}
