#ifndef ARTICULO_HPP
#define ARTICULO_HPP

#include "../P1/cadena.hpp"
#include "../P1/fecha.hpp"
#include <iostream>
#include <set>
//
// ------------| CLASE ARTICULO |------------|
//
class Articulo
{
    public:

        //CONSTRUCTOR
        Articulo(const Autores& a, const Cadena& r, const Cadena& t, Fecha f, double p, int s = 0);
        
        //OBSERAVORES
        Cadena referencia() const {return cod_referencia_;}
        Cadena titulo() const {return titulo_; }
        Fecha f_publi() const {return fecha_publi_;}
        double precio() const {return precio_;}
        double& precio() {return precio_;}
        unsigned stock() const {return stock_;}
        unsigned& stock() {return stock_;}

        virtual void impresion_especifica(ostrea& os)

        class Autores_vacios{};

        typedef std::set<Autores*> Autores;

    private:
        Cadena cod_referencia_;
        Cadena titulo_;
        Fecha fecha_publi_;
        double precio_;
        unsigned stock_;

};
//OPERADOR DE INSERCION DE FLUJO
std::ostream& operator <<(std::ostream& os, const Articulo& art);



//
// ------------| CLASE ARTICULOALMACENABLE |------------|
//
class ArticuloAlmacenable: public Articulo{
    public:
        Articulo(Cadena r, Cadena t, Fecha f, double p, int s = 0)

        unsigned stock() const;
        void stock();
        
    private:
}


//
// ------------| CLASE LIBRO |------------|
//
class Libro: public ArticuloAlmacenable {
    public:

    private:
}

//
// ------------| CLASE CEDERRON |------------|
//

class Cederron: public ArticuloAlmacenable {
    public:

    private:
};

//
// ------------| CLASE LIBRODIGITAL |------------|
//
class LibroDigital: public LibroDigital {
    public:

    private:
};

//
// ------------| CLASE AUTOR |------------|
//
class Autor{
    public:
        
        //CONSTRUCTOR
        Autor(const Cadena& n, const Cadena& a, const Cadena& d);

        //OBSERAVORES
        const Cadena& nombre() const noexcept {return nombre_;}
        const Cadena& apellidos() const noexcept {return apellidos_;}
        const Cadena& direccion() const noexcept {return direccion_;}

    private:
        
        Cadena nombre_;
        Cadena apellidos_;
        Cadena direccion_;
};

#endif