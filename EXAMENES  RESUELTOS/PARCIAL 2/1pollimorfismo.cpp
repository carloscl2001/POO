using namespace std;
#include <iostream>
#include <math.h>
/*
#include <iostream>
#include <string>

class Mamifero{
    public:
        Mamifero(string s) : nombre_(s) {}
        virtual void saludo() const{
        cout << "El nombre del animal es " << nombre() << " y es un " <<
        tipo() << endl; }
        virtual string tipo() const = 0;
        string nombre() const{ return nombre_; }
    private:
        string nombre_;
};

class Gato: public Mamifero{
    public:
        Gato(string s):Mamifero(s) {}
        
        string tipo() const { return "gato";}
        
    private:
    
};

int main(){
    Mamifero* mp = new Gato("Miai");
    mp->saludo();
    delete mp;
}



//EJERICICO 2

#include <math.h>
using namespace std;
class Objeto{
    public:
        Objeto(char const *nombre): nombre_(nombre) {
        cout << "Constructor de Objeto para " << nombre_ << endl;
        }
        ~Objeto() {
        cout << "Destructor de Objeto para " << nombre_ << endl;
        }
        void lanzamiento() {
        Objeto o("'objeto local de lanzamiento()'");
        cout << "Metodo lanzamiento() para " << nombre_ << endl;
        throw &o;
        }
        void saludo() {
        cout << "Hola de parte de " << nombre_ << endl;
        }
    private:
        char const *nombre_;
};

int main() {
    Objeto o("'objeto de main()'");
    try { o.lanzamiento(); }
    catch(Objeto *o) {
    cout << "Excepción capturada" << endl;
    o->saludo();
    }
}


//EJERCICIO3
class Forma{
    public:
        virtual double area() = 0;
};

class Rectangulo: public Forma{
    public:
        Rectangulo(double l, double a): lado_(l), ancho_(a) {}
        virtual double area(){ return lado_ * ancho_;}
        virtual void lado(double x) { lado_ = x;}
        void ancho(double x) { ancho_ = x;}

    protected:
        double lado_;
        double ancho_;
};

class Cuadrado: public Rectangulo{
    public:
        Cuadrado(double l): Rectangulo(l,l) {}
        void ancho(double x) = delete;
        void lado(double x) {lado_ = x; ancho_ = x;}

};


class Circulo: public Forma{
    public:
        Circulo(double r): radio_(r)
        {
            if(r < 0)
            {
                throw Radio_Negativo(r);
            }
        }
        double area(){return std::pow(radio_,2) * 3.14;}
        class Radio_Negativo{
            public:
                Radio_Negativo(double rd): rd_(rd) {}
                double valor() const{return rd_;}
            private:
                double rd_;
        };
    private:
        double radio_;
};


int main(){
    Circulo cir(1.0);
    Cuadrado cua(2.0);
    Rectangulo rect(2.0, 2.0);
    Forma * formas[] = {&cir, &cua, &rect};
    for (int i=0;i<3;i++)
    {
        cout << "El area de la figura " << (i+1) << "es: " << formas[i]->area()<<endl;
    }
    
}
*/