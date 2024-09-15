/*
Implementar  una  función  que  reciba  una  cola  de  números  enteros  y  una  pila  entera  vacía,  y 
separe los elementos de la cola de tal manera que los elementos pares de la cola permanezcan 
en la cola, y los elementos impares formen parte de la pila. 
Observaciones:
● Al insertar los elementos en la pila, deberán aparecer en orden inverso a como estaban 
en  la  cola:  el  elemento  de  la  posición  1  de  la  cola  estará  al  fondo  de  la  pila,  el  de  la 
posición 3 será el segundo desde el fondo, etc. 
● Si la cola estuviera vacía mostrar mensaje de error.
*/

#include <iostream>
#include "Cola/Cola.h"
#include "Pila/Pila.h"
#include <limits>
using namespace std;

void separar(Cola<int> &cola, Pila<int> &pila){
    Cola<int> colaAux;
    Pila<int> pilaAux;

    while(!cola.esVacia()){
       int dato = cola.desencolar();
       if(dato%2 == 0){
        colaAux.encolar(dato);
       } else {
        pilaAux.push(dato);
       } 
    }

    while(!colaAux.esVacia()){
        cola.encolar(colaAux.desencolar());
    }

    while(!pilaAux.esVacia()){
        pila.push(pilaAux.pop());
    }
}

void mostrar(Cola<int> &cola, Pila<int> &pila){
    cout << "*****COLA*****" << endl;
    while(!cola.esVacia()){
        int dato = cola.desencolar();
        cout << " <- " << dato;
    }
    cout << "" << endl;
    cout << "****PILA****" << endl;
    while(!pila.esVacia()){
        int dato = pila.pop();
        cout << dato << " -> ";
    }
    cout << "NULL" <<endl;
}

int main() {
    Cola<int> cola;
    Pila<int> pila;
    int num;
    cout << "Ingrese los numeros de la cola(ingrese q para finalizar)" << endl;
    while (true) {
        cout << "Numero: ";
        if (cin >> num) {
            cola.encolar(num);
        } else {
            cin.clear(); // Limpiar el estado de error del stream
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorar entrada incorrecta
            break; // Salir del bucle cuando se ingresa algo que no es un número
        }
    }
    cout << "" << endl;
    separar(cola,pila);
    mostrar(cola,pila);
}