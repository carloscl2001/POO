#include <iostream>
#include <vector>

class  MatrizDispersa
{
    private:
        struct terna
        {
            size_t f, c;
            double v;
        };
        
        size_t m, n;
        std::vector<terna> val;

        bool buscar(size_t fil, size_t col, size_t& indice);

        bool operator < (const terna& t1);

    public:
        explicit MatrizDispersa(int f = 1, int c = 1);
        void asignar();
        double valor() const;
        inline size_t filas() const noexcept {return m;}
        inline size_t columnas() const noexcept {return n;}
        size_t n_valores() const;
};

