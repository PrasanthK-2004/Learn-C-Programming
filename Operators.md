1.
'''c
#include<stdio.h>
 int main() 
{ 
char name='E';
 name=name+'A'-13;
 printf("%c",name);
 }c'''

 2.#include <stdio.h>
 int main() 
{ 
int _1a=023, _1b=0x75; 
int _1c= _1a + _1b +5; 
printf("%d",_1a); 
}
 3.
 #include <stdio.h>
 void main()
 {
 int x=8;
 int y;
 y=x++ + ++4;
 printf("%d",y);
 }
 4.#include <stdio.h>
 int main()
 {
 int x = 5, y = 2;
 x /= x / y;
 printf("%d\n", x);
 return 0;
 }
 
