#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
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

    std::cout<<"Wyslij wiadomosc\n";
    std::cout<<"-----MENU-----\n";
    std::cout<<"w - wpisz wlasna wiadomosc\n";
    std::cout<<"r - wczytaj wiadomosc z pliku\n";
    std::cout<<"d - wyslij wiadomosc domyslna\n";
    std::cout<<"q - wyjscie\n";

    char choice;
    std::cin >> choice;
    while(choice != 'e') {
        switch (choice) {
            case 'w': {
                std::cin.ignore( std::numeric_limits < std::streamsize >::max(), '\n' );
                std::cout << "Wpisz wiadomosc: ";
                getline(std::cin, message);
                std::cout << message << std::endl;
                choice = 'e';
                break;
            }
            case 'r': {
                std::ifstream file;
                std::string path;
                std::cin.ignore( std::numeric_limits < std::streamsize >::max(), '\n' );
                std::cout << "Podaj sciezke do pliku. UWAGA! gdy uzywasz znaku \\, napisz go 2 razy: \nC:\\\\Users\\\\Karolina\\\\Desktop\\\\nazwa.txt: ";
                getline(std::cin, path);
                //std::cout << path << "\n";
                file.open(path);
                if (file.is_open()) {
                    while (!file.eof()) getline(file, message);
                    file.close();
                    std::cout<<"Wczytano.\n";
                    choice = 'e';
                }
                else {
                    std::cout << "Otwieranie pliku nie powiodlo sie. Sprobuj jeszcze raz";
                    choice = 'm';
                }

                break;
            }
            case 'd': {
                message = "Litwo! Ojczyzno moja! ty jestes jak zdrowie Ile cie trzeba cenic, ten tylko sie dowie, Kto cie stracil. Dzis pieknosc twa w calej ozdobie widze i opisuje, bo tesknie po tobie.";
                choice = 'e';
                break;
            }
            case 'q': {
                std::cout << "\nDo zobaczenia!\n";
                exit(0);
            }
            case 'm': {
                std::cout << "Wyslij wiadomosc\n";
                std::cout << "-----MENU-----\n";
                std::cout << "w - wpisz wlasna wiadomosc\n";
                std::cout << "r - wczytaj wiadomosc z pliku\n";
                std::cout << "d - wyslij wiadomosc domyslna\n";
                std::cout << "q - wyjscie\n";
                std::cin >> choice;
                break;
            }
            default:
                choice = 'm';

        }
    }

    char answer;
    std::cout<<"Czy chcesz zmienic ilosc znakow w paczce? Domyslna wartosc to: 4. Y/N  ";
    std::cin>>answer;
    while(answer != 'e') {
        switch (answer) {
            case 'Y': {
                std::cout << "Podaj nowa ilosc znakow w paczce: \n";
                std::cin >> packlen;
                answer  = 'e';
                break;
            }
            case 'N': {
                answer = 'e';
                break;
            }

            case 'o': {
                std::cout << "Czy chcesz zmienic ilosc znakow w paczce? Domyslna wartosc to: 4. Y/N  ";
                std::cin >> answer;
                break;
            }
            default: {
                std::cout << "Bledna wartosc. Sprobuj jeszcze raz.\n";
                answer = 'o';
            }
        }
    }


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
  }

    srand(time(NULL));
    int num_of_iter = rand() % packnum + message.length();

    for(int i = 0; i < num_of_iter; i++){
        int index_1 = rand() % packnum;
        int index_2 = rand() % packnum;
        std::swap(pack[index_1],pack[index_2]);
    }
    std::cout<<" Dowod, ze wiadomosci sa wysylane losowo\n";
    std::string t;
    int a;
    for(int i=0; i<packnum; i++){
        t=pack[i].data;
        a = pack[i].ID;
        std::cout<<t<<" ID:"<<a<<"\n";
    }

    for(int i = 0; i < packnum; i++){
        queue.push(pack[i]);
    }


    std::cout<<"Odebrano wiadomosc!\n";
    std::string mg;
    for(int i = 0; i < packnum; i++){
        mg = queue.front();
        std::cout<<mg;
        queue.pop();
    }

    return 0;
}
