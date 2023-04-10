#include <iostream>
using namespace std;

class complejo{
    public:

        //~complejo(){cout<<"destructor"<<endl;};

        // complejo(const complejo &&c): r(c.r), i(c.i){
        //     cout<<"constructor por copia"<<endl;
        // };

        complejo(double n1 = 0, double n2 = 0): r(n1), i(n2){
            cout<<"constructor por defecto"<<endl;
        };

        void imprimir();

        

        //void real(double x) {(*this).r = x;}
        //double real() const {cout<<r<<endl;}

        //double operator *(Complejo c1, Complejo c2);
    private:
        double r, i;

};


void complejo::imprimir(){
    cout<<"real:"<<r;
    cout<<"\timaginario:"<<i<<endl;
}



int main(){
    
    complejo v(1.);
    v.imprimir();
    cout<<"----------------------"<<endl;
    complejo w;
    w.imprimir();
    cout<<"----------------------"<<endl;
    complejo x(2, -1.2);
    x.imprimir();
    cout<<"----------------------"<<endl;
    complejo y (x);
    y.imprimir();
    cout<<"----------------------"<<endl;
    complejo z = y;
    z.imprimir();
    cout<<"----------------------"<<endl;
    complejo i2 = -1;
    i2.imprimir();
    cout<<"----------------------"<<endl;
    x = -3.5;
    x.imprimir();


    cout<<"-----FINALIZADO-----------------"<<endl;
}