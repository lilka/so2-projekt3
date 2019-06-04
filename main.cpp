#include "Screen.h"
#include "River.h"
#include "Prom.h"
#include "People.h"
#include <mutex>
#include <thread>
#include <vector>
#include <iostream>
#include <fstream>
#include <ncurses.h>
#include <string>
#include <unistd.h>


using namespace std;

Screen *screen;
River *river;
Prom *prom;
bool flag = true;
vector<thread> threads;
vector<People*> peoples;




void refreshScreen(){

    while(flag) {
        clear();
            river->drawRiver();
            river->drawSecondRiver();
            river->drawPort();
            prom->drawProm();
                for (int i = 0; i < peoples.size(); i++) {
                        peoples[i]->drawPeople();
                 }
                 
        refresh();
        usleep(20000);
    }
    clear();
    endwin();
}

void escape(){
    int inputChar;
    while(flag){
        inputChar = getch();
        if(inputChar == 'q'){
            flag= false;
        }
    }
}

void makeriver(){
    float x = screen->getScreenWidth();
    float y = screen->getScreenHeight();

     river = new River(x, y);
     usleep(50000);

}

void moveProm(Prom *prom){
 while((flag)){
     prom->moveProm();
     usleep(90000);
 }
}

void makeNewProm(){
     float x = screen->getScreenWidth();
     float y = screen->getScreenHeight();

     prom=new Prom(x,y);
     moveProm(prom);

     usleep(50000);

}


void movePeople(People *people){
 while((flag)){
     people->movePeople();
     usleep(90000);
 }
}

void makeNewPeople(){

    float x = screen->getScreenWidth();
    float y = screen->getScreenHeight();

    short tmp;
 
    while(flag)
    {

        tmp = rand() % 8 +1;
        People *people = new People(x, y);
        people=new People(x,y);
        peoples.push_back(people);
   
        threads.push_back(thread(movePeople, peoples.back()));
        
        usleep(5000000);



    }
}





int main() {
    srand(time(NULL));
    screen= new Screen();
    thread generateNewProm(makeNewProm);
    thread generateNewPeople(makeNewPeople);
    thread generateriver(makeriver);
    thread refreshScreenThread(refreshScreen);
    thread escapeThread(escape);
    
    
    escapeThread.join();
    generateNewPeople.join();
    refreshScreenThread.join();
    generateriver.join();
    generateNewProm.join();
  


    for(int i = 0; i<threads.size(); i++){
        threads[i].join();
    }
    

    endwin();
    return 0;

}

