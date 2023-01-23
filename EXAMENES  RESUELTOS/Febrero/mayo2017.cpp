#include <set>
#include <map>

using namespace std;
class A{
    public:
    private:
        map <int, C*> relacionAC;
};

class B{
    public:
    private:
        set <D*> relacionBD;
};

class C{
    public:
    private:
        int c1;
        set<D*> relacionCD;
        set<A*> relacionCA;
        B b_;
};

class D{
    public:
    private:
        C* c_;
};

class CDASOCIACION{
    public:
        typedef map<C*,set<D*>> CD;
        typedef map<D*,C*> DC;
        void asocia(C& c, D& d);
        void asocia(D& d, C& c);
        C* asociados(D& d);
        set<D*> asociados(C& c);
    private:
        CD relCD;
        DC relDC;
};

void CDASOCIACION::asocia(C& c, D& d){
    relCD[&c].insert(&d);

    if(relDC.find(&d) != relDC.end()){
        relDC.erase(&d);
    }
    relDC.insert(make_pair(&d,&c));

}

void CDASOCIACION::asocia(D& d, C& c){
    asocia(c, d);
}

C* CDASOCIACION::asociados(D& d){
    if(relDC.find(&d) != relDC.end())
        return relDC.find(&d)->second;
    else
        return nullptr;
}

set<D*> CDASOCIACION::asociados(C& c){
    if(relCD.find(&c) != relCD.end())
        return relCD.find(&c)->second;
    else
        return set<D*>();
}



