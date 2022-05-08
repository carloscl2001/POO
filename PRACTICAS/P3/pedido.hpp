#ifndef PEDIDO_HPP
#define PEDIDO_HPP

#include "../P1/fecha.hpp"
#include "numero.hpp"
#include "tarjeta.hpp"
#include "usuario.hpp"

class Usuario_Pedido;
class Pedido_Articulo;

class Pedido{
    public:
        //CONSTRUCTOR
        Fecha(Usuario_Pedido& usuped, Pedido_Articulo& pedart, Usuario& usu, Tarjeta& tar, const Fecha& fech = Fecha());
        
        //OBSERVADORES
        int numero()const {return num_;}
        Tarjeta tarjeta() const {return tarjeta_;}
        Fecha fecha()const {return fecha_;}
        double total() const {return total_;}
        n_total_pedidos() const {return num_pedido_;}
        //CLASES DE EXCEPCIONES
        class Vacio{
            public:
                Vacio(usu): usu_(usu){}
                Usuario& usuario() const{return *usu_;}
            private:
                Usuario* usu_;
        };

        class Impostor{
            public:
                Vacio(usu): usu_(usu){}
                Usuario& usuario() const{return *usu_;}
            private:
                Usuario* usu_;
        };

        class SinStock{
        }
        //SOBRECARGA DEL OPERADOR DE INSERCION DE FLUJO
        std::ostream& operator <<(std::ostream& os, const Pedido& p);

    private:
        
        int num_;
        const Tarjeta* tarjeta_;
        Fecha fecha_;
        double total_;
        static int num_pedido_;


};

#endif