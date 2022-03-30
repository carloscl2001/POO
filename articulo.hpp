#include "cadena.hpp"
#include "fecha.hpp"

class Articulo
{
    public:
    
        //CONSTRUCTOR
        Articulo(Cadena r, Cadena t, Fecha f, double p, int e = 0);
        
        //OBSERAVORES
        inline Cadena referencia() const {return cod_referencia_;}
        inline Cadena titulo() const {return titulo_; }
        inline Fecha f_publi() const {return fecha_publi_;}
        inline double precio() const {return precio_;}
        inline double& precio() {return precio_;}
        inline int stock() const {return n_ejem_vent_;}
        inline int sstock() {return n_ejem_vent_;}

    private:
        Cadena cod_referencia_;
        Cadena titulo_;
        Fecha fecha_publi_;
        double precio_;
        int n_ejem_vent_;

};
