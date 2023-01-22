#include  <iostream>
#include <initializer_list>
#include <vector>
#include <list>
#include <sort>

using namespace std;

class MatrizDispersa{
    public:
        typedef struct terna;
        explicit MatrizDispersa(size_t m=1, size_t n=1);
        void asignar(size_t fil, size_t col, double valor);
        MatrizDispersa(const initializer_list<terna>& l);
        double valor(size_t fil, size_t col ) const;
        size_t filas() const noexcept;
        size_t columnas() const noexcept;
        size_t n_valores() const noexcept;


        friend void intercambiar(MatrizDispersa& A, MatrizDispersa& B);
        inline double& valor(size_t indice) {return val[indice].v;} //esto faltaria el out of range 
        
    private:
        bool buscar(size_t fil, size_t col, size_t& indice);

        struct terna{
            size_t f,c;
            double v;
            friend bool operator <(const terna& t1, const terna& t2);
        };
        size_t m,n;
        vector<terna> val;
};
/*double MatrizDispersa::valor(size_t indice)const{
    if(indice>val.size()) throw out_of_range("Indice fuera de rango");
    return val[indice].v;
}*/

size_t MatrizDispersa::filas() const noexcept{
    return m;
}

size_t MatrizDispersa::columnas() const noexcept{
    return n;
}

size_t MatrizDispersa::n_valores() const noexcept{
    return val.size();
}

MatrizDispersa::MatrizDispersa(const initializer_list<terna>& l){
    initializer_list<terna>::iterator it;
    for(it= l.begin(); it != l.end()-1;it++){
        val.push_back((*it));
        it++;
    }
    it++;
    if(it->v != 0) val.push_back(*it);

    m = it->f;
    n = it->c;
}

int main(){ //suponemos que terna esta en public pq sino no se puede hacer
    MatrizDispersa a(5,4);
    a.asignar(3,0,18.2);
    //a.asignar().....;
    //o se podria hacer esto
    //Matriz dispersa a={terna(0,1,7.5),terna(2,0,18.2)} ...
    try{
        a.asignar(8,6,0);
    }catch(out_of_range& e){
        cout<<"El programa se ha interrumpida por el siguiente motivo: " << e.what() << endl;
    }
}
void intercambiar(MatrizDispersa& A, MatrizDispersa& B){

}

friend bool MatrizDispersa::terna::operator <(const terna& t1, const terna& t2){
    if(f < t2.f) return true;
    if(f == t2.f && c < t2.c) return true;

    return false;

}

bool MatrizDispersa::buscar(size_t fil, size_t col, size_t& indice){
    int ind = 0;

    terna aux; aux.f = fil; aux.c = col;

    while(ind < val.size() && val[ind] < aux){
            if(val[ind].f == fil && val[ind].c == col){
                indice = ind;
                return true;
            }
            ind++;
    }
    if(ind == val.size()){
        indice = n_valores();
        return false;
    }else{
        indice = ind;
        return false;
    }
}

inline MatrizDispersa::MatrizDispersa(size_t m=1, size_t n=1): m(n), n(n){}

void MatrizDispersa::asignar(size_t fil, size_t col, double valor){
    if(fil >= m || col >= n) throw out_of_range("Fuera de rango");

    terna aux; aux.f = fil; aux.c = col;aux.v = valor;
    val.push_back(aux);
    //list<terna>  l;
    //copy(val.begin(),val.end(), l.begin());
    
    sort(val.begin(),val.end(), [](terna t1, terna t2) -> bool{return t1 < t2;});
}