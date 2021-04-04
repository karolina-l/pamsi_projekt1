#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <time.h>
#include "priority_queue.h"


//funkcja zwraca ilosc paczek, jakie nalezy stworzyc
int num_of_packs(const int& packlen, const int &messlen){
    auto pl = (float) packlen;
    auto ml = (float) messlen;
    return (int)ceil(ml/pl);
}

static int counter = 0;

int main()
{
    std::string message;
    int packlen=4;

    std::cout << "Wpisz wiadomosc: ";
    getline(std::cin, message);
    std::cout<<message<<std::endl;

    std::cout << "Podaj dlugosc paczki:" ;
    std::cin>>packlen;

    int packnum = num_of_packs(packlen, message.length());   //ilosc paczek
    PrQueue queue;

    Package* pack = new Package[packnum];
    for(int i = 0; i < packnum; i++){                      //do i mniejszego od ilosci paczek
        pack[i].ID = i;
        for(int j = 0; j < packlen; j++){                   //do j mniejszego od dlugosci paczki
            if(counter <= message.length()) {               //jesli counter jest mniejszy od dlugosci wiadomosci
                pack[i].data += message[counter];              //zapisz do daty znak wiadomosci
                counter++;
            }
             else pack[i].data += '\0';                         //jesli nie, wstaw znak konca tekstu
        }
        pack[i].showPack();
  }

    srand(time(NULL));
    int num_of_iter = rand() % packnum + message.length();

    for(int i = 0; i < num_of_iter; i++){
        int index_1 = rand() % (packnum-1);
        int index_2 = rand() % (packnum-1);
        std::swap(pack[index_1],pack[index_2]);
    }
    std::cout<<"\n\n shuffle\n\n";
    std::string t;
    int a;
    for(int i=0; i<packnum; i++){
        t=pack[i].data;
        a = pack[i].ID;
        std::cout<<t<<" "<<a<<"\n";
    }

    for(int i = 0; i < packnum; i++){
        queue.push(pack[i]);
    }

    std::string bla;
    for(int i = 0; i < packnum; i++){
        bla = queue.front();
        std::cout<<bla;
        queue.pop();
    }


    /*for(int i = 0; i < packnum; i++){                      //do i mniejszego od ilosci paczek
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
    }*/

    return 0;
}
