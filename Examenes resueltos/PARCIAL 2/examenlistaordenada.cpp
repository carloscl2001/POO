#include <iostream>
#include <list>
#include <iterator>
using namespace std;


class ListaOrdenada {
    public:
        typedef list<double>::const_iterator iterator;
        ListaOrdenada():lista_(list<double>()) {}
        void insertar(double e);
        iterator buscar(double e) const;
        iterator begin() const;
        iterator end() const;

        size_t contar(double e) const;

    private:
        list<double> lista_;
};


void ListaOrdenada::insertar(double e){
    lista_.insert(lista_.end(),e);
}

iterator ListaOrdenada::buscar(double e) const{
    
}

