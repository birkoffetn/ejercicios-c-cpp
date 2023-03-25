#include<iostream>
#include<string>
#include<vector>

using namespace std;

template<typename T>
void leer(const char* mensaje, T &dato){
    cout<<mensaje;
    cin>>dato;
    while(cin.get()!= '\n');
}
template<>
void leer<string>(const char* mensaje, string &dato){
    cout<<mensaje;
    getline(cin, dato);
}

struct Producto{
    string tipo;
    double precio;
    int cantidad;
};

int main(){
    vector<Producto> lista;
    int opcion;
    cout<<"------Almacenes Sin costo-------\n";
    do{
        Producto producto;
        leer("Ingrese tipo    : ", producto.tipo);
        leer("Ingrese cantidad: ", producto.cantidad);
        int indice= EOF;
        for(int i= 0; i< int(lista.size()); ++i){
            if(lista[i].tipo== producto.tipo){
                indice= i;
                break;
            }
        }
        if(indice== EOF){
            leer("Ingrese Precio  : ", producto.precio);
            lista.push_back(producto);
            cout<<"Producto agregado correctamente.\n";
        }
        else{
            lista[indice].cantidad+= producto.cantidad;
            cout<<"Cantidad agregada correctamente.\n";
        }
        leer("Continuar? 1. si  2. no  : ", opcion);
    }while(opcion!= 2);

    double total= 0.0;
    cout<<"--------------------------------\n";
    cout<<"------Almacenes Sin costo-------\n";
    for(int i= 0; i< int(lista.size()); ++i){
        cout<<"Tipo    : "<<lista[i].tipo<<"\n";
        cout<<"Cantidad: "<<lista[i].cantidad<<"\n";
        cout<<"Valor: "<<lista[i].precio<<"\n";
        total+= lista[i].precio* lista[i].cantidad;
        cout<<"--------------------------------\n";
    }

    double neto= total* (lista.size()>= 3? 0.70: 1.0);
    cout<<"Total facura: "<<total<<"\n";
    cout<<"Neto a pagar: "<<neto<<"\n";
    cout<<"Ahorro      : "<<total- neto<<"\n";
    cout<<"--------------------------------\n";
    return EXIT_SUCCESS;
}
