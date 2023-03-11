#include <iostream>
#include "Collector.cpp"


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

    nodoPtr ptrTemp; //puntero de dirección de nodo
    ptrTemp = new Nodo; //crea el nuevo nodo
    ptrTemp->info = info; // dato ingresado
    ptrTemp->sig = cabeza; //
    cabeza = ptrTemp;
    //delete ptrTemp;
}




nodoPtr head;
void nuevo(nodoPtr& cabeza, int info){
        cabeza = reinterpret_cast<nodoPtr>(head->info);
        cout << "hola"<<endl;
        crearNuevoNodo(cabeza,info);
        //Nodo* cabeza = new Nodo;
        //cabeza->info = info;
        //cabeza->sig = NULL;
        /**
        cabeza = reinterpret_cast<nodoPtr>(head->info);
        crearNuevoNodo(cabeza, info);
        cabeza->info = info;
        cabeza->sig = head->sig;
        */
        head = head->sig;


}

void quitar(nodoPtr& cabeza){
    nodoPtr temp;
    temp = cabeza;
    head = temp;
    temp->sig = head;
}



int main() {

    nodoPtr cabeza;
    cabeza = new Nodo;
    cabeza->info = NULL;
    cabeza->sig = NULL;
    int nuevoDato;
    string operacion;
    //quitar(cabeza);
    while (true) {

        cout<< "ingrese que desea hacer + para agregar, - para eliminar";
        cin >> operacion;
        if (operacion == "+") {//Crea dato nuevo
            cout << "ingrese los datos del nuevo nodo";
            cin >> nuevoDato;

            //crearNuevoNodo(cabeza, nuevoDato);
            nuevo(cabeza, nuevoDato);
            nodoPtr temp;
            nodoPtr tmpCol;
            temp = cabeza;
            tmpCol = head;


            while (temp != NULL) {//imprime lista nodo
                cout << temp->info;
                cout << "-";
                temp = temp->sig;
            }
            cout <<"-------------------------------------------"<<endl;
            /**
            while (tmpCol != NULL) {//imprime lista collector
                cout << tmpCol->info;
                cout << "-";
                tmpCol = tmpCol->sig;
            }
            cout << "\n";
             */
        }
        if (operacion == "-"){//elimina primer dato viejo

            quitar(cabeza);
            nodoPtr temp, tmpCol;
            temp = cabeza;
            while (temp != NULL) {//imprime lista nodo
                cout << temp->info;
                cout << "-";
                temp = temp->sig;
            }
            cout << "-------------------------------------------"<<endl;
            while (tmpCol != NULL) {//imprime lista collector
                cout << tmpCol->info;
                cout << "-";
                tmpCol = tmpCol->sig;
            }
            cout << "\n";
        }

    }
}
