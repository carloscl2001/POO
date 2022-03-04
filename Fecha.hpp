#ifndef FECHA_HPP_
#define FECHA_HPP_


class Fecha
{
    public://=>métodos

        //CONSTANTES
        static const int AnnoMinimo;
        static const int AnnoMaximo;
        
        //CONSTRUCTORES
        explicit Fecha(int d = 0, int m = 0, int y = 0);
        Fecha(const Fecha& fecha);

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
        inline int dia() const {return dia_;}
        inline int mes() const {return mes_;}
        inline int anno() const {return anno_;}


        Fecha& operator =(const Fecha& fecha);
    
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

#endif