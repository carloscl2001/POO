#ifndef CADENA_HPP_
#define CADENA_HPP_
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iterator>
#include <iomanip>


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
        inline const char* c_str() const {return s_;}


        //METODO DE CONVERSION / ANTIGUO OPERADOR DE CONVERSION
        char* c_str() {return s_;}
        
        //OPERADORES
        Cadena& operator +=(const Cadena& cadena);
        Cadena& operator =(const Cadena& cadena);
        Cadena& operator =(Cadena&& cadena);

        inline char& operator[](size_t i) const{ return s_[i];};
        inline char& operator[](size_t i){ return s_[i];};

        char& at(size_t i) const;
        char& at(size_t i);

        Cadena substr(size_t i, size_t t) const;


        //ITERADORES
        typedef char* iterator;
        typedef const char* const_iterator;

        typedef std::reverse_iterator<iterator> reverse_iterator;
        typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

        inline iterator begin() {return s_;}
        inline iterator begin() const {return s_;}

        inline iterator end() {return s_ + tam_;}
        inline iterator end() const {return s_ + tam_;}

        inline const_iterator cbegin() {return const_iterator(begin());}
        inline const_iterator cbegin() const {return const_iterator(begin());}

        inline const_iterator cend() {return const_iterator(end());}
        inline const_iterator cend() const{return const_iterator(end());}

        inline reverse_iterator rbegin() noexcept {return reverse_iterator(end());}
        inline reverse_iterator rbegin() const noexcept{return reverse_iterator(end());}
        
        inline reverse_iterator rend() noexcept{return reverse_iterator(begin());}
        inline reverse_iterator rend() const noexcept{return reverse_iterator(begin());}

        inline const_reverse_iterator crbegin() const {return const_reverse_iterator(rbegin());}

        inline const_reverse_iterator crend() const {return const_reverse_iterator(rend());}



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

//OPERADORES DE FLUJOS
std::ostream& operator <<(std::ostream& os, const Cadena& cadena);
std::istream& operator >>(std::istream& is, Cadena& cad);

#endif
