#include <iostream>
#include <cstdlib> // Для очистки экрана и паузы
#include "ModulesSaveniuk.h" // Твоя библиотека

using namespace std;

int main() {
    // Делаем так, чтобы консоль нормально показывала украинские буквы
    system("chcp 65001 > nul");

    char choice;

    // Цикл do-while, чтобы меню возвращалось после завершения задачи
    do {
        system("cls"); // Пункт 1: Очистить экран

        // Пункт 2: Главное меню
        cout << "====== ГОЛОВНЕ МЕНЮ ======" << endl;
        cout << "1. Розрахунок депозиту (Завдання 9.1)" << endl;
        cout << "2. Шкала Бофорта (Завдання 9.2)" << endl;
        cout << "3. Підрахунок бітів (Завдання 9.3)" << endl;
        cout << "4. Вихід" << endl;
        cout << "==========================" << endl;
        cout << "Оберіть пункт меню (1-4): ";
        cin >> choice;

        // Пункт 3 и 5: Вызов функций и проверка правильности ввода
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
                return 0; // Полное завершение программы
            }
            default: {
                // Пункт 5: Если ввели дичь (например, 5 или букву)
                cout << "\nПОМИЛКА: Невірний пункт меню! Будь ласка, оберіть від 1 до 4." << endl;
                break;
            }
        }

        // Пункт 4: Ожидание нажатия клавиши для возврата в меню
        cout << "\nНатисніть будь-яку клавішу для повернення в меню...";
        system("pause > nul");

    } while (true);

    return 0;
}
