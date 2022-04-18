#include <random>
#include <ctime>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <unistd.h>
#include "usuario.hpp"


Clave::Clave(const char* cadena)
{
    if(strlen(cadena) < 5)
    {
        throw Incorrecta(Razon::CORTA);
    }

    const char* crypto = "zyxwvutsrqponmlkjihgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA9876543210/.";
    char* cifrar = new char [2];
    char* encry;

    cifrar[0] = crypto[rand() % 64];
    cifrar[1] = crypto[rand() % 64];

    encry = crypt(cadena, cifrar);

    if( encry == NULL)
    {
        throw Incorrecta(Razon::ERROR_CRYPT);
    }

    contrasena_ = crypt(cadena, cifrar);
}

bool Clave::verifica(const char* cad) const
{
    if(strcmp(crypt(cadena, contrasena_.c_str()), contrasena_.c_str()) == 0)
    {
        return true;
    }
    else{
        return false;
    }
}

