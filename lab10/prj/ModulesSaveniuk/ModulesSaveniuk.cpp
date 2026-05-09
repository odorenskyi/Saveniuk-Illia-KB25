#include "ModulesSaveniuk.h"
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

void processSentence(const char* inputFileName, const char* outputFileName) {
    ifstream inFile(inputFileName);
    ofstream outFile(outputFileName);
    if (!inFile.is_open() || !outFile.is_open()) return;

    string sentence;
    getline(inFile, sentence);

    bool isEng = false;
    for (char c : sentence) {
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) { isEng = true; break; }
    }

    outFile << "Розробник: Савенюк Ілля, Україна, 2024\n";

    if (isEng) {
        outFile << "Мова речення: Англійська\n";
        for (char &c : sentence) c = toupper(c);
        outFile << sentence << endl;
    } else {
        outFile << "Мова речення: Українська\n";
        string words[] = {"лінощі", "сесія", "академзаборгованість"};
        for (const string& w : words) {
            size_t pos;
            while ((pos = sentence.find(w)) != string::npos) sentence.erase(pos, w.length());
        }
        outFile << sentence << endl;
    }
    inFile.close(); outFile.close();
}

void appendLawArticle(const char* outputFileName) {
    ofstream outFile(outputFileName, ios::app);
    if (!outFile.is_open()) return;
    outFile << "\n--- Стаття 62 Закону України «Про вищу освіту» ---\n";
    outFile << "Особи, які навчаються у закладах вищої освіти, мають право на безпечні і нешкідливі умови...\n";
    time_t now = time(0);
    outFile << "Дата й час дозапису: " << ctime(&now);
    outFile.close();
}

float s_calculation(float x, float y, float z) { return x + y + z; }

void appendCalculation(const char* outputFileName, float x, float y, float z, int b) {
    ofstream outFile(outputFileName, ios::app);
    if (!outFile.is_open()) return;
    outFile << "\nРезультат s_calculation: " << s_calculation(x, y, z) << endl;
    outFile << "Число " << b << " у двійковому коді: ";
    if (b == 0) outFile << "0";
    else {
        string bin = "";
        int temp = b;
        while (temp > 0) { bin = to_string(temp % 2) + bin; temp /= 2; }
        outFile << bin;
    }
    outFile << endl;
    outFile.close();
}
