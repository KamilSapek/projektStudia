#ifndef ZADANIA_H
#define ZADANIA_H
#include <string>
#include <vector>
using namespace std;

struct strukturaZadania {
    int ID, procentRealizacji;
    string nazwa, opis, priorytet, status;
    vector<int> zaleznosci, przewidywanyKoniec, dataRozpoczecia, przypisaneOsoby;
};

void dodajZadanie();
void usunZadanie();
void raportZadanie();
void edytujZadanie();
void odczytajZadania(const char* nazwa, vector<strukturaZadania>& struktura);
void zapiszZadania(const char* nazwa, vector<strukturaZadania>& struktura);


#endif //ZADANIA_H
