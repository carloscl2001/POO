 #include <iostream>
 #include <math.h>
 #include <vector>
using namespace std;
class Complejo {
        double real, imag;
    public:
        Complejo (double r = 0 , double i = 0.): real(r), imag(i) {}
        double real_() const{return real;}
};  


int main() {
vector<Complejo>vectorcito (100);

cout<<vectorcito[20].real_();

}