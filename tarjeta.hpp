#include "cadena.hpp"
#include <iostream>

class Numero
{
    public:
        Numero(Cadena cadena);

        operator char*();
        

    private:
        Cadena n_troquelado;
        bool luhn(Cadena cadena);
};