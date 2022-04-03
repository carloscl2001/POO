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