//  /-------------------------------\
//  |                               |
//  |   CARLOS ANTONIO CORTÉS LORA  |
//  |                               |
//  \-------------------------------/


#include "usuario-pedido.hpp"


//
// ------------| CLASE USUARIO PEDIDO |------------|
//
void Usuario_Pedido::asocia(Pedido &p, Usuario &user)
{
    userped_[&user].insert(&p);
    peduser_[&p] = &user;
}

void Usuario_Pedido::asocia(Usuario &user, Pedido &p)
{
    return asocia(p,user);
}