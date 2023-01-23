#include <iostream>
using namespace std;
class Objeto
{
    public:
        Objeto(char const *nombre): nombre (nombre) {
        cout << "Constructor de Objeto para " << nombre << endl;
        }
        ~Objeto() {
        cout << "Destructor de Objeto para " << nombre << endl;
        }
        void lanzamiento() {
            Objeto o("objeto local de lanzamiento()");
            cout << "Metodo lanzamiento() para " << nombre << endl;
            throw &o;
        }
        void saludo() {
        cout << "Hola de parte de " << nombre << endl;
        }
    private:
        char const *nombre ;
};

int main(){
    Objeto o("objeto de main()");
    try {
        o.lanzamiento();
    }
    catch(Objeto *o) {
        cout << "Excepcion capturada" << endl;
        o->saludo();
    }
}