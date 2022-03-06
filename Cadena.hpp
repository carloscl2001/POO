#ifndef CADENA_HPP_
#define CADENA_HPP_


class Cadena
{
    public://=>métodos
        
        //CONSTRUCTORES
        explicit Cadena(size_t s = 0, char c = ' ');
        Cadena(const Cadena& cadena);


        //OBSERVADOR
        inline size_t length() const {return tam_;}

        //OPERADORES

    private://=>atribitos

        char *s_;
        size_t tam_;

        //FUNCIONES PRIVADAS AUXILIARES
};

#endif