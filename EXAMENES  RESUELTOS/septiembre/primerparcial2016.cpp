#include <iostream>
#include <string>
#include <set>
#include <map>
using namespace std;

class Alumno{
    public:
    private:
};

class Asignatura{
    public:
        typedef set<Grupo*> grupo;
        void impardaen(Grupo& g);
        grupo impardaen() const;

    private:
        grupo grupo_;
};

class Profesor{
    public:
        typedef set<Grupo*> Grps;
        
        void imparte(Grps& g);
        const Grps& imparte() const;
        
    private:
        Grps grps_;
};

/*
void Profesor::imparte(Grupo& g){
    grps_.insert(&g);
};
*/

const Profesor::Grps& Profesor::imparte() const{
    return grps_;
};

class Grupo{
    public:
        Profesor* p;
        void impartido(Profesor& p);
        Profesor& impartido() const;

        Asignatura& a;
        void daen(Asignatura& a);
        Asignatura& daen() const;
    private:
        string aula;
        int h_semana;
};

void Grupo::impartido(Profesor& pro){
    p = &pro;
}

class AGP{
    public:
        typedef map<Grupo*,Asignatura*> rd;
        typedef map<Grupo&,Alumno*> ri;
    private:
        rd rd_;
        ri ri_;
};