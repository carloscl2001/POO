#include "tarjeta.hpp"
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>

bool luhn(const Cadena& num);

//
//
    //CLASE NUMERO
//
//

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
//
//
    //CLASE TARJETA
//
//
Tarjeta::Tarjeta(const Numero& n, Usuario& u, const Fecha& f): numero_(n), usuario_(&u), fech_caducidad(f)
{
    if(fech_caducidad < Fecha())
    {
        throw Caducada(fech_caducidad);
    }

    const char* aux = n;

    switch(aux[0]){
        case '4':
            tipo_ = Tipo::VISA;
            break;
        case '5':
            tipo_ = MasterCard;
            break;
        case '6':
            tipo_ = Maestro;
            break;
        case '3':
            if(aux[1] == 4 || aux[1] == 7)
            {
                tipo_ = AmericanExpress;
            }
            else{
                tipo_ = JCB;
            }
            break;
        default:
            tipo_ = Otro;
            break;
    }

    actividad_ = true;

    u.es_titular_de(*this);
}

bool Tarjeta::activa(bool b)
{
    actividad_ = b;
    return actividad_;
}

void Tarjeta::anular_titular()
{
    usuario_ = nullptr;
    actividad_ = false;
}

Tarjeta::~Tarjeta()
{
    usuario_->no_es_titular_de(*this);
}

bool operator <(const Tarjeta& t1, const Tarjeta& t2)
{
    if(t1.numero() < t2.numero())
    {
        return true;
    }
    else{return false;}
}