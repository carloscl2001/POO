#include <set>
#include <map>
#include <string.h>
#include <cstring>
#include <iostream>
using namespace std;

class Llamada{
    public:
        Llamada(string s1, string s2, string s3 ):codigo_(s1), hIncio_(s2), hFin_(s3){}
        void asignar(Operador&);
        Operador* asistente(Llamada& llamada);
    private:
        string codigo_;
        string hIncio_;
        string hFin_;
        Operador* operador_;
};

void Llamada::asignar(Operador& opera){
    operador_ = &opera;
}


class Operador{
    public:
        void recibir(string s1, Llamada& llamada);
        map<string, Llamada*> atendidas(Operador& ope){return llamadas_;};
    private:
        map<string, Llamada*> llamadas_;
};

void Operador::recibir(string s1, Llamada& llamada){
    llamadas_.insert(make_pair(s1,&llamada));
}


