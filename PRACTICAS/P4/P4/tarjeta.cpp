//  /-------------------------------\
//  |                               |
//  |   CARLOS ANTONIO CORTÉS LORA  |
//  |                               |
//  \-------------------------------/


#include "tarjeta.hpp"
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <iostream>
#include <functional>

bool luhn(const Cadena& num);

struct EsDigito: public std::unary_function<char,bool>
{
    bool operator() (char c) const {return isdigit(c);};
};


//
// ------------| CLASE NUMERO |------------|
//


//CONSTRUCTOR
Numero::Numero(const Cadena& n): num_(elimina_espacio(n)){

    if( std::find_if(num_.begin(), num_.end(), std::not1(EsDigito())) != num_.end())
    {
        throw Incorrecto(Razon::DIGITOS);
    }

    if(!luhn(num_))
    {
        throw Incorrecto(Razon::NO_VALIDO);
    }

    if(num_.length() > 19 || num_.length() == 0 || num_.length() < 13 )
    {
        throw Incorrecto(Razon::LONGITUD);
    }
}

//FUNCION AUXILIAR
Cadena Numero::elimina_espacio(const Cadena &cad)
{
    Cadena aux (cad);

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

std::set<Numero> Tarjeta::tarjetas_;

//CONSTRUCTOR
Tarjeta::Tarjeta(const Numero &n, Usuario& user, const Fecha &f): numero_(n), usuario_(&user), f_caducidad_(f)
{
    if (f_caducidad_ < Fecha())
    {
        throw Caducada(f_caducidad_);
    }

    if(tarjetas_.insert(n).second == false)
    {
        throw Num_duplicado(n);
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
            tipo_ = Otro;
            break;
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
    Numero a = numero_;
    tarjetas_.erase(a);
}

//OPERADOR <
bool operator <(const Tarjeta& t1, const Tarjeta& t2)
{
    return t1.numero() < t2.numero();
}

//OPERADOR DE INSERCION DE FLUJO DE TIPO
std::ostream& operator <<(std::ostream& os, const Tarjeta::Tipo& tip) noexcept
{
    
    switch(tip)
    {
        case 0: os << "Tipo indeterminado" ; break;
        case 1: os << "VISA" ; break ;
        case 2: os << "Mastercard"; break ;
        case 3: os << "Maestro"; break ;
        case 4: os << "JCB" ; break ;
        case 5: os << "AmericanExpress" ; break ;
        default: os << "Tipo indeterminado"; break ;
    }

    return os ;
}

//OPERADOR DE INSERCION DE FLUJO DE TARJETA
std::ostream& operator << (std::ostream& os, const Tarjeta& t) noexcept
{
	Cadena nombre = t.titular()->nombre();
	Cadena apellidos = t.titular()->apellidos();


	for(size_t i=0; i< nombre.length(); i++)
	{
		nombre[i] = toupper(nombre[i]);
	}
	for(size_t j=0; j< apellidos.length(); j++)
	{
		apellidos[j] = toupper(apellidos[j]);
	}

	
    os<<"/-----------------------\\\n";
    os<<"| "<< t.tipo() <<"\t\t|"<<"\n";
    os<<"| "<<  t.numero()<<"\t|" <<  "\n";
    os<<"| "<<  nombre << " " << apellidos<<"\t|" <<  "\n";
    os<<"| "<<  "Caduca: ";
    os<< std::setfill('0') << std::setw(2) << t.caducidad().mes();
    os<<"/";
    os<<  std::setw(2) << (t.caducidad().anno() % 100 ) <<"\t\t|" << std::endl;
    os<<"\\-----------------------/\n";

    return os ;

}