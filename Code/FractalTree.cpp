#include <winbgim.h>
#include <math.h>
#include <iostream>

using namespace std;

void stem(int x,int y,float delta,float d)
{
	int x1,y1,n,m;
	float pi=3.1415927;
	setcolor(COLOR(255*(500-y)/(500-20),255*(y-20)/(500-20),0));
	x1=x-d*sin(delta);
	y1=y-d*cos(delta);
	n=x-d*sin(delta-2*pi/6);
	m=y-d*cos(delta-2*pi/6);

	line(x,y,x1,y1);
	line(x,y,n,m);
	if(d>10)
	{	
		delay(10);
		stem(x1,y1,delta+pi/6,d*0.75); 
		stem(n,m,delta-pi/6,d*0.75);
	}
}

void stick(int x,int y,float d)
{
	float pi=3.1415927,delta=pi/6;
	setcolor(COLOR(0,255,0));
	line(x,y,350,600);

	stem(x,y,delta,d);
}
int main()
{
	int x=350,y=400,l=100,k=250,j=600,h=300;
	float d=80;
	initwindow(700,700);

	stick(x,y,d);
	getch();
	return 0;
}
