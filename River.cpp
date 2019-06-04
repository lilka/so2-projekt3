#include <ncurses.h>
#include "River.h"

River::River(int initX, int initY){

    screenX = initX;
    screenY = initY;

    x = 0;
    y = 80;
}

void River::drawRiver() {
    for(int i =0;i<56;i++){
        move(0+i,70); 
        printw("|");
    
     
    }
   
 }

void River::drawSecondRiver() {
    
   for(int i =0;i<56;i++){
        move(0+i,150); 
        printw("|");
    }
}
void River::drawPort(){
    for(int i = 0; i<8; i++){
        move(25+i, 55);
        printw("|");
    }

    for(int i = 0; i<15; i++){
        move(25, 55+i);
        printw("-");
    }

    for(int i = 0; i<15; i++){
        move(32, 55+i);
        printw("-");
    }

  
}




   
 