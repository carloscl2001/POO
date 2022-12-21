#include <iostream>
using namespace std;
template <typename iterator, typename fun>
bool ordenado(iterator it1, iterator it2, fun f){
    for (auto i = it1; i != it2 - 1; i++)
    {
        if(!f(*i, *(i + 1))){
            return false;
        }
    }
    return true;
    
};




//OBJETO FUNCION
class fun{
    public:
        int operator()(int a, int b){
            return a < b;
        }   
};



int main(){
    bool res;
    int v[3] = {1,2,4};
    fun f;

    res = ordenado(&v[0], &v[2], f);
    cout<<res;
}