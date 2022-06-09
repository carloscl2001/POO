#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
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

ListaOrdenada::iterator ListaOrdenada::buscar(double e) const{
    for(iterator it = lista_.cbegin(); it != lista_.cend(); it++)
    {
        if(*it == e)
        {
            return it;
        }
    }
    return lista_.cend();
}

ListaOrdenada::iterator ListaOrdenada::begin() const{
    return lista_.cbegin();
}

ListaOrdenada::iterator ListaOrdenada::end() const{
    return lista_.cend();
}

size_t ListaOrdenada::contar(double e) const{
    count_if(lista_.cbegin(),lista_.cend(), []);
}