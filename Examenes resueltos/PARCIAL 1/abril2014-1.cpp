#include <iostream>
using namespace std;

class Complejo{
    public:
        Complejo(double n1 = 0, double n2 = 0);
        void mostrar();

        void real(double x) {(*this).r = x;}
        double real() const {cout<<r<<endl;}

        double operator *(Complejo c1, Complejo c2);
    private:
        double r, i;

};

Complejo::Complejo(double n1, double n2): r(n1), i(n2){}

void Complejo::mostrar(){
    cout<<"real:"<<r;
    cout<<"\timaginario:"<<i<<endl;
}



int main(){
    Complejo i,i2,z,y;

    //i.real() = 0;
    i2 = i * i;


    cout<<"hola"<<endl;
}