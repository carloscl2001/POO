#include <random>
#include <ctime>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <unistd.h>
#include "usuario.hpp"
//
//
    //CLASE CLAVE
//
//

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

//
//
    //CLASE USUARIO
//
//

Usuario::Usuario(const Cadena i, const Cadena n, const Cadena a, const Cadena d, const Clave c, const Tarjetas t, const Articulos at):identificador_(i), nombre_(n), apellidos_(a), dirreccion_(d), contrasena_(c), tarjetas_(t), articulos_(at)
{
    if(!usuario_.insert(identificador_).second)
    {
        throw Id_duplicado(identificador_);
    }
}

void Usuario::es_titular_de(Tarjeta& t)
{
    if(this == t.titular())
    {
        tarjetas_.insert(std::make_pair(t.numero(), &t));
    }
}

void Usuario::no_es_titular_de(Tarjeta& t)
{
    t.anular_titular();
    tarjetas_.erase(t.numero());
}

std::ostream& mostrar_carro(std::ostream& output, const Usuario& u)
{
    output << "Carrito de compra de " << u.id() << " [ArtÃ­culos: "<< u.n_articulos() << "]" << "\n"
       << "Cant.ArtÃ­culo"<< std::endl
       << std::setw(95) << std::setfill('=') << '\n' << std::setfill(' ');

    int nart = u.n_articulos() ;

    while( nart > 0 )
    {
        for(auto i = u.compra().begin(); i != u.compra().end(); i++)
        {
            output << std::setw(4) << i->second << "    "
                   << " [" << (*i->first).referencia() << "] " << "\""
                   << (*i->first).titulo() << "\", "
                   << (*i->first).f_publi().anno()
                   << ". " << std::fixed << std::setprecision(2) << (*i->first).precio() << " â‚¬" << std::endl;

            --nart;
        }
    }

    return output;
}

std::ostream& operator <<(std::ostream& output, const Usuario& u)
{
    output << u.id()<< "[" << u.password_() << "]" << u.nombre() << u.apellidos() << "\n"
       << u.direccion() << std::endl;
    output <<"Tarjetas:" ;
    for(auto i = u.tarjetas().begin(); i != u.tarjetas().end(); i++)
    {
        output << *i->second << std::endl ;
    }

    return output ;
}