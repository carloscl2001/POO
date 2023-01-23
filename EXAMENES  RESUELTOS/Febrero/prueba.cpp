 #include <iostream>
using namespace std;
class A{
    public:
        void f(){cout<<"f de A"<<endl;}
};

class B:  public A{
    public:
        void f(){cout<<"f de B"<<endl;}
};

int main(){
    A a;
    B b{dynamic_cast<&B>(a)};

}