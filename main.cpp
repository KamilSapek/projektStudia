#include "interface.h"

#include <iostream>
#include <cstring>
#include <vector>


using namespace std;

/*funkcja ktora szuka parametru podanego w argumencie*/
int findParamValue(int argc, char *argv[], const char *param) {
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], param) == 0) {
            return i + 1;
        }
    }
    return -1;
}

int main(int argc, char *argv[]) {
    /*sprawdzanie parametrow*/
    if (argc == 0) {
        cout << "Do poprawnego korzystania z programu, musisz uzyc parametrow.\n"
                "-p [nazwa pliku z danymi do projektow]\n"
                "-z [nazwa pliku z danymi do zadan]\n"
                "-c [nazwa pliku z danymi do czlonkow]" << endl;
    } else if (argc < 3) {
        cout << "Nie podales jakiegos parametru" << endl;
    } else {
        /*glowna czesc programu*/
        mainMenu();
        return 0;
    }
}
