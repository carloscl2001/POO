#include <iostream>
using namespace std;

class Cadena{
    public:
        explicit Cadena(size_t n = 0);
        Cadena(const char*);
        Cadena& operator =(const Cadena& cad);

        char operator [](size_t t) const;
        char& operator [](size_t t);
        class AccesoIndevido{
            public:
            private:
        };

        size_t n() const{return n_;}
        
        friend Cadena operator + (const Cadena& cad1, const Cadena& cad2);
    private:
        size_t n_;
        char* pc_;
};

//a)
Cadena::Cadena(size_t n):n_(n), pc_(new char[n+1]){
    for(size_t i = 0; i < n+1; i++){
        pc_[i] = ' ';
    }
    pc_[n+1] = '\0';
}

//b)Se pone explicit y ponemos n = 0

//c)
Cadena::Cadena(const char* cad):n_(0){
    for (size_t i = 0; cad[i] != '\0'; i++){
        n_++;
    }
    pc_ = new char[n_];
    for (size_t i = 0; i < n_; i++){
        pc_[i] = cad[i];
    }
    pc_[n_] = '\0';
}

//d)Si, es necesario ya que estamos trabajando con memoria dinámica.
Cadena& Cadena::operator = (const Cadena& cad){
    if(this != &cad){
        pc_ = cad.pc_;
        n_ = cad.n_;   
    }
    return *this;
}

//e)
char Cadena::operator [](size_t t) const{
    if(t >= 0 && t < n_ + 1){
        return pc_[t];
    }else{
        throw AccesoIndevido();
    }
}

char& Cadena::operator [](size_t t) {
    if(t >= 0 && t < n_ + 1){
        return pc_[t];
    }else{
        throw AccesoIndevido();
    }
}

//f)
Cadena operator +(const Cadena& cad1, const Cadena& cad2){
    Cadena aux(cad1.n_ + cad2.n_);
    for (size_t i = 0; i < cad1.n_; i++)
    {
        aux.pc_[i] = cad1.pc_[i];
    }
    for (size_t i =  cad1.n_; i < cad2.n_; i++)
    {
        aux.pc_[i] = cad2.pc_[i];
    }
    aux.pc_[aux.n_] = '\0';
    return aux;
}

//g)
ostream& operator <<(ostream& os, const Cadena& cad){
    for (size_t i = 0; i < cad.n(); i++)
    {
        os << cad[i];
    }
    return os;
}

//Ejercicio 4
//a)
template <typename iterator>
bool ordenado(iterator begin, iterator end){
    for(auto i = begin +1; i != end ; i++){
        if(*i < *(i -1)) return false;
    }

    return true;
}

template <typename iterator, typename T>
bool ordenado(iterator begin, iterator end, T func){
    for(iterator i = begin ; i != end ; i++){
        if(func(*i, *(i++))) return true;
    }
    return false;
}


struct funcion{
    public:
        bool operator()(int a, int b){
            return a < b;
        }
};

int main(){
    int v[6] = {1,2,3,4,5,6};
    funcion f;
    int a, b;
    cout << ordenado(&v[0], &v[5], f);
}