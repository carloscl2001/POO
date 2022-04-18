#ifndef USARIO_HPP
#define USUARIO_HPP

#include "../P1/cadena.hpp"
#include "tarjeta.hpp"
#include "articulo.hpp"
#include <map>
#include <unordered_map>


class Clave
{
    public:
        enum Razon {CORTA,ERROR_CRYPT};

        bool verifica(const char* cad) const;

        Cadena clave()const {return contrasena_;}

        Clave(const char* cadena);

        class Incorrecta
        {
            public:
                Incorrecta(const Razon r): r_(r) {};
                Razon clave()const{return r_;}
            private:
                Razon r_;
        };
    private:
        Cadena contrasena_;
};

class Usuario 
{
    public:
        typedef std::map<Numero, Tarjeta*> Tarjetas;
        typedef std::unordered_map<Articulo*, unsigned > Articulos;
    
    private:
        Cadena identificador_;
        Cadena nombre_;
        Cadena apellidos_;
        Cadena dirreccion_;

        Clave contrasena_;

        Tarjetas tarjetas_;

        Articulos articulos_;
};



#endif