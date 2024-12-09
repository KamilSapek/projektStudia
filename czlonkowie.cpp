#include "czlonkowie.h"
#include "wspolneFunkcje.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

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
                        case 3: strukt.przypisaneZadania = utworzWektor(test, ',');
                        break;
                        case 4: strukt.historiaZadan = utworzWektor(test, ',');
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
            linia += odczytajWektor(i.przypisaneZadania, *",") + ";";
            linia += odczytajWektor(i.historiaZadan, *",") + "\n";
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