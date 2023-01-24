#include <set>
#include <map>
#include <string.h>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
class Vehiculo{
    public:
        virtual void imprimir() = 0;
        virtual void fecha() = 0;
        ~Vehiculo();
};

class Turismo:public Vehiculo{
    public:
        Turismo(string s1, int pasa):fech_fabricacion(s1), n_pasajeros(pasa){}
        void imprimir() const;
        void fecha() const;
    private:
        string fech_fabricacion;
        int n_pasajeros;
};

class Camion: public Vehiculo{
    public:
        void imprimir() const{}
        void fecha() const;
    private:
        string fech_fabricacion;
        int peso_maximo;
};

void clasificar(vector<Vehiculo*>& vh, vector<Turismo*>& vt, vector<Camion*>& vc){
    for(auto it = vh.begin(); it != vh.end(); it++){
        if(typeid(*it) == typeid(Turismo))
            vt.push_back(dynamic_cast<Turismo*>(*it));
        
        if(dynamic_cast<Camion*>(*it) != nullptr)
            vc.push_back(dynamic_cast<Camion*>(*it));
    }
}