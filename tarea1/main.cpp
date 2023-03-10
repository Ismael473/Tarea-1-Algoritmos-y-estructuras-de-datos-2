#include <iostream>

using namespace std;

class Nodo{
public:
    int info;
    Nodo *sig;

};

typedef Nodo* nodoPtr;

void crearNuevoNodo(nodoPtr& cabeza, int info)
{
    nodoPtr ptrTemp;
    ptrTemp = new Nodo;
    ptrTemp->info = info;
    ptrTemp->sig = cabeza;
    cabeza = ptrTemp;
}

int main() {

    nodoPtr cabeza;
    cabeza = new Nodo;
    cabeza->info = NULL;
    cabeza->sig = NULL;
    int nuevoDato;

    while (true) {


        cout << "ingrese los datos del nuevo nodo";
        cin >> nuevoDato;
        crearNuevoNodo(cabeza, nuevoDato);
        nodoPtr temp;
        temp = cabeza;
//        delete cabeza;

        while (temp != NULL) {
            cout << temp->info ;
            cout << "-" ;
            temp = temp->sig;
        }
        cout << "\n";


    }
}
