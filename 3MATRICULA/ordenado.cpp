#include <iostream>
using namespace std;

template <typename iterator>
bool ordenado(iterator it1, iterator it2){
    for(auto it = it1 ; it != it2){
        if(*i < *(i-1)) return false;
    }
    return true;
}


template <typename iterator, typename funcion>
bool ordenado(iterator it1, iterator it2, funcion f){
    for(auto it = it1 ; it != it2){
        if(f(*i,*(i-1)) == false) return false;
    }
    return true;
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
    cout << ordenado(&v[0], &v[5], f);
}
