#include <iostream>
#include "ModulesSaveniuk.h" // Підключаємо твій заголовковий файл

using namespace std;

// Заглушка для 8 лабораторної (щоб програма не видавала помилку)
double s_calculation(double x, double y, double z) {
    return x + y + z;
}

// ЗАДАЧА 9.1
void calculate_deposit(double amount, int months) {
    // 16% річних для півроку (<12), 18% для року (>=12)
    double annual_rate = (months >= 12) ? 0.18 : 0.16;

    // Загальна сума відсотків = сума * ставка * (кількість місяців / 12)
    double total_interest = amount * annual_rate * (months / 12.0);
    double monthly_payout = total_interest / months;

    cout << "Щомісячна виплата відсотків: " << monthly_payout << " грн." << endl;
    cout << "Загальна сума відсотків за весь строк: " << total_interest << " грн." << endl;
}

// ЗАДАЧА 9.2
int get_beaufort_scale(double speed) {
    if (speed < 0.3) return 0;
    if (speed <= 1.5) return 1;
    if (speed <= 3.3) return 2;
    if (speed <= 5.4) return 3;
    if (speed <= 7.9) return 4;
    if (speed <= 10.7) return 5;
    if (speed <= 13.8) return 6;
    if (speed <= 17.1) return 7;
    if (speed <= 20.7) return 8;
    if (speed <= 24.4) return 9;
    if (speed <= 28.4) return 10;
    if (speed <= 32.6) return 11;
    return 12; // >= 32.7
}

// ЗАДАЧА 9.3
int count_bits(int N) {
    // Отримуємо значення 13-го біта (D13)
    int bit13 = (N >> 13) & 1;
    int count = 0;

    // Перевіряємо всі 32 біти числа
    for (int i = 0; i < 32; i++) {
        int current_bit = (N >> i) & 1;
        // Використання тернарного оператора за вимогою:
        // Якщо bit13 == 0, рахуємо нулі. Інакше рахуємо одиниці.
        count += (bit13 == 0) ? (current_bit == 0 ? 1 : 0) : (current_bit == 1 ? 1 : 0);
    }

    return count;
}
