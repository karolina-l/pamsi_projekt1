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
        std::string temp;
        for(int j = 0; j < packlen; j++){                   //do j mniejszego od dlugosci paczki
            if(counter <= message.length()) {               //jesli counter jest mniejszy od dlugosci wiadomosci
                temp += message[counter];              //zapisz do daty znak wiadomosci
                counter++;
            }
            else temp += '\0';                         //jesli nie, wstaw znak konca tekstu
        }
        queue.push(i, temp);
    }
    counter = 0;
    std::string test;
    for(int i = 0; i < packnum; i++){
        test = queue.front();
        std::cout<<test<<std::endl;
        queue.pop();
    }


    return 0;
}
