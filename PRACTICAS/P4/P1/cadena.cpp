//  /-------------------------------\
//  |                               |
//  |   CARLOS ANTONIO CORTÉS LORA  |
//  |                               |
//  \-------------------------------/


#include "cadena.hpp"
#include <cstring>
#include <iomanip>


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


//=>OPERADORES
Cadena& Cadena::operator +=(const Cadena& cadena)
{
    char* aux = new char[tam_ + 1];
    strcpy(aux, s_);

    delete[] s_;
    tam_ += cadena.tam_;
    s_ = new char[tam_ + 1];

    strcpy(s_, aux);
    strcat(s_, cadena.s_);

    return *this;
}

Cadena& Cadena::operator =(const Cadena& cadena)
{
    if( this != &cadena)
	{
		copiar(cadena);
	}
	return *this;
}

Cadena& Cadena::operator =(Cadena&& cadena)
{
    if( this != &cadena)
    {
        copiar(cadena);
        cadena.s_ = nullptr;
        cadena.tam_ = 0;
    }
    return *this;

}

char& Cadena::at(size_t i) const
{
    if (i< tam_) {return s_[i];}
    else{throw std::out_of_range("AT CONST");}
}

char& Cadena::at(size_t i) 
{
    if (i< tam_) {return s_[i];}
    else{throw std::out_of_range("AT");}
}

Cadena Cadena::substr(size_t i, size_t t) const
{
    if(i >= 0 && i< tam_ && t > 0 && t <= tam_ && tam_- i >= t)
    {
        Cadena aux(t);
		strncpy(aux.s_, s_ + i, t);
		aux.s_[t] = '\0';
		return aux;
    }
    else{throw std::out_of_range("SUBSTR");}
}

//=>FUNCION AUXILIAR COPIAR
void Cadena::copiar(const Cadena& cadena)
{
	delete[]s_;
	tam_ = cadena.tam_;

	s_ = new char[tam_ + 1];
	strcpy(s_, cadena.s_);
}

//DESTRUCTOR
Cadena::~Cadena()
{
    delete[] s_;
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


Cadena operator + (const Cadena& cadena1, const Cadena& cadena2)
{
    return Cadena(cadena1) += cadena2;
}

ostream& operator << (ostream& os, const Cadena& cadena) noexcept
{
    os << cadena.c_str();
    return os;
}

istream& operator >> (istream& is, Cadena& cadena)
{
    char *aux = new char[33]{'\0'};
    
    is >> setw(33) >> aux;

    cadena = aux;
    delete[] aux;

    return is;
}
