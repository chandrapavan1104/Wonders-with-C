#include<stdio.h>
#include<conio.h>
#include<dos.h>
int main(void)
{
sound(264);
delay(250);
sound(0);
delay(500);

sound(264);
delay(250);
sound(0);
delay(500);

sound(297);
delay(1000);
sound(0);
delay(250);

sound(264);     //4
delay(1000);
sound(0);
delay(250);

sound(352);        //5
delay(250);
sound(0);
delay(500);

sound(264);        //6
delay(250);
sound(0);
delay(500);

sound(264);        //7
delay(250);
sound(0);
delay(250);

sound(264);        //8
delay(1000);
sound(0);
delay(500);

sound(440);        //9
delay(1000);
sound(0);
delay(500);

sound(352);        //10
delay(500);
sound(0);
delay(250);

sound(352);        //11
delay(500);
sound(0);
delay(250);

sound(352);        //12
delay(250);
sound(0);
delay(250);

sound(330);        //13
delay(1000);
sound(0);
delay(250);

sound(297);        //14
delay(2000);
sound(0);
delay(500);

sound(466);        //15
delay(250);
sound(0);
delay(500);

sound(466);        //16
delay(250);
sound(0);
delay(250);

sound(440);        //17
delay(1000);
sound(0);
delay(250);

sound(396);        //18
delay(1000);
sound(0);
delay(250);

sound(352);        //19
delay(2000);
sound(0);
delay(250);

getch();
return 0;
}
