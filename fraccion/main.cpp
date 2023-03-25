#include "Racional.h"

#include <iostream>

using namespace std;

int main(){
    Racional r1(3, 4);
    Racional r2("2/4");
    Racional r3= r1+ r2;
    cout<<r1<<" + "<<r2<<" = "<<r3<<endl;
    return EXIT_SUCCESS;
}