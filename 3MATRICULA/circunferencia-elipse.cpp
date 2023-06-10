#include <iostream>
using namespace std;
/*
//a)
//La opción mas conveniente sería la especialiazción, ya que como nos dice en el enunciado 
//una circunferencia es un tipo de elipse.

class Elipse{
    public:
        Elipse(float f1, float f2);
        float radio_x() const;
        float radio_y() const;
        void escala(float escala);

    protected:
        void escala(float escala1, float escala2);
        
    private:
        float radiox;
        float radioy;
};

Elipse::Elipse(float f1, float f2):radiox(f1), radioy(f2){}

float Elipse::radio_x() const{return radiox;}

float Elipse::radio_y() const{return radioy;}

void Elipse::escala(float escala){
    radiox *= escala;
    radioy *= escala;
}

void Elipse::escala(float escala1, float escala2){
    radiox *= escala1;
    radioy *= escala2;
}

//

class Circunferencia: public Elipse{
    public:
        Circunferencia(float radio);
    private:
};

Circunferencia::Circunferencia(float radio):Elipse(radio,radio){}
*/

//b)]
//Vamos a usar una clase abstracta en vez de una interfaz, ya que tenemos atributos y  métodos en común
class FiguraPlana{
    public:
        FiguraPlana(float f1, float f2):radiox(f1), radioy(f2){}
        void escala(float escalado){
            radiox *= escalado;
            radioy *= escalado;
        }
        float radio_x() const{return radiox;}
        float radio_y() const{return radioy;}

        virtual void dibuja() const = 0;
    private:
        float radiox;
        float radioy;
};

class Elipse: public FiguraPlana{
    public:
        Elipse(float f1,float f2):FiguraPlana(f1,f2){}
        virtual void dibuja() const{
            cout<<"Dibujando una elipse"<<endl;
        }
};

class Circuferencia: public Elipse{
    public:
        Circuferencia(float f):Elipse(f,f){}
        void dibuja() const{
            cout<<"Dibujando una circunferencia"<<endl;
        }
        
        float radio() const{
            return radio_x();
        }
};
