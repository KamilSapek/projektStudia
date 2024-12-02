#include <iostream>
#include <cstring>

#include "zadania.h"
using namespace std;

int znajdzWartoscParametru(int argc, char* argv[], const char* param) {
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], param) == 0) {
            return i + 1;
        }
    }
    return -1;
}

int main(int argc, char* argv[]) {
    if (argc == 0) {
        cout << "Do poprawnego korzystania z programu, musisz uzyc parametrow.\n"
                "-p [nazwa pliku z danymi do projektow]\n"
                "-z [nazwa pliku z danymi do zadan]\n"
                "-c [nazwa pliku z danymi do czlonkow]" << endl;
    } else if (argc < 3) {
        cout << "Nie podales jakiegos parametru" << endl;
    } else {
        odczytajZadania("..\\informacje\\zadania.txt");
    }
    return 0;
}