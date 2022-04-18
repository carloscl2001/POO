#include "../P1/cadena.hpp"
#include <iostream>
#include 

bool luhn(Cadena cadena);


class Numero
{
    public:

        enum Razon {LONGITUD, NO_VALIDO, DIGITOS};
        
        Numero(const Cadena& cadena);

        operator const char*() const;

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
        
};

