//Ejericio 1
#include <iostream>
#include <set>
using namespace std;
class capa{
    public:
        capa();
        capa(capa c, char icono);
        capa(const capa& capa);
        ~capa();
        //Observadores
        char icono() const{return icono_;}
        unsigned x() const{return x_;}
        unsigned y() const {return y_;}
        void activa() {activada_ = true;}
        void desactiva() {activada_ = false;}
        bool activada() const{return activada_;}
        pair<unsigned, unsigned> ocupada(unsigned x1, unsigned x2) const;


    private:
        unsigned x_;
        unsigned y_;
        char icono_;
        bool activada_;
        bool existente_;
        set<pair<unsigned, unsigned>> cuadricula_;
};

capa::capa(){
    x_ = 0;
    y_ = 0;
    activada_ = false;
    existente_ = false;
}

capa::capa(capa ca, char icono){
    x_ = ca.x_;
    y_ = ca.y_;
    icono_ = icono;
    activada_ = true;
    existente_ = false;
}

capa::capa(const capa& ca){
    x_ = ca.x_;
    y_ = ca.y_;
    icono_ = ca.icono_;
    activada_ = ca.activada_;
    existente_ = ca.existente_;
}

capa::~capa(){
    x_ = 0;
    y_ = 0;
    icono_ = '0';
}

pair<unsigned, unsigned> capa::ocupada(unsigned m, unsigned n) const{
    return (*cuadricula_.find(make_pair(m,n)));
}


int main(){
    cout<<"Hola"<<endl;
    return 0;
}