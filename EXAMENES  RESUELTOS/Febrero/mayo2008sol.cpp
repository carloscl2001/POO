#include <iostream>
#include <string>
using namespace std;
class X {
public:
    X(string s = "por omision") { cout << "Constructor de X: " << s << endl; }
};
class A {
    X x;
    public:
    A(): x("A") { cout << "Constructor de A" << endl; }
    void f() { cout << "Metodo f() de A" << endl; }
};
class B: virtual public A {
    X x;
    public:
    B() { cout << "Constructor de B" << endl; }
    void f() { cout << "Metodo f() de B" << endl; }

    
};
class C: virtual public A {
    X x;
    public:
    C() { cout << "Constructor de C" << endl; }
    void f() { cout << "Metodo f() de C" << endl; }
};
class D: public B,  public C {
    X x;
    public:
    D(): x("D") { cout << "Constructor de D" << endl; }
};


int main()
{
    A *pa;  //no hace na
    B *pb;      // no hace na
    C *pc;
    D d;
    D *pd;   // Constructor de X: A;   pd no hace na
                //Constructor de A;
                /*
                      Contructor de X: por omision // primero hace las variables por omision y luego los constructores 
                    Constructor de B
                    Contructor de X: por omision
                    Constructor de C
                    Contructor de X: D
                    Constructor de D
                */

    pd = &d;   //no hace na
    pa = &d;    // tampoco
    cout<<"--------------------------------------------------------"<<endl;
    pa->f();    // Metodo de f() de A
    pc = &d;
    pc->f();
    pb = &d;
    pb->f();    //Metedo de f() de B
    // d = *pa;    //esto esta mal estamos asignando a una d algo de A y encima d ni es puntero
    pd = (D *)pb; 
    pd->B::f(); // Metodo de f() de B
    d.C::f(); // Metodo de f() de C
}