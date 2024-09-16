/*
Diseñe un programa que sea capaz de leer dos colas y mediante un mensaje indicar si son 
iguales. Nota: los elementos constitutivos de las colas son caracteres
*/

#include <iostream>
#include "Cola/Cola.h"
using namespace std;

bool leerCola(Cola<char> &cola1,Cola<char> &cola2, int &cont1, int &cont2){
    char dato;
    bool iguales = true;
    if(cont1 != cont2){
        return 0;
    }
    for(int i=0; i<cont1; i++){
        if(cola1.desencolar() != cola2.desencolar()){
            iguales = false;
            return 0;
        }
    }
    return 1;
}

int main() {
    Cola<char> cola1, cola2;
    char dato, opcion;
    int cont1 = 0, cont2 = 0;
    cout << "*** CARGA DE COLA 1 ***" << endl;
    do{
        cout<<"Ingrese un dato: ";
        cin>>dato;
        cola1.encolar(dato);
        cont1++;
        cout<<"Desea ingresar otro dato? (s/n): ";
        cin>>opcion;
    }while(opcion=='s');
    cout << "*** CARGA DE COLA 2 ***" << endl;
    do{
        cout<<"Ingrese un dato: ";
        cin>>dato;
        cola2.encolar(dato);
        cont2++;
        cout<<"Desea ingresar otro dato? (s/n): ";
        cin>>opcion;
    }while(opcion=='s');

    if(leerCola(cola1, cola2, cont1, cont2)){
        cout<<"Las colas son iguales"<<endl;
    }else{
        cout<<"Las colas son distintas"<<endl;
    }

    return 0;
}

