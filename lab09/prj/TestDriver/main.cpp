#include <iostream>
#include <cstdlib> // Для очищення екрана та паузи
#include "ModulesSaveniuk.h" // Твоя бібліотека

using namespace std;

int main() {
    // Робимо так, щоб консоль нормально відображала українські літери
    system("chcp 65001 > nul");

    char choice;

    // Цикл do-while, щоб меню поверталося після завершення задачі
    do {
        system("cls"); // Пункт 1: Очистити екран

        // Пункт 2: Головне меню
        cout << "====== ГОЛОВНЕ МЕНЮ ======" << endl;
        cout << "1. Розрахунок депозиту (Завдання 9.1)" << endl;
        cout << "2. Шкала Бофорта (Завдання 9.2)" << endl;
        cout << "3. Підрахунок бітів (Завдання 9.3)" << endl;
        cout << "4. Вихід" << endl;
        cout << "==========================" << endl;
        cout << "Оберіть пункт меню (1-4): ";
        cin >> choice;

        // Пункт 3 і 5: Виклик функцій та перевірка правильності введення
        switch (choice) {
            case '1': {
                system("cls");
                cout << "--- Розрахунок депозиту ---" << endl;
                double amount;
                int months;
                cout << "Введіть суму вкладу (грн): ";
                cin >> amount;
                cout << "Введіть кількість місяців: ";
                cin >> months;

                calculate_deposit(amount, months);
                break;
            }
            case '2': {
                system("cls");
                cout << "--- Шкала Бофорта ---" << endl;
                double speed;
                cout << "Введіть швидкість вітру (м/с): ";
                cin >> speed;

                int result = get_beaufort_scale(speed);
                cout << "Сила вітру за шкалою Бофорта: " << result << " балів" << endl;
                break;
            }
            case '3': {
                system("cls");
                cout << "--- Підрахунок бітів ---" << endl;
                int N;
                cout << "Введіть ціле число N: ";
                cin >> N;

                int bits = count_bits(N);
                cout << "Результат підрахунку: " << bits << endl;
                break;
            }
            case '4': {
                cout << "\nВихід з програми. Гарного дня!" << endl;
                return 0; // Повне завершення програми
            }
            default: {
                // Пункт 5: Якщо ввели щось не те (наприклад, 5 або літеру)
                cout << "\nПОМИЛКА: Невірний пункт меню! Будь ласка, оберіть від 1 до 4." << endl;
                break;
            }
        }

        // Пункт 4: Очікування натискання клавіші для повернення в меню
        cout << "\nНатисніть будь-яку клавішу для повернення в меню...";
        system("pause > nul");

    } while (true);

    return 0;
}
