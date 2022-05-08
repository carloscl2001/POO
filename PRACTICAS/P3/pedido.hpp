#ifndef PEDIDO_HPP
#define PEDIDO_HPP

#include "fecha.hpp"
#include "numero.hpp"

class Pedido{
    public:

    private:
        Tarjeta* tarjeta_;
        Fecha fecha_pedido_;
        unsigned importe_total_;
        Numero num_pedido_p;


};

#endif