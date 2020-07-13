#include <iostream>

using namespace std;

//Estructura con todos los datos de caracteres y numeros que se utilizaran para la factura
const int longCad = 20;
struct costoPorArticulo{
char nombreArticul[longCad + 1];
int cantidad;
float precio;
float costoPorArticulo;

};

//Funcion para pedir los datos necesarios al usuario y empezar a hacer los calculos y los agrega al arreglo
void solicitarDatos(int n, costoPorArticulo *factura){
     
    for(int i=0; i<n;i++){
        cout<<"Ingrese el nombre del producto "<<i+1<<": ";
        cin>>factura[i].nombreArticul;
        cout<<"Ingrese la cantidad de "<<factura[i].nombreArticul<<": ";
        cin>>factura[i].cantidad;
        cout<<"Ingrese el precio unitario de "<<factura[i].nombreArticul<<": ";
        cin>>factura[i].precio;
        factura[i].costoPorArticulo=factura[i].precio*factura[i].cantidad;
    }
}

void mostrarDatos(int n, costoPorArticulo *factura){
    cout<<"COMPROBANTE"<<endl<<endl;
    cout<<"Cantidad    Articulo    Precio Unitario   Costo"<<endl;
    for(int i=0; i<n;i++){
cout<<factura[i].cantidad<<"            "<<factura[i].nombreArticul<<"         "<<"$"<<factura[i].precio<<"            "<<"$"<< factura[i].costoPorArticulo<<endl;
    }
}
//Se encarga de calcular el costo total entre todos los articulos y devuelve el resultado
float calcularTotal( costoPorArticulo *factura, int n){
    float suma=0.0;
    for(int i=0; i<n;i++){
        suma += factura[i].costoPorArticulo;
    }
    return suma;
}

int main()
{
    int n;
    cout<<"Ingrese la cantidad de articulos que desea comprar: ";
    cin>>n;
    //Se guarda la estructura en un puntero y se convierte en un arreglo
   costoPorArticulo *factura = new costoPorArticulo[n];
        solicitarDatos(n, factura);
    mostrarDatos(n, factura);
    calcularTotal(factura, n);

    cout<<"                                     Total:$"<< calcularTotal(factura, n)<<endl;
    return 0;
}
