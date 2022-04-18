#ifndef TARJETA_HPP
#define TARJETA_HPP

#include "../P1/cadena.hpp"
#include "../P1/fecha.hpp"
#include "usuario.hpp"
#include <iostream>

//
//
    //CLASE NUMERO
//
//

class Numero
{
    public:

        enum Razon {LONGITUD, NO_VALIDO, DIGITOS};
        
        Numero(const Cadena& cadena);

        operator const char*() const{return num_.c_str();}

        class Incorrecto
        {
            public:
                Incorrecto(Razon r): r_(r) {}
                const Razon razon() const {return r_;}
            private:
                Razon r_;
        };

        friend bool operator <(const Numero& n1, const Numero& n2);

    private:
        Cadena num_;

        Cadena elimina_espacios(const Cadena& cad);
        Cadena longitud_cadena(const Cadena& cad);
        
};

//
//
    //CLASE TARJETA
//
//

class Tarjeta
{
    public:
        enum Tipo {Otro,Visa,MasterCard, Maestro, JCB, AmericanExpress};
    
    private:
        Tipo tipo_;
        Numero numero_;
        const Usuario* usuario;
        Fecha fech_caducidad;
        bool vacia();

};
#endif