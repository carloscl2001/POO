#include <stdio.h>
#include <iostream>
using namespace std;

class racional{
    public:
        racional(int n1 = 0, int n2 = 1);
        racional& inv();

        friend racional operator +(const racional& r1, const racional& r2);
        friend racional operator -(const racional& r1, const racional& r2);

        friend bool operator ==(const racional& r1, const racional& r2);
        friend bool operator !=(const racional& r1, const racional& r2);
        friend bool operator <(const racional& r1, const racional& r2);
        friend bool operator <=(const racional& r1, const racional& r2);
        friend bool operator >=(const racional& r1, const racional& r2);
        friend bool operator >(const racional& r1, const racional& r2);

        racional operator +();
        racional operator -();

    private:
        int n, d;
        static int mcd(int, int);
};

racional::racional(int n1, int n2):n(n1/mcd(n1,n2)), d(n2/mcd(n1,n2)){
    if(d == 0){
        throw invalid_argument("no valido");
    }

    if(d > 0){
        n = -n;
        d = -d;
    }
}

inline racional racional::operator+(){
    return *this;
}

inline racional racional::operator-(){
    return (-n,d);
}

racional operator +(const racional& r1, const racional& r2){
    int mcd = racional::mcd(r1.d, r2.d);
    return racional(r1.n*(mcd/r1.d) + r2.n*(mcd/r2.d), mcd);
}


bool operator ==(const racional& r1, const racional& r2){
    if(r1.n == r2.n && r1.d == r2.d){
        return true;
    }else{
        return false;
    }
}

bool operator !=(const racional& r1, const racional& r2){
    return !(r1 == r2);
}

int main(){

    racional r(0,1);//Constructor 
    racional s;//Constructor por defecto
    racional t{4,-8};//Constructor 
    racional u(3);//Constructor de conversion
    racional v = 5;//Operador de asignacion
    racional w = v;//Constructor de copia por defecto
    racional x {w};
    r = t;
    s = racional{9,6};
    v = -4;
    cout<<"hola"<<endl;
}