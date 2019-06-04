#include <ncurses.h>
#include "People.h"

People::People( int initX, int initY) {
   

    screenX = initX;
    screenY = initY;

    x=23;
    y=0;

    xVectora = -1;
    yVectora = 0;

}

void People::movePeople() {
   

    x += xVectora;
    y += yVectora;


   if( x>= screenX ) {
        xVectora *= -1;
    }

   if(x<=0){
       xVectora *=-1;
     
    }

    if( y >= screenY  ) {
        yVectora *= -1;
    }

   if(y <= 0){
        yVectora *= -1;
        
    }
   
}

void People::drawPeople() {
    move(x,y);
    printw(" cz ");
 }
