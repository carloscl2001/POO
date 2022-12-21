#include <iostream>
using namespace std;

class A{
    public:
        virtual void f() = 0;
        virtual void g() = 0;
};

class B: virtual public A{
    public:
        void f() {cout<<"f de B"<<endl;}
        //virtual void g() {cout<<"g de B"<<endl;}
        //void g(int) {cout<<"g int de B"<<endl;}
};

class C: virtual public A{
    public:
        void g() {cout<<"g de C"<<endl;}
};

class D: public B, public C{
    public:
        void g() {cout<<"g de D"<<endl;}
        void g(int) {cout<<"g int de D"<<endl;}
};

void f(A& a){
    a.g();
}

int main(){
    A *pa = new D();
    D d;
    //a.g();
    
    f(d);
    pa->g();

    return 0;
}
