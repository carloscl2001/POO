#include <iostream>
using namespace std;
class B{
    public:
        B(){std::cout<<"Construcctor de Base"<<endl;}
        ~B(){std::cout<<"Destructor de Base"<<endl;}
};


class D{
    public:
        D(){std::cout<<"Construcctor de Derivada"<<endl;}
        ~D(){std::cout<<"Destructor de Derivada"<<endl;}
};

int main(){
    B* pb;
    pb = new B();
    delete pb;
}