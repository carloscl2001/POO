#ifndef USARIO_HPP
#define USUARIO_HPP

#include "../P1/cadena.hpp"
#include "tarjeta.hpp"
#include "articulo.hpp"
#include <map>
#include <unordered_map>
#include <unordered_set>
//
//
    //CLASE CLAVE
//
//

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
//
//
    //CLASE USUARIO
//
//

class Numero;
class Tarjeta;
class Usuario 
{
    public:
        //CONTENEDORES
        typedef std::unordered_set<Cadena> Usuarios;
        typedef std::map<Numero, Tarjeta*> Tarjetas;
        typedef std::unordered_map<Articulo*, unsigned > Articulos;

        Usuario(const Cadena i, const Cadena n, const Cadena a, const Cadena d, const Clave c, const Tarjetas t, const Articulos at);

        //OBSERVADORES
        Cadena id() const{return identificador_;}
        Cadena nombre() const{return nombre_;}
        Cadena apellidos() const{return apellidos_;}
        Cadena direccion() const{return dirreccion_;}

        Tarjetas tarjetas() const{return tarjetas_;}
        Articulos compra() const{return articulos_;}

        //ENLACE
        void es_titular_de(Tarjeta& t);
        void no_es_titular_de(Tarjeta& t);

        void compra(const Articulo& art, unsigned c = 1);

        int n_articulos() const;

        class Id_duplicado
        {
        public:
            Id_duplicado(const Cadena& i): id_(i){}
            const Cadena idd() const {return id_;};
        private:
            Cadena id_;
        };

    private:
        Cadena identificador_;
        Cadena nombre_;
        Cadena apellidos_;
        Cadena dirreccion_;

        Clave contrasena_;

        Tarjetas tarjetas_;

        Articulos articulos_;

        static Usuarios usuario_;
};



#endif