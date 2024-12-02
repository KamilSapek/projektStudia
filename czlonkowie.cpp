#include "czlonkowie.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct czlonkowie {
    vector<int> ID_czlonka;
    vector<string> imie, nazwisko, przypisaneZadania, historiaZadan;
};

void dodajCzlonka() {
    int ID;
    cout << "Podaj ID czlonka:";
    cin >> ID;
    czlonkowie().ID_czlonka.emplace_back();
}

void usunCzlonka() {

}

void raportCzlonkowie() {

}

void edytujCzlonka() {

}