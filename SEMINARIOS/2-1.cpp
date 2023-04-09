#include <iostream>
#include <cstring>
using namespace std;
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

// class C {
// public:
//     C();
//     C(int a, int b, int c, int d);
//     // int f1(int i) const;
//     int f2(int i);
//     // static void f3() {m = h;}
//     static int n;
// private:
//     int h;
//     mutable int i;
//     const int j;
//     mutable int k;
//     static int m;
// };

// int C::f1(int i) const
// {
//     h = i; k = i; return 0;
// }

// C::C():j(0){h = i = k = 0;}

// // C::C(int a, int b, int c, int d) : h(a), i(b), j(c), k(d) {}

// int C::f2(int i){
//     k = i; h = i; return 0;
// }

// int C::n = 3;

// int main() {
//     C c1, c2;
//     std::cout << C::n << " " << c2.n << std::endl;
//     c1.n = 4;
//     std::cout << C::n << " " << c2.n << std::endl;
 
// }


// class punto {
//     double x, y;
// public:
//     punto(double a = 0., double b = 0.) : x{a}, y{b} {
//         std::cout << "Primer constructor(" << a << ", " << b << ")" << std::endl;
//     }
//     punto(const punto& p) : x{p.x}, y{p.y} {
//         std::cout << "Segundo constructor" << std::endl;
//     }
//     punto& operator =(const punto& p)
//     { x = p.x; y = p.y; return *this; 
//         std::cout << "Asignacion" << std::endl;
//     }
// };

// int main(){
//     punto p;
//     punto q{};
//     punto r{2.,};
//     punto s{3.4};
//     punto t{};
//     punto u(q);
//     punto v = p;
//     t = q;
// }

// class Libro1 {
//     string titulo_;
//     int pags_;
//     public:
//     // Libro1(string t = "", int p = 0){
//     //     cout<<"Constructor Libro1"<<endl;
//     // };
//     // ...
// };

// class Libro2 {
//     string titulo_;
//     int pags_;
//     public:
//     // Libro2(string t, int p = 0){
//     //     cout<<"Constructor Libro2"<<endl;
//     // };
//     // Libro2(const char* c){
//     //     cout<<"Constructor Libro22"<<endl;
//     // };
//      // ...
// };

// int main(){
//     Libro1* lib4 = new Libro1("El Quijote");
//     Libro2* lib5 = new Libro2("El Quijote");
// }


// class Libro {
    
//  public:
//     Libro() : titulo_(new char[1]), paginas_(0) {*titulo_= 0;}

//     Libro(const char* t, int p) : paginas_(p) {
//         titulo_ = new char[strlen(t) + 1];
//         strcpy(titulo_, t);
//     }


//     ~Libro() { delete[] titulo_; }

//     int paginas() const { return paginas_; }
//     char* titulo() const { return titulo_; }

//     char* titulo_; 
//     int paginas_;
// };

// void mostrar(Libro l) {
//     cout << l.titulo() << " tiene "<< l.paginas() << " páginas" << endl;
// }
 
//  int main() {
//     Libro l1("Fundamentos de C++", 474), l2;
//     l2 = l1;
//     mostrar(l2);
//     cout<<"-----------------------------"<<endl;
//     l1.titulo_ = "HOLA";
//     cout<<"-----------------------------"<<endl;
//     mostrar(l2);
// }


// struct B; // Declaración adelantada
// struct A {
//     explicit A(B){
//         cout<<"Constructor de conversion"<<endl;
//     }; // Constructor de conversión de B a A
// };
// struct B {
//     operator A(){
//         cout<<"Operador de conversion"<<endl;
//     }; // Operador de conversión de B a A
// };
// void f(const A&); // Recibe por referencia un objeto constante de A 
// int main() { 
//     B b; f(b);
// }