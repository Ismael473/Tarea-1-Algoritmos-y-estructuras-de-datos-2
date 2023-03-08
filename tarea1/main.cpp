#include <iostream>

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


    while (true) {
        nodoPtr cabeza;
        cabeza = new Nodo;
        cabeza->info = 0;
        cabeza->sig = NULL;

        std::cout << "ingrese los datos del nuevo nodo";
        int nuevoDato;
        std::cin >> nuevoDato;
        crearNuevoNodo(cabeza, nuevoDato);
        nodoPtr temp;
        temp = cabeza;

        while (temp != NULL) {
            std::cout << temp->info ;
            std::cout << "-" ;
            temp = temp->sig;
        }
        std::cout << "\n";

    }
}
