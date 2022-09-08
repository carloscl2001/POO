//  /-------------------------------\
//  |                               |
//  |   CARLOS ANTONIO CORTÉS LORA  |
//  |                               |
//  \-------------------------------/


#include <iomanip>
#include <ostream>
#include "pedido-articulo.hpp"


//
// ------------| CLASE LINEA PEDIDO |------------|
//

LineaPedido::LineaPedido(double precio, unsigned int cant): cantidad_(cant), precio_venta_(precio){}

std::ostream& operator <<(std::ostream& os, const LineaPedido& linped)
{
    os << std::fixed << std::setprecision(2) << linped.precio_venta() << ' ' << "€" << '\t' << linped.cantidad() ;

    return os;
}


//
// ------------| CLASE PEDIDO ARTICULO |------------|
//

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
        os << "Ventas de " << "[" << (it->first)->referencia() << "] " ;
        os << "\"" << it->first->titulo() << "\"" ;
        os << it->second << std::endl ;
    }

    return os;
}

std::ostream& Pedido_Articulo::mostrarDetallePedidos(std::ostream& os)
{
    double aux = 0;

    for(auto it = Ped_Art_.begin(); it != Ped_Art_.end() ; it++)
    {
            os << "\nPedido núm." << it->first->numero() << "\n" << "Cliente: " << it->first->tarjeta()->titular()->nombre() 
            << "\t\t"<< "Fecha: " << it->first->fecha() << it->second;         
            aux += it->first->total();     
    }     
    os << "\nTOTAL VENTAS\t"<< std::fixed<< std::setprecision(2)<< aux<< " €"<< std::endl;     
    return os;
}


std::ostream& operator <<(std::ostream& os, const Pedido_Articulo::ItemsPedido& ip){

    double aux = 0.0;

    os << "\n"<< std::setw(70)<< std::setfill('=')<< '\n'<< std::setfill(' ')<< std::endl
    << "  PVP \t\tCant.\t Articulos\n"<< std::setw(70)<< std::setfill('=')<< '\n'<< std::setfill(' ');

    for (auto it = ip.begin(); it != ip.end(); it++){
        os <<" "<< it->second.precio_venta() << " €\t" << it->second.cantidad() << "\t" 
        << "["<< it->first->referencia() << "]\"" << it->first->titulo() << "\"" << '\n';
        aux += it->second.precio_venta() * it->second.cantidad();
    }
    os << std::setw(70) << std::setfill('=') << '\n' << std::setfill(' ') << " Total\t\t" << aux<< " €"<< std::endl;

    return os;


}

std::ostream& operator <<(std::ostream& os, const Pedido_Articulo::Pedidos& p){

    double aux = 0.0;
    size_t cant = 0;

    os << "\n"<< std::setw(70)<< std::setfill('=')<< '\n'<< std::setfill(' ')<< std::endl
    << "  PVP \t\tCant.\t Fecha venta\n"<< std::setw(70)<< std::setfill('=')<< '\n'<< std::setfill(' ');

    for(auto it = p.begin(); it != p.end(); it++){
        os << " "<< it->second.precio_venta()<< " €\t"<< it->second.cantidad()<< "\t"<< it->first->fecha()<< std::endl;
        aux += (it->second.cantidad() * it->second.precio_venta());
        cant += it->second.cantidad();
    }
    os << std::setw(70)<< std::setfill('=')<< '\n'<< std::setfill(' ')<<" "<< std::fixed<< std::setprecision(2)<< aux<< " €\t"<< cant<< std::endl;

    return os;

}