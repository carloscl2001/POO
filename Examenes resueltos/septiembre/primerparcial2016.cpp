#include <iostream>
#include <set>
#include <map>
using namespace std;

class A{
    public:
        typedef map<string,C*> ma;
        void imparte(C& c);
        const ma& imparte() const;
        
    private:
        ma ma_;
};

class B{
    public:
        typedef set<D*> sd;
        void imparte2(D& d);
        sd& imaprte2() const;

    private:
        sd sd_;
};

class C{
    private:
        int c1;
        typedef set<D*> sd2;
        B b_;
    public:
        sd2 sd2_;
};

class D{
    public:
        C* c;
        
    private:
};