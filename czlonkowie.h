#ifndef CZLONKOWIE_H
#define CZLONKOWIE_H
#include <string>
#include <vector>

struct strukturaCzlonkowie {
    int ID;
    std::pmr::string imie, nazwisko;
    std::vector<int> przypisaneZadania, historiaZadan;
};

void dodajCzlonka();
void usunCzlonka();
void raportCzlonkowie();
void edytujCzlonka();
void zapiszCzlonkowie(const char* nazwa, std::pmr::vector<strukturaCzlonkowie>& struktura);
void odczytajCzlonkowie(const char* nazwa, std::pmr::vector<strukturaCzlonkowie>& struktura);



#endif //CZLONKOWIE_H
