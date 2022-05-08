#include "tarjeta.hpp"
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>

bool luhn(const Cadena& num);

//
// ------------| CLASE NUMERO |------------|
//


//CONSTRUCTOR
Numero::Numero(const Cadena& n): num_(elimina_espacio(n)){

    if( std::find_if(num_.begin(), num_.end(), static_cast<int(*)(int)>(std::isdigit)) != num_.length() )
    {
        throw Incorrecto(Razon::DIGITOS) ;
    }

    if(!luhn(num_))
    {
        throw Incorrecto(Razon::NO_VALIDO);
    }

    if(num_.length() > 19 || num_.length() == 0 || num_.length() < 13 )
    {
        throw Incorrecto(Razon::LONGITUD) ;
    }
}

//FUNCION AUXILIAR
Cadena Numero::elimina_espacio(const Cadena &cad)
{
    Cadena aux (cad) ;

    std::remove_if(aux.begin(),aux.end()+1,[](char c){return isspace(c);});


    if(aux.length() > 19 || aux.length() == 0 || aux.length() < 13 )
    {
        throw Incorrecto(Razon::LONGITUD) ;
    }

    return Cadena(aux.c_str());

}

//OPERADOR <
bool operator <(const Numero& n1, const Numero& n2)
{
    return strcmp(n1,n2) < 0;
}


//
// ------------| CLASE TARJETA |------------|
//

//CONSTRUCTOR
Tarjeta::Tarjeta(const Numero &n, Usuario& user, const Fecha &f): numero_(n), usuario_(&user), f_caducidad_(f)
{
    if (f_caducidad_ < Fecha())
    {
        throw Caducada(f_caducidad_);
    }

    const char* aux = n;

    switch(aux[0]){
        case '4':
            tipo_ = Tipo::VISA; break;
        case '5':
            tipo_ = Mastercard; break;
        case '6':
            tipo_ = Maestro; break;
        case '3':
            if(aux[1] == 4 || aux[1] == 7) { tipo_ = AmericanExpress;}
            else{tipo_ = JCB;}
            break;
        default:
            tipo_ = Otro;break;
    }
    
    activa_ = true;

    user.es_titular_de(*this);
}

//ACTIVAR O DESACTIVAR TARJETA
bool Tarjeta::activa(bool valor)
{
	activa_ = valor;
	return activa_;
}

//DESENLACE CON USUARIO
void Tarjeta::anula_titular()
{
    usuario_= nullptr;
}

//DESTRUCTOR DE TARJETA
Tarjeta::~Tarjeta()
{
    if(Usuario* usuario = const_cast<Usuario*>(usuario_)){
        usuario->no_es_titular_de(*this);
    }
}

//OPERADOR <
bool operator <(const Tarjeta& t1, const Tarjeta& t2)
{
    return t1.numero() < t2.numero();
}

//OPERADOR DE INSERCION DE FLUJO DE TIPO
std::ostream& operator << (std::ostream& os ,const Tarjeta::Tipo& t)
{

    switch(t)
    {
        case 0: os << "Otro"; break;
        case 1: os << "VISA"; break ;
        case 2: os << "Mastercard"; break ;
        case 3: os << "Maestro"; break ;
        case 4: os << "JCB"; break ;
        case 5: os << "AmericanExpress"; break ;

        default: os << "Otro"; break ;
    }
    return os;
}

//OPERADOR DE INSERCION DE FLUJO DE TARJETA
std::ostream& operator << (std::ostream& os, const Tarjeta& t)
{
	Cadena aux1 = t.titular()->nombre();
	Cadena aux2 = t.titular()->apellidos();


	for(size_t i=0; i< aux1.length(); i++)
	{
		aux1[i] = toupper(aux1[i]);
	}
	for(size_t j=0; j< aux2.length(); j++)
	{
		aux2[j] = toupper(aux2[j]);
	}

	
    os <<"| "<< t.tipo() << " |"<< "\n"
       <<"| "<<  t.numero() << " |"<<  "\n"
       <<"| "<<  aux1 << " " << aux2 <<" |"<<  "\n"
       <<"| "<<  "Caduca: "
       <<"| "<< std::setfill('0') << std::setw(2) << t.caducidad().mes()
       <<"/"
       <<  std::setw(2) << (t.caducidad().anno() % 100 ) << "\n" << " |"<<  std::endl;

    return os ;

}
