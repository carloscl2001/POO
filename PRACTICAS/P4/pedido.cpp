#include "pedido.hpp"
#include "tarjeta.hpp"
#include "usuario-pedido.hpp"
#include "pedido-articulo.hpp"

#include "../P1/cadena.hpp"
#include "../P1/fecha.hpp"

//Variable para inicializar el numero del pedido
int Pedido::num_pedido_ = 0;

Pedido::Pedido(Usuario_Pedido& usuped, Pedido_Articulo& pedart, Usuario& usu, const Tarjeta& tar, const Fecha& fech):num_(num_pedido_ + 1), tarjeta_(&tar), fecha_(fech), total_(0)
{
    if(usu.n_articulos() == 0)
    {
        throw Vacio(usu);
    }

    if(&usu != tar.titular())
    {
        throw Impostor(usu);
    }

    if(tar.caducidad() < fech)
    {
        throw Tarjeta::Caducada(tar.caducidad());
    }

    if(tar.activa() == false)
    {
        throw Tarjeta::Desactivada();
    }

    auto carro = usu.compra();

    for(auto i: carro)
    {
        if((i.first)->stock() < (i.second))
        {
            const_cast<Usuario::Articulos&>(usu.compra()).clear();
            throw SinStock(i.first);
        }
    }

    carro = usu.compra();

    for(auto it : carro)
    {
        unsigned int cant = (it.second);
        Articulo* art = (it.first);
        double precio = art->precio();
        art->stock() -= cant;


        pedart.pedir(*this, *art, precio, cant);
        total_ += precio * cant;
        usu.compra(*art,0);
    }
    
    usuped.asocia(usu, *this);

    ++num_pedido_;
}


std::ostream& operator << (std::ostream& os, const Pedido ped){

    os << "Núm. pedido: " << ped.numero() << std::endl;
    os << "Fecha:       " << ped.fecha() << std::endl;
    os << "Pagado con:  " << ped.tarjeta()->tipo() << " n.º: "<< ped.tarjeta()->numero() << std::endl;
    os << "Importe:     " << std::fixed << std::setprecision(2) << ped.total() << " €" << std::endl;
    return os;

}
