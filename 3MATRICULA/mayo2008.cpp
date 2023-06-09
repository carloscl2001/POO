#include <iostream>
#include <set>

using namespace std;

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
