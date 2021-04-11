//
// Created by Karolina on 02.04.2021.
//

#ifndef KLECKA_PR1_PRIORITY_QUEUE_H
#define KLECKA_PR1_PRIORITY_QUEUE_H
#include "package.h"
#include <memory>

class PrQueue{

    Package* head;
    Package* tail;

public:
    PrQueue();
    ~PrQueue();
    bool empty();
    std::string front();
    //void push(int new_id, const std::string& mess_text);
    void push(Package& pack);
    void pop();

};

PrQueue::PrQueue(): head(nullptr), tail(nullptr){}
PrQueue::~PrQueue() {
    while(head){
        pop();
    }
}
//sprawdzenie czy kolejka jest pusta
//True gdy head==NULL
//False gdy tail==NULL
bool PrQueue::empty() {
    return !head;
}

//zwraca pierwszy element kolejki bez zdejmowania go
//gdy kolejka jest pusta wyrzuca wyjatek std::length_error
std::string PrQueue::front() {
    if(head)  return head->data;
    else throw std::length_error("Kolejka jest pusta");
}

void PrQueue::push(Package& pack) { //priorytet 1 jest wazniejszy niz priorytet 2 etc.
    Package* iter;

    pack.nextPack = nullptr;
    if(empty()) {                             //czy kolejka jest pusta?
        head = &pack;
    }
    else if((head->ID) >= pack.ID){        //czy  ID pierwszego elementu jest wieksze niz id nowego?
        pack.nextPack = head;
        head = &pack;

    }
    else {                                   //jesli nic poprzedniego, to szukaj miejsca, w ktorym ID nastepnego jest wieksze niz wstawianego
        iter = head;
        while ((iter->nextPack) && ((iter->nextPack->ID) < pack.ID))   iter = iter->nextPack;
        pack.nextPack = iter->nextPack;    //wstaw nowy przed element z wiekszym ID
        iter->nextPack = &pack;               //ustaw wskaznik elementu przed na nowy element

        if ((pack.nextPack) == nullptr)
            tail = &pack;  //jesli dodany element wskazuje na null, to staje sie nowym tailem
    }
}


/*void PrQueue::push(int new_id, const std::string &mess_text) { //priorytet 1 jest wazniejszy niz priorytet 2 etc.
    Package* temp;
    Package* iter;
    temp = new Package;
    temp->ID = new_id;
    temp->data = mess_text;
    temp->nextPack = nullptr;
    if(!head) {                             //czy kolejka jest pusta?
        head = temp;
    }
    else if((head->ID) >= temp->ID){        //czy  ID pierwszego elementu jest wieksze niz id nowego?
        temp->nextPack = head;
        head = temp;

    }
    else {                                   //jesli nic poprzedniego, to szukaj miejsca, w ktorym ID nastepnego jest wieksze niz wstawianego
        iter = head;
        while ((iter->nextPack) && ((iter->nextPack->ID) < temp->ID))   iter = iter->nextPack;
        temp->nextPack = iter->nextPack;    //wstaw nowy przed element z wiekszym ID
        iter->nextPack = temp;               //ustaw wskaznik elementu przed na nowy element

        if ((temp->nextPack) == nullptr)
            tail = temp;  //jesli dodany element wskazuje na null, to staje sie nowym tailem
    }
}*/


void PrQueue::pop() {
    if(!empty()){
        head = head->nextPack;
        if(empty()) tail= nullptr;    //czy lista jest pusta? tak -> ustaw tail na null
    }
    else throw std::length_error("Kolejka jest pusta. Usuwanie elementu nie powiodlo sie.");
}

#endif //KLECKA_PR1_PRIORITY_QUEUE_H

