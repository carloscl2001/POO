//  /-------------------------------\
//  |                               |
//  |   CARLOS ANTONIO CORTÉS LORA  |
//  |                               |
//  \-------------------------------/


#ifndef USUARIO_PEDIDO_H
#define USUARIO_PEDIDO_H

#include <map>
#include <set>
#include <utility>
#include "pedido.hpp"
#include "usuario.hpp"

//
// ------------| CLASE USUARIO PEDIDO |------------|
//

class Usuario_Pedido{
public:
    typedef std::set<Pedido*> Pedidos;

    void asocia(Pedido& p, Usuario& user);
    void asocia(Usuario& user, Pedido& p);

    Pedidos pedidos(Usuario& user) {return userped_[&user];}
    Usuario* cliente(Pedido& p) {return peduser_[&p];}

private:
    std::map<Pedido*, Usuario*> peduser_;
    std::map<Usuario*, Pedidos> userped_;

};

void asocia(Pedido &p, Usuario &user);
void asocia(Usuario &user, Pedido &p);

#endif