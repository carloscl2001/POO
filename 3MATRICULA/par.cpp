#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <class T1, class T2> class par{
    public:
        par(const T1& x = T1(), const T2& y = T2()): prime(x), segun(y) {}
        T1 primero() const {return prime;}
        T1& primero() const {return prime;}
        T2 segundo() const {return segun;}
        T2& segundo() const {return segun;}
    protected:
        T1 prime;
        T2 segun;
};

//a)
template <class T1, class T2>
iostream operator <<(iostream& os, par<T1,T2>& p){
    os<<primero()<<segundo()<<endl;

    return os;
}


template <class T1, class T2>
class racional: public par{

};