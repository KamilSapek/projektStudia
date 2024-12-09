#include "czlonkowie.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

vector<int> utworzWektorC(string dane, char rozdzielnik) {
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

string odczytajWektorC(vector<int> wektor, const char rozdzielnik) {
    string zwrot;
    for (int i = 0; i < wektor.size(); i++) {
        zwrot += to_string(wektor.at(i)) + rozdzielnik;
    }
    zwrot.pop_back();
    return zwrot;
}

void odczytajCzlonkowie(const char* nazwa, vector<strukturaCzlonkowie>& struktura) {
    cout << nazwa << endl;
    ifstream plik(nazwa);
    if (!plik.is_open()) {
        cout << "Nie mozna otworzyc pliku" << endl;
    } else {
        strukturaCzlonkowie strukt;
        int licznik, numerLinii;
        string linia, test;
        numerLinii = 0;
        while (getline(plik, linia)) {
            linia += ';';
            licznik = 0;
            for (int i = 0; i < linia.length(); i++) {
                if (linia.at(i) == ';') {
                    switch (licznik) {
                        case 0: strukt.ID = stoi(test);
                        break;
                        case 1: strukt.imie = test;
                        break;
                        case 2: strukt.nazwisko = test;
                        break;
                        case 3: strukt.przypisaneZadania = utworzWektorC(test, ',');
                        break;
                        case 4: strukt.historiaZadan = utworzWektorC(test, ',');
                        break;
                    }
                    test = "";
                    licznik++;
                } else {
                    test += linia.at(i);
                }
            }
            numerLinii++;
        }
        struktura.push_back(strukt);
    }
}

void zapiszCzlonkowie(const char* nazwa, vector<strukturaCzlonkowie>& struktura) {
    ofstream plik(nazwa, ios::app);
    if (!plik.is_open()) {
        cout << "Nie mozna otworzyc pliku" << endl;
    } else {
        string linia;
        for (auto i : struktura) {
            linia += to_string(i.ID) + ";";
            linia += i.imie + ";";
            linia += i.nazwisko + ";";
            linia += odczytajWektorC(i.przypisaneZadania, *",") + ";";
            linia += odczytajWektorC(i.historiaZadan, *",") + "\n";
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