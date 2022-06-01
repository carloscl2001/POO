#include <iostream>
#include <set>
#include <map>
using namespace std;

class A{
    public:
        typedef map<char, C*> calificada_;
        void asociaC(C&);
        calificada_ asocaiC() const;

    private:

};

class B{
    public:
        typedef set<D*> d_;
        void asociaB(D&);
        d_ asociaB() const;
    private:

};

class C{
    public:
        typedef set<D*> d_;
        void asociaD(D&);
        d_ asociaD() const;
        C& c_;
    
    private:
        char c1 = 'i';

};

class D{
    public:
        C* c_;
    private:

};