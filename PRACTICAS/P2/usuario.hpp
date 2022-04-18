#ifndef USARIO_HPP
#define USUARIO_HPP

#include "../P1/cadena.hpp"


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




#endif