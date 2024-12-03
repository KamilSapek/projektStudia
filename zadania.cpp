#include "zadania.h"

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

struct strukturaZadania {
    vector<int> ID, procentRealizacji;
    vector<string> nazwa, opis, priorytet, status;
    vector<vector<int>> zaleznosci, przewidywanyKoniec, dataRozpoczecia, przypisaneOsoby;
};

vector<int> utworzWektor(string dane, char rozdzielnik) {
    dane += rozdzielnik;
    vector<int> zwor;
    string test;
    for (int i = 0; i < dane.length(); i++) {
        if (dane.at(i) == rozdzielnik) {
            zwor.push_back(stoi(test));
            test = "";
        } else {
            test += dane.at(i);
        }
    }
    return zwor;
}

string odczytajWektor(vector<int> wektor, const char rozdzielnik) {
    string zwrot;
    for (int i = 0; i < wektor.size(); i++) {
        zwrot += wektor.at(i) + rozdzielnik;
    }
    zwrot.pop_back();
    return zwrot;
}

void odczytajZadania(const char* nazwa) {
    strukturaZadania struktura;
    cout << nazwa << endl;
    int licznik;
    string linia, test;
    ifstream plik(nazwa);
    if (!plik.is_open()) {
        cout << "Nie mozna otworzyc pliku" << endl;
    } else {
        while (getline(plik, linia)) {
            linia += ';';
            licznik = 0;
            for (int i = 0; i < linia.length(); i++) {
                if (linia.at(i) == ';') {
                    switch (licznik) {
                        case 0: struktura.ID.push_back(stoi(test));
                        break;
                        case 1: struktura.nazwa.push_back(test);
                        break;
                        case 2: struktura.opis.push_back(test);
                        break;
                        case 3: struktura.priorytet.push_back(test);
                        break;
                        case 4: struktura.przypisaneOsoby.push_back(utworzWektor(test, *","));
                        break;
                        case 5: struktura.dataRozpoczecia.push_back(utworzWektor(test, *"."));
                        break;
                        case 6: struktura.przewidywanyKoniec.push_back(utworzWektor(test, *"."));
                        break;
                        case 7: struktura.status.push_back(test);
                        break;
                        case 8: struktura.zaleznosci.push_back(utworzWektor(test, *","));
                        break;
                        case 9: struktura.procentRealizacji.push_back(stoi(test));
                        break;
                    }
                    test = "";
                    licznik++;
                } else {
                    test += linia.at(i);
                }
            }
        }
    }
    for (auto i: struktura.przewidywanyKoniec)
        for (auto j: i)
            cout << j << endl;
}

void zapiszZadania(const char* nazwa) {
    strukturaZadania struktura;
    ofstream plik(nazwa, ios::app);
    string linia;
    if (!plik.is_open()) {
        cout << "Nie mozna otworzyc pliku" << endl;
    } else {
        for (int i = 0; i < struktura.ID.size(); i++) {
            linia += struktura.ID[i] + ";";
            linia += struktura.nazwa[i] + ";";
            linia += struktura.opis[i] + ";";
            linia += struktura.priorytet[i] + ";";
            linia += odczytajWektor(struktura.przypisaneOsoby[i], *",") + ";";
            linia += odczytajWektor(struktura.dataRozpoczecia[i], *".") + ";";
            linia += odczytajWektor(struktura.przewidywanyKoniec[i], *".") + ";";
            linia += struktura.status[i] + ";";
            linia += odczytajWektor(struktura.zaleznosci[i], *",") + ";";
            linia += struktura.procentRealizacji[i] + "\n";
            plik << linia;
        }
    }
}

void dodajZadanie() {
}

void usunZadanie() {
}

void raportZadania() {
}

void edytujZadanie() {
}
