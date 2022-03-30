#include "MatrizDispersa.hpp"

bool operator < (const terna& t)
{
    if(f < t.f ) return true;
    if(f == t.f && c < c.f) return true;
    else return false;
}

bool MatrizDispersa::buscar(size_t fil, size_t col, size_t& indice)
{
    vector<size_t>:: pointer ind = v[fil][col];

    if(v[fil][col] != 0)
    {
        return true && buscar(fil,col,ind);
    }
    else
    {
        return false && buscar(fil,col,ind++);
    }
}