//  /-------------------------------\
//  |                               |
//  |   CARLOS ANTONIO CORTÉS LORA  |
//  |                               |
//  \-------------------------------/


#include "fecha.hpp"
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <iomanip>


const int Fecha::AnnoMinimo(1902);
const int Fecha::AnnoMaximo(2037);
using namespace std;


//=>CONSTRUCTOR 
Fecha::Fecha(int d /*d = 0*/, int m /*m = 0*/ , int a /* a 0 0*/ ): dia_(d), mes_(m), anno_(a)
{
    std::time_t tiempo_calendario = std::time(nullptr);
    std::tm* tiempo_descompuesto = std::localtime(&tiempo_calendario);

    //En caso de 0 => asignamos la fecha del sistema 

    if (dia_ == 0) {dia_ = tiempo_descompuesto->tm_mday;}
    if (mes_ == 0) {mes_ = tiempo_descompuesto->tm_mon + 1;}
    if (anno_ == 0) {anno_ = tiempo_descompuesto->tm_year + 1900;}

    comprobarFecha();
}
/*
//=>CONSTRUCTOR DE COPIA
Fecha::Fecha(const Fecha& f): dia_(f.dia_), mes_(f.mes_), anno_(f.anno_)
{
    std::time_t tiempo_calendario = std::time(nullptr);
    std::tm* tiempo_descompuesto = std::localtime(&tiempo_calendario);

    //En caso de 0 => asignamos la fecha del sistema 

    if (dia_ == 0) {dia_ = tiempo_descompuesto->tm_mday;}
    if (mes_ == 0) {mes_ = tiempo_descompuesto->tm_mon + 1;}
    if (anno_ == 0) {anno_ = tiempo_descompuesto->tm_year + 1900;}

    comprobarFecha();
}
*/

//=>CONSTRUCTOR DE CADENA DE BAJO NIVEL
Fecha::Fecha(const char *fecha)
{
    std::time_t tiempo_calendario = std::time(nullptr);
	std::tm* tiempo_descompuesto = std::localtime(&tiempo_calendario);
	
	int aux = sscanf(fecha,"%d/%d/%d", &dia_,&mes_,&anno_);
	
	if(aux != 3) throw Fecha::Invalida("Formato incorrecto");
	if(dia_ == 0) { dia_ = tiempo_descompuesto -> tm_mday; }
	if(mes_ ==0) { mes_ = tiempo_descompuesto -> tm_mon + 1;}
	if(anno_ ==0) { anno_ = tiempo_descompuesto -> tm_year + 1900;}

	comprobarFecha();
}


//=>DE FECHA A CADENA
const char* Fecha::cadena() const noexcept
{
    std::locale::global(std::locale("es_ES.UTF-8"));
  	
  	std::time_t tiempo_calendario = std::time(nullptr);
    std::tm* tiempo_descompuesto = std::localtime(&tiempo_calendario);

    char *cadena = new char[50];

    
   tiempo_descompuesto->tm_mday = dia_;
   tiempo_descompuesto->tm_mon = mes_ - 1;
   tiempo_descompuesto->tm_year = anno_ - 1900;

    mktime(tiempo_descompuesto);
   
    strftime(cadena,50, "%A %d de %B de %Y", tiempo_descompuesto);

	return cadena;
}


//=>OPERADORES
/*
Fecha& Fecha::operator =(const Fecha& fecha)
{
    dia_ = fecha.dia_;
    mes_ = fecha.mes_;
    anno_ = fecha.anno_;
    return *this;
}
*/

Fecha& Fecha::operator +=(int n)
{
    this->dia_ += n;
    arreglarFecha();
    comprobarFecha();
    return *this;
} 


Fecha& Fecha::operator -=(int n)
{
    return (*this += -n);
} 


Fecha& Fecha::operator ++()
{
    return (*this += 1);
}


Fecha& Fecha::operator ++(int n)
{
    Fecha *aux = new Fecha(*this);
    *this += 1;
    return *aux;
}


Fecha& Fecha::operator --()
{
    return (*this -= 1);
}


Fecha& Fecha::operator --(int n)
{
    Fecha *aux = new Fecha(*this);
    *this -= 1;
    return *aux;
}


//=>FUNCION AUXILIAR comprobarFecha()
void Fecha::comprobarFecha()
{
    int n_Dias_Mes = 0;
    n_Dias_Mes = nDiasMes();

        if( anno_ < AnnoMinimo || anno_ > AnnoMaximo)
        {
            Fecha::Invalida fallo("Anno invalido");
            throw fallo;
        }

        //mes valido
        if( mes_ < 1 || mes_ > 12)
        {
            Fecha::Invalida fallo("Mes invalido");
            throw fallo;
        }

        //dia valido
        if( dia_ > n_Dias_Mes || dia_ < 1)
        {
            Fecha::Invalida fallo("Dia invalido");
            throw fallo;
        }
}


//=>FUNCION AUXILIAR nDiaMes()
int Fecha::nDiasMes()
{

    if (mes_ == 1 || mes_ == 3 || mes_ == 5 || mes_ == 7 || mes_ == 8 || mes_ == 10 || mes_ == 12) { return 31;}
    else if (mes_ == 4 || mes_ == 6 || mes_ == 9 || mes_ == 11) { return 30;}
    else if (mes_ == 2)
    {
        if (anno_ % 4 == 0 && (anno_ % 400 == 0 || anno_ % 100 != 0)) {return 29;}
        else{ return 28;} 
    }
    else{ return 30;}
}


//=>FUNCION AUXILIAR arreglarFecha()
void Fecha::arreglarFecha()
{
    tm f={};
    f.tm_mday = dia_;
    f.tm_mon = mes_ - 1;
    f.tm_year = anno_ - 1900;

    mktime(&f);

    dia_ = f.tm_mday;
    mes_ = f.tm_mon + 1;
    anno_ = f.tm_year + 1900;
}


//=>OPERADORES FUERA DE LA CLASE
bool operator <(const Fecha& fecha1, const Fecha& fecha2)
{
    if( fecha1.anno() < fecha2.anno()) { return true;}
    
    else if( fecha1.anno() == fecha2.anno())
    {
        if(fecha1.mes() < fecha2.mes()){ return true;}

        else if(fecha1.mes() == fecha2.mes())
        {
            if(fecha1.dia() < fecha2.dia()){ return true;}
            else{return false;}

        }else{return false;}
        
    }
    else{return false;}
}

bool operator <=(const Fecha& fecha1, const Fecha& fecha2)
{
    return !(fecha1 > fecha2);
}

bool operator ==(const Fecha& fecha1, const Fecha& fecha2)
{
    if(fecha1.anno() == fecha2.anno() && fecha1.mes() == fecha2.mes() && fecha1.dia() == fecha2.dia()) {return true;}
    else{return false;}
}

bool operator >(const Fecha& fecha1, const Fecha& fecha2)
{
    if( fecha1.anno() > fecha2.anno()) { return true;}
    
    else if( fecha1.anno() == fecha2.anno())
    {
        if(fecha1.mes() > fecha2.mes()){ return true;}

        else if(fecha1.mes() == fecha2.mes())
        {
            if(fecha1.dia() > fecha2.dia()){ return true;}
            else{return false;}

        }else{return false;}
        
    }
    else{return false;}
}


bool operator >=(const Fecha& fecha1, const Fecha& fecha2)
{
    return !(fecha1 < fecha2);
}

bool operator !=(const Fecha& fecha1, const Fecha& fecha2)
{
    return !(fecha1 == fecha2);
}


Fecha operator +(const Fecha& fecha, int n)
{
    Fecha aux(fecha);
    aux += n;
    return aux;
}

Fecha operator -(const Fecha& fecha, int n)
{
    Fecha aux(fecha);
    aux -= n;
    return aux;
}

//=>OPERADORES DE FLUJO
std::ostream& operator <<(std::ostream& os, const Fecha& fecha)
{
    os << fecha.cadena();
    return os;
}

std::istream& operator >>(std::istream& is, Fecha& fecha)
{
    char* aux = new char[11];

    is >> setw(11) >> aux;
    try
    {
        fecha = Fecha(aux);
    }
    catch(Fecha::Invalida e)
    {
        is.setstate(std::ios_base::failbit);
        throw e;
    }
    
    return is;
}