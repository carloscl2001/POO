#ifndef FECHA_HPP_
#define FECHA_HPP_
#include <iostream>
#include <ctime>
#include <stdio.h>

class Fecha
{
    public://=>métodos

        //CONSTANTES
        static const int AnnoMinimo;
        static const int AnnoMaximo;
        
        //CONSTRUCTORES
        explicit Fecha(int d = 0, int m = 0, int a = 0);
        Fecha(const Fecha& fecha);
        Fecha(char* fecha);
        const char* cadena();

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
        inline int dia() const noexcept{return dia_;}
        inline int mes() const noexcept{return mes_;}
        inline int anno() const noexcept{return anno_;}

        //OPERADORES
        Fecha& operator =(const Fecha& fecha);

        Fecha& operator +=(int n);
        Fecha& operator -=(int n);

        Fecha& operator ++();//pre
        Fecha& operator ++(int n);//pos

        Fecha& operator --();//pre
        Fecha& operator --(int n);//pos
    
    
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

#endif