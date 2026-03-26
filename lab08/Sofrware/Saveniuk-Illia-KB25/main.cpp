#include <iostream>
#include <iomanip>
#include <clocale>
#include "ModulesSaveniuk.h" // Подключаем твою библиотеку

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    double x, y, z;

    cout << "--- Лабораторная работа №8 ---" << endl;
    cout << "Введите x: "; cin >> x;
    cout << "Введите y: "; cin >> y;
    cout << "Введите z: "; cin >> z;

    // Вызываем функцию из библиотеки
    double result = s_calculation(x, y, z);

    cout << fixed << setprecision(3);
    cout << "Результат вычисления S = " << result << endl;

    return 0;
}
