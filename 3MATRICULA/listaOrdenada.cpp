#include <list>
#include <iostream>
#include <algorithm>


using namespace std;

//Vamos a a definir listaOredenada como una composición de de list y usa 
//la delegación de operaciones

class listaOrdenada
{
    
    public:
        listaOrdenada(/* args */);
        typedef list<double>::const_iterator iterador;
        void insertar(double e);
        iterador buscar(double e) const;
        iterador begin() const;
        iterador end() const; 

        size_t contar(double e)const;
    private:
        list<double> lista;
};

listaOrdenada::listaOrdenada():lista(list<double>()){}

void listaOrdenada::insertar(double e){
    lista.insert(lista.end(), e);
    lista.sort();
}


listaOrdenada::iterador listaOrdenada::buscar(double e) const{
    iterador it = lista.cbegin();
    while(*it != e || it != lista.cend()){
        if(*it == e)
            return it;
        else
            return lista.cend();
    }
}

listaOrdenada::iterador listaOrdenada::begin() const{return lista.cbegin();}

listaOrdenada::iterador listaOrdenada::end() const{return lista.cend();}

size_t listaOrdenada::contar(double e)const{
    return (count_if(lista.cbegin(), lista.cend(), [e](double valor) -> bool{return e == valor;}));
}