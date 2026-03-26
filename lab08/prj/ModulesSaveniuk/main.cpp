#include <cmath>
#include "ModulesSaveniuk.h" // Обязательно подключи заголовок
// Функция для обчисления S (Вариант 3)
double s_calculation(double x, double y, double z) {
    // Числитель: 12 * x^2
    double numerator = 12 * pow(x, 2);

    // Знаменатель: десятковый логарифм lg(x - 3)
    double denominator = log10(x - 3);

    // Выражение под корнем
    double inner_sqrt = numerator / denominator;

    // Вычисление синуса от корня
    double term = 3 * sin(sqrt(inner_sqrt));

    // Итоговая формула: возводим term в квадрат и добавляем 0.5 * z
    return pow(term, 2) + 0.5 * z;
}
#include "ModulesSaveniuk.h" // Обязательно подключи заголовок
