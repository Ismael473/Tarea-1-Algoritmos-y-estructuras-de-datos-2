//
// Created by ismae on 10/3/2023.
//
#include <iostream>
class Collector{
public:

    int info;
    Collector *sig;

};
typedef Collector* collectorPtr;

collectorPtr head;
void nuevo(collectorPtr& cabeza, int info){

    if(head == NULL){
        Collector* cabeza = new Collector;
        cabeza->info = info;
        cabeza->sig = NULL;
    }else{
        cabeza = head;
        cabeza->info = info;
        cabeza->sig = head->sig;
        head = head->sig;

    }

}

void quitar(collectorPtr& cabeza){
    collectorPtr temp;
    temp = cabeza;
    head = temp;
    temp->sig = head;
}



