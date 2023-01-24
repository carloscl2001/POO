class Elipse{
    public:
        Elipse(double d1, double d2):radiox(d1), radioy(d2){}
        double radio_x() const{return radiox;}
        double radio_y() const{return radioy;}
        virtual void escala(double f);
        void escala(double f1, double f2);
    private:
        double radiox;
        double radioy;

};
class Circunferenia{
    public:
        Circunferenia(double r):e(Elipse(r,r)){}
        void escala(double f);
        double radio() const{}
    private:
        Elipse e;
};