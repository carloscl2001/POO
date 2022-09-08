//  /-------------------------------\
//  |                               |
//  |   CARLOS ANTONIO CORTÉS LORA  |
//  |                               |
//  \-------------------------------/


#ifndef TARJETA_HPP
#define TARJETA_HPP

#include "../P1/cadena.hpp"
#include "../P1/fecha.hpp"
#include "usuario.hpp"
#include <ostream>
#include <set>




class Usuario;

//
// ------------| CLASE NUMERO |------------|
//

class Numero{
    public:
        
        //CONSTRUCTOR
        Numero(const Cadena& cadena);

        enum Razon {LONGITUD, NO_VALIDO, DIGITOS};        

        friend bool operator <(const Numero& x, const Numero& y);

        //OPERADOR DE CONVERSION
        operator const char*() const{return num_.c_str();}

        class Incorrecto{
        public:
            Incorrecto(Razon r): fallo_(r) {}
            const Razon& razon() const {return fallo_;};
        private:
            Razon fallo_;
        };

    private:
        Cadena num_;

        //FUNCION AUXILIAR
        Cadena elimina_espacio(const Cadena& cad);
};


//
// ------------| CLASE TARJETA |------------|
//

class Tarjeta{
    public:

        //SET DE NUMEROS EN TARJETA
        typedef std::set<Numero> Tarjetas;

        //RESTRICCION DE TARJETA
        Tarjeta& operator =(const Tarjeta& t) = delete;
        Tarjeta(const Tarjeta& t) = delete;

        //CONSTRUCTOR
        Tarjeta(const Numero& n, Usuario& user, const Fecha& f);
        
        enum Tipo {Otro, VISA, Mastercard, Maestro, JCB, AmericanExpress};

        //OBSERVADORES
        Tipo tipo() const noexcept{return tipo_;}
        Numero numero() const noexcept{return numero_;}
        const Usuario* titular() const noexcept{return usuario_;}
        Fecha caducidad() const noexcept{return f_caducidad_;}
        bool activa() const noexcept{return activa_;}

        //ACTIVAR O DESACTIVAR LA TARJETA
        bool activa(bool valor);

        //DESENLACE CON USUARIO
        void anula_titular();

        //DESTRUCTOR
        ~Tarjeta();

        class Caducada
        {
            public:
                Caducada(const Fecha& f):fc_(f){}
                Fecha cuando() const {return fc_;}
            private:
                Fecha fc_;
        };

        class Desactivada{};

        class Num_duplicado
        {
            public:
                Num_duplicado(const Numero& n): n_(n){}
                const Numero que() const {return n_;};
            private:
                Numero n_;
        };

    private:
        Tipo tipo_;
        Numero numero_;
        const Usuario* usuario_;
        Fecha f_caducidad_;
        bool activa_;

        static Tarjetas tarjetas_;
};

//OPERADORES DE FLUJO EXTERNOS Y OPERADOR < EXTERNO
bool operator <(const Tarjeta& t1, const Tarjeta& t2);
std::ostream& operator << (std::ostream& os, const Tarjeta::Tipo& t) noexcept;
std::ostream& operator << (std::ostream& os, const Tarjeta& t) noexcept;

#endif