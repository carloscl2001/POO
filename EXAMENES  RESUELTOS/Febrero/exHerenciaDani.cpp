#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std ;
// Herencia
class V{
    public :
    void f () { cout << " f ( ) de v " << endl ; }
    virtual void g ( ) = 0 ;
    virtual void g ( int i ) { cout << " g ( " <<  i  << " ) de V" << endl;}
    virtual void h ( ) { cout << " h ( ) de V" << endl ; }

    void j(){}
        protected :
        int v_;
};

class W : virtual public V {
public :
    void f ( int i ) { cout << " f ( " << i << " ) de W"<< endl ; }
    void g ( ) { cout << " g ( ) de W " << endl ; }
protected :
    int w_;
};


class X : virtual public V { // abstracta
public :
    void f () {cout << " f ( ) de X " << endl ; }
    void h () { cout << " h ( ) de X " << endl ; }
protected:
int x_;
} ;
class Y : public W{ 
public :
    void g ( ) { cout << " g ( ) de Y " << endl ; }
    void h ( ) { cout << " h ( ) de Y " << endl ; }
private :
    int y_;
} ;
class Z : public W , public X { 
    int z_;
public :
    void g ( ) { std :: cout << " Z :: g ( )" << std :: endl ; }
    void g ( int i ) { std :: cout << " Z :: g ( int ) " << std :: endl ; }
} ;
// FUNCIONES
void f(V& v ) {
    cout << " f ( ) externa" << endl ;
    v.f ( ) ;
    v.g ( ) ;
    v.h ( ) ;
}

int main(){
    // V v;
    // V *pV;
    // X x;
    // Y y;
    // W w;
    Z z;
    // f(v);
    // f(w);
    // f(x);
    // f(z);
    // z.X::f();
    z.f();
    z.f(5);
    // z.g(3);
    // z.h();s
    // pV = new Z;
    // pV->f();
    // pV->X::f();
    // pV->g();
    // pV->g(2.5);
    // pV->h();
    // delete pV;

}