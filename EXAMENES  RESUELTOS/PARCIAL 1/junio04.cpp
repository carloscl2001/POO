#include <iostream>
class Cadena{
    private:
        char* pc;
        size_t n;
    public: 
        explicit Cadena(size_t tam = 0);
        Cadena(const char*);
};  

Cadena::Cadena(size_t tam):n(tam), pc(new char[n]){
    for(int i = 0; i < tam; i++){
        pc[i] = ' ';
    }
}

