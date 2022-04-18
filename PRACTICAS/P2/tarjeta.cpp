#include "tarjeta.hpp"
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>

bool luhn(const Cadena& num);

//CONSTRUCTOR
Numero::Numero(const Cadena& cad):num_(longitud_cadena(cad))
{
    for(int i = 0; i < cad.length(); ++i)
    {
        if(! isdigit(cad[i]))
        {
            throw Incorrecto(Razon::DIGITOS);
        }
    }
    if(!luhn(num_))
    {
        throw Incorrecto(Razon::NO_VALIDO);
    }
}

//FUNCIONES AUXILIARES
Cadena Numero::elimina_espacios(const Cadena& cad)
{
    Cadena aux (cad) ;

    std::remove_if(aux.begin(),aux.end()+1,[](char c){return isspace(c);});

    return Cadena(aux.c_str());
}

Cadena Numero::longitud_cadena(const Cadena& cad)
{
    Cadena aux = elimina_espacios(cad);

    if(aux.length() > 19 || aux.length() == 0 || aux.length() < 13 )
    {
        throw Incorrecto(Razon::LONGITUD);
    }
    return aux;
}

//OPARADOR DE COMPARACION
bool operator <(const Numero& n1, const Numero& n2)
{
    return strcmp(n1,n2) < 0;
}