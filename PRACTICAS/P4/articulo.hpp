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
        Articulo(const Autores& a, const Cadena& r, const Cadena& t, Fecha f, double p);
        
        //OBSERAVORES
        const Cadena& referencia() const noexcept{return cod_referencia_;}
        const Cadena& titulo() const noexcept{return titulo_; }
        const Fecha& f_publi() const noexcept{return fecha_publi_;}
        double precio() const noexcept{return precio_;}
        
        double& precio() {return precio_;}

        const Autores& autores() const noexcept {return autor_;}
        
        //METODOS VIRTUALES
        virtual ~Articulo() {}
        virtual void impresion_especifica(ostrea& os) const noexcept = 0;

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
        //CONSTRUCTOR
        ArticuloAlmacenable(const Autores& a, const Cadena& r, const Cadena& t, Fecha f, double p, unsigned s = 0);


        unsigned stock() const noexcept {return stock_;}
        unsigned& stock() const noexcept {return stock_;}
        
    private:
        unisgned stock_;
};


//
// ------------| CLASE LIBRO |------------|
//
class Libro: public ArticuloAlmacenable{
    public:
        Libro(const Autores& a, const Cadena& r, const Cadena& t, Fecha f, double p, unsigned p, unsigned s = 0): ArticuloAlmacenable(a, r, t, f, s), n_pag_(npag)
        unsigned tam_() const noexcept{return tam_;}
        void impresion_especifica(ostream& os) const noexcept;

    private:
        const unsigned n_pag_;
};

//
// ------------| CLASE CEDERRON |------------|
//
class ArticuloAlmacenable;
class Cederron: public ArticuloAlmacenable {
    public:
        Cederron(const Autores& a, const Cadena& r, const Cadena& t, const Fecha& f, double p, unsigned s, unsigned MB)
        unsigned tam() const noexcept {return tam_;}
        
        void impresion_especifica(ostream& os) const noexcept;

    private:
        const unsigned tam_;
};

//
// ------------| CLASE LIBRODIGITAL |------------|
//
class LibroDigital: public Articulo {
    public:
        LibroDigital(const Autores& a, const Cadena& r, const Cadena& t, const Fecha& f, double p, const Fecha& f_exp);
        const Fecha& f_expir() const noexcept {return f_exp_;}

        void impresion_especifica(ostream& os) const noexcept;

    private:
        const Fecha f_exp_;
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

//OPERADOR DE INSERCION DE FLUJO
std::ostream& operator<< (std::ostream& os, const Articulo& art);
#endif