#include <graphics.h>
#include <math.h> 
 
int main()
{
   int gd = DETECT, gm;
   int cx = 320, cy = 240, r1=70, r2=100, r3=60;
   int x, y; 
   double theta1, theta2;       

   initgraph(&gd, &gm, NULL);

   for ( theta1 = 0.0; theta1 <= 2*M_PI; theta1 = theta1 + M_PI/10.0 ){
   	for ( theta2 = 0.0; theta2 <= 2*M_PI; theta2 = theta2 + M_PI/10 ){

	if (theta1 > theta2) setcolor(RED);
	else setcolor(BLUE);

	x= (int) (r1*cos(theta1) + r2*cos(theta2));
        y= (int) (r1*sin(theta1) + r2*sin(theta2));

        circle(cx + x, cy + y, r3);
	}	       

   }
    
   getch();
   closegraph();
   return 0;

}

