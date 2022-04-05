#include <iostream>

using namespace std;

class Complejo
{   
    public:
        Complejo(double a = 0, double b = 0):a(a),b(b){}
        double& real(){return a;}
        //double real() const {return a;}
        double& imag(){return b;}
        Complejo operator * (const Complejo& c);
        bool operator == (const Complejo& c);
        bool operator != (const Complejo& c);
        Complejo operator +(const Complejo& c);

    private:
        double a,b;
};

Complejo Complejo::operator * (const Complejo& c)
{
    a * c.a;
    b * c.b;

    return *this;
}

bool Complejo::operator ==(const Complejo& c)
{
    if(a == c.a && b == c.b) {return true;}
    else {return false;}
}

bool Complejo::operator !=(const Complejo& c)
{
    if(a != c.a && b != c.b) {return true;}
    else {return false;}
}

Complejo Complejo::operator +(const Complejo& c)
{
    a = a + c.a;
    b = b + c.b;
    return *this;
}

int main(){

    Complejo i, i2, z, y;

    i.real() = 0;
    i.imag() = 1;

    i2 = i * i;

    if(i2 == Complejo(2.5,1)) cout<<"ok";
    if(i2 != -1.0) cout <<"mal";

    z = y = Complejo(2.5,1);

    y.imag() = -y.imag();

    if( z + y != Complejo(0,2 * z.imag()))  cout<<"Mal"

}