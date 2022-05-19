

#ifndef PEDIDO_ARTICULO_HPP
#define PEDIDO_ARTICULO_HPP

#include "articulo.hpp"
#include "pedido.hpp"
#include <utility>
#include <map>

//
// ------------| CLASES DE ORDENACION |------------|
//

struct OrdenaArticulos: public std::binary_function <Articulo*, Articulo*, bool>
{
    bool operator()(const Articulo* a1, const Articulo* a2) const { return a1->referencia() < a2->referencia() ; }
};


struct OrdenaPedidos: public std::binary_function <Pedido*, Pedido*, bool>
{
    bool operator()(const Pedido* p1, const Pedido* p2) const {return p1->numero() < p2->numero();}
};

//
// ------------| CLASE LINEA PEDIDO |------------|
//

class LineaPedido{
public:
    explicit  LineaPedido(double price, unsigned int n = 1);
    unsigned cantidad() const { return cantidad_; };
    double precio_venta() const {return precio_venta_; };

private:
    unsigned cantidad_;
    double precio_venta_;
};

std::ostream& operator << (std::ostream& output, const LineaPedido& lp) ;

//
// ------------| CLASE PEDIDO ARTICULO |------------|
//

class Pedido_Articulo{
public:

    typedef std::map <Articulo*, LineaPedido, OrdenaArticulos> ItemsPedido ;
    typedef std::map <Pedido*, LineaPedido, OrdenaPedidos > Pedidos ;

    void pedir(Articulo& art, Pedido& ped,double precio, unsigned n = 1) ;
    void pedir(Pedido& ped, Articulo& aart,double precio, unsigned n = 1) ;

    ItemsPedido& detalle(Pedido& p);
    Pedidos ventas(Articulo& a);

    std::ostream& mostrarDetallePedidos(std::ostream& os);
    std::ostream& mostrarVentasArticulos(std::ostream& os);

private:
    std::map <Articulo*, Pedidos, OrdenaArticulos> Art_Ped_ ;
    std::map <Pedido*, ItemsPedido, OrdenaPedidos> Ped_Art_ ;
};

//SOBRECARGA DE OPERADORES DE INSERCCION DE FLUJO
std::ostream& operator <<(std::ostream& os, const Pedido_Articulo::ItemsPedido& iteped) ;
std::ostream& operator <<(std::ostream& os, const Pedido_Articulo::Pedidos& ped) ;


#endif
