#ifndef CADENA_HPP_
#define CADENA_HPP_


class Cadena
{
    public://=>métodos
        
        //CONSTRUCTORES
        explicit Cadena(size_t s = 0, char c = ' ');
        Cadena(const Cadena& cadena);
        Cadena(const char* cadena);
        Cadena(Cadena&& cadena);


        //OBSERVADOR
        inline size_t length() const noexcept {return tam_;}


        //OPERADOR DE CONVERSION
        char* c_str() const;
        
        //OPERADORES
        Cadena& operator +=(const Cadena& cadena);

    private://=>atribitos

        char *s_;
        size_t tam_;

        //FUNCIONES PRIVADAS AUXILIARES
};

bool operator <(const Cadena& cadena1, const Cadena& cadena2);
bool operator <=(const Cadena& cadena1, const Cadena& cadena2);
bool operator ==(const Cadena& cadena1, const Cadena& cadena2);
bool operator >(const Cadena& cadena1, const Cadena& cadena2);
bool operator >=(const Cadena& cadena1, const Cadena& cadena2);
bool operator !=(const Cadena& cadena1, const Cadena& cadena2);

#endif
