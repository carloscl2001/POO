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
        Operador* asistente(){return operador_;};
    private:
        string codigo_;
        string hIncio_;
        string hFin_;
        Operador* operador_;
};


class Operador{
    public:
        void recibir(string s1, Llamada& llamada);
        map<string, Llamada*> atendidas(Operador& ope){return llamadas_;};
    private:
        map<string, Llamada*> llamadas_;
};

// void Operador::recibir(string s1, Llamada& llamada){
//     llamadas_.insert(make_pair(s1,&llamada));
// }

// void Llamada::asignar(Operador& ope){
//     operador_ = &ope;
// }


class asociacion{
    public:
        void recibir(Operador& ope, Llamada& lla);
        void asignar(Llamada& lla, Operador& ope);
        Operador* asistente(Llamada& llama);
        set<Llamada*> llamadas(Operador& ope);

    private:
        map<Operador*, set<Llamada*>> relOpeLla_;
        map<Llamada*, Operador*> relLlaOpe_;
};

void asociacion::recibir(Operador& ope, Llamada& lla){
    relOpeLla_[&ope].insert(&lla);
}

void asociacion::asignar(Llamada& lla, Operador& ope){
    relLlaOpe_.insert(make_pair(&lla,&ope));
}

Operador* asociacion::asistente(Llamada& lla){
    if(relLlaOpe_.find(&lla) != relLlaOpe_.end())
        return relLlaOpe_.find(&lla)->second;
    else
        return nullptr;
}

set<Llamada*> asociacion::llamadas(Operador& ope){
    if(relOpeLla_.find(&ope) != relOpeLla_.end())
        return relOpeLla_.find((&ope))->second;
    else
        return set<Llamada*>();
}