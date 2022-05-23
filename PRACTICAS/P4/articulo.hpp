#ifndef ARTICULO_HPP
#define ARTICULO_HPP

#include "../P1/cadena.hpp"
#include "../P1/fecha.hpp"
#include <iostream>
#include <set>

class Autor;
//
// ------------| CLASE ARTICULO |------------|
//
class Articulo
{
    public:

        //SET DE AUTORES
        typedef std::set<Autores*> Autores;
        
        //CONSTRUCTOR
        Articulo(const Autores& a, const Cadena& r, const Cadena& t, Fecha f, double p, int s = 0);
        
        //OBSERAVORES
        const Cadena& referencia() const noexcept{return cod_referencia_;}
        const Cadena& titulo() const noexcept{return titulo_; }
        const Fecha& f_publi() const noexcept{return fecha_publi_;}
        double precio() const noexcept{return precio_;}
        double& precio() {return precio_;}

        const Autores& autores() const noexcept {return autor_;}
        

        virtual void impresion_especifica(ostrea& os);

        //CLASE DE EXCEPCION
        class Autores_vacios{};


    private:
        Autores autor_;
        Cadena cod_referencia_;
        Cadena titulo_;
        Fecha fecha_publi_;
        double precio_;
        

};


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
};

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