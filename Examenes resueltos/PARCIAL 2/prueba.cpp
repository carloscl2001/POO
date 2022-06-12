#include <iostream>
using namespace std;

class A{
    public:
        virtual void f() = 0;
        virtual void g() {cout<<"g de A"<<endl;};
};

class B: public A{
    public:
        void f() {cout<<"f de B"<<endl;}
        //virtual void g() {cout<<"g de B"<<endl;}
        //void g(int) {cout<<"g int de B"<<endl;}
};

class C: public B{
    public:
        void g() {cout<<"g de C"<<endl;}
};

class D: public C{
    public:
        void g() {cout<<"g de D"<<endl;}
};

void f(A& a){
    a.g();
}

int main(){
    A *pa = new D();
    B b;
    //a.g();
    
    f(b);
    pa->g();

    return 0;
}
