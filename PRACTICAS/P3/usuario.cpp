#include <random>
#include <ctime>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <unistd.h>
#include "usuario.hpp"


//
// ------------| CLASE CLAVE |------------|
//

//CONSTRUCTOR
Clave::Clave(const char* c)
{
    const char* crypto = "zyxwvutsrqponmlkjihgfedcbaZYXWVUTSRQPONMLKJIHGFEDCBA9876543210/.";
    char* cifrar = new char [2];

    if(strlen(c) < 5)
    {
        throw Incorrecta(Razon::CORTA);
    }

    cifrar[0] = crypto[rand() % 64];
    cifrar[1] = crypto[rand() % 64];

    if(crypt(c,cifrar) == NULL)
    {
        throw Incorrecta(Razon::ERROR_CRYPT);
    }

    contrasena_ = crypt(c,cifrar);
}

//COMPROBAR CONTRASEÑA
bool Clave::verifica(const char* c) const
{
    return std::strcmp(crypt(c, contrasena_.c_str()), contrasena_.c_str()) == 0;
}


//
// ------------| CLASE USUARIO |------------|
//

Usuario::Usuarios Usuario::usuario_;

//CONSTRUCTOR
Usuario::Usuario(const Cadena &i, const Cadena &n, const Cadena &a, const Cadena &d, const Clave &c):
identificador_(i), nombre_(n), apellidos_(a), direccion_(d), contrasena_(c)
{
    if(!usuario_.insert(i).second)
    {
        throw Id_duplicado(identificador_);
    }
}

//COMPRA
void Usuario::compra(Articulo &a, unsigned cant)
{
    if(cant != 0)
    {
        articulos_[&a] = cant;
    }else{
        articulos_.erase(&a);
    }
}

//ENLACE CON TARJETA
void Usuario::es_titular_de(Tarjeta& t)
{
    if(this == t.titular())
    {
        tarjetas_.insert(std::make_pair(t.numero(), &t));
    }
}

//DESENLACE CON TARJETA
void Usuario::no_es_titular_de(Tarjeta& t)
{
    t.anula_titular();
    tarjetas_.erase(t.numero());
}

//DESTRUCTOR
Usuario::~Usuario()
{
    for(auto i = tarjetas_.begin(); i != tarjetas_.end(); i++)
    {
        i->second->anula_titular();
    }

    usuario_.erase(identificador_);
}

//FUNCION MOSTRAR CARRO
std::ostream& mostrar_carro(std::ostream& os, const Usuario& u)
{
    os << "Carrito de compra de " << u.id() << " [Artículos: "<< u.n_articulos() << "]" << "\n"
       << "Cant.Artículo"<< std::endl
       << "======================================";

    int n_art = u.n_articulos() ;

    while( n_art > 0 )
    {
        for(auto i = u.compra().begin(); i != u.compra().end(); i++)
        {
            os << std::setw(4) << i->second << "    "
                   << " [" << (*i->first).referencia() << "] " << "\""
                   << (*i->first).titulo() << "\", "
                   << (*i->first).f_publi().anno()
                   << ". " << std::fixed << std::setprecision(2) << (*i->first).precio() << " €" << std::endl;

            --n_art;
        }
    }

    return os;
}

//OPERADOR DE INSERCCION DE FLUJO
std::ostream& operator <<(std::ostream& os, const Usuario& u)
{
    os << u.identificador_ << "[" << u.contrasena_.clave().c_str() << "]" << u.nombre_ << u.apellidos_ << "\n"
       << u.direccion_ << std::endl;
    os <<"Tarjetas:" ;
    for(auto i = u.tarjetas().begin(); i != u.tarjetas().end(); i++)
    {
        os << *i->second << std::endl ;
    }

    return os ;
}
