//  /-------------------------------\
//  |                               |
//  |   CARLOS ANTONIO CORTÉS LORA  |
//  |                               |
//  \-------------------------------/


#include "articulo.hpp"
#include <iomanip>
#include <iostream>

//
//-----------------| CLASE AUTOR |------------------/
//

Autor::Autor(const Cadena& n, const Cadena& a, const Cadena& d): nombre_(n), apellidos_(a), direccion_(d) {}


//
//-----------------| CLASE ARTICULO |------------------/
//

Articulo::Articulo(const Autores& autor, const Cadena& referencia, const Cadena& titulo, const Fecha& f,  double precio) : autor_(autor), referencia_(referencia),titulo_(titulo), fecha_pub_(f),precio_(precio)
{
    if(autor_.empty())
    {
        throw Autores_vacios();
    }
}


//OPERADOR DE INSERCCION DE FLUJO DE ARTICULO
ostream& operator<<(ostream& os, const Articulo& art) noexcept
{
	os << "[" << art.referencia() << "] \"" << art.titulo()<< "\", de ";
    auto autor = art.autores().begin();
    os << (*autor)->apellidos();

    for(++autor; autor != art.autores().end(); ++autor)
    {
        os << ", " << (*autor)->apellidos();
    }
    os << ". ";

    int anno = art.f_publi().anno();

    os << anno << ". " << fixed << setprecision(2)
       << art.precio() << " €" << endl;
       os << "\t";
	
    art.impresion_especifica(os);

    return os;
}

//
//-----------------| CLASE ARTICULO-ALMACENABLE |------------------/
//
ArticuloAlmacenable::ArticuloAlmacenable(const Autores& a, const Cadena& r, const Cadena& t, const Fecha& f, double p, unsigned s): Articulo(a, r, t, f, p), stock_(s) {}

//
//-----------------| CLASE LIBRO |------------------/
//
Libro::Libro(const Autores& a, const Cadena& r, const Cadena& t,const Fecha& f, double p, unsigned n_pag, unsigned s):ArticuloAlmacenable(a, r, t, f, p, s),n_pag_(n_pag) {}

void Libro::impresion_especifica(ostream& os) const noexcept
{
    os << n_pag_ << " págs., " << stock() << " unidades.";
}

//
//-----------------| CLASE CEDERRON |------------------/
//
Cederron::Cederron(const Autores& a, const Cadena& r, const Cadena& t, const Fecha& f, double p, unsigned MB, unsigned s): ArticuloAlmacenable(a, r, t, f, p, s), tam_(MB) {}

void Cederron::impresion_especifica(ostream& os) const noexcept
{
    os << tam_ << " MB, " << stock() << " unidades.";
}



//
//-----------------| CLASE LIBRODIGITAL |------------------/
//
LibroDigital::LibroDigital(const Autores& a, const Cadena& r, const Cadena& t, const Fecha& f, double p, const Fecha& f_expir): Articulo(a, r, t, f, p), f_expir_(f_expir) {}

void LibroDigital::impresion_especifica(ostream& os) const noexcept
{
    os << "A la venta hasta el " << f_expir()<< '.';
}