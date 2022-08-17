#include <iostream>
using namespace std;


class Vector{
    public:
        explicit Vector(size_t t, double n = 0);
        Vector(const initializer_list<double>& li);
        Vector(const Vector& v);
        Vector(Vector&& v);
        void mostrar() const;
        ~Vector();
        double at(int i) const;
        double& at(int t);
    private:
        size_t n;
        double* datos;
};

void Vector::mostrar() const{
    for(int i = 0; i < n; i++)
    {
        cout<<"\tpos["<<i<<"]:"<<datos[i];
    }
}

Vector::Vector(size_t t, double num): n(t), datos(new double[n]){
    for(int i =0; i < t; i++)
    {
        datos[i] = num;
    }
}

Vector::Vector(const initializer_list<double>& li):n(li.size()), datos(new double[li.size()])
{
    copy(li.begin(), li.end(), datos);
}

Vector::Vector(const Vector& v):n(v.n), datos(new double[v.n]){
    for(int i =0; i < n; i++)
    {
        datos[i] = v.datos[i];
    }
}

Vector::Vector(Vector&& v):n(v.n), datos(new double[v.n]){
    for(int i =0; i < n; i++)
    {   
        datos[i] = v.datos[i];
    }

    v.~Vector();
}

double Vector::at(int i) const{ 
    return datos[i];
}

double& Vector::at(int i){
    return datos[i];
}



Vector::~Vector(){
    n = 0;
    delete[] datos;
}
/*
int main(){
    
    const Vector v6 = {1,2,3,4,5,6};
    Vector v7(6);
    try{
        v7.at(0) = v6.at(9);
    }catch(std::out_of_range& e){
        std::cout<<e.what()<<std::endl;
    }
}
*/
//EJERCICIO 2
class doble{
    public:
        doble(double n);
        operator double();
    private:
        double n_;
};

doble::doble(double n):n_(n){}
doble::operator double(){return n_;}

int main(){
    double a = 1.5, b= 10.5;
    doble c = 5.25,
    
    d = c;
    std::cout<<d<<std::endl;
    std::cout << c / d * b + b * c - c * c / b + b / c << std::endl; //65
    d = a = b += c;
    std::cout << d << ' ' << a << ' ' << b << ' '<< c << std::endl; // 15,75 15,75 15,75 5,25
}