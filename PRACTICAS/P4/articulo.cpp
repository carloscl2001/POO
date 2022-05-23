#include "articulo.hpp"
#include <iostream>
#include <iomanip>

//
// ------------| CLASE ARTICULO |------------|
//

//CONSTRUCTOR 
Articulo::Articulo(const Autores& a, const Cadena& r, const Cadena& t, Fecha f, double p): cod_referencia_(r), titulo_(t), fecha_publi_(f), precio_(p)
{
    if(a.empty())
    {
        throw Autores_vacios();
    }
}

//OPERADOR DE INSERCION DE FLUJO
std::ostream& operator<< (std::ostream& os, const Articulo& art)
{
    os <<"["<< art.referencia() << "] \""<< art.titulo() << ","<<art.f_publi()<<"."<< art.precio() <<"€";
    return os;
}


//
// ------------| CLASE AUTOR |------------|
//
Autor::Autor(const Cadena& n, const Cadena& a, const Cadena& d): nombre_(n), apellidos_(a), direccion_(d) {}