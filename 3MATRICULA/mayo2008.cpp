#include <iostream>
#include <set>

using namespace std;
/*
class A{};

class D{};

class B: public A{
    private:
        set<D*> d_;
    public:
        void rel3(D& d);
};

class C{
    private:
        D d;
    public:

};

class D{
    private: 
        B* b;
    public:
        void rel3(B& b);
};

class E: public A{
    private:
        set<D*> d_;
    public:
        void rel5(D& d);
};

class F: public C, public E{};
*/

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
    //A *pa;  //sin problema
    //B *pb;  //sin problema
    D d,*pd;    //sin problema
    cout<<("--------------");

    pd = &d;    //sin problema
    //pa = &d;    //sin problema
    cout<<("--------------")<<endl;
    //pa->f();    //Metodo f de A
    //pb = &d;    //sin problema
    //pb->f();    //Metodo f de B
    cout<<("--------------")<<endl;
    //d =*pa;     //error
    //pd = (D*)pb;    //sin poroblema
    pd->B::f(); //Metodo f de B
    d.C::f();   //Metodo f de C
}
