#include <cstring>
#include <iostream>
#include <vector>
//Vamos a utilzar una clase abstracta
using namespace std;

class vehiculo
{
    public:
        vehiculo(string f):fecha(f){}
        virtual void mostrar_datos() = 0;
        string fecha_(){return fecha;}
    private:
        string fecha;
};

class turismo: public vehiculo{
    public:
        turismo(string s, size_t n):n_pasajeros(n), vehiculo(s){}
        size_t pasajeros() const;
        void mostrar_datos();
        
    private:
        size_t n_pasajeros;
};

class camion: public vehiculo{
    public:
        camion(size_t p, string s):peso_max(p), vehiculo(s){}
        size_t peso() const;
        void mostrar_datos();
    private:
        size_t peso_max;
};

void turismo::mostrar_datos(){
    cout<<"fecha"<<fecha_();
    cout<<"n pasajeros"<<n_pasajeros;
}

void camion::mostrar_datos(){
    cout<<"fecha"<<fecha_();
    cout<<"peso"<<peso_max;
}
//
///
//
void clasificacion(std::vector<vehiculo*> vehiculo_, std::vector<turismo*> turismo_, vector<camion*> camion_){
    
    for(auto z = vehiculo_.begin(); z < vehiculo_.end(); z++){
        if(turismo* t = dynamic_cast<turismo*>(*z)){
            turismo_.push_back(t);
        }

        if(camion* c = dynamic_cast<camion*>(*z)){
            camion_.push_back(c);
        }
    }
}

