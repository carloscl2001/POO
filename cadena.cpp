#include "cadena.hpp"
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

//=>CONSTRUCTORES
Cadena::Cadena(size_t t , char c): s_(new char[t + 1]), tam_(t)
{
    memset(s_, c, tam_);
    s_[ tam_ ] = '\0';
}

//=>CONSTRUCTOR DE COPIA
Cadena::Cadena(const Cadena& cadena): s_(new char[cadena.tam_ + 1]), tam_(cadena.tam_)
{
    strcpy(s_, cadena.s_);
}

//=>CONSTRUCTOR DE CADENA A BAJO NIVEL
Cadena::Cadena(const char* cadena): s_(new char[strlen(cadena)+ 1]), tam_(strlen(cadena))
{
    strcpy(s_, cadena);
}

//=>CONSTRUCTOR DE MOVIMIENTO
Cadena::Cadena(Cadena&& cadena)
{

}