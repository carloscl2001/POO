#ifndef PEDIDO_HPP
#define PEDIDO_HPP

#include "../P1/fecha.hpp"
#include "../P2/numero.hpp"
#include "../P2/tarjeta.hpp"
#include "../P2/usuario.hpp"

class Usuario_Pedido;
class Pedido_Articulo;

class Pedido{
    public:
        Fecha(Usuario_Pedido& usuped, Pedido_Articulo& pedart, Usuario& usu, Tarjeta& tar, const Fecha& fech = Fecha());
        
        //OBSERVADORES
        int numero()const {return num_;}
        Tarjeta tarjeta() const {return tarjeta_;}
        Fecha fecha()const {return fecha_;}
        double total() const {return total_;}
        n_total_pedidos() const {return num_pedido_;}

        //SOBRECARGA DEL OPERADOR DE INSERCION DE FLUJO
        

    private:
        
        int num_;
        const Tarjeta* tarjeta_;
        Fecha fecha_;
        double total_;
        static int num_pedido_;


};

#endif