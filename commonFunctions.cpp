#include "commonFunctions.h"
#include "tasks.h"
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

/*tworzy wektor intow na podstawie podanego tekstu i znaku interpunkcyjnego*/
vector<int> createVector(string data, char splitter) {
    data += splitter;
    vector<int> vectorToReturn;
    string test;
    for (int i = 0; i < data.length(); i++) {
        if (data.at(i) == splitter) {
            vectorToReturn.push_back(stoi(test));
            test = "";
        } else {
            test += data.at(i);
        }
    }
    return vectorToReturn;
}

/*przetwarza wektor na string*/
string readVector(const std::vector<int> &vector, const char splitter) {
    string stringToReturn;
    for (const int i: vector) {
        stringToReturn += to_string(i) + splitter;
    }
    stringToReturn.pop_back();
    return stringToReturn;
}

/*prosi uzytkownika o podanie stringa i sprawdza czy nie wystapil blad podczas tego lub czy cokolwiek wpisal*/
string inputString(const string &text) {
    string toReturn;
    cout << text << " ";
    getline(cin, toReturn);
    // dopoki istnieje blad podczas wpisywania stringa
    while (toReturn.empty() || !cin) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Ups! Cos poszlo nie tak. Sprobuj ponownie." << endl;
        cout << text;
        getline(cin, toReturn);
    }
    return toReturn;
}

/*prosi uzytkownika o podanie inta i sprawdza czy nie wystapil blad podczas tego lub czy cokolwiek wpisal*/
int inputInt(const string &text, const int &minChoice, const int &maxChoice) {
    string toReturn;
    int ret;
    // dopoki wystepuje blad podczas podawania liczby
    while (true) {
        cout << text;
        cin >> toReturn;
        if (toReturn.size() > 1 || !isdigit(toReturn[0])) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Ups! Cos poszlo nie tak. Sprobuj ponownie.\nDopuszczalne wartsci 1 - " << maxChoice << endl;
            continue;
        }
        cin.ignore();
        ret = stoi(toReturn);
        if (ret > maxChoice || ret < minChoice) {
            cout << "Mozesz podac liczby " << minChoice << " - " << maxChoice << "!" << endl;
        } else {
            break;
        }
    }
    return ret;
}

date createDate(const string &text) {
    date dateToReturn = {};
    int iterator = 0;
    string test;
    for (int i = 0; i < text.length(); i++) {
        if (text.at(i) == '.') {
            int number = stoi(test);
            switch (iterator) {
                case 0:
                    while (number < 1 || number > 31) {
                        cout << "Dzien musi znajdowac sie w przedziale 1 - 31" << endl;
                        number = inputInt("Podaj dzien: ", 1, 31);
                    }
                    dateToReturn.day = number;
                    break;
                case 1:
                    while (number < 1 || number > 12) {
                        cout << "Miesiac musi znajdowac sie w przedziale 1 - 12" << endl;
                        number = inputInt("Podaj miesiac: ", 1, 12);
                    }
                    dateToReturn.month = stoi(test);
                    break;
                case 2:
                    dateToReturn.year = stoi(test);
                    break;
            }
            iterator++;
            test = "";
        } else {
            test += text.at(i);
        }
    }
    return dateToReturn;
}

bool isEarlierDate(const date &date1, const date &date2) {
    if (date1.year < date2.year) {
        return true;
    }
    if (date1.month < date2.month && date1.year == date2.year) {
        return true;
    }
    if (date1.day < date2.day && date1.month == date2.month && date1.year == date2.year) {
        return true;
    }
    return false;
}

bool isLaterDate(const date &date1, const date &date2) {
    if (date1.year > date2.year) {
        return true;
    }
    if (date1.month > date2.month) {
        return true;
    }
    if (date1.day > date2.day) {
        return true;
    }
    return false;
}
