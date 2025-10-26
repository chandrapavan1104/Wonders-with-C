#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void main()
{
int gd=DETECT,gm,x,y,i,j,k=0;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
x=getmaxx();
y=getmaxy();
setfillstyle(5,4);
rectangle(0,10,x,y-10);       //total screen
rectangle(x-80,40,x,y-10);    //side bar
rectangle(0,10,x,40);         //top bar
rectangle(x-80,40,x,60);      //tools
settextstyle(0,0,1);
outtextxy(x-60,48,"TOOLS");
rectangle(x-80,60,x,80);      //shapes
outtextxy(x-60,68,"SHAPES");
rectangle(x-80,80,x-40,110);
circle(x-60,95,10);           //circle
rectangle(x-40,80,x,110);
line(x-30,105,x-20,87.68);    //triangle
line(x-20,87.68,x-10,105);
line(x-10,105,x-30,105);
rectangle(x-80,110,x-40,140);
rectangle(x-70,115,x-50,135); //square
rectangle(x-40,110,x,140);
ellipse(x-20,125,0,360,15,10); //ellipse
rectangle(x-80,140,x,160);
outtextxy(x-60,148,"COLORS");


for(j=160;j<=220;j+=15)
for(i=x-80;i<=x;i+=20)
{
rectangle(i,j,i+20,j+15);
setfillstyle(SOLID_FILL,k);
circle(i+10,j+7,5);
floodfill(i+10,j+7,WHITE);
k++;
}


floodfill(x/2,y/2,0);

setfillstyle(SOLID_FILL,RED); //cross
rectangle(x-40,10,x,40);
floodfill(x-25,20,WHITE);
settextstyle(0,0,3);
outtextxy(x-30,13,"x");
settextstyle(0,0,1);
rectangle(0,10,100,40);
outtextxy(20,22,"Free Hand");


getch();
closegraph();
}
