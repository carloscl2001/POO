#include "cadena.hpp"
#include "fecha.hpp"
#include <iostream>

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
        int stock() const {return n_ejem_vent_;}
        int sstock() {return n_ejem_vent_;}

    private:
        Cadena cod_referencia_;
        Cadena titulo_;
        Fecha fecha_publi_;
        double precio_;
        int n_ejem_vent_;

};

std::ostream& operator <<(std::ostream os, const Articulo& art);