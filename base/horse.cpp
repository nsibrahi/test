#include <iostream>
#include <time.h>
#include <ctime>
#include <cstdlib>

//const int HORSE_NUM = 5;
// should be NUM_HORSES

const int NUM_HORSES = 5;

//I'm also going to declare the track length as a constant
const int LENGTH = 15;

// mispelled 'position' I fixed it globally
// spelling errors will absolutely KILL you as a programmer. 
// get the spelling right, and keep it right throughout.  
// You tend to spell things wrong early (hose_loc for horse_loc)
// then hang on doggedly to the wrong spelling.  The next
// programmer who has to modify your code will hunt you down
// with a bazooka.

void show_track(int horse, int hose_loc, int length){
    // nice function -
    // but I've made length a constant, and if you know horse
    // you know the horse loc.
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

// again, coinf_flip()


bool coinf_flip(){
    int rand_num = rand()%2;
    return rand_num==1 ;
    // you made this more complex than it had to be.
    // you can just return rand_num as it will already be zero or one
    // this works, but it makes your other code harder
}

// if you really want this boolean, I would name it something like
// is_heads() then return a boolean.  But honestly a number is a lot 
// easier to work with, so I might make the function return an integer
// 1 or zero:

int andy_flip(){
  // % 2 gets a 0 or 1
  int step = rand() %2;
  return step;
}

void race ( int horses , int length){
    int position[horses];
    int winner = -1;
    for(int i=0; i<horses; i++){
        position[i]=0;
    }

    // a while true loop is always problematic, because you don't really 
    // mean it.  You want this loop to end at some point, but you don't 
    // know how it will end here.  That causes a lot of problems and you
    // end up using something rude like exit() to get out of the loop
    // eventually.

    while(true){
        for (int i=0; i<horses ; i++){
            if(true){
            // true is always true, so this if statement doesn't mean anything
            // coin_flip as a function sounds like a good idea, but 
            // you are making things a lot harder for yourself than you need
            // to.  You can make it return a 0-1 number, which might be 
            // a lot easier.
                bool increase = coinf_flip();
                if(increase){
                    position[i]=position[i]+1;
                }

                
            }
            show_track(i,position[i],length);

            // this should be an if statement, not a while loop
            while(position[i]==(length-1)){
                winner=i;
                std::cout << "Horse " << winner << " wins!" << std::endl;
                // this is a very crude way to end the program
                // It's like throwing a boat anchor out the window
                // every time you want to stop the car. 
                exit(0);
            }
        }
        std::cout << "\n";
    }
}

void andyRace(){

/*
  here's my version of the race function
algorithm:

set keepGoing to true
while keepGoing is true:
  for each horse:
    advance the horse (or not)
    print the lane
    determine if we have a winner
    if we do have a winner
      set keepGoing to false
  allow for user input to see next round

See how I implement the algorithm below
*/

  // initialize horse positions
  int position[] = {0, 0, 0, 0, 0};

  // keepGoing - it really is a wonderful tool.
  bool keepGoing = true;
  while (keepGoing){

    for (int horseNum = 0; horseNum < NUM_HORSES; horseNum++){
      // look how much easier my coin_flip method is to use
      position[horseNum] += andy_flip();
      show_track(horseNum, position[horseNum], LENGTH);
      
      //  check for winning condition
      if (position[horseNum] >= LENGTH){
        std::cout << "Horse # " << horseNum << " wins!" << std::endl;
        keepGoing = false;
      } // end if
    } // end for

    // get user input for fun
    std::cout << std::endl;
    std::cout << "Press ENTER for another turn" << std::endl;
    std::cin.ignore();

  } // end while
} // end function

void start_race()
{
    int seed;
    std::cout<<"Please enter a random seed: ";
    std::cin >> seed;
    srand(seed);
    //race(5,15);
    andyRace();
}

int main()
{
    start_race();
}
