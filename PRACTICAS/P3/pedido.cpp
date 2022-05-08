#include "pedido.hpp"

Pedido::Pedido(Usuario_Pedido& usuped, Pedido_Articulo& pedart, Usuario& usu, Tarjeta& tar, const Fecha& fech)
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