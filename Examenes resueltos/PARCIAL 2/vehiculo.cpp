#include <cstring>
#include <iostream>
//Vamos a utilzar una clase abstracta
using namespace std;

class vehiculo
{
    public:
        vehiculo(string f):fecha(f){}
        virtual void mostrar_datos() = 0;
    private:
        string fecha;
};

class turismo: public vehiculo{
    public:
        size_t n_pasajeros;

        size_t pasajeros() const;
        void mostrar_datos();
};

class camion: public vehiculo{
    public:
        size_t peso_max;
        size_t peso() const;
        void mostrar_datos();
};


