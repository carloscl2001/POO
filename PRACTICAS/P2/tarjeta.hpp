#include "cadena.hpp"
#include <iostream>

class Numero
{
    public:
        Numero(Cadena cadena);


        enum Razon {LONGITUD, NO_VALIDO, DIGITOS};


        operator const char*() const;

        class Incorrecto
        {
            public:
                Incorrecto(Razon r): fallo_(r) {}
                const Razon razon() const {return fallo_;}
            private:
                Razon fallo_;
        };

    private:
        Cadena num_;
        bool luhn(Cadena cadena);
};