#include <iostream>
#include <string>
#include <cmath>
#include "priority_queue.h"


//funkcja zwraca ilosc paczek, jakie nalezy stworzyc
int num_of_packs(int packlen, int messlen){
    auto pl = (float) packlen;
    auto ml = (float) messlen;
    return (int)ceil(ml/pl);
}

static int counter = 0;

int main()
{
    std::string message;
    int packlen=4;

    std::cout << "Wpisz wiadomosc:";
    getline(std::cin, message);
    std::cout<<message<<std::endl;


    int packnum = num_of_packs(packlen, message.length());   //ilosc paczek

    PrQueue queue;

    for(int i = 0; i < packnum; i++){                      //do i mniejszego od ilosci paczek
        Package pack;
        pack.ID = i;
        for(int j = 0; j < packlen; j++){                   //do j mniejszego od dlugosci paczki
            if(counter <= message.length()) {               //jesli counter jest mniejszy od dlugosci wiadomosci
                pack.data += message[counter];              //zapisz do daty znak wiadomosci
                counter++;
            }
            else pack.data += '\0';                         //jesli nie, wstaw znak konca tekstu
        }
        //pack.showPack();
    }
    counter = 0;



    return 0;
}
