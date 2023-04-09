#include <iostream>
// class C {
//     public:
//     C(int i = 0): n(i) {}
//     void mostrar(){ std::cout << "i = " << n << std::endl; }
//     private:
//     int n;
// };
// int main() {
//     C c; 
//     c.mostrar(); 
// }

class C {
public:
    C();
    C(int a, int b, int c, int d);
    // int f1(int i) const;
    int f2(int i);
    // static void f3() {m = h;}
    static int n;
private:
    int h;
    mutable int i;
    const int j;
    mutable int k;
    static int m;
};

// int C::f1(int i) const
// {
//     h = i; k = i; return 0;
// }

C::C():j(0){h = i = k = 0;}

// C::C(int a, int b, int c, int d) : h(a), i(b), j(c), k(d) {}

int C::f2(int i){
    k = i; h = i; return 0;
}

int C::n = 3;

int main() {
    C c1, c2;
    std::cout << C::n << " " << c2.n << std::endl;
    c1.n = 4;
    std::cout << C::n << " " << c2.n << std::endl;
 
}
