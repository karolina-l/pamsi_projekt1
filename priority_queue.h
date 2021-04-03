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
    void push(int new_id, std::string& mess_text);
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

//zwraca ierwszy element kolejki bez zdejmowania go
//gdy kolejka jest pusta wyrzuca wyjatek std::length_error
std::string PrQueue::front() {
    if(head) return head->data;
    else throw std::length_error("Kolejka jest pusta");
}
void PrQueue::push(int new_id, std::string &mess_text) { //priorytet 1 jest wazniejszy niz priorytet 2 etc.
    Package* temp;
    Package* iter;
    temp = new Package;
    temp->ID=new_id;
    temp->data=mess_text;
    temp->nextPack= nullptr;
    if(head) head=temp=tail;               //czy kolejka jest pusta?
    else if((head->ID) >= temp->ID){       //czy  ID pierwszego elementu jest wieksze niz id nowego?
        temp->nextPack = head;
        head = temp;
    }
    else{                               //jesli nic poprzedniego, to szukaj miejsca, w ktorym ID nastepnego jest wieksze niz wstawianego
        iter = head;
        while(((iter->nextPack->ID) < temp->ID) && (iter->nextPack)) iter = iter->nextPack;
        temp->nextPack = iter->nextPack;   //wstaw nowy przed element z wiekszym ID
        iter->nextPack =temp;             //ustaw wskaznik elementu przed na nowy element
    }
    if((temp->nextPack) == nullptr) tail = temp;  //jesli dodany element wskazuje na null, to staje sie nowym tailem
}


void PrQueue::pop() {
    if(head){
        Package *temp = head;       //zapisanie heada do zmiennej dodatkowej
        head = head->nextPack;
        if(!head) tail= nullptr;    //czy lista jest pusta? tak -> ustaw tail na null
        delete temp;                //usuniecie elementu z pamieci
    }
}

#endif //KLECKA_PR1_PRIORITY_QUEUE_H
