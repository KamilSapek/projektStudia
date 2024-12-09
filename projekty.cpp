#include "projekty.h"

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

vector<int> utworzWektorP(string dane, char rozdzielnik) {
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

string odczytajWektorP(vector<int> wektor, const char rozdzielnik) {
    string zwrot;
    for (int i = 0; i < wektor.size(); i++) {
        zwrot += to_string(wektor.at(i)) + rozdzielnik;
    }
    zwrot.pop_back();
    return zwrot;
}

void odczytajProjekty(const char* nazwa, vector<strukturaProjekty>& struktura) {
    cout << nazwa << endl;
    ifstream plik(nazwa);
    if (!plik.is_open()) {
        cout << "Nie mozna otworzyc pliku" << endl;
    } else {
        strukturaProjekty strukt;
        int licznik;
        string linia, test;
        while (getline(plik, linia)) {
            linia += ';';
            licznik = 0;
            for (int i = 0; i < linia.length(); i++) {
                if (linia.at(i) == ';') {
                    switch (licznik) {
                        case 0: strukt.nazwa = test;
                        break;
                        case 1: strukt.opis = test;
                        break;
                        case 2: strukt.dataRozpoczecia.push_back(stoi(test));
                        break;
                        case 3: strukt.dataZakonczenia.push_back(stoi(test));
                        break;
                        case 4: strukt.status = test;
                        break;
                        case 5: strukt.listaZadan.push_back(stoi(test));
                    }
                    test = "";
                    licznik++;
                } else {
                    test += linia.at(i);
                }
            }
            struktura.push_back(strukt);
        }
    }
}

void zapiszProjekty(const char* nazwa, vector<strukturaProjekty>& struktura) {
    ofstream plik(nazwa, ios::app);
    if (!plik.is_open()) {
        cout << "Nie mozna otworzyc pliku" << endl;
    } else {
        string linia;
        for (auto i : struktura) {
            linia += i.nazwa + ";";
            linia += i.opis + ";";
            linia += odczytajWektorP(i.dataRozpoczecia, *".") + ";";
            linia += odczytajWektorP(i.dataZakonczenia, *".") + ";";
            linia += odczytajWektorP(i.listaZadan, *",") + ";";
            plik << linia << endl;;
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
