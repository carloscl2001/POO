#include <iostream>
#include <vector>
#include <cassert>
#include <sort>

using namespace std;
class MatrizDispersa
{
    public:
        explicit MatrizDispersa(size_t n1 = 1, size_t n2 = 1):n(n1),m(n2){}
        void asignar(size_t pos1, size_t pos2, double valor);
        double valor(size_t pos1, size_t pos2) const;
        size_t filas() const{return n;}
        size_t columnas() const{return m;}
        size_t n_valores() const;
        bool buscar(size_t pos1, size_t pos2, size_t& indice);
        
    private:
        struct terna{
            size_t f,c;
            double v;
            bool operator<(const terna& t1, const terna& t2);
        };
        size_t n;
        size_t m;
        std::vector<terna>val;
};

void MatrizDispersa::asignar(size_t pos1, size_t pos2, double valor){
    int i = 0;
    for(auto it = val.begin(); it != val.end(); it++){
        if(it->f == pos1 && it->c == pos2)
            val[i].v = valor;
        else{
            terna t;
            t.f = pos1;
            t.c = pos2;
            t.v = valor;
            val.insert(it, t);
        }
        i++;
    }
    val.sort([](terna t1, terna t2) -> bool{return (t1 < t2);});
}

double MatrizDispersa::valor(size_t pos1, size_t pos2) const{
    int i = 0;
    for(auto it = val.begin(); it != val.end(); it++){
        if(it->f == pos1 && it->c == pos2)
            return val[i].v;
        i++;
    }
}

size_t MatrizDispersa::n_valores() const{
    size_t i = 0;
    for(auto it = val.begin(); it != val.end(); it++)
        i++;
    return i;
}

bool MatrizDispersa::buscar(size_t pos1, size_t pos2, size_t& indice){
    size_t i = 0;
    terna t;
    t.f = pos1;
    t.c = pos2;
    while(indice < val.size() && val[i] < t){
        if(it->f == pos1 && it->c == pos2){
            return true;
            indice = i;
        }
        else{
            if(i == n_valores())
                indice = n_valores();
            else
                indice = i
            return false;
            
        }
        i++;
    }
}

friend bool MatrizDispersa::terna::operator <(const terna& t1, const terna& t2){
    if(f < t2.f) return true;
    if(f == t2.f && c < t2.c) return true;

    return false;

}