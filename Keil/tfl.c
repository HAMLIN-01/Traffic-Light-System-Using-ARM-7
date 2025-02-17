#include<lpc214x.h>
void delay(unsigned int);
void display(unsigned char);
void redandgreen();
void yellow();
int main()
{
PINSEL0=0x00000000;
PINSEL2=0x00000000;
IO1DIR=0x000f0000;
IO0DIR=0x000000ff;
while(1)
{
redandgreen();
yellow();
}}
void redandgreen()
{
unsigned char i;
IO1SET=0x00010000;
for(i=0;i<10;i++)
{
display(i);
delay(100);
}
IO1CLR=0x00010000;
IO1SET=0x00020000;
for(i=0;i<10;i++)
{
display(i);
delay(100);
}
IO1CLR=0x00020000;
}
void yellow()
{
unsigned char i;
IO1SET=0x00040000;
for(i=1;i<6;i++)
{
display(i);
delay(100);
}
IO1CLR=0x00040000;
}
void delay(unsigned int a)
{
unsigned int c,d;
for(c=0;c<a;c++)
{
for(d=0;d<1275;d++);
}
}
void display(unsigned char num)
{
IO0CLR = 0x000000ff;
switch(num)
{
	case 1:IO0SET=0x00000006;
	break;
	case 2:IO0SET=0x0000005B;
	break;
	case 3:IO0SET=0x0000004F;
	break;
	case 4:IO0SET=0x00000066;
	break;
	case 5:IO0SET=0x0000006D;
	break;
	case 6:IO0SET=0x0000007D;
	break;
	case 7:IO0SET=0x00000007;
	break;
	case 8:IO0SET=0x0000007F;
	break;
	case 9:IO0SET=0x0000006F;
	break;
	case 10:IO0SET=0x0000003F;
	break;
	}}

