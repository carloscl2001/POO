#include <set>
using namespace std;
class A{};

class B: public A{
    private:
        set<D*> rel3;
};

class C{
    private:
        D d_;
};

class D{
    B* b;
};

class E: public A{
    private:
        set<D*> rel5;
};

class F: public C, public E{};