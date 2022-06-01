#include <iostream>
#include <map>
#include <cstring>
#include <fstream>

using namespace std;
class Diccionario
{
    private:
        map<string,string> dic;
    
    public:
        explicit Diccionario(string s = "");
        size_t entradas() const;
        void introduce(string pa, string tra);
        string traduccion(string pa) const;
};

Diccionario::Diccionario(string s)
{
    fstream fichero(s);

    while(!getline())
}
