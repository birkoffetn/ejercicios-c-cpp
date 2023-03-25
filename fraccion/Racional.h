#ifndef __RACIONAL__H__
#define __RACIONAL__H__

#include <string>
#include <iostream>

class Racional{
    friend std::ostream& operator<<(std::ostream &salida, const Racional &racional);
public:
    Racional(): Racional(1, 1){}

    Racional(int num, int den);

    Racional(const std::string& str);

    Racional &operator=(const std::string& str);

    Racional operator+(Racional otro) const;

    Racional operator+(int entero) const;

    Racional operator-(Racional otro) const;

    Racional operator-(int entero) const;

    Racional operator*(Racional otro) const;

    Racional operator*(int entero) const;

    Racional operator/(Racional otro) const;

    Racional operator/(int entero) const;

    static int mcd(int a, int b);
private:
    int num, den;

    void operar_signo();
};

#endif
