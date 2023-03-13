#include <iostream>



using namespace std;


class Nodo{
private:
    int info;
    Nodo *sig;
    Nodo() = default;

public:
    Nodo(int info);//Es el metodo nodo que agrega el valor al nodo
    /**
     *
     * @param size es el tamaño del nodo
     * @param info es el numero
     * @return el nuevo puntero
     *
     */
    void* operator new(size_t size, int info);
    void operator delete(void *ptr);
    void setinfo(int info);
};

class Collector{
private:
    void* cabeza;//dirección del primer nodo

public:
    /**
     * @param ptr es el puntero que se añade para que el collector tenga una dirección
     * */
    void add(void* ptr){
        if(cabeza == NULL){
            cabeza = ptr;
        }

    }
    /**
    *@return cabeza la cual es la dirección del primer espacio del collector
    * */
    void* first(){
        return cabeza;
    }
    /**
     *
     * @return cabeza en este caso es el primer espacio del collector
     */
    void* getfirst() {
        return cabeza;
    }
};

Collector *collector = new Collector();

Nodo::Nodo(int info) {
    this->info = info;
}

void* Nodo::operator new(size_t size, int info) {
    if(collector->first() == NULL){
        return ::new Nodo(info);
    }
    static_cast<Nodo*>(collector->first())->setinfo(info);
    return collector->getfirst();
}

void Nodo::operator delete(void *ptr) noexcept {
    collector->add(ptr);
}

void Nodo::setinfo(int info) {
    this->info = info;
}




typedef Nodo* nodoPtr;

/**
 *
 * @param cabeza
 */
void eliminarNodo(nodoPtr& cabeza){
    nodoPtr ptrTemp;
    if(cabeza == NULL){
        cout << "la collector está vacía" << endl;
    }else {
        ptrTemp = cabeza;
        cabeza = cabeza->sig;
        //delete ptrTemp;
    }
}
/**
 *
 * @param cabeza
 * @param info
 */
void crearNuevoNodo(nodoPtr& cabeza, int info)
{

    nodoPtr ptrTemp; //puntero de dirección de nodo
    ptrTemp = new Nodo; //crea el nuevo nodo
    ptrTemp->info = info; // dato ingresado
    ptrTemp->sig = cabeza; //
    cabeza = ptrTemp;
    //delete ptrTemp;.
    free(ptrTemp);
}




nodoPtr head;
/**
 *
 * @param cabeza
 * @param info
 */
void nuevo(nodoPtr& cabeza, int info){
        cabeza = head;
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



}
/**
 *
 * @param cabeza
 */
void quitar(nodoPtr& cabeza){
    nodoPtr temp;
    temp = cabeza;
    head = temp;
    temp->sig = head;
}



int main() {

    nodoPtr cabeza;
    cabeza = new Nodo();
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


            while (temp != NULL) {//imprime collector nodo
                cout << temp->info;
                cout << "-";
                temp = temp->sig;
            }
            cout <<"-------------------------------------------"<<endl;
            /**
            while (tmpCol != NULL) {//imprime collector collector
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
            while (temp != NULL) {//imprime collector nodo
                cout << temp->info;
                cout << "-";
                temp = temp->sig;
            }
            cout << "-------------------------------------------"<<endl;
            while (tmpCol != NULL) {//imprime collector collector
                cout << tmpCol->info;
                cout << "-";
                tmpCol = tmpCol->sig;
            }
            cout << "\n";
        }

    }
}
