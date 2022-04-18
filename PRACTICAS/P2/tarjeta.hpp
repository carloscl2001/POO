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
class Usuario;

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
        enum Tipo {Otro,VISA,MasterCard, Maestro, JCB, AmericanExpress};
        Tarjeta(const Numero& n, Usuario& u, const Fecha& f);
        
        //OBSERVADORES
        Numero numero() const{return numero_;}
        Usuario* titular() const {return usuario_;}
        Fecha caducidad() const{return fech_caducidad;}
        bool activa() const {return actividad_;}
        Tipo tipo() const{return tipo_;}

        bool activa(bool b = true);

        void anular_titular();
        
        class Caducada{
        public:
            Caducada(const Fecha& f):fc_(f){}
            Fecha cuando() const {return fc_;}
        private:
            Fecha fc_;
        };

        class Desactivada{};

        ~Tarjeta();
    
    private:
        Tipo tipo_;
        Numero numero_;
        mutable Usuario* usuario_;
        Fecha fech_caducidad;
        bool actividad_;

};

std::ostream& operator << (std::ostream& output, const Tarjeta::Tipo& t) ;
std::ostream& operator << (std::ostream& output, const Tarjeta& t) ;
bool operator <(const Tarjeta& t1, const Tarjeta& t2);
#endif