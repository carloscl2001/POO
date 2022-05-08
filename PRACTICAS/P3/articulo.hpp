#ifndef ARTICULO_HPP
#define ARTICULO_HPP

#include "../P1/cadena.hpp"
#include "../P1/fecha.hpp"
#include <iostream>
//
// ------------| CLASE ARTICULO |------------|
//
class Articulo
{
    public:

        //CONSTRUCTOR
        Articulo(Cadena r, Cadena t, Fecha f, double p, int e = 0);
        
        //OBSERAVORES
        Cadena referencia() const {return cod_referencia_;}
        Cadena titulo() const {return titulo_; }
        Fecha f_publi() const {return fecha_publi_;}
        double precio() const {return precio_;}
        double& precio() {return precio_;}
        unsigned stock() const {return stock_;}
        unsigned& stock() {return stock_;}

    private:
        Cadena cod_referencia_;
        Cadena titulo_;
        Fecha fecha_publi_;
        double precio_;
        unsigned stock_;

};
//OPERADOR DE INSERCION DE FLUJO
std::ostream& operator <<(std::ostream& os, const Articulo& art);

#endif