#include "cadena.hpp"
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

//=>CONSTRUCTORES
Cadena::Cadena(size_t t , char c): s_(new char[t + 1]), tam_(t)
{
    memset(s_, c, tam_);
    s_[ tam_ ] = '\0';
}

//=>CONSTRUCTOR DE COPIA
Cadena::Cadena(const Cadena& cadena): s_(new char[cadena.tam_ + 1]), tam_(cadena.tam_)
{
    strcpy(s_, cadena.s_);
}

//=>CONSTRUCTOR DE CADENA A BAJO NIVEL
Cadena::Cadena(const char* cadena): s_(new char[strlen(cadena)+ 1]), tam_(strlen(cadena))
{
    strcpy(s_, cadena);
}

//=>CONSTRUCTOR DE MOVIMIENTO
Cadena::Cadena(Cadena&& cadena): s_(cadena.s_), tam_(cadena.tam_)
{
    cadena.s_ = nullptr;
    cadena.tam_ = 0;
}

//=>OPERADOR DE CONVERSION
char* Cadena::c_str() const
{
	return s_;
}

//=>OPERADORES
Cadena& Cadena::operator +=(const Cadena& cadena)
{
    char* aux = new char[tam_ + 1];
    strcpy(aux, s_);

    delete[] s_;
    tam_ += cadena.tam_;
    s_ = new char[tam_ + 1];

    strcpy(s_, aux);
    strcpy(s_, cadena.s_);
}

Cadena& Cadena::operator =(const Cadena& cadena)
{
    if( this != &cadena)
	{
		copiar(cadena);
	}
	return *this;
}



//=>FUNCION AUXILIAR COPIAR
void Cadena::copiar(const Cadena& cadena)
{
	delete[]s_;
	tam_ = cadena.tam_;

	s_ = new char[tam_ + 1];
	strcpy(s_, cadena.s_);
}


//=>OPERADORES FUERA DE LA CLASE
bool operator <(const Cadena& cadena1, const Cadena& cadena2)
{
    if (strcmp(cadena1.c_str(), cadena2.c_str()) < 0)
    {
        return true;
    }else{return false;}
}

bool operator <=(const Cadena& cadena1, const Cadena& cadena2)
{
    if (strcmp(cadena1.c_str(), cadena2.c_str()) <= 0)
    {
        return true;
    }else{return false;}
}

bool operator ==(const Cadena& cadena1, const Cadena& cadena2)
{
    if (strcmp(cadena1.c_str(), cadena2.c_str()) == 0)
    {
        return true;
    }else{return false;}
}

bool operator >(const Cadena& cadena1, const Cadena& cadena2)
{
    if (strcmp(cadena1.c_str(), cadena2.c_str()) > 0)
    {
        return true;
    }else{return false;}
}

bool operator >=(const Cadena& cadena1, const Cadena& cadena2)
{
    if (strcmp(cadena1.c_str(), cadena2.c_str()) >= 0)
    {
        return true;
    }else{return false;}
}

bool operator !=(const Cadena& cadena1, const Cadena& cadena2)
{
    return !(cadena1 == cadena2);
}