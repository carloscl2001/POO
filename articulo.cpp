#include "articulo.hpp"
#include <iostream>

Articulo::Articulo(Cadena r, Cadena t, Fecha f, double p, int e): cod_referencia_(r), titulo_(t), fecha_publi_(f), precio_(p), n_ejem_vent_(e){}

std::ostream& operator<< (std::ostream os,const Articulo& art)
{
    os <<"["<<art.referencia()<<"]"<<" "<<"\""<<art.titulo()<<"\""<<","<<" "<<art.f_publi()<<"."<<" "<<art.precio()<<" "<<"€";
    return os;
}