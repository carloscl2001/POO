#ifndef CADENA_HPP_
#define CADENA_HPP_


class Cadena
{
    public://=>métodos
        
        //CONSTRUCTORES
        explicit Cadena(size_t s = 0, char c = ' ');
        Cadena(const Cadena& cadena);
        Cadena(const char* cadena);
        //Cadena(Cadena&& cadena);


        //OBSERVADOR
        inline size_t length() const noexcept {return tam_;}


        //OPERADOR DE CONVERSION
        char* c_str() const;
        
        //OPERADORES
        Cadena& operator +=(const Cadena& cadena);
        Cadena& operator =(const Cadena& cadena);

        inline char& operator[](size_t i) const{ return s_[i];};
        inline char& operator[](size_t i) const{ return s_[i];};

        char& at (size_t i) const;
        char& at (size_t i);

        Cadena& substr(size_t i, size_t t);

    private://=>atribitos

        char *s_;
        size_t tam_;

        //FUNCIONES PRIVADAS AUXILIARES
        void copiar(const Cadena& cadena);
};

bool operator <(const Cadena& cadena1, const Cadena& cadena2);
bool operator <=(const Cadena& cadena1, const Cadena& cadena2);
bool operator ==(const Cadena& cadena1, const Cadena& cadena2);
bool operator >(const Cadena& cadena1, const Cadena& cadena2);
bool operator >=(const Cadena& cadena1, const Cadena& cadena2);
bool operator !=(const Cadena& cadena1, const Cadena& cadena2);

Cadena operator + (const Cadena& cadena1, const Cadena& cadena2);
#endif
