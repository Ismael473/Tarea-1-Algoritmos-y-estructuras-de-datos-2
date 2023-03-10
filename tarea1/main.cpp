#include <iostream>
#include "Collector.cpp"
#include "Prueba.cpp"

using namespace std;

class Nodo{
public:
    int info;
    Nodo *sig;

};

typedef Nodo* nodoPtr;

void eliminarNodo(nodoPtr& cabeza){
    nodoPtr ptrTemp;
    if(cabeza == NULL){
        cout << "la lista está vacía" << endl;
    }else {
        ptrTemp = cabeza;
        cabeza = cabeza->sig;
        //delete ptrTemp;
    }
}

void crearNuevoNodo(nodoPtr& cabeza, int info)
{
    if(cabeza->info == NULL){
        cabeza->info = info;
    }else {
        nodoPtr ptrTemp; //puntero de dirección de nodo
        ptrTemp = new Nodo; //crea el nuevo nodo
        ptrTemp->info = info; // dato ingresado
        ptrTemp->sig = cabeza; //
        cabeza = ptrTemp;
    }
}

int main() {

    nodoPtr cabeza;
    cabeza = new Nodo;
    cabeza->info = NULL;
    cabeza->sig = NULL;
    int nuevoDato;
    string operacion;

    while (true) {

        cout<< "ingrese que desea hacer + para agregar, - para eliminar";
        cin >> operacion;
        if (operacion == "+") {
            cout << "ingrese los datos del nuevo nodo";
            cin >> nuevoDato;

            crearNuevoNodo(cabeza, nuevoDato);
            nodoPtr temp;
            temp = cabeza;


            while (temp != NULL) {
                cout << temp->info;
                cout << "-";
                temp = temp->sig;
            }
            cout << "\n";
        }
        if (operacion == "-"){

            eliminarNodo(cabeza);
            nodoPtr temp;
            temp = cabeza;
            while (temp != NULL) {
                cout << temp->info;
                cout << "-";
                temp = temp->sig;
            }
            cout << "\n";
        }

    }
}
