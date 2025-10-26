#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
int main()
{
int gd=DETECT,gm,x,y,k,i,j,c=2,m,n,p,q=2,o;
char a[10][10][2];
initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
x=getmaxx()/2-100;
y=getmaxy()/2-100;
printf("choose\n 1.vs computer 2.vs player\n");
scanf("%d",&k);
for(m=0;m<3;m++)
for(n=0;n<3;n++)
{
a[m][n][0]='\b';
a[m][n][1]='\0';
}
q=0;
settextstyle(1,0,4);
for(p=0;p<9;p++)
{
q++;
line(x+30,y,x+30,y+90);
line(x+60,y,x+60,y+90);
line(x,y+30,x+90,y+30);
line(x,y+60,x+90,y+60);
label:
if(k==1&&c%2==0)
o=random()/100;
if(k==1&&c%2==1)
{
printf("\nUser :");
scanf("%d",&o);
}
if(k==2||(k==1&&c%2==1))
{
printf("\nUser %d:",(c++%2)+1);
scanf("%d",&o);
switch(o)
{
case 1:m=0;n=0;break;
case 2:m=1;n=0;break;
case 3:m=2;n=0;break;
case 4:m=0;n=1;break;
case 5:m=1;n=1;break;
case 6:m=2;n=1;break;
case 7:m=0;n=2;break;
case 8:m=1;n=2;break;
case 9:m=2;n=2;break;
default:printf("\nINVALID INPUT \n ENTER AGAIN \n");c--;goto label;
}
if((c%2)==1)
a[m][n][0]='x';
else
a[m][n][0]='0';

settextstyle(1,0,2);
for(i=x+10,m=0;i<x+72,m<3;i+=30,m++)
for(j=y+5,n=0;j<y+72,n<3;j+=30,n++)
{
if(a[m][n][0]=='x'||a[m][n][0]=='0');
outtextxy(i,j,a[m][n]);
}
for(m=0;m<3;m++)
if(a[m][0][0]==a[m][1][0]&&a[m][0][0]==a[m][2][0]&&a[m][0][0]!='\b')
break;
if(m!=3)
break;
for(n=0;n<3;n++)
if(a[0][n][0]==a[1][n][0]&&a[0][n][0]==a[2][n][0]&&a[0][n][0]!='\b')
break;
if(n!=3)
break;
if(a[0][0][0]==a[1][1][0]&&a[0][0][0]==a[2][2][0]&&a[0][0][0]!='\b')
break;
if(a[2][0][0]==a[1][1][0]&&a[2][0][0]==a[0][2][0]&&a[2][0][0]!='\b')
break;
}
if(p==9)
{
settextstyle(1,0,8);
outtextxy(200,300,"GAME DRAWN");
}
else
{
if(k==1&&c%2==1)
outtextxy(200,300,"COMPUTER WON");
else if(k==1&&c%2==1)
outtextxy(200,300,"PLAYER WON");
else if(k==2&&c%2==1)
outtextxy(200,300,"PLAYER 1 WON");
else
outtextxy(200,300,"PLAYER 2 WON");
}
getch();
closegraph();
return 0;
}
