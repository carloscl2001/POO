 #include <iostream>
 #include <math.h>
using namespace std;
class Complejo {
        double real, imag;
    public:
        Complejo (double r = 0., double i = 0.): real(r), imag(i) {}
        Complejo (const Complejo& c) {real = c.real; imag = c.imag;}
        void print() { cout << "(" << real << "," << imag << ")"; }
        // operator double() const { return sqrt(real * real + imag * imag); }
        friend Complejo operator +(const Complejo& c1, const Complejo& c2);
        friend Complejo operator -(const Complejo& c1, const Complejo& c2);
        friend Complejo operator *(Complejo& c1, Complejo& c2);
};  
Complejo operator +(const Complejo& c1, const Complejo& c2) {
    return Complejo(c1.real + c2.real, c1.imag + c2.imag);
}
Complejo operator -(const Complejo& c1, const Complejo& c2) {
    return Complejo(c1.real - c2.real, c1.imag - c2.imag);
}
Complejo operator *(Complejo& c1, Complejo& c2) {
    return Complejo(c1.real * c2.real - c1.imag * c2.imag,c1.real * c2.imag + c2.real * c1.imag);
}

int main() {
Complejo a(3.);
Complejo b(2., 2.);
Complejo c = a + b;
Complejo d = b + 3.;
Complejo e = 3. + b;
cout << "a * b = ", (a * b).print();
}