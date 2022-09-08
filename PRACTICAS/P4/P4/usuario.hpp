//  /-------------------------------\
//  |                               |
//  |   CARLOS ANTONIO CORTÉS LORA  |
//  |                               |
//  \-------------------------------/


#ifndef USUARIO_HPP
#define USUARIO_HPP

#include "tarjeta.hpp"
#include "articulo.hpp"
#include "../P1/cadena.hpp"

#include <map>
#include <unordered_map>
#include <unordered_set>


//
// ------------| CLASE CLAVE |------------|
//

class Clave
{
    public:

        enum Razon{CORTA, ERROR_CRYPT};

        //COSNTRUCTOR
        Clave(const char* c);
        
        //OBSERVADOR
        const Cadena& clave() const {return contrasena_;};
        bool verifica(const char* c) const;

        class Incorrecta {
        public:
            Incorrecta(const Razon r): fallo_(r) {}
            Razon razon() const {return fallo_; }
        private:
            Razon fallo_;
        };

    private:
        Cadena contrasena_;
};


//
// ------------| CLASE USUARIO |------------|
//

class Numero;
class Tarjeta;

class Usuario
{
    public:
        //CONTENEDORES 
        typedef std::unordered_set<Cadena> Usuarios;
        typedef std::map<Numero, Tarjeta*> Tarjetas;
        typedef std::unordered_map<Articulo*, unsigned > Articulos;

        //RESTRICCIONES DE USUARIO
        Usuario& operator =(const Usuario& u) = delete;
        Usuario(const Usuario& u) = delete;

        //CONSTRUCTOR
        Usuario(const Cadena& i, const Cadena& n, const Cadena& a, const Cadena& d, const Clave& c);

        //OBSERVADORES
        Cadena id() const {return identificador_;}
        Cadena nombre() const {return nombre_;}
        Cadena apellidos() const {return apellidos_;}
        Cadena direccion() const {return direccion_;}

        const Tarjetas& tarjetas() const {return tarjetas_; }
        const Articulos& compra() const {return articulos_; }
        void compra(Articulo& a, unsigned cant = 1);

        //ENLACE Y DESENLACE CON TARJETA
        void es_titular_de(Tarjeta& t);
        void no_es_titular_de(Tarjeta& t);

        //OPERADOR DE INSERCION DE FLUJO amigo
        friend std::ostream& operator <<(std::ostream& output, const Usuario& user);

        //DESTRUCTOR
        ~Usuario();

        size_t n_articulos() const {return articulos_.size();};

        class Id_duplicado
        {
        public:
            Id_duplicado(const Cadena& i): id_(i){}
            const Cadena idd() const {return id_;}
        private:
            Cadena id_;
        };

    private:
        Cadena identificador_;
        Cadena nombre_;
        Cadena apellidos_;
        Cadena direccion_;
        Clave contrasena_;
        Tarjetas tarjetas_;
        Articulos articulos_;
        static Usuarios usuario_;

};

//FUNCION EXTERNA PARA MOSTRAR EL CARRO
std::ostream& mostrar_carro(std::ostream& os, const Usuario& u);

#endif
