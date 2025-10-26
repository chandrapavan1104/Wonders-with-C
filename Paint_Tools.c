#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

union REGS in,out;

void check()
{
in.x.ax=0;
int86(0X33,&in,&out);
if(out.x.ax==0)
printf("failed");
else
printf("passed");
}
void button()
{
int i,j;
for(i=200;i<281;i++)
for(j=200;j<223;j++)
putpixel(i,j,8);
outtextxy(217,206,"CLICK");
while(out.x.bx==1)
{
in.x.ax=3;
int86(0X33,&in,&out);
if(out.x.bx==1||out.x.bx==2)
outtextxy(217,250,"HELLO WORLD");
//else
//outtextxy(217,250,"stupid");
}
}



void draw()
{
int x,y,x1,y1;
while(!kbhit())
{
in.x.ax=4;
int86(0X33,&in,&out);
x=out.x.cx;
y=out.x.dx;
in.x.ax=3;
int86(0X33,&in,&out);
if(out.x.bx==1)
{
in.x.ax=3;
int86(0X33,&in,&out);
while(!kbhit())
{
in.x.ax=4;
int86(0X33,&in,&out);
x1=out.x.cx;
y1=out.x.dx;
line(x,y,x1,y1);
x=x1;
y=y1;
in.x.ax=3;
int86(0X33,&in,&out);
}
}
}
}

void show()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\TURBOC3\\BGI");
in.x.ax=1;
int86(0X33,&in,&out);
//button();
draw();
getch();
closegraph();
}

int main()
{
clrscr();
check();
show();
getch();
return 0;
}
