#include <iostream>

class Cadena{
    public:
        explicit Cadena(size_t t = 0);
        Cadena(const char* cad);
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
    
}
