#include "czlonkowie.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct strukturaCzlonkowie {
    vector<int> ID;
    vector<string> imie, nazwisko;
    vector<vector<int>> przypisaneZadania, historiaZadan;
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

void odczytajCzlonkowie(const char* nazwa) {
    strukturaCzlonkowie struktura;
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
                        case 1: struktura.imie.push_back(test);
                        break;
                        case 2: struktura.nazwisko.push_back(test);
                        break;
                        case 3: struktura.przypisaneZadania.push_back(utworzWektor(test, ','));
                        break;
                        case 4: struktura.historiaZadan.push_back(utworzWektor(test, ','));
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
}

void zapiszCzlonkowie(const char* nazwa) {
    strukturaCzlonkowie struktura;
    ofstream plik(nazwa, ios::app);
    string linia;
    if (!plik.is_open()) {
        cout << "Nie mozna otworzyc pliku" << endl;
    } else {
        for (int i = 0; i < struktura.ID.size(); i++) {
            linia += struktura.ID[i] + ";";
            linia += struktura.imie[i] + ";";
            linia += struktura.nazwisko[i] + ";";
            linia += odczytajWektor(struktura.przypisaneZadania[i], *",") + ";";
            linia += odczytajWektor(struktura.historiaZadan[i], *",") + "\n";
            plik << linia;
            linia = "";
        }
    }
}

void dodajCzlonka() {
    int ID;
    cout << "Podaj ID czlonka:";
    cin >> ID;
}

void usunCzlonka() {

}

void raportCzlonkowie() {

}

void edytujCzlonka() {

}