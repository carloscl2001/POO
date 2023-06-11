#include <iostream>
#include <vector>
using namespace std;


//a)

class Vehiculo{
    public:
        Vehiculo(string fecha):fecha_fabricacion(fecha){}
        string fecha() const{return fecha_fabricacion;}
        virtual void imprimir() const = 0;
    private:
        string fecha_fabricacion;
};


class Turismo: public Vehiculo{
    public:
        Turismo(string f, size_t p):Vehiculo(f),num_max_pasajeros(p){}
        size_t pasajeros() const{return num_max_pasajeros;}
        void imprimir() const{
            cout<<num_max_pasajeros<<fecha()<<endl;
        }
    private:
        size_t num_max_pasajeros;
};

class Camion: public Vehiculo{
    public:
        Camion(string f, size_t p):Vehiculo(f), peso_max_autorizado(p){}
        size_t peso() const{return peso_max_autorizado;}
        void imprimir() const{
            cout<<peso_max_autorizado<<fecha()<<endl;
        }
    private:
        size_t peso_max_autorizado;
};




//b)


void clasificarVehiculos(const vector<Vehiculo*>& vehiculos, vector<Turismo*>& turismos, vector<Camion*>& camiones) {
    for (vector<Vehiculo*>::const_iterator it = vehiculos.begin(); it != vehiculos.end(); ++it) {
        if (Turismo* turismo = dynamic_cast<Turismo*>(*it)) {
            turismos.push_back(turismo);
        } else if (Camion* camion = dynamic_cast<Camion*>(*it)) {
            camiones.push_back(camion);
        }
    }
}

int main(){
    // Crear algunos objetos de vehículos
    Turismo turismo1("01/01/2022", 4);
    Turismo turismo2("01/02/2022", 2);
    Camion camion1("01/03/2022", 5000);
    Camion camion2("01/04/2022", 7000);

    // Crear un vector de punteros a vehículos y agregar los objetos
    vector<Vehiculo*> vehiculos;
    vehiculos.push_back(&turismo1);
    vehiculos.push_back(&turismo2);
    vehiculos.push_back(&camion1);
    vehiculos.push_back(&camion2);

    // Clasificar los vehículos en vectores separados
    vector<Turismo*> turismos;
    vector<Camion*> camiones;
    clasificarVehiculos(vehiculos, turismos, camiones);

}


