#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
int main()
{
int gd=DETECT,gm,x,y,i,j=1;
float p;
char a[10];
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
x=getmaxx()/2;
y=getmaxy()/2;
p=3.14;
setfillstyle(1,3);
circle(x,y,200);
floodfill(x+10,y+10,3);
for(i=1;i<=12;i++)
{
line(x,y,x+150*cos((i*p/6)),y+150*sin((i*p/6)));
sprintf(a,"%d",(i+3)%12);
settextstyle(1,0,3);
outtextxy(x+170*cos((i*p/6)),y+180*sin((i*p/6)),a);
}
while(1)
{
j++;
line(x,y,x+150*cos((j*p/180)),y+150*sin((j*p/180)));
delay(1000);
}
getch();
closegraph();
return 0;
}
