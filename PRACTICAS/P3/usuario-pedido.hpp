#ifndef USUARIO_PEDIDO_HPP
#define USUARIO_PEDIDIO_HPP

#include <map>
#include <set>
#include "usuario.hpp"
#include "pedido.hpp"

class Usuario_Pedido{
    private:
        typedef std::map<Usuario*, std::set<Pedido*>> usu_ped_;
        typedef std::map<Pedido*, Usuario*> ped_usu_

    public:
        void asocia(Usuario& usu, Pedido& ped);
        void asocia(Pedido& ped, Usuario& usu);

        Pedidos pedidos(Usuario& usu) {return usu_ped[&usu];}
        Usuario* cliente(Pedido& ped) {return ped_usu[&ped];}
};

inline  void asocia(Usuario& usu, Pedido& ped)
{
    usu_ped_[&usu].insert(&ped);
    ped_usu_[&ped] = &user;

}

inline  void asocia(Pedido& ped, Usuario& usu)
{
    asocia(usu,ped);
}





#endif