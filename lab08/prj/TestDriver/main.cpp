#include <iostream>
#include <cmath>
#include "ModulesSaveniuk.h"

using namespace std;

int main() {
    cout << "=== TEST DRIVER RUNNING ===" << endl;

    // Тестовый прогон: x=10, y=10, z=10
    double res = s_calculation(10, 10, 10);

    cout << "Test 1: x=10, y=10, z=10" << endl;
    cout << "Expected: 5.003" << endl;
    cout << "Actual:   " << res << endl;

    if (res > 5.0 && res < 5.1) {
        cout << "STATUS: SUCCESS" << endl;
    } else {
        cout << "STATUS: FAILED" << endl;
    }

    return 0;
}
