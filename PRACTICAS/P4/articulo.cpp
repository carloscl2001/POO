#include "articulo.hpp"
#include <iostream>
#include <iomanip>

//
// ------------| CLASE ARTICULO |------------|
//

//CONSTRUCTOR 
Articulo::Articulo(const Autores& a, const Cadena& r, const Cadena& t, Fecha f, double p): cod_referencia_(r), titulo_(t), fecha_publi_(f), precio_(p)
{
    if(a.empty())
    {
        throw Autores_vacios();
    }
}

//OPERADOR DE INSERCION DE FLUJO
std::ostream& operator<< (std::ostream& os, const Articulo& art)
{
    os << "[" << setw(3) << setfill('0') << art.referencia() << "] \"" << a.titulo()<< "\", de ";

    auto autor = art.autores().begin();

    os << (*autor)->apellidos();

    for(++autor; autor != art.autores().end(); ++autor)
        os << ", " << (*autor)->apellidos();

    os << ". ";

    int anno = art.f_publi().anno();

    os << anno << ". " << fixed << setprecision(2)
       << art.precio() << " €" << endl;
       os << "\t";
	art.impresion_especifica(os);

    return os;
}


//
// ------------| CLASE AUTOR |------------|
//
Autor::Autor(const Cadena& n, const Cadena& a, const Cadena& d): nombre_(n), apellidos_(a), direccion_(d) {}

//
// ------------| CLASE ARTICULOALMACENABLE |------------|
//
ArticuloAlmacenable::ArticuloAlmacenable(const Autores& a, const Cadena& r, const Cadena& t, Fecha f, double p, unsigned s = 0) : ArticuloAlmacenable(a, r, t, f, p), stock_(s) {}

//
// ------------| CLASE LIBRO |------------|
//
Libro::Libro(const Autores& a, const Cadena& r, const Cadena& t,const Fecha& f,
		double p, unsigned s, unsigned n): ArticuloAlmacenable(a, r, t, f, p, s), n_pag_(n) {}

void Libro::impresion_especifica(ostream& os) const noexcept
{
    os << n_pag_ << " págs., " << stock_ << " unidades.";
}

//
// ------------| CLASE CEDERRON |------------|
//
Cederron::Cederron(const Autores& a, const Cadena& r, const Cadena& t, const Fecha& f, double p, unsigned s, unsigned MB) : ArticuloAlmacenable(a, r, t, f, p, s), tam_(MB) {}

void Cederron::impresion_especifica(ostream& os) const noexcept
{
    os << tam_ << " MB, " << stock_ << " unidades.";
}

//
// ------------| CLASE LIBRODIGITAL |------------|
//
LibroDigital::LibroDigital(const Autores& a, const Cadena& r, const Cadena& t, const Fecha& f, double p, const Fecha& f_exp) : Articulo(a, r, f, p), f_exp_(f_exp) {}
void LibroDigital::impresion_especifica(ostream& os) const noexcept
{
    os << "A la venta hasta el " << f_expir_ << '.';
}