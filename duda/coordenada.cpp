#include <iostream>
using namespace std;

class coordenada{
    public:

        ~coordenada(){cout<<"destructor"<<endl;};

        // coordenada(const coordenada &c): r(c.r), i(c.i){
        //     cout<<"constructor por copia"<<endl;
        //};

        coordenada(double n = 0.0, double d = 0.0): n1(n), n2(d){
            cout<<"constructor por defecto"<<endl;
        };

        void imprimir();

        //double n1_() const {cout<<r<<endl;}

        //double operator *(coordenada c1, coordenada c2);
    private:
        double n1, n2;

};


void coordenada::imprimir(){
    cout<<"x:"<<n1;
    cout<<"\ty:"<<n2<<endl;
}



int man2n(){
    
    coordenada c1(1.);
    c1.imprimir();
    cout<<"----------------------"<<endl;
    coordenada c2;
    c2.imprimir();
    cout<<"----------------------"<<endl;
    coordenada c3(2, -1.2);
    c3.imprimir();
    cout<<"----------------------"<<endl;
    coordenada c4 (c3);
    c4.imprimir();
    cout<<"----------------------"<<endl;
    coordenada c5 = c4;
    c5.imprimir();
    cout<<"----------------------"<<endl;
    coordenada c6 = -1;
    c6.imprimir();
    cout<<"----------------------"<<endl;
    c3 = -3.5;
    c3.imprimir();


    cout<<"-----FINALIZADO-----------------"<<endl;
}