#include <iostream>

using namespace std;

// class Complejo
// {   
//     public:
//         Complejo(double a = 0, double b = 0):a(a),b(b){}
//         double& real(){cout<<"NO Constante"<<endl;return a;}
//         double& imag(){cout<<"NO Constante"<<endl; return b;}
//         double real() const {cout<<"SI Constante"<<endl;return a;}
//         double imag() const {cout<<"SI Constante"<<endl;return b;}

//     private:
//         double a,b;
// };

// //Operadores fuera de la clase
// bool operator == (const Complejo& c1, const Complejo& c2);
// Complejo operator * (const Complejo& c1, const Complejo& c2);
// bool operator != (const Complejo& c1, const Complejo& c2);
// Complejo operator +(const Complejo& c1, const Complejo& c2);
        
// //_______________________________________________________________

// Complejo operator * (const Complejo& c1, const Complejo& c2){
//     cout<<"Multiplicacion"<<endl;
//     return Complejo(c1.real() * c2.real(), c1.imag() * c2.imag() );
// }

// bool operator ==(const Complejo& c1, const Complejo& c2)
// {
//     cout<<"Igualdad"<<endl;
//     if(c1.real() == c2.real() && c1.imag() == c2.imag()) {return true;}
//     else {return false;}
// }

// bool operator !=(const Complejo& c1, const Complejo& c2)
// {
//     return!(c1 == c2);
// }

// Complejo operator +(const Complejo& c1, const Complejo& c2)
// {
//     cout<<"Suma"<<endl;
//     return Complejo(c1.real() + c2.real(), c1.imag() + c2.imag());
// }

// int main(){

//     Complejo i, i2, z, y;

//     i.real() = 5;
//     i.imag() = 10;

//     cout<<"----------------------"<<endl;
//     i2 = i * i;
//     cout<<"i: "<<i.real()<<" "<<i.imag()<<endl;
//     cout<<"i2: "<<i2.real()<<" "<<i2.imag()<<endl;

//     cout<<"----------------------"<<endl;
//     if(i2 == Complejo(-1.0)) cout<<"ok"<<std::endl;
//     if(i2 != -1.0) cout <<"mal"<<std::endl;

//     z = y = Complejo(2.5,1);
//     y.imag() = -y.imag();
//     cout<<y.imag()<<endl;
//     cout<<"----------------------"<<endl;

//     cout<<"z: "<<z.real()<<" "<<z.imag()<<endl;
//     cout<<"y: "<<y.real()<<" "<<y.imag()<<endl;
//     if( z + y == 2 * z.real())  cout<<"OK"<<std::endl;
//     cout<<"----------------------"<<endl;


//     cout<<"z: "<<z.real()<<" "<<z.imag()<<endl;
//     cout<<"y: "<<y.real()<<" "<<y.imag()<<endl;

//     if( z + y != Complejo(0,2 * z.imag()))  cout<<"Mal"<<std::endl;

// }

class A{};
class B{


    public:

        int i_;
        const char* s_;
        int j_;


        B(int i, const char* s = "CADENA GUAPA", int j = 0):i_(i),j_(j), s_(s){
        }
};

int main(){
    A a1,a2;
    B b1 = 0;
    cout<<b1.i_<<endl;
    cout<<b1.s_<<endl;
    cout<<b1.j_<<endl;
    
//     B* p = new B(10);
//     B* q = new B[10];
//     B b2 = "examen";
//     A a3(b1);
//     a2 = a1 = *q;
//     B b3 = a2;
cout<<"hola"<<endl;
}