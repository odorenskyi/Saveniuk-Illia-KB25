#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <sstream>
#include "ModulesSaveniuk.h"

using namespace std;

string getDeveloperInfo() {
    return "(c) Saveniuk Illia";
}

bool checkLogicalExpression(char a, char b) {
    return (a + 1) > abs(b - 2);
}

string getFormattedDataAndS(double x, double y, double z) {
    stringstream ss;
    ss << "DEC: x=" << x << ", y=" << y << ", z=" << z << "\n";
    ss << "HEX: x=" << hexfloat << x << ", y=" << y << ", z=" << z << defaultfloat << "\n";
    ss << "S = " << s_calculation(x, y, z);
    return ss.str();
}

int main() {
    double x, y, z;
    char a, b;

    cout << "Enter three numbers (x, y, z) separated by space: ";
    cin >> x >> y >> z;

    cout << "Enter two characters (a, b) separated by space: ";
    cin >> a >> b;

    cout << "\n--- RESULTS ---\n";
    cout << "8.2.1 Developer: " << getDeveloperInfo() << endl;
    cout << "8.2.2 Logical result: " << boolalpha << checkLogicalExpression(a, b) << endl;
    cout << "8.2.3 Data and S:\n" << getFormattedDataAndS(x, y, z) << endl;

    return 0;
}
