#include <iostream>
using namespace std;
// class complejo
// {
//     public:
//         complejo(double r1 = 0, double r2 = 0):r(r1), i(r2){};
//         ~complejo();
//         void real(double rl){r = rl;}
//         double& real(){return r;}
//         double& imag(){return i;}
//         friend complejo operator*(const complejo& c1,const complejo& c2);
//         friend bool operator==(const complejo& c1,const complejo& c2);
//         friend bool operator!=(const complejo& c1,const complejo& c2);
//         friend complejo operator+(const complejo& c1, const complejo& c2);
//         friend complejo operator-(const complejo& c1, const complejo& c2);
//         complejo& operator-();
//     private:
//         double r;
//         double i;
// };

// int main(){
//     complejo v(1.);
//     complejo w;
//     complejo x(2, -1.2);
//     complejo y (x);
//     complejo z = y;
//     complejo i2 = -1;
//     x = -3.5;


//     complejo i, i2, z, y;

//     i.real() = 0;
//     i.imag() = 1;

//     i2 = i * i;

//     if(i2 == complejo(2.5,1)) cout<<"ok"<<std::endl;
//     if(i2 != -1.0) cout <<"mal"<<std::endl;

//     z = y = complejo(2.5,1);

//     y.imag() = -y.imag();

//     if( z + y != complejo(0,2 * z.imag()))  cout<<"Mal"<<std::endl;

//     if(z + -y != complejo(0,2 * z.imag())) cout << "MAL\n";
// }

// complejo operator*(const complejo& c1, const complejo& c2){
//     return complejo(c1.i * c2.i, c1.r * c2.r);
// }

// bool operator==(const complejo& c1, const complejo& c2){
//     return ( c1.i == c2.i && c1.r == c2.r);
// }

// bool operator!=(const complejo& c1, const complejo& c2){
//     return !(c1 == c2);
// }

// complejo operator+(const complejo& c1, const complejo& c2){
//     return complejo(c1.i + c2.i, c1.r + c2.r);
// }

// complejo& complejo::operator-(){
//     r = -r;
//     i = -i;
//     return *this;
// }

class A{};

class B{
    public:
        B(int i, const char* s = "", int j = 0);
        B(const B& b);
        B& operator = (const B& b);
        B& operator = (const A& a);
        operator A() const;
};

int main(){
    A a1, a2;
    B b1 = 0;
    // B* p = nesw B(10);
    // B* q = new B[10];sss
    // B b2 = "examen";s
    // A a3(b1);s
    // a2 = a1 = *q;
    // B b3 = a2;s
    cout<<"hola"<<endl;
}