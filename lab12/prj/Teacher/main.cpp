#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <windows.h> // Додано для відновлення нормального тексту в консолі
#include "ModulesSaveniuk.h"

int main() {
    // Фікс кракозябр: встановлюємо кодування Windows-1251 для консолі
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string compile_path = __FILE__;

    // Перевірка шляху компіляції (Вимога №2)
    if (compile_path.find("\\Lab12\\prj") == std::string::npos &&
        compile_path.find("/Lab12/prj") == std::string::npos &&
        compile_path.find("\\lab12\\prj") == std::string::npos &&
        compile_path.find("/lab12/prj") == std::string::npos) {

        for (int i = 0; i < 100; ++i) { std::cout << '\a'; }

        std::ofstream errorFile("TestResults.txt");
        if (errorFile.is_open()) {
            errorFile << "Встановлені вимоги порядку виконання лабораторної роботи порушено!" << std::endl;
            errorFile.close();
        }
        std::cout << "Помилка шляху! Результат записано в TestResults.txt" << std::endl;
        return 0;
    }

    // Локальний клас для юніт-тестування (Вимога №12)
    class LocalTester {
    public:
        static void runUnitTests() {
            std::ifstream testFile;
            std::ofstream reportFile;

            // Список усіх можливих папок
            std::string folders[] = {
                "../../TestSuite/",
                "../../../../TestSuite/",
                "../TestSuite/",
                "TestSuite/",
                "./"
            };

            // Перевірка на випадок подвійного розширення файлу (suite.txt.txt)
            std::string filenames[] = {
                "suite.txt",
                "suite.txt.txt"
            };

            bool fileFound = false;
            std::string successfulFolder = "";
            std::string successfulFile = "";

            // Шукаємо правильну комбінацію папки та назви файлу
            for (const std::string& folder : folders) {
                for (const std::string& name : filenames) {
                    testFile.open(folder + name);
                    if (testFile.is_open()) {
                        successfulFolder = folder;
                        successfulFile = name;
                        fileFound = true;
                        break;
                    }
                    testFile.clear();
                }
                if (fileFound) break;
            }

            // Якщо навіть так не знайшли — даємо зрозумілу помилку українською
            if (!fileFound) {
                std::cerr << "Помилка: Не знайдено файл тестів (перевірено suite.txt та suite.txt.txt) у жодній папці!" << std::endl;
                return;
            }

            // Відкриваємо файл звіту там же, де знайшли тести
            reportFile.open(successfulFolder + "TestResults.txt");
            if (!reportFile.is_open()) {
                std::cerr << "Помилка: Не вдалося створити файл результатів TestResults.txt!" << std::endl;
                testFile.close();
                return;
            }

            reportFile << "Test Case ID -> Action -> Expected Result -> Test Result\n";
            reportFile << "---------------------------------------------------------\n";

            double radius, expectedArea;
            int testId = 1;

            while (testFile >> radius >> expectedArea) {
                ClassLab12_Saveniuk wheel(radius);
                double actualArea = wheel.getArea();
                bool passed = std::abs(actualArea - expectedArea) < 0.01;

                reportFile << "TC0" << testId << " -> Set Radius: " << radius
                           << " -> Expected Area: " << expectedArea
                           << " -> " << (passed ? "PASSED" : "FAILED")
                           << " (Actual: " << actualArea << ")\n";
                testId++;
            }

            testFile.close();
            reportFile.close();
            std::cout << "Тестування завершено успішно! Звіт збережено в папку TestSuite." << std::endl;
        }
    };

    LocalTester::runUnitTests();
    return 0;
}

