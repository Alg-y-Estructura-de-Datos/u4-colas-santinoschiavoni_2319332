/*
Crear  un  programa  que  solicite  números  enteros  al  usuario  hasta  que  desee,  almacenar  los 
números  en  una  cola,  pedir  también  un  numero  entero  "n".  Luego  crear  una  función  que 
recibiendo una cola y un número entero “n”, si el "n" se encuentra en una de las posiciones de 
la  cola.  Devuelva  la  suma  de  los  elementos de  la  cola  hasta  llegar  a  "n"  (sin  incluir  a  n).  Si  el 
número "n" no se encuentra en la cola, la función devuelve la suma de todos los elementos de 
la cola. Imprimir primero la cola antes de la suma de sus elementos.
*/

#include <iostream>
#include "Cola/Cola.h"
#include <limits>
using namespace std;

int sumaElementosHastaN(Cola<int> &cola, int n){
    bool encontrado = false;
    int suma1 = 0;
    while(!cola.esVacia()){
        int dato = cola.desencolar();
        if(dato==n){ // Si dato == n, booleano paso a true
            encontrado = true;
        }
        if(encontrado){ // Si es verdadero, devuelvo la suma 2
            return suma1;
        } else { // Si no, sigo sumando ambos
            suma1+=dato;
        }
    }
        return suma1; // Si nunca es verdadero el bool encontrado, devuelvo la suma 2
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
    cout << "Ingrese el numero que desea sumar hasta llegar al mismo: "; cin >> num;
    cout << "La suma es: " << sumaElementosHastaN(cola,num);
}