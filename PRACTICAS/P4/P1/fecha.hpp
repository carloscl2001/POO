//  /-------------------------------\
//  |                               |
//  |   CARLOS ANTONIO CORTÉS LORA  |
//  |                               |
//  \-------------------------------/


#ifndef FECHA_HPP_
#define FECHA_HPP_
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <cstdlib>
#include <cstring>
#include <iomanip>

class Fecha
{
    public://=>métodos

        //CONSTANTES
        static const int AnnoMinimo;
        static const int AnnoMaximo;
        
        //CONSTRUCTORES
        explicit Fecha(int d = 0, int m = 0, int a = 0);
        //Fecha(const Fecha& fecha);
        Fecha(const char* fecha);
        const char* cadena() const noexcept;

        //CLASE INVALIDA
        class Invalida
        {
            public:
                Invalida(const char* m):e(m){}
                const char* por_que()const{return e;}
            private:
                const char* e;
        };  

        //OBSERVADORES
        int dia() const noexcept{return dia_;}
        int mes() const noexcept{return mes_;}
        int anno() const noexcept{return anno_;}

        //OPERADORES
        //Fecha& operator =(const Fecha& fecha);

        Fecha& operator +=(int n);
        Fecha& operator -=(int n);

        Fecha& operator ++();//preincremento
        Fecha& operator ++(int n);//posincremento

        Fecha& operator --();//predecremento
        Fecha& operator --(int n);//posdecremento

        
    
    
    private://=>atribitos
    
        int dia_;
        int mes_ ;
        int anno_;

        //FUNCIONES PRIVADAS AUXILIARES
        void comprobarFecha();
        int nDiasMes();
        void arreglarFecha();
    
};

//=>OPERADORES FUERA DE LA CLASE
bool operator <(const Fecha& fecha1, const Fecha& fecha2);
bool operator <=(const Fecha& fecha1, const Fecha& fecha2);
bool operator ==(const Fecha& fecha1, const Fecha& fecha2);
bool operator >(const Fecha& fecha1, const Fecha& fecha2);
bool operator >=(const Fecha& fecha1, const Fecha& fecha2);
bool operator !=(const Fecha& fecha1, const Fecha& fecha2);

Fecha operator +(const Fecha& fecha, int n);
Fecha operator -(const Fecha& fecha, int n);

std::ostream& operator <<(std::ostream& os, const Fecha& fecha);
std::istream& operator >>(std::istream& is, Fecha& fecha);



#endif