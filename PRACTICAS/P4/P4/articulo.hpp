//  /-------------------------------\
//  |                               |
//  |   CARLOS ANTONIO CORTÉS LORA  |
//  |                               |
//  \-------------------------------/

#ifndef ARTICULOS_HPP
#define ARTICULOS_HPP

#include <iostream>
#include <set>

#include "../P1/cadena.hpp"
#include "../P1/fecha.hpp"

using namespace std;

//
//-----------------| CLASE AUTOR |------------------/
//

class Autor{
    public:
        //CONSTRUCTOR
        Autor(const Cadena& n, const Cadena& a, const Cadena& d);

        //OBSERVADORES
        const Cadena& nombre() const noexcept { return nombre_; }
        const Cadena& apellidos() const noexcept { return apellidos_; }
        const Cadena& direccion() const noexcept { return direccion_; }

    private:
        Cadena nombre_;
        Cadena apellidos_;
        Cadena direccion_;
};

//
//-----------------| CLASE ARTICULO |------------------/
//


class Articulo{
public:

    //SET DE AUTORES
    typedef set<Autor*> Autores;

    //CONSTRUCTOR
	Articulo(const Autores& autor, const Cadena& referencia, const Cadena& titulo, const Fecha& f,  double precio);

	//CONSULTORAS
    const Cadena& referencia() const noexcept { return referencia_; }
	const Cadena& titulo() const noexcept { return titulo_; }
	const Fecha& f_publi() const noexcept { return fecha_pub_; }
    double precio() const noexcept { return precio_; }
	double& precio() noexcept { return precio_; }

    const Autores& autores() const noexcept { return autor_; }

    //METODOS VIRTUALES
    virtual ~Articulo() {}
    virtual void impresion_especifica(ostream& os) const noexcept = 0;

    //CLASE DE EXCEPCION
    class Autores_vacios {};

private:
    
    Autores autor_;
	Cadena referencia_;
	Cadena titulo_;
	Fecha fecha_pub_;
	double precio_;
};



//
//-----------------| CLASE ARTICULO-ALMACENABLE |------------------/
//

class ArticuloAlmacenable : public Articulo{
    
    public:
        
        //CONSTRUCTOR
        ArticuloAlmacenable(const Autores& a, const Cadena& r, const Cadena& t, const Fecha& f, double p, unsigned s);

        unsigned stock() const noexcept { return stock_; }
    	unsigned& stock() noexcept { return stock_;}

    private:
        unsigned stock_;
};


//
//-----------------| CLASE LIBRO |------------------/
//

class Libro : public ArticuloAlmacenable{
    public:
        
        //CONSTRUCTOR
        Libro(const Autores& a, const Cadena& r, const Cadena& t,const Fecha& f, double p, unsigned n_pag, unsigned s = 0);

        unsigned n_pag() const noexcept { return n_pag_; }
        void impresion_especifica(ostream& os) const noexcept;

    private:
        const unsigned n_pag_;
};


//
//-----------------| CLASE CEDERRON |------------------/
//

class Cederron : public ArticuloAlmacenable{
    public:
        
        //CONSTRUCTOR
        Cederron(const Autores& a, const Cadena& r, const Cadena& t, const Fecha& f, double p, unsigned MB, unsigned s);
      
        unsigned tam() const noexcept { return tam_; }
        void impresion_especifica(ostream& os) const noexcept;

    private:
        const unsigned tam_;
};


//
//-----------------| CLASE LIBRODIGITAL |------------------/
//
class LibroDigital : public Articulo{
    public:
        
        //CONSTRUCTOR
        LibroDigital(const Autores& a, const Cadena& r, const Cadena& t, const Fecha& f, double p, const Fecha& f_expir);

        const Fecha& f_expir() const noexcept { return f_expir_; }
        void impresion_especifica(ostream& os) const noexcept;

    private:
        const Fecha f_expir_;    
};

ostream& operator<<(ostream& os, const Articulo& a) noexcept;


#endif
