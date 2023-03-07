#include <iostream>
#include <mmcobj.h>


class Nodo
{
public:
    int data;
    Nodo* siguiente;
};
class Nodo* newNodo(int data){//establece la clase nodo
    Nodo* nodo = new Nodo;//puntero que apunta a la dirección de memoria del nodo
    nodo->data = data;//Se le asigna la información de data a la dirección de nodo
    nodo->siguiente = NULL;//Establece que el siguiente nodo será vacío
    return nodo;
}
void insertarNodo(Nodo** raiz, int data){//Crea los nodos
    Nodo* nodo = newNodo(data);//establece el valor almacenado en la dirección de nodo
    Nodo* ptr;//puntero que apunta a nodo ?
    if(*raiz == NULL){
        *raiz = nodo;
    }else{
        ptr = *raiz;//se crea el puntero cuyo valor es igual a raíz
        while(ptr->siguiente != NULL){//se crea loop de busqueda del ultimo nodo
            ptr = ptr->siguiente;//mueve los nodos en busqueda del ultimo
        }
        ptr->siguiente = nodo;//asigna el ultimo nodo
    }
}
void imprimeLinkedList(Nodo* raiz){
    while(raiz != NULL) {
        std::cout << raiz->data << "->";
        raiz = raiz->siguiente;
    }
    std::cout<<"NULL"<<std::endl;
}
Nodo creaLinkedList(int arreglo[], int n){
    Nodo *raiz = NULL;
    for(int i = 0; i < n; i++){
        insertarNodo(&raiz,arreglo[i]);
    }
    return *raiz;
}
int main() {
    int arr[] = {1,2,3,4,5}, n=5;
    Nodo raiz = creaLinkedList(arr,n);
    imprimeLinkedList(*raiz);
    return 0;

}
