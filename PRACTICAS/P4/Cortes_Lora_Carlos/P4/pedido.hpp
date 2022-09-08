//  /-------------------------------\
//  |                               |
//  |   CARLOS ANTONIO CORTÉS LORA  |
//  |                               |
//  \-------------------------------/


#ifndef PEDIDO_HPP
#define PEDIDO_HPP

#include "../P1/fecha.hpp"
#include "tarjeta.hpp"
#include "usuario.hpp"
#include "iostream"

class Usuario_Pedido;
class Pedido_Articulo;

//
// ------------| CLASE PEDIDO |------------|
//

class Pedido{
    public:
        //CONSTRUCTOR
        Pedido(Usuario_Pedido& usuped, Pedido_Articulo& pedart, Usuario& usu, const Tarjeta& tar, const Fecha& fech = Fecha() );
        
        //OBSERVADORES
        int numero()const {return num_;}
        const Tarjeta* tarjeta() const {return tarjeta_;}
        Fecha fecha() const {return fecha_;}
        double total() const {return total_;}
        static int n_total_pedidos() {return num_pedido_;}
        
        //CLASES DE EXCEPCIONES
        class Vacio{
            public:
                Vacio(Usuario& usu): usu_(&usu){}
                Usuario& usuario() const{return *usu_;}
            private:
                Usuario* usu_;
        };

        class Impostor{
            public:
                Impostor(Usuario& usu): usu_(&usu){}
                Usuario& usuario() const{return *usu_;}
            private:
                Usuario* usu_;
        };

        class SinStock{
            public:
                SinStock(Articulo* a):articulo_(a) {}
                Articulo& articulo() const { return *articulo_;};
            private:
                Articulo* articulo_;
        };

    private:
        
        int num_;
        const Tarjeta* tarjeta_;
        Fecha fecha_;
        double total_;
        static int num_pedido_;
};

//SOBRECARGA DEL OPERADOR DE INSERCION DE FLUJO
std::ostream& operator << (std::ostream& os, const Pedido ped);

#endif