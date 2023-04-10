#include <iostream>
#include <cstring>
using namespace std;

class Cadena{
    private:
        char* pc;
        size_t n;
    public: 
        explicit Cadena(size_t tam = 0);
        Cadena(const char* cad);
        Cadena& operator = (const Cadena& cad);
        Cadena& operator = (Cadena&& cad);
        Cadena(const Cadena& cad);
        Cadena(Cadena&& cad);

        char operator[] (size_t t) const;
        char& operator[] (size_t t);

        class ClaseIndivida{};

        friend Cadena operator + (const Cadena& cad, const Cadena& cad2);


        operator const char* (){
            return pc;
        } 
};  

ostream& operator <<(ostream& os, const Cadena& cad);

Cadena::Cadena(size_t tam):n(tam), pc(new char[n+1]){
    for(int i = 0; i < tam; i++){
        pc[i] = ' ';
    }
    pc[n] = '\0';
}

Cadena::Cadena(const char* cad): n(strlen(cad)), pc(new char[n+1]){
    strcpy(pc, cad);
}


Cadena::Cadena(const Cadena& cad):n(cad.n), pc(new char[n+1]){
    strcpy(pc, cad.pc);
}


Cadena& Cadena::operator = (const Cadena& cad){
    if(this != &cad){
        //limpiamos el vector del implicito
        delete[] pc;

        //cambiamos tamanno del implicito
        n = cad.n;

        //reservamos memoria para el implicito y rellenamos
        pc = new char[n + 1];
        strcpy(pc, cad.pc);
    }
    return *this;
}

Cadena& Cadena::operator = (Cadena&& cad){
    if(this != &cad){
        //limpiamos el vector implicito, movimiento logico de datos y  cambiamos tamnno
        delete[] pc;
        pc = cad.pc;
        n = cad.n;

        cad.n = 0;
        cad.pc = new char[1];
        cad.pc[0] = '\0';

    }
    return *this;
}

Cadena::Cadena(Cadena&& cad):n(cad.n), pc(cad.pc){
    pc = cad.pc;
    
    cad.n = 0;
    cad.pc = new char[1];
    cad.pc[0] = '\0';
}

char Cadena::operator[](size_t i) const{
    if(i >= 0 && i <= n)
        return pc[i];
    else
        throw ClaseIndivida();
}


char& Cadena::operator[](size_t i) {
    if(i >= 0 && i <= n)
        return pc[i];
    else
        throw ClaseIndivida();
}


Cadena operator + (const Cadena& cad1, const Cadena& cad2){
    Cadena aux(cad1.pc);
    strcat(aux.pc, cad2.pc);
    return aux;
}


ostream& operator << (ostream& os, const Cadena& cad){
    os<<(const char*)cad;
    return os;
}

