#include <iostream>
#include <fstream>
#include <windows.h> // Бібліотека для роботи з консоллю Windows
#include "ModulesSaveniuk.h"

using namespace std;

int main() {
    // Встановлюємо українське кодування для консолі
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Вказуємо імена файлів
    const char* inputFile = "input_test.txt";
    const char* outputFile = "output_test.txt";

    cout << "=== СТАРТ ТЕСТУВАННЯ ===" << endl;

    // 1. Створюємо вхідний файл для перевірки (щоб не створювати вручну)
    ofstream testIn(inputFile);
    if (testIn.is_open()) {
        testIn << "Лінощі завжди заважають студентам, через що наступає важка сесія та академзаборгованість." << endl;
        testIn.close();
        cout << "[OK] Створено тестовий вхідний файл." << endl;
    }

    // 2. Тестуємо Задачу 10.1
    cout << "\n--- Запуск Задачі 10.1 ---" << endl;
    processSentence(inputFile, outputFile);
    cout << "[OK] Функція 10.1 відпрацювала." << endl;

    // 3. Тестуємо Задачу 10.2
    cout << "\n--- Запуск Задачі 10.2 ---" << endl;
    appendLawArticle(outputFile);
    cout << "[OK] Функція 10.2 відпрацювала (дозапис)." << endl;

    // 4. Тестуємо Задачу 10.3
    cout << "\n--- Запуск Задачі 10.3 ---" << endl;
    // Передаємо тестові параметри x, y, z та число b для двійкового коду
    appendCalculation(outputFile, 2.5, 3.5, 4.0, 13);
    cout << "[OK] Функція 10.3 відпрацювала (дозапис результатів та коду)." << endl;

    cout << "\n=== ТЕСТУВАННЯ ЗАВЕРШЕНО ===" << endl;
    cout << "Перевір файл " << outputFile << " у папці проекту TestDriver!" << endl;

    return 0;
}
