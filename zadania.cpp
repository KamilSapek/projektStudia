#include "zadania.h"
#include "wpsolneFunkcje.h"

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

using namespace std;

void odczytajZadania(const char* nazwa, vector<strukturaZadania>& struktura) {
    cout << nazwa << endl;
    ifstream plik(nazwa);
    if (!plik.is_open()) {
        cout << "Nie mozna otworzyc pliku" << endl;
    } else {
        strukturaZadania strukt;
        int licznik;
        string linia, test;
        while (getline(plik, linia)) {
            linia += ';';
            licznik = 0;
            for (int i = 0; i < linia.length(); i++) {
                if (linia.at(i) == ';') {
                    switch (licznik) {
                        case 0: strukt.ID = stoi(test);
                        break;
                        case 1: strukt.nazwa = test;
                        break;
                        case 2: strukt.opis = test;
                        break;
                        case 3: strukt.priorytet = test;
                        break;
                        case 4: strukt.przypisaneOsoby = utworzWektor(test, *",");
                        break;
                        case 5: strukt.dataRozpoczecia = utworzWektor(test, *".");
                        break;
                        case 6: strukt.przewidywanyKoniec = utworzWektor(test, *".");
                        break;
                        case 7: strukt.status = test;
                        break;
                        case 8: strukt.zaleznosci = utworzWektor(test, *",");
                        break;
                        case 9: strukt.procentRealizacji = stoi(test);
                        break;
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
    for (auto i : struktura)
        cout << i.opis << endl;
}

void zapiszZadania(const char* nazwa, vector<strukturaZadania>& struktura) {
    ofstream plik(nazwa, std::ios::in | std::ios::out | ios::app);
    if (!plik.is_open()) {
        cout << "Nie mozna otworzyc pliku" << endl;
    } else {
        string linia;
        for (auto i : struktura) {
            i.opis = "a jednak jest to polska";
            linia += to_string(i.ID) + ";";
            linia += i.nazwa + ";";
            linia += i.opis + ";";
            linia += i.priorytet + ";";
            linia += odczytajWektor(i.przypisaneOsoby, *",") + ";";
            linia += odczytajWektor(i.dataRozpoczecia, *".") + ";";
            linia += odczytajWektor(i.przewidywanyKoniec, *".") + ";";
            linia += i.status + ";";
            linia += odczytajWektor(i.zaleznosci, *",") + ";";
            linia += to_string(i.procentRealizacji);
            plik << linia << endl;
            linia = "";
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
