#ifndef PROJEKTY_H
#define PROJEKTY_H
#include <string>
#include <vector>

struct strukturaProjekty {
    std::pmr::string nazwa, opis, status;
    std::vector<int> listaZadan, dataRozpoczecia, dataZakonczenia;
};

void dodajProjekt();
void usunProjekt();
void raport();
void odczytajProjekty(const char* nazwa, std::vector<strukturaProjekty>& struktura);
void zapiszProjekty(const char* nazwa, std::vector<strukturaProjekty>& struktura);



#endif //PROJEKTY_H
