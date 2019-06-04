#include <ncurses.h>
#include "Prom.h"

Prom::Prom( int initX, int initY) {
   

    screenX = initX;
    screenY = initY;

    x=0;
    //x = screenX/2+11;
    y = 70;

    xVectora = 0;
    yVectora = -1;

}

void Prom::moveProm() {
   

    x += xVectora;
    y += yVectora;


   if( x>= screenX ) {
        xVectora *= -1;
    }

   if(x<=0){
       xVectora *=-1;
     
    }

    if( y >= 70  ) {
        yVectora *= -1;
    }

   if(y <= 138){
        yVectora *= -1;
        
    }
   
}

void Prom::drawProm() {
    move(x,y);
    printw("(            )");
 }
