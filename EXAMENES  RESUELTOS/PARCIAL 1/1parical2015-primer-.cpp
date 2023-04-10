#include <iostream>
using namespace std;

class Vector{
    public:     
        explicit Vector(size_t tam, double num = 0);
        Vector(initializer_list<double> lista);
        ~Vector();
        Vector(const Vector&);
        Vector(Vector&&);
        double& at(size_t i);
        double at(size_t i) const;
        void mostrar() const;


        
    private:
        size_t n;
        double* datos;

};

Vector::Vector(size_t tam, double num):n(tam), datos(new double[tam]){
    for(int i = 0; i < tam; i++){
        datos[i] = num;
    }
}

Vector::Vector(initializer_list<double> lista):n(lista.size()), datos(new double[lista.size()]){
    copy(lista.begin(), lista.end(), datos);
}

//b) No es válido y que el compilador no es capaz de destruir correctamente objetos dinamicos
Vector::~Vector(){
    n = 0;
    delete[] datos;
}

//d)No es válido y que el compilador no es capaz de copiar correctamente objetos dinamicos
Vector::Vector(const Vector& v): n(v.n), datos(new double[v.n]){
    for(int i = 0; i <n; i++){
        datos[i] = v.datos[i];
    }
}

//e) No es válido y que el compilador no es capaz de copiar correctamente objetos dinamicos
Vector::Vector(Vector&& v): n(v.n), datos(v.datos){
    v.n = 0;
}

//f)
double& Vector::at(size_t i){
    if(i >= 0 && i < n)
        return datos[i];
    else
        throw std::out_of_range("Indice fuera de rango");
}

double Vector::at(size_t i) const{
    if(i >= 0 && i < n)
        return datos[i];
    else
        throw std::out_of_range("Indice fuera de rango");
}



void Vector::mostrar() const{
    for(int i = 0; i < n; i++)
    {
        cout<<"\tpos["<<i<<"]:"<<datos[i];
    }
}

int main(){
    // Vector v1(5, 1.2);
    // Vector v2(4); //v2={0, 0, 0, 0}
    // Vector v3;
    // Vector v4 = 3;
    // Vector v5={1,2.5,3}; //v5={1,2.5,3}


    const Vector v6={1,2,3,4,5,6};
    Vector v7(6);
    try{
        v7.at(0)=v6.at(3);
    }catch (std::out_of_range& e){
        std::cout << e.what() << std::endl;
    }
    v6.mostrar();
    v7.mostrar();

    cout<<"-------|FIN|-------"<<endl;
}