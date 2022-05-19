#include <iomanip>
#include <ostream>
#include "pedido-articulo.hpp"



LineaPedido::LineaPedido(double precio, unsigned int cant): cantidad_(cant), precio_venta_(precio){}

std::ostream& operator <<(std::ostream& os, const LineaPedido& linped)
{
    os << std::fixed << std::setprecision(2) << linped.precio_venta() << ' ' << "€" << '\t' << linped.cantidad() ;

    return os;
}


void Pedido_Articulo::pedir(Pedido& ped, Articulo& art,double precio, unsigned cant)
{
    Art_Ped_[&art].insert(std::make_pair(&ped,LineaPedido(precio,cant))) ;
    Ped_Art_[&ped].insert(std::make_pair(&art,LineaPedido(precio,cant))) ;
}

void Pedido_Articulo::pedir(Articulo& art, Pedido& ped,double precio, unsigned cant)
{
    pedir(ped,art,precio,cant) ;
}

Pedido_Articulo::ItemsPedido& Pedido_Articulo::detalle(Pedido& ped)
{
    return Ped_Art_[&ped] ;
}

Pedido_Articulo::Pedidos Pedido_Articulo::ventas(Articulo& art)
{
    return Art_Ped_[&art] ;
}

std::ostream& Pedido_Articulo::mostrarVentasArticulos(std::ostream& os)
{
    for(auto it = Art_Ped_.begin(); it != Art_Ped_.end(); it++)
    {
        os << "Ventas" << "[" << (it->first)->referencia() << "]" ;
        os << "\"" << it->first->titulo() << "\"" ;
        os << it->second << std::endl ;
    }

    return os;
}

std::ostream& Pedido_Articulo::mostrarDetallePedidos(std::ostream& os)
{
    double precio = 0;

    for(auto it = Ped_Art_.begin(); it != Ped_Art_.end() ; it++)
    {

        os << "Pedido núm." << (it->first)->numero() << "\t" ;
        os << "Cliente: " << (it->first)->tarjeta()->titular()->nombre() << "\t";
        os << "Fecha: " << (it->first)->fecha() << (it->second) ;

        precio = precio + (it->first)->total() ;
    }

    os << std::fixed ;
    os << "TOTAL VENTAS: " << std::setprecision(2) << precio << " €" << std::endl ;

    return os ;
}

std::ostream& operator <<(std::ostream& os,const Pedido_Articulo::ItemsPedido& iteped)
{

    double precio = 0;

    os << "\n" ;
    os << std::setw(40) << std::setfill('=') << '\n' << std::setfill(' ') << std::endl ;
    os << "PVP \t Cant.\t Articulo\n" ;
    os << std::setw(40) << std::setfill('=') << '\n' << std::setfill(' ') << std::endl ;

    for(auto it = iteped.begin(); it != iteped.end() ; it++)
    {

        os << (it->second).precio_venta() << "€\t" ;
        os << (it->second).cantidad() << "\t" ;
        os << "[ "<< (it->first)->referencia() << "]\t";
        os << "\"" << (it->first)->titulo() << "\"" << std::endl;

        precio = precio + (it->second).cantidad() * (it->second).precio_venta() ;
    }

    os << std::setw(40) << std::setfill('=') << '\n' << std::setfill(' ') << std::endl ;
    os << std::fixed ;
    os << std::setprecision(2) << precio << " €" << std::endl ;

    return os ;
}

std::ostream& operator <<(std::ostream& os, const Pedido_Articulo::Pedidos& pedart)
{

    double precio = 0;
    unsigned aux = 0  ;

    os << "\n" ;
    os << std::setw(40) << std::setfill('=') << '\n' << std::setfill(' ') << std::endl ;
    os << "PVP \t Cant.\t Fecha venta\n" ;
    os << std::setw(40) << std::setfill('=') << '\n' << std::setfill(' ') << std::endl ;

    for(auto it = pedart.begin(); it != pedart.end() ; it++)
    {

        os << " " << (it->second).precio_venta() << " €\t" ;
        os << (it->second).cantidad() << "\t" ;
        os << (it->first)->fecha() << std::endl ;

        precio = precio + (it->second).cantidad() * (it->second).precio_venta() ;
        aux += (it->second).cantidad() ;
    }


    os << std::setw(40) << std::setfill('=') << '\n' << std::setfill(' ') << std::endl ;
    os << std::fixed ;
    os << std::setprecision(2) << precio << " €\t" << aux << std::endl ;

    return os;

}

