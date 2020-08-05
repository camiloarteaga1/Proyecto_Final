#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;

class Archivos
{
public:
    Archivos();
    void borrar(string dir);

    void renome(string dirtemp, string dircamb);

    void escribir(string dir, string txt);

};

#endif // ARCHIVOS_H
