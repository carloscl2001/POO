//  /-------------------------------\
//  |                               |
//  |   CARLOS ANTONIO CORTÉS LORA  |
//  |                               |
//  \-------------------------------/


#include "pedido.hpp"
#include "tarjeta.hpp"
#include "usuario-pedido.hpp"
#include "pedido-articulo.hpp"

#include "../P1/cadena.hpp"
#include "../P1/fecha.hpp"

#include <iostream>
#include <iomanip>

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

    for(auto it : carro)
    {
        if(ArticuloAlmacenable* artal = dynamic_cast<ArticuloAlmacenable*>(it.first))
        {
            if(artal->stock() < it.second)
            {
                const_cast<Usuario::Articulos&>(usu.compra()).clear();
                throw Pedido::SinStock(it.first);
            }   
        }
        if(LibroDigital* libdig = dynamic_cast<LibroDigital*>(it.first))
        {
            if(libdig->f_expir() < Fecha())
            {
                usu.compra(*it.first, 0);
                if(usu.n_articulos() == 0)
                {
                    throw Vacio(usu);
                }
            }
        }
    }
    
    usuped.asocia(usu, *this);

    carro = usu.compra();

    for(auto it : carro)
    {
        pedart.pedir(*this, *it.first, (it.first)->precio(), it.second);
        usu.compra(*it.first, 0);
        total_ += (it.first)->precio() * it.second;

        if(ArticuloAlmacenable *artal = dynamic_cast<ArticuloAlmacenable*>(it.first))
        {
            artal->stock() -= it.second;
        }
    }

    ++num_pedido_;
}


std::ostream& operator << (std::ostream& os, const Pedido ped){

    os << "Núm. pedido: "<< ped.numero() << std::endl<< "Fecha:       "<< ped.fecha()<< std::endl
    << "Pagado con:  "<< ped.tarjeta()->tipo() << " n.º: "<< ped.tarjeta()->numero()<< std::endl
    << "Importe:     "<< std::fixed<< std::setprecision(2)<< ped.total() << " €"<< std::endl;
    return os;
}
