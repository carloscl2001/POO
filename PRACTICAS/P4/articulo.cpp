#include "articulo.hpp"
#include <iostream>

//
// ------------| CLASE ARTICULO |------------|
//

//CONSTRUCTOR 
Articulo::Articulo(const Autores& a, const Cadena& r, const Cadena& t, Fecha f, double p, int e): cod_referencia_(r), titulo_(t), fecha_publi_(f), precio_(p), stock_(s)
{
    if(au)
}

//OPERADOR DE INSERCION DE FLUJO
std::ostream& operator<< (std::ostream& os, const Articulo& art)
{
    os <<"["<< art.referencia() << "] \""<< art.titulo() << ","<<art.f_publi()<<"."<< art.precio() <<"€";
    return os;
}