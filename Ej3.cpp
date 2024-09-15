/*
Crear una función que reciba una cola por referencia y un número. Dicha función debe: Eliminar 
todas las ocurrencias de dicho número, menos la primera. Si dicho número no se repite, deja la 
cola como esta. Si dicho número no está en la cola, debe anunciar un mensaje de error. Imprimir 
la cola al final para verificar si hubo o no modificaciones.
 */

#include <iostream>
#include "Cola/Cola.h"
#include <limits>
using namespace std;

void funcionEliminarOcurrencia(Cola<int> &cola, int num){
    Cola<int> colaAux;
    bool encontrado = false;
    while(!cola.esVacia()){
        int dato = cola.desencolar();
        if(dato != num){
            colaAux.encolar(dato);
        }
        if(dato == num && encontrado==false){
            encontrado = true;
            colaAux.encolar(dato);
        }
    }
    // Restauro la cola
    while(!colaAux.esVacia()){
        cola.encolar(colaAux.desencolar());
    }
}

void imprimirCola(Cola<int> &cola){
    Cola<int> colaAux;
    while(!cola.esVacia()){
        int dato = cola.desencolar();
        cout << dato << " ";
        colaAux.encolar(dato);
    }
    cout << endl;
    // Restauro la cola
    while(!colaAux.esVacia()){
        cola.encolar(colaAux.desencolar());
    }
}

int main() {
    Cola<int> cola;
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
    cout << "Ingrese el numero a eliminar: ";
    cin >> num;
    funcionEliminarOcurrencia(cola, num);
    cout << "Cola: ";
    imprimirCola(cola);
    return 0;
}
