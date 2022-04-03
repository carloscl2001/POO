#include <iostream>
#include <initializer_list>

using namespace std;

class Vector
{
    public:
        explicit Vector(size_t n, double d = 0);
        Vector(const std::initializer_list<double>& li);
        Vector(const Vector& v);
        Vector(Vector&& v);
        ~Vector();
        double& at(size_t i);
        double at(size_t t)const;

    private:
        size_t n;
        double* datos;
};

Vector::Vector(size_t n,double d): n(n), datos(new double[n])
{
    for(int i = 0; i < n; i++)
    {
        datos[i] = d;
    }
}

Vector::Vector(const std::initializer_list<double>& li): n{li.size()}, datos{new double(li.size())}
{
    std::copy(li.begin(),li.end(), datos);
}

Vector::~Vector()
{
    delete[] datos;
}

Vector::Vector(const Vector& v): n(v.n), datos(new double[v.n])
{
    for(int i = 0; i < n; i++)
    {
        datos[i] = v.datos[i];
    }
}

Vector::Vector(Vector&& v): n(v.n), datos(v.datos)
{
    for(int i = 0; i < n; i++)
    {
        datos[i] = v.datos[i];
    }
    
    v.n = 0;
    v.datos = nullptr;
}

double& Vector::at(size_t i)
{
    if(i < n)
    {
        throw std::out_of_range("Indice fuera del rango");
    }
    else{
        return datos[i];
    }
}

double Vector::at(size_t i) const
{
    if(i < n)
    {
        throw std::out_of_range("Indice fuera del rango");
    }
    else{
        return datos[i];
    }
}


class doble
{
    public:
        doble(double n);
        inline operator double(){return d;}
    private:
        double d;
};

doble::doble(double n): d(n){}

int main(){
double a = 1.5, b= 10.5;
doble c = 5.25,
d=c;
double e = 4;
e = a;
std::cout << c / d * b + b * c - c * c / b + b / c << std::endl; //65
d = a = b += c;
std::cout << d << ' ' << a << ' ' << b << ' '<< c << ' ' << e <<std::endl; // 15,75 15,75 15,75 5,25
}