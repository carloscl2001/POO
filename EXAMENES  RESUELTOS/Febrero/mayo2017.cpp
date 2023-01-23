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

class CD{
    public:
        void asocia(C& c, D& d);
        void asocia(D& d, C& c);
        C* asociados(D& d) const;
        set<D*> asociados(C& c) const;
    private:
        map <C*,set<D*>> asocCD;
        map <D*,C*> asocCD;
};

void CD::asocia(C& c, D& d){
    asocCD[&c].insert(&d);
}