#include "cadena.hpp"
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

//CONSTRUCTORES
Cadena::Cadena(size_t t = 0, char c): s_(new char[t + 1]), tam_(t)
{

}