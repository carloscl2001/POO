#include <iostream>
class racional
{
    public:
        racional(int n1 = 0, int n2 = 1);
        racional operator/=(const racional& r);
        racional operator*=(const racional& r);
        friend racional operator*(const racional& r1, const racional& r2);
        friend racional operator/(const racional& r1, const racional& r2);
        friend bool operator<(const racional&, const racional&);
        friend bool operator>=(const racional&, const racional&);
        racional inv() const;
    private:
        int n,d;
        int mcd(unsigned int, unsigned int);
};

racional::racional(int n1, int n2):n(n1), d(n2){
    if(n1 == 0){
        n = 0;
        d = 1;
    }else if(d <= 0 ){
        n = -n1;
        d = -n2;
    }

    if((n1 && n2) % mcd(n1,n2) == 0){
        n1 /= mcd(n1,n2);
        n2 /= mcd(n1,n2);
    }

}

// racional racional::operator*=(const racional& r){
//     this->n *= r.n;
//     this->d *= r.d;
//     return *this;
// }

// racional racional::operator/=(const racional& r){
//     *this *= r.inv();
// }

// using namespace std;
// int main(){
//     racional r(0,1);
//     racional s; // equivalente a la instrucción anterior.
//     racional t(4,-8); // racional -1/2
//     racional v(3); // racional 3/1
//     racional w=5; // racional 5/1
//     racional x = v;
//     racional y(x);
//     r = 4;
//     cout<<"hola"<<endl;
// }
#include<iostream>
using namespace std;
struct B {
    virtual void f ( ) { std::cout << "f ( ) de B" << std::endl; }
};
struct D:B {
    void f ( ) { std::cout<<"f ( ) de D" << std::endl;}
};
void f ( B b) {
    std::cout << "f ( ) externa"<< std::endl; b.f();
}
int main( ) {
    B b; 
    D d;
    f(b); // f externa y f de b
    f(d); // f externa y f de d
}