#include <iostream>
#include <cstring>
using namespace std;

class Cadena{
    public:
        explicit Cadena(size_t t = 0);
        Cadena(const char* cad);
        Cadena operator =(const Cadena& cad);
        char operator[](int i)const ;
        char& operator[](int i);

        friend Cadena operator+(const Cadena& cad1, const Cadena& cad2);

        class AccesoIndebido{};
    private:
        char* pc;
        size_t n;
};

Cadena::Cadena(size_t t):pc(new char[t + 1]), n(t){
    for(int i = 0; i < t; i++){
        pc[i] = ' ';
    }
    pc[t] = '\0';
}

Cadena::Cadena(const char* cad){
    char aux = cad[0];
    int n = 0;
    while(aux != '\0')
    {
        n++;
    }

    pc = new char[n + 1];

    for(int i = 0; i < n; i++){
        pc[i] = ' ';
    }
    pc[n] = '\0';
}

Cadena Cadena::operator =(const Cadena& cad){
    if(this != &cad)
    {
        Cadena ca(cad.n);
        return ca;
    }
}

char Cadena::operator[](int i) const{
    if(i > 0 && i < n){
        return pc[i];
    }
    else{
        throw AccesoIndebido();
    }
}


char& Cadena::operator[](int i){
    if(i > 0 && i < n){
        return pc[i];
    }
    else{
        throw AccesoIndebido();
    }
}


Cadena operator+(const Cadena& cad1, const Cadena& cad2){
    Cadena aux(cad1.n + cad2.n - 1);
    strcpy(aux.pc,cad1.pc);
    strcpy(aux.pc,cad2.pc);
}