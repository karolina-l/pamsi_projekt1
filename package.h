//
// Created by Karolina on 02.04.2021.
//

#ifndef KLECKA_PR1_PACKAGE_H
#define KLECKA_PR1_PACKAGE_H
#include <memory>

struct Package{

    int ID;             //priorytet
    std::string data;   //tresc wiadomosci
    Package* nextPack;  //wskaznik na nastepny obiekt
    void showPack();
    //Package() = default;
    //Package(int new_id, std::string text);


};

void Package::showPack() {
    std::cout<<data<<std::endl;
}

//Package::Package(int new_id, std::string text): ID(new_id), data(text), nextPack(nullptr){}

/*std::unique_ptr<Package> createPackage(int new_id, std::string text)
{
    return std::unique_ptr<Package>(new Package(new_id,text));
}
*/
#endif //KLECKA_PR1_PACKAGE_H
