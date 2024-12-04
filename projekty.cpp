#include "projekty.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct strukturaProjekty {
    vector<string> nazwa, opis, status;
    vector<int> listaZadan;
    vector<vector<int>> dataRozpoczecia, dataZakonczenia;
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
    strukturaProjekty struktura;
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
                        case 0: struktura.nazwa.push_back(test);
                        break;
                        case 1: struktura.opis.push_back(test);
                        break;
                        case 2: struktura.dataRozpoczecia.push_back(utworzWektor(test, *"."));
                        break;
                        case 3: struktura.dataZakonczenia.push_back(utworzWektor(test, '.'));
                        break;
                        case 4: struktura.status.push_back(test);
                        break;
                        case 5: struktura.listaZadan.push_back(stoi(test));
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
    strukturaProjekty struktura;
    ofstream plik(nazwa, ios::app);
    string linia;
    if (!plik.is_open()) {
        cout << "Nie mozna otworzyc pliku" << endl;
    } else {
        for (int i = 0; i < struktura.nazwa.size(); i++) {
            linia += struktura.nazwa[i] + ";";
            linia += struktura.opis[i] + ";";
            linia += odczytajWektor(struktura.dataRozpoczecia[i], *".") + ";";
            linia += odczytajWektor(struktura.dataZakonczenia[i], *".") + "\n";
            linia += struktura.listaZadan[i] + ";";
            plik << linia;
            linia = "";
        }
    }
}

void dodajProjekt() {

}

void usunProjekt() {

}

void raport() {

}
