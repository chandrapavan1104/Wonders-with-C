#include<stdio.h>
#include<conio.h>
#include<string.h>

void main()
{
struct std
{
char name[30];
char rno[20];
int age;
struct dob
{
int day;
int month;
int year;
}d;
char add[50];
int rank;
char gender;
char cat;
};

struct std s[8][10],p[3][10];
int i=0,k,a[30]={0},x,f[30]={0},j,b=0,g=0;
char c='y',rtemp[]="17071A00A0",t[50];
clrscr();
	       //taking info of students

do
{
printf("\nSelect the section of the student.Enter the corresponding number:");
printf("\n1.CSE  2.ECE  3.IT  4.ME  5.EEE  6.CE  7.EIE  8.AM \n");
scanf("%d",&k);
a[k]++;
printf("\nEnter the name of the student %d : ",i+1);
fflush(stdin);
gets(s[k][a[k]].name);
printf("\nEnter age : ");
scanf("%d",&s[k][a[k]].age);
printf("\nEnter date of birth in (dd mm yyyy) format");
scanf("%d%d%d",&s[k][a[k]].d.day,&s[k][a[k]].d.month,&s[k][a[k]].d.year);
fflush(stdin);
printf("\nEnter the address: ");
gets(s[k][a[k]].add);
printf("\nEnter EAMCET rank : ");
scanf("%d",&s[k][a[k]].rank);
fflush(stdin);
printf("\nEnter character for gender(M-male,F-female): ");
scanf("%c",s[k][a[k]].gender);
fflush(stdin);
printf("\nEnter the charatcter for type of admission i.e., A,B or C : ");
scanf("%c",s[k][a[k]].cat);
printf("\n****************************************************************\n\n");
printf("\n Do you want to enter another student details ?- y or n ");
fflush(stdin);
scanf("%c",c);
if(c!='y')
break;
}while(c=='y'||c=='Y');
	       //sorting based on name

for(k=1;k<9;k++)
{
for(j=1;j<=a[k];j++)
{
if(s[k][j].gender=='M'||s[k][j].gender=='m')
b++;
else
g++;
for(x=j+1;x<a[k];x++)
if((strcmp(s[k][j].name,s[k][x].name))<0)
{
strcpy(t,s[k][j].name);
strcpy(s[k][j].name,s[k][x].name);
strcpy(s[k][x].name,t);
}
}
}
	     //giving roll no.

for(k=1;k<=8;k++)
{
for(j=1;j<=a[k];j++)
{
strcpy(s[k][j].rno,rtemp);
rtemp[9]++;
if(rtemp[9]>'9')
{
rtemp[8]++;
rtemp[9]=0;
}
}
rtemp[7]++;
}
printf("\n Number of girls =%d\n Number of boys=%d",g,b);

		 //based on category
for(k=1;k<=8;k++)
for(j=1;j<=a[k];j++)
{
if(s[k][j].cat=='A'||s[k][j].cat=='a')
{
x=1;
p[x][f[x]]=s[k][j];
}
else if(s[k][j].cat=='B'||s[k][j].cat=='b')
{
x=2;
p[x][f[x]]=s[k][j];
}
else if(s[k][j].cat=='C'||s[k][j].cat=='c')
{
x=3;
p[x][f[x]]=s[k][j];
}
}
	   //printing of data
c='y';
while(c=='y')
{
printf("\nHow do you want info.?");
printf("\n1.Based on branches ?\n2.Based on categories ?\n");
scanf("%d",&x);
printf("\nroll no.   name   age   category   eamcet_rank    gender   address ");
if(x==1)
{
for(k=1;k<=8;k++)
for(j=0;j<=a[k];j++)
printf("\n %12s   %15s   %3d   %c            %11d    %c            %s  ",s[k][j].rno,s[k][j].name,s[k][j].age,s[k][j].cat,s[k][j].rank,s[k][j].gender,s[k][j].add);
}
else
{
for(k=1;k<=3;k++)
for(j=1;j<=f[k];j++)
printf("\n %12s   %15s   %3d   %c            %11d    %c            %s  ",p[k][j].rno,p[k][j].name,p[k][j].age,p[k][j].cat,p[k][j].rank,p[k][j].gender,p[k][j].add);
}
printf("\ndo you want to print data again ? y or n\n");
fflush(stdin);
scanf("%c",c);
}
getch();
}
