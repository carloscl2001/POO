#include <iostream>
#include <set>
#include <map>
using namespace std;

class A{
    public:
        typedef map<char, C*> calificada_;

    private:

};

class B{
    public:
        typedef set<D*> d_;
    private:

};

class C{
    public:
        typedef set<D*> d_;
        C& c_;
    
    private:
        char c1 = 'i';

};

class D{
    public:
        C* c_;
    private:

};