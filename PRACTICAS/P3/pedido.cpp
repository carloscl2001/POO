#include "pedido.hpp"
#include "tarjeta.hpp"
#include "usuario-pedido.hpp"
#include "pedido-articulo.hpp"

#include "../P1/cadena.hpp"
#include "../P1/fecha.hpp"

//Variable para inicializar el numero del pedido
int Pedido::num_pedido_ = 0;

Pedido::Pedido(Usuario_Pedido& usuped, Pedido_Articulo& pedart, Usuario& usu, Tarjeta& tar, const Fecha fech):tarjeta_(&tar), fecha_(fech), num_(num_pedido_ + 1), total_(0)
{
    if(usu.n_articulos() = 0)
    {
        throw Vacio(usu);
    }

    if(&usu != tar.titular())
    {
        throw Impostor(usu);
    }

    if(tar.caducidad() > fech)
    {
        throw Tarjeta::Caducada(t.caducidad());
    }

    if(tar.activa() == false)
    {
        throw Tarjeta::Desactivada();
    }

    
}
