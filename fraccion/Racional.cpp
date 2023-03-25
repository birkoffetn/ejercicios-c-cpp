#include "Racional.h"

#include <cstdlib>
#include <sstream>

Racional::Racional(int num, int den): num(num), den(den){
    if(den== 0){
        std::cerr<<"Denominador igual a cero."<<std::endl;
        exit(EXIT_FAILURE);
    }
    operar_signo();
}

Racional::Racional(const std::string &str){
    std::istringstream entrada(str);
    char fraccion;
    entrada>>num>>fraccion>>den;
    if(entrada.fail()){
        std::cerr<<"Error en formato de cadena: "<<str<<std::endl;
        exit(EXIT_FAILURE);
    }
    if(den== 0){
        std::cerr<<"Denominador igual a cero"<<std::endl;
    }
    operar_signo();
}

Racional &Racional::operator=(const std::string &str){
    return *this= Racional(str);
}

Racional Racional::operator+(Racional otro) const{
    int cd= den* otro.den/ mcd(den, otro.den);
    int nn= cd/ den* num+ cd/ otro.den* otro.num;
    return Racional(nn, cd);
}

Racional Racional::operator+(int entero) const{
    return *this+ Racional(entero, 1);
}

Racional Racional::operator-(Racional otro) const{
    otro.num*= (-1);
    return *this+ otro;
}

Racional Racional::operator-(int entero) const{
    return *this- Racional(entero, 1);
}

Racional Racional::operator*(Racional otro) const{
    return Racional(num* otro.num, den* otro.den);
}

Racional Racional::operator*(int entero) const{
    return *this* Racional(entero, 1);
}

Racional Racional::operator/(Racional otro) const{
    return Racional(num* otro.den, den* otro.num);
}

Racional Racional::operator/(int entero) const{
    return *this/ Racional(entero, 1);
}

int Racional::mcd(int a, int b){
    while(b!= 0){
        int temp= a;
        a= b;
        b= temp% b;
    }
    return a;
}

void Racional::operar_signo(){
    if(den< 0){
        num*= (-1);
        den*= (-1);
    }
}

std::ostream &operator<<(std::ostream &salida, const Racional &racional){
    if(abs(racional.num)> racional.den){
        salida<<racional.num/ racional.den<<' ';
        salida<<abs(racional.num% racional.den)<<'/'<<racional.den;
    }
    else{
        salida<<racional.num<<'/'<<racional.den;
    }
    return salida;
}
