#include <iostream>
#include <set>
#include <map>
using namespace std;

class A{
    public:
        typedef map<int, C*> calificada;
        calificada asociaC() const;
        void asociaC(C& c)
        {
            calificada.insert(make_pair(int, &C));
        };

    private:
        calificada calificada_;

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

        //COMPOSICION
        B b_;

        int obs() {return c1;}
    
    private:
        int c1;

};

class D{
    public:
        C* c_;
    private:

};