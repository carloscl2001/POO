#include <iostream>


using namespace std;
class B{
    public:
        void f(){ cout<< "f() de B" << endl;}
        virtual void g() {cout << "g() de B "<< endl;}
        virtual void h() = 0;
    protected:
        int b;
};

class D1: virtual public B{
    public:
        void f(){ cout << "f() de D1" << endl;}
        virtual void g(){ cout << "g() de D1" << endl;}
    protected:
        int d1;
};

class D2: virtual public B{
    public:
        void f(int){ cout << "f(" << d2 <<") de D2" << endl;}
        virtual void h(){ cout << "h() de D2"<< endl; }
    protected:
        int d2;
};
class D3: public D1{
    public:
        void g(){ cout << "g() de D3" << endl;}
        void h(){ cout << "h() de D3" << endl;}
    private:
        int d3;
};

class D4: public D1, public D2{
    private:
        int d4;
};

void f(B& b){
    cout << "f() externa" << endl;
    b.f();
    b.g();
    b.h();
}

int main(){
    
    //B b,*pB; 
    //D1 d1; 
    D2 d2; D3 d3; D4 d4;
    //f(b); f(d1);  no se pueden hacer

    //f(d2);
    //f externa
    //f de B
    //g de B
    //h de D2

    //f(d3);
    //f externa
    //f de B
    //g de D3
    //h de D3
 
    //f(d4);
    //f externa
    //f de B
    //g de D1
    //h de D2
    
    //d4.D1::f();
    //f de D1

    //d4.f(5);
    //ambiguo

    //d4.f(3.5);
    //ambiguo

    //d4.g();
    //g de D1

    //d4.h();
    //h de D2

    //no esta definido pb ni pB
    //pB = new D4;
    //pB->f();
    //pb->D4::f(3);
    //pb->g();
    //pB->h();
    //delete pB;
}