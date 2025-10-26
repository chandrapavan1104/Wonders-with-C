#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
#include<stdlib.h>
union REGS in,out;
int i,j,m,n,color=0;

int get_key()
{
   union REGS in,out;

   in.h.ah = 0;
   int86(22, &in, &out);

   return ( out.h.ah );
}
void show()
{
   in.x.ax=1;
   int86(0x33,&in,&out);
}
void hide()
{
   in.x.ax=2;
   int86(0x33,&in,&out);
}
void get(int *x,int *y)
{
   in.x.ax=3;
   int86(0x33,&in,&out);
   *x=out.x.cx;
   *y=out.x.dx;
}

void setmouse()
{
in.x.ax=4;
int86(0X33,&in,&out);
in.x.cx=100;
in.x.dx=100;
}

void restrictmouseptr( int x1, int y1, int x2, int y2)
{
   in.x.ax = 7;
   in.x.cx = x1;
   in.x.dx = x2;
   int86(0x33, &in, &out);

   in.x.ax = 8;
   in.x.cx = y1;
   in.x.dx = y2;
   int86(0x33, &in, &out);
}

void detect(int *b)
{
in.x.ax=3;
int86(0x33,&in,&out);
*b=out.x.bx;
}

void design()
{
int p=0;
m=getmaxx();
n=getmaxy();
setfillstyle(5,4);
rectangle(0,10,m,n-10);       //total screen
rectangle(m-80,40,m,n-10);    //side bar
rectangle(0,10,m,40);         //top bar
rectangle(m-80,40,m,60);      //tools
settextstyle(0,0,1);
outtextxy(m-60,48,"TOOLS");
rectangle(m-80,60,m,80);      //shapes
outtextxy(m-60,68,"SHAPES");
rectangle(m-80,80,m-40,110);
circle(m-60,95,10);           //circle
rectangle(m-40,80,m,110);
line(m-30,105,m-20,87.68);    //triangle
line(m-20,87.68,m-10,105);
line(m-10,105,m-30,105);
rectangle(m-80,110,m-40,140);
rectangle(m-70,115,m-50,135); //square
rectangle(m-40,110,m,140);
ellipse(m-20,125,0,360,15,10); //ellipse
rectangle(m-80,140,m,160);
outtextxy(m-60,148,"COLORS");
for(j=160;j<=220;j+=15)  //colors
for(i=m-80;i<=m;i+=20)
{
rectangle(i,j,i+20,j+15);
setfillstyle(SOLID_FILL,p);
circle(i+10,j+7,5);
floodfill(i+10,j+7,WHITE);
p++;
}
rectangle(m-80,240,m,260);  //clear
outtextxy(m-60,248,"CLEAR");

floodfill(m/2,n/2,0);

setfillstyle(SOLID_FILL,RED); //cross
rectangle(m-40,10,m,40);
floodfill(m-25,20,WHITE);
settextstyle(0,0,3);
outtextxy(m-30,13,"x");

settextstyle(0,0,1);         //free hand drawing
rectangle(0,10,100,40);
outtextxy(20,22,"Free Hand");
}

void set_color(int x,int y)
{
int flag=0;
for(j=160;j<=220;j+=15)  //colors
{
for(i=m-80;i<=m;i+=20)
{
if(x>j&&x<j+15&&y>i&&y<i+20)
{
flag=1;
break;
}
}
if(flag==1)
break;
color++;
setcolor(color);
}
}

/*void setshape(int x,int y)
{
int flag=0;
shape=0;
for(j=80;j<=140;j+=30)  //colors
{
for(i=m-80;i<=m;i+=40)
{
if(y>j&&y<j+30&&x>i&&x<i+40)
{
flag=1;
break;
}
}
if(flag==1)
break;
shape=shape%5;
shape++;
}
}
*/

int setshape(int x,int y)
{
if(x>m-80&&y>80&&x<m-40&&y<110)
return(1);
else if(x>m-40&&y>80&&x<m&&y<110)
return(2);
else if(x>m-80&&y>110&&x<m-40&&y<140)
return(3);
else if(x>m-40&&y>110&&x<m&&y<140)
return(4);
else
return(0);
}






void main()
{
int gd=DETECT,gm,button,temp1,temp2,x1=100,y1=100,key,shape=0;
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
show();
design();
   setviewport(0,0,m,n,1);

   restrictmouseptr(1,1,m-1,n-1);
   show();
  // rectangle(10,40,m-80,n-10);
  rectangle(2,42,m-82,n-12);
   setviewport(1,41,m-81,n-11,1);
   setmouse();
   show();
while(1)
   {
      if(kbhit())
      {
	 key = get_key();

	 if( key == 1 )
	 {
	    closegraph();
	    exit(0);
	 }
      }
      fflush(stdin);
      get(&x1,&y1);
      detect(&button);
      if( button == 1 )
      {
	 if( x1 > m-40 && x1 < m && y1 > 10 && y1 < 40)
	 {
	    closegraph();
	    exit(0);
	 }
	 if( x1 > 0 && x1 < 100 && y1 > 10 && y1 < 40)
	    shape=0;
	 if( x1 > m-80 && x1 < m && y1 > 240 && y1 < 260)
	    shape=-1;
	 if( x1 > m-80 && x1 < m && y1 > 160 && y1 < 220 )
	    set_color(x1,y1);
	 else if ( x1 > m-80 && x1 < m && y1 > 80 && y1 < 140 )
	    shape=setshape(x1,y1);

	 temp1 = x1 ;
	 temp2 = y1 ;
	 if(shape>4)
	 shape=0;
	 if (shape==0)
	 {
	    hide();
	    while( button == 1 )
	    {
	       line(temp1,temp2,x1,y1);
	       temp1 = x1;
	       temp2 = y1;
	       get(&x1,&y1);
	       detect(&button);
	    }
	    show();
	 }
	 while( button == 1)
	 {
	    get(&x1,&y1);
	    detect(&button);
	 }
	 hide();
	 if ( shape==1 )
	    circle(temp1,temp2,sqrt(pow(x1-temp1,2)+pow(y1-temp2,2)));
	 else if ( shape==2 )
	 {
	    int len=sqrt(pow((temp1-x1),2)+pow((temp2-y1),2));
	    line(temp1,temp2,temp1+len*cos(-1.204),temp2+len*sin(-1.204));
	    line(x1,y1,temp1+len*cos(-1.204),temp2+len*sin(-1.204));
	    line(temp1,temp2,x1,y1);
	 }
	 else if ( shape==3 )
	    rectangle(temp1,temp2,x1,y1);
	 else if ( shape==4 )
	    ellipse(temp1,temp2,0,360,abs(x1-temp1),abs(y1-temp2));

	 else if ( shape==-1 )
	 {
	    shape = 0;          // setting to freehand drawing
	    clearviewport();
	    color = getcolor();
	    setcolor(WHITE);
	    rectangle(0,0,getmaxx(),getmaxy());
	    setcolor(color);
	 }

	 show();
      }
}
}
