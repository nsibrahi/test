#include <iostream>
#include <time.h>
#include <ctime>
#include <cstdlib>

const int HORSE_NUM = 5;

void show_track(int horse, int hose_loc, int length){
    for(int i=0;i < length;i++){
        if(i == hose_loc){
            std:: cout << horse;
        }
        else{
           std:: cout<<".";
        }
    }
    std:: cout<< std::endl;
}

bool coinf_flip(){
    int rand_num = rand()%2;
    return rand_num==1 ;
}

void race ( int horses , int length){
    int postion[horses];
    int winner = -1;
    for(int i=0; i<horses; i++){
        postion[i]=0;
    }
    while(true){
        for (int i=0; i<horses ; i++){
            if(true){
                bool increase = coinf_flip();
                if(increase){
                    postion[i]=postion[i]+1;
                }
            }
            show_track(i,postion[i],length);
            while(postion[i]==(length-1)){
                winner=i;
                std::cout << "Horse " << winner << " wins!" << std::endl;
                exit(0);
            }
        }
        std::cout << "\n";
    }
}

void start_race()
{
    int seed;
    std::cout<<"Please enter a random seed: ";
    std::cin >> seed;
    srand(seed);
    race(5,15);
}

int main()
{
    start_race();
}
