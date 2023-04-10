#include <iostream>
#include <cmath>
using namespace std;

class Complejo{
    

    public:
        double real, imag;

        explicit Complejo (double r = 0., double i = 0.):real(r), imag(i){ cout<<"Constructor\n"; cout<<real<<endl; cout<<imag<<endl;};
        Complejo (const Complejo& c){ cout<<"Cosntructor de copia"<<endl; this->real = c.real; this->imag = c.imag;} // fthis = c;g
        void print(){ std::cout << "(" << real << "," << imag << ")";}
        operator double() const{ cout<<"Conversion\n"; return sqrt(real * real + imag * imag); }

        friend Complejo operator +(const Complejo& c1, const Complejo& c2);
        friend Complejo operator -(Complejo c1, Complejo c2);
        friend const Complejo operator *(Complejo& c1, Complejo& c2);

        Complejo operator =(const Complejo& c){ cout<<"Asignacion\n"; this->real = c.real; this->imag = c.imag; return *this; }
};

Complejo operator +(const Complejo& c1, const Complejo& c2){
    cout<<"Suma\n";
    double aux = c1.real + c2.real;
    double aux2 = c1.imag + c2.imag;
    cout<<aux<<endl;
    cout<<aux2<<endl;
    return Complejo(aux, aux2);
} 
Complejo operator -(Complejo c1, Complejo c2){
    cout<<"Resta\n";
    c1.real -= c2.real, c1.imag -= c2.imag;
    return Complejo(c1.real, c1.imag);
}

const Complejo operator *(Complejo& c1, Complejo& c2){
    cout<<"Multiplicacion\n";
    return Complejo(c1.real * c2.real - c1.imag * c2.imag, c1.real * c2.imag + c1.imag * c2.real);
}


int main(){
    Complejo a(3.), b(2., 2.);
    cout<<"------------------\n"<<endl;
    Complejo c = a + b;
    cout<<c.real<<endl;
    cout<<c.imag<<endl;
    cout<<"------------------\n"<<endl;
    double e = 3. + b;
    cout<<"------------------\n"<<endl;
    cout<<b.imag<<endl;
    cout<<b.real<<endl;
    std::cout << "a * b = ", (Complejo(a * b)).print();
}