//  /-------------------------------\
//  |                               |
//  |   CARLOS ANTONIO CORTÉS LORA  |
//  |                               |
//  \-------------------------------/


#ifndef CADENA_HPP_
#define CADENA_HPP_
#include <iterator>


class Cadena
{
    public://=>métodos
        
        //CONSTRUCTORES
        explicit Cadena(size_t s = 0, char c = ' ');
        Cadena(const Cadena& cadena);
        Cadena(const char* cadena);
        Cadena(Cadena&& cadena);


        //OBSERVADOR
        size_t length() const noexcept {return tam_;}
        const char* c_str() const {return s_;}


        //METODO DE CONVERSION / ANTIGUO OPERADOR DE CONVERSION
        char* c_str() {return s_;}
        
        //OPERADORES
        Cadena& operator +=(const Cadena& cadena);
        Cadena& operator =(const Cadena& cadena);
        Cadena& operator =(Cadena&& cadena);

        char& operator[](size_t i) const{ return s_[i];};
        char& operator[](size_t i){ return s_[i];};

        char& at(size_t i) const;
        char& at(size_t i);

        Cadena substr(size_t i, size_t t) const;

        ~Cadena();


        //ITERADORES
        typedef char* iterator;
        typedef const char* const_iterator;

        typedef std::reverse_iterator<iterator> reverse_iterator;
        typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

        iterator begin() {return s_;}
        iterator begin() const {return s_;}

        iterator end() {return s_ + tam_;}
        iterator end() const {return s_ + tam_;}

        const_iterator cbegin() {return const_iterator(begin());}
        const_iterator cbegin() const {return const_iterator(begin());}

        const_iterator cend() {return const_iterator(end());}
        const_iterator cend() const{return const_iterator(end());}

        reverse_iterator rbegin() noexcept {return reverse_iterator(end());}
        reverse_iterator rbegin() const noexcept{return reverse_iterator(end());}
        
        reverse_iterator rend() noexcept{return reverse_iterator(begin());}
        reverse_iterator rend() const noexcept{return reverse_iterator(begin());}

        const_reverse_iterator crbegin() const {return const_reverse_iterator(rbegin());}

        const_reverse_iterator crend() const {return const_reverse_iterator(rend());}




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
std::ostream& operator <<(std::ostream& os, const Cadena& cadena) noexcept;
std::istream& operator >>(std::istream& is, Cadena& cad);

namespace std{// Estaremos dentro del espacio de nombres std
template<>// Es una especialización de una plantilla para Cadena
struct hash<Cadena> 
{// Es una clase con solo un operador publico
    size_t operator() (const Cadena& cad)const// El operador función
    {
        hash<string> hs;// Creamos un objeto hash de string
        const char*p = cad.c_str();// Obtenemos la cadena de la Cadena
        string  s(p);// Creamos un string desde una cadena
        size_t  res=hs(s);// El hash del string. Como hs.operator()(s);
        return res;// Devolvemos el hash del string
        }
    };
}

#endif
