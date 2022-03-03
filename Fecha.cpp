#include "Fecha.hpp"
#include <iostream>
#include <ctime>

const int Fecha::AnnoMinimo(1902);
const int Fecha::AnnoMaximo(2037);
using namespace std;

//=>CONSTRUCTOR
Fecha::Fecha(int d = 0, int m = 0, int a = 0): dia_(d) mes_(m) anno_(a)
{
    std::time_t tiempo_calendario = std::time(nullptr);
    std::tm* tiempo_descompuesto = std::localtime(&tiempo_calendario);

    //En caso de 0 => asignamos la fecha del sistema 

    if (dia_ == 0) {int dia_ = tiempo_descompuesto->tm_mday;}
    if (mes_ == 0) {int mes_ = tiempo_descompuesto->tm_mon + 1;}
    if (anno_ == 0) {int anno_ = tiempo_descompuesto->tm_year + 1900;}
}

//=>CONSTRUCTOR DE COPIA
Fecha::Fecha(const Fecha& f): dia_(f.dia_): mes_(f.mes_) anno_(f.anno_)
{
    std::time_t tiempo_calendario = std::time(nullptr);
    std::tm* tiempo_descompuesto = std::localtime(&tiempo_calendario);

    //En caso de 0 => asignamos la fecha del sistema 

    if (dia_ == 0) {int dia_ = tiempo_descompuesto->tm_mday;}
    if (mes_ == 0) {int mes_ = tiempo_descompuesto->tm_mon + 1;}
    if (anno_ == 0) {int anno_ = tiempo_descompuesto->tm_year + 1900;}
}


//FUNCION AUXILIAR nDiaMes()
int Fecha::nDiaMes()
{

    if (mes_ == 1 || mes_ == 3 || mes_ == 5 || mes_ == 7 || mes_ == 8 || mes_ == 10 || mes_ == 12) { return 31;}
    if (mes_ == 4 || mes_ == 6 || mes_ == 9 || mes_ == 11) { return 30;}
    if (mes_ == 2)
    {
        if (anno_ % 4 == 0 && (anno_ % 400 == 0 || anno_ % 100 != 0)) {return 29;}
        else{ return 28;} 
    }
}

//FUNCION AUXILIAR comprobarFecha()
void Fecha::comprobarFecha()
{
    n_Dia_Mes = nDiaMes();

    //anno valido
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
    if( dia_ > n_Dia_Mes || dia_ < 1)
    {
        Fecha::Invalida fallo("Dia invalido");
        throw fallo;
    }
}