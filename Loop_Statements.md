# Loop Statements in C

This file contains 50 example programs to master `Loop Statements` in c

---
[🔽 Go to Bottom](#program50) | [⬅ Back to Table of Contents](README.md)

---

## Problem 1

```c
#include <stdio.h>
int main(){
 int i, j , x=4;
 i = 1 ; j = 1;
 while ( i< 10 ) {
   j = j * i;
   i= i + 1;
   if (i == x) break;
   printf("%d %d\n",i,j);
 }
}
```

**Output:**

```
2 1
3 2
```

**Explanation:**

* Loop starts with `i=1`, `j=1`.
* Iteration 1: `j=j*i=1*1=1`, `i=2`, prints `2 1`.
* Iteration 2: `j=1*2=2`, `i=3`, prints `3 2`.
* Iteration 3: `i=4`, condition `if(i==x)` true → `break`. Loop ends.

---

## Problem 2

```c
#include <stdio.h> 
int main(){
 int i = 1; 
 do{ 
   if(i % 2 != 0)
     printf("%d ", i);
   i++; 
 } while(i <= 5);
 return 0;
}
```

**Output:**

```
1 3 5
```

**Explanation:**

* `do-while` executes at least once.
* For odd values of `i` (1,3,5), they are printed.
* When `i=6`, condition `i<=5` fails → loop ends.

---

## Problem 3

```c
#include <stdio.h>
#define and &&
#define or ||
int main() {
 int var1=5,var2=3;
 for(;var1 and var2;)
 {
   var1=var1 or ~var2;
   var2=~var2 and !var1;
 }
 printf("%d %d",var1,var2);
}
```

**Output:**

```
1 0
```

**Explanation:**

* Macros: `and` → `&&`, `or` → `||`.
* First iteration: `var1=5||~3` → `5||-4=1`. Then `var2=~3 && !1` → `-4 && 0=0`.
* Condition fails (`var2=0`), loop stops.
* Final values: `var1=1, var2=0`.

---

## Problem 4

```c
#include <stdio.h>
int main(){
 int x;
 for(x = 1; x = 3; x++)
   printf("Hi");
}
```

**Output:**

```
Infinite loop printing "Hi"
```

**Explanation:**

* Condition is `x=3`, assignment not comparison.
* Always true (non-zero), loop never ends.

---

## Problem 5

```c
#include <stdio.h>
int main() {
 int num = 0;
 do {
   --num;
   printf("%d",--num);
   if(num<-5)
     break;
 }while(num < 2);
}
```

**Output:**

```
-2-4-6
```

**Explanation:**

* Start: `num=0`.
* Iter1: `--num=-1`, print `--num=-2`.
* Iter2: `--num=-3`, print `--num=-4`.
* Iter3: `--num=-5`, print `--num=-6`. Condition `num<-5` true → break.

---

## Problem 6

```c
#include <stdio.h>
int main() {
 char i=0;
 for(i=34;i>-128;i--);
 i--;
 printf("%d",i);
}
```

**Output:**

```
-128
```

**Explanation:**

* Loop runs until `i=-128`, then stops.
* After loop, `i--` makes it `-129` but due to `char` overflow → prints `-128` (implementation-defined).

---

## Problem 7

```c
#include <stdio.h> 
int main(){ 
 int sum = 0, i = 2; 
 while(i <= 10) { 
   sum += i;
   i += 2; 
 } 
 printf("%d", sum);
 return 0;
}
```

**Output:**

```
30
```

**Explanation:**

* Adds even numbers: `2+4+6+8+10=30`.
* Loop ends at `i=12`.

---

## Problem 8

```c
#include <stdio.h>
int main(){ 
 int i = 0; 
 while(i < 5){ 
   printf("%d ", i);
   return 0;  
 }
}
```

**Output:**

```
0
```

**Explanation:**

* Prints `i=0`.
* Immediately `return` exits program.
* No further iterations.

---

## Problem 9

```c
#include <stdio.h>
int main(){
 int i;
 for (i = -2; i < -5; i++)
   if(i==-3)
     printf("welcome\n");
   else 
     printf("hai\n");
}
```

**Output:**

```
(no output)
```

**Explanation:**

* Loop starts `i=-2`.
* Condition `i<-5` false at start.
* Loop never executes.

---

## Problem 10

```c
#include <stdio.h> 
int main(){
 int i;
 for(i = 1; i <= 4; i++){
   if(i % 2 == 0)
     continue; 
   printf("%d ", i);
 } 
 return 0;
}
```

**Output:**

```
1 3
```

**Explanation:**

* Loop 1–4.
* Even numbers skipped using `continue`.
* Prints only odd numbers.

---

## Problem 11

```c
#include <stdio.h>
int main() {
 int digit = 0;
 for(; digit <= 9; )
   digit++;
 digit *= 2;--digit;
 return 0;
}
```

**Output:**

```
(no output)
```

**Explanation:**

* Loop increments until `digit=10`.
* After loop: `digit=10*2=20`, then `--digit=19`.
* Value updated but never printed.

---

## Problem 12

```c
#include <stdio.h>
int main() {
 char c=10;
 for(c++;c--;c>2);
 printf("%d",c--);
}
```

**Output:**

```
-1
```

**Explanation:**

* Loop: `c` decreases until `c=0`.
* After loop `c=0`.
* `printf("%d",c--)` → prints `0`, then decrements to -1 internally.
* Depending on compiler, may display `0` or `-1`. Most likely `-1`.

---

## Problem 13

```c
#include <stdio.h>
int main(){
 int i = 0;
 for (i=0; i<20; i++){
   switch(i){
     case 0: i += 5;
     case 1: i += 2;
     case 5: i += 5;
     default: i += 4; break;
   }
   printf("%d  ", i);
 }
 return 0;
}
```

**Output:**

```
16 21
```

**Explanation:**

* i=0 → case 0 → i=5, fall-through → case 5 → i=10, default adds 4 → i=14, plus loop increment → i=15. Prints 16.
* Second run: i=20 stops loop after printing 21.

---

## Problem 14

```c
#include<stdio.h>
int main() {
 int i = 3;
 while(i>>1){
   switch (i) {
     case 1:printf("0");
            break;
     case 1+2:printf("1");
     default:printf("2");return 0;
   }
 }
}
```

**Output:**

```
12
```

**Explanation:**

* `i=3`, `i>>1=1` → true.
* Matches case `3` (1+2).
* Prints `1`, falls through to `default`, prints `2`.
* Program ends.

---

## Problem 15

```c
#include <stdio.h>
int main(){
 int c = 20, no = 10;
 do {
   no /= c;
 } while(c--);
 printf ("%d\\n", no);
 return 0;
}
```

**Output:**

```
0
```

**Explanation:**

* Iteration 1: `no=10/20=0`.
* After that, `no` remains 0.
* Loop runs until `c` decreases to -1 and then exits.
* Prints 0.

---

# C Loop and Control Flow Programs (16–29)

---

## Problem 16

```c
#include<stdio.h>
int main()
{
 int i=1;
 char ch='a';
 do
 {
   printf("%c\n",ch);
 }while(i++<2||++ch<100);
 printf("%d\n",i);
}
```

**Output:**

```
a
b
c
...
 d ... (up to 'c')
3
```

**Explanation:**

* The loop is `do…while`, so it executes at least once.
* Initially `i=1, ch='a'`. Prints `a`.
* Condition: `i++<2 || ++ch<100`. Post-increment allows continuation.
* Loop runs until `ch` crosses ASCII 99. Final `i=3` printed.

---

## Problem 17

```c
#include<stdio.h>
int main(){
 int a,b;
 for(a=5,b=10;a+b;)
 {
    printf("%d %d\n",a,b);
    a/=2;
    b%=2;
 }
}
```

**Output:**

```
5 10
2 0
1 0
```

**Explanation:**

* Loop runs while `a+b != 0`.
* Iteration 1: `a=5,b=10`. Prints. Then `a=2,b=0`.
* Iteration 2: `a=2,b=0`. Prints. Then `a=1,b=0`.
* Iteration 3: `a=1,b=0`. Prints. Then `a=0,b=0`.
* Loop ends.

---

## Problem 18

```c
#include <stdio.h>
int main()
{
    int x = 3;
    while(x==3)
   {
    if (x == 2);
    x = 0;
    if (x == 3)
      x++;
    else x += 2;
    printf("x = %d", x);
    return 0;
 }
}
```

**Output:**

```
x = 2
```

**Explanation:**

* Initially `x=3`. Condition true.
* `if(x==2);` is null statement.
* Then `x=0`. Condition `if(x==3)` false → goes to `else` → `x=0+2=2`.
* Prints `x=2` then `return 0;` terminates.

---

## Problem 19

```c
#include<stdio.h>
int main()
{
 int i=0,j=6,k=6;
 for(;1;)
 {
        if(i==j || k<0)
                break;
        printf("%d %d %d \n",i,j,k);
        i++;j--;
        k=k-4;
 }
}
```

**Output:**

```
0 6 6
1 5 2
```

**Explanation:**

* Infinite `for(;1;)`. Inside, if `i==j || k<0`, breaks.
* Iter1: `0 6 6`. Then `i=1,j=5,k=2`.
* Iter2: `1 5 2`. Then `i=2,j=4,k=-2`.
* Next loop → `k<0` true → break.

---

## Problem 20

```c
#include<stdio.h>
int main()
{
 int i=0;
 while(i++==0)
        printf("%d",++i);
 printf("\n");
}
```

**Output:**

```
2
```

**Explanation:**

* Initially `i=0`. Condition `i++==0` true (post-increment).
* Inside loop: `++i` → prints `2`.
* Next check: `i=2`. `2==0` false → exit.
* Newline prints.

---

## Problem 21

**Q:** The minimum number of executions for a `do while` loop is \_\_\_\_\_.
**Answer:** 1 (since `do while` executes once before checking condition).

---

## Problem 22

```c
#include<stdio.h>
int main()
{
    int i = -5;
    while (i <= 5)
    {
        if (i >= 0)
            break;
        else
        {
            i++;
            continue;
        }
        printf("Hello");
    }
    return 0;
}
```

**Output:**

```
(no output)
```

**Explanation:**

* Loop runs with `i=-5`. Since `i<0`, `else` executes → `i++` and `continue;`.
* `printf("Hello");` never reached.
* Loop exits once `i=0` (`break`).
* Program ends silently.

---

## Problem 23

```c
#include <stdio.h>
int main()
{
 int index;
 for(index=1; index<=5; index++)
 {
   printf("%d", index);
   if (index==3)
     continue;
 }
}
```

**Output:**

```
12345
```

**Explanation:**

* Loop from 1 to 5. Always prints `index`.
* `continue` just skips nothing extra here, since `printf` already executed.
* Final output is digits 1 to 5 concatenated.

---

## Problem 24

```c
#include<stdio.h>
int main()
{
 int i=5;
 while(i++>=i)
   printf("%d ",i);
 while(i++<--i);
 printf("%d ",i);
}
```

**Output:**

```
6
```

**Explanation:**

* First loop: `i=5`. Condition `i++>=i` → evaluates `5>=6` false. No print.
* Second loop: `while(i++<--i)` becomes infinite? Let’s check: `i=6`. Condition `6<5` false. Loop skipped.
* Prints final `i=6`.

---

## Problem 25

```c
#include<stdio.h>
int main()
{
 int r=12,s=35;
 for( ;r<p,s&p;r++,s++ )
   printf("hello");
 printf("hai");
}
```

**Output:**

```
hai
```

**Explanation:**

* Code invalid: `r<p` uses undeclared `p`. Assuming typo → maybe `r<s && s&p`. As written, it won’t compile.
* If corrected: The condition fails initially and only `hai` prints.

---

## Problem 26

```c
#include<stdio.h>
int main()
{
 int i,val;
 for(i=0;i<10;i+=3)
        val+=i*i;
 printf("%d\n",val);
}
```

**Output:**

```
Garbage value (undefined)
```

**Explanation:**

* `val` is **uninitialized**, so adding to it produces undefined result.
* Correct code should initialize `val=0;`.
* Then sum would be: `0^2 + 3^2 + 6^2 + 9^2 = 0+9+36+81=126`.

---

## Problem 27

```c
#include <stdio.h>
int main()
{
    unsigned int i = 65000;
    while (i++ != 0);
    printf("%d", i);
    return 0;
}
```

**Output:**

```
0
```

**Explanation:**

* `unsigned int` wraps around after 65535 to 0.
* Loop continues until `i` overflows to 0.
* After exit, `i=0`. Prints 0.

---

## Problem 28

```c
#include <stdio.h>
int main()
{
  int i = 1, j;
  for ( ; ; )
  { 
    if (i)
        j = --i;
    if (j < 10)
       printf("Yes", j++);
    else
       break;
  }
  return 0;
}
```

**Output:**

```
Infinite printing of "Yes"
```

**Explanation:**

* Initially `i=1`. Then `j=--i=0`.
* Condition `j<10` true, prints `Yes`.
* But note: `printf("Yes", j++)` ignores `j`. Only prints `Yes`.
* Since `i` never changes after first decrement, `j` keeps being `0`. Infinite loop.

---

## Problem 29

```c
#include <stdio.h>
int main()
{
 int a=15;
 do
   printf("loop");
 while (a/=2 && 0);
}
```

**Output:**

```
loop
```

**Explanation:**

* `do while` executes once.
* Condition `(a/=2 && 0)` → always 0 (because `&&0` false).
* Loop exits after 1 execution.

---

# C Programming Problems (30 to 40)

## Problem 30

``` c
#include <stdio.h>
int main()
{
    int i,j,a;
    for(i=0;i<5;i++)
        for(j=i;j>0;j--)
            a=i+j+3;
    printf("a=%d\n",a);
}
```

**Output:**

    a=7

**Explanation:**\
Nested loops execute. For `i=4` and `j=1`, final assignment is
`a=4+1+3=8`. But due to last decrement `j=0`, last executed value is
`a=7`. Final print: `7`.

------------------------------------------------------------------------

## Problem 31

``` c
#include <stdio.h>
void main()
{
    int i = 0;
    while (i < 4)
    {
        i+=i*2;
        printf("hi\n");
        while (i < 4) 
        {
            i++;
            printf("hello\n");
        }
    }
}
```

**Output:**

    hi
    hello
    hello
    hello

**Explanation:**\
Outer while runs with `i=0`. Inside, `i+=i*2=0`. Prints `hi`. Inner loop
increments i until 4, printing `hello` thrice.

------------------------------------------------------------------------

## Problem 32

**Question:** What is the purpose of break statement and where it can be
used?

**Answer:**\
The `break` statement is used to **terminate a loop or switch
immediately**, transferring control to the statement following the
loop/switch.\
- Used in `for`, `while`, `do-while`, and `switch` blocks.\
- Prevents infinite loops and allows conditional exit.

------------------------------------------------------------------------

## Problem 33

``` c
#include <stdio.h>
int main()
{
    int i = 1, j = 0;
    while (i< 3, j<6)
    {
        i*=2;
        j=j+1;
    }
    printf("%d, %d\n", i, j);
}
```

**Output:**

    16, 6

**Explanation:**\
Comma operator evaluates last condition `j<6`. Loop runs while `j<6`.
Each iteration doubles `i` and increments `j`. After loop, `i=16`,
`j=6`.

------------------------------------------------------------------------

## Problem 34

``` c
#include <stdio.h>
int main()
{
    int i = 1, j = 0;
    for(i=0;i<2;i++)
    {
        continue;
        for(j=0;j<3;j++)
        {
            if(i==1)
                break;
        }
        printf("%d %d",i,j);
    }
    printf("%d %d\n", i, j);
}
```

**Output:**

    2 0

**Explanation:**\
`continue;` skips remaining statements in loop body. The inner loop and
`printf` never execute. After outer loop, `i=2`, `j=0`. Final print:
`2 0`.

------------------------------------------------------------------------

## Problem 35

``` c
#include <stdio.h>
int main()
{
    char c = '1';
    while(c<53 || c<54 && c<55)
    {
        printf("%c ",c);
        c+=2;
    }
}
```

**Output:**

    1 3 5 7 9 ;

**Explanation:**\
ASCII of `'1'` = 49. Condition holds until `c=59` (`';'`). Prints every
2 steps.

------------------------------------------------------------------------

## Problem 36

``` c
#include <stdio.h>
int main()
{
    int a=0xa0;
    char b=a>>7;
    while(b)
    {
        switch(b+48)
        {
            case 1: printf("hai");
            case '1': printf("hello"); break;
        }
        b=!b;
    }
}
```

**Output:**

    hello

**Explanation:**\
`a=0xa0=160`. `a>>7=1`. So `b=1`. Switch(b+48=49 → '1') matches case
`'1'`. Prints "hello". Then `b=!1=0`, loop ends.

------------------------------------------------------------------------

## Problem 37

``` c
#include <stdio.h>
int main() {
    int val=10;
    for(;;)
    {
        while(1)
        {
            break;
            val^=6;
        }
        break;
    }
    printf("%d",val);
}
```

**Output:**

    10

**Explanation:**\
The `break` in inner while executes before `val^=6`, so `val` unchanged.
Program breaks outer loop too. Prints `10`.

------------------------------------------------------------------------

## Problem 38

``` c
#include <stdio.h>
int main() {
    int no=10;
    l:
    for(no++; ;no++)
    {
        printf("%d ",no+=2);    
        if(no==13)
            goto l;
        break;
    }
}
```

**Output:**

    13 16

**Explanation:**\
First iteration: `no=11`, then `no+=2=13`. Prints `13`. `if(no==13)`
triggers `goto l;`. Now `no=13`, increments to 14, then `no+=2=16`,
prints `16`. Breaks.

------------------------------------------------------------------------

## Problem 39

``` c
#include<stdio.h>
int main()
{
    int k,j;
    for(k=0;k<=4;k++)
    {
        for(j=0;j<3;j++)
            if(j!=k)
                continue;
            else 
                break;
        printf("%d,%d\n",k,j);
    }
}
```

**Output:**

    0,3
    1,1
    2,2
    3,3
    4,3

**Explanation:**\
Inner loop continues until `j==k` (break). If `k>=3`, inner loop
finishes at `j=3`. Values printed accordingly.

------------------------------------------------------------------------

## Problem 40

``` c
#include<stdio.h>
int main()
{
    char ch=257;
    do
    {
        if(ch>2)
            continue;
        else
            printf("%d\n",ch);
    }while(ch>>2);
}
```

**Output:**

    (infinite loop)

**Explanation:**\
`char ch=257;` → overflow → `ch=1`. In loop, `if(ch>2)` false, so prints
`1`. Then loop checks `ch>>2=0`? But `continue;` causes skipping
increment (none here). Since `ch` never changes, infinite loop results.
Some compilers may warn about this.

---

# C Programming Practice – Problems 41 to 50

---

## Problem 41
```c
#include<stdio.h>
int main()
{
    int a=10;
label:
    while(1)
    {
        printf("hello\n");
        if(a++<15)
            goto label;
        else
            break;
        printf("%d\n",a);
    }
}
```
### Explanation  
- Infinite recursion-like behavior because of `goto label;` inside `while(1)`.  
- Prints `"hello"` repeatedly until `a` reaches 16, then exits loop.  
- `printf("%d\n",a);` after `break;` is unreachable.  

### Output  
```
hello
hello
hello
hello
hello
hello
```

---

## Problem 42
```c
#include<stdio.h>
int main()
{
    int s=4>>3;   // s = 0
    while(!s)     // !0 = 1 → loop executes infinitely
    {
        switch(~s)   // ~0 = -1
        {
            default: printf("default\n"); break;
            case 0:  printf("hai\n"); break;
            case 1:  printf("hello\n"); break;
            case -1: printf("bye\n");
            default: printf("welcome\n"); break;
        }
    }
}
```
### Explanation  
- `s = 0`.  
- Condition `while(!s)` → true, infinite loop.  
- `~0 = -1`.  
- `case -1` executes → prints `"bye"` and falls into `default` → prints `"welcome"`.  

### Output (infinite loop)  
```
bye
welcome
bye
welcome
...
```

---

## Problem 43
```c
#include<stdio.h>
int main()
{
    int a=20;
    float m=2,m2=4;
    for(;a>5;a++)
    {
        a=a^m;        // float converted to int (2)
        printf("%d",a);
        a=a^m2;       // XOR with 4
        printf("%d",a);
    }
}
```
### Explanation  
- XOR operations with float → implicitly converted to int.  
- `a` keeps increasing because of loop.  
- Prints XOR results for each iteration until overflow. (Practically infinite).  

---

## Problem 44
```c
#include<stdio.h>
int main()
{
    int k,a=2;
    while(k=sizeof('A'),a--)
    {
        printf("%d\n",k);
    }
}
```
### Explanation  
- `sizeof('A')` in C is `int` (usually 4).  
- `while(k=4, a--)` → comma operator, assigns 4 to `k`, then checks `a--`.  
- Runs 2 times (`a=2,1`).  

### Output  
```
4
4
```

---

## Problem 45
```c
#include<stdio.h>
int main()
{
    int n=5;
    do
    {
        switch(n>>1)  // 5>>1 = 2
        {
            case 1: printf("case1\n"); break;
            case 3: printf("case2\n"); break;
            case 2: goto label;
        }
    }while(1);
label:
    printf("welcome\n");
}
```
### Explanation  
- `n=5`, `n>>1 = 2`.  
- Jumps to `label`.  
- Prints `"welcome"`.  

### Output  
```
welcome
```

---

## Problem 46
```c
#include<stdio.h>
int main()
{
    char ch= 'b' , ch1 = ch ;
    for(;;)
    {
        ch = ch + '1';       // 'b'(98) + '1'(49) = 147
        ch1= ch1 - 32;       // 'b'(98) - 32 = 66
        printf("ch= %d , ch1= %d \n", ch , ~ch1 );
        break;
    }
}
```
### Explanation  
- `ch = 147`.  
- `ch1 = 66`.  
- `~ch1 = ~66 = -67`.  

### Output  
```
ch= 147 , ch1= -67
```

---

## Problem 47
```c
#include<stdio.h>
int main()
{
    int coding='2'+ 05;  // '2' = 50, 50+5=55
    while(coding)
    {
        printf("%x \n",coding);
        coding=!coding;   // becomes 0
    }
}
```
### Explanation  
- First iteration: `coding=55`.  
- Prints in hex: `37`.  
- Then `coding=!55 = 0`. Loop exits.  

### Output  
```
37
```

---

## Problem 48
```c
#include<stdio.h>
int main()
{
    int x = 5, counter = 1 ;
    while ( (x -1 ) )
    {
        ++counter ;
        x -- ;
    }
    printf("%d ",counter);
}
```
### Explanation  
- Loop runs while `x-1 != 0`.  
- Iterations: x=5→4→3→2. Stops when x=1.  
- Counter increments each time. Final counter=5.  

### Output  
```
5
```

---

## Problem 49
```c
#include <stdio.h>
int main()
{
    int i = 3;
    while (i--)
    {
        int i = 100;  // inner scope variable
        i--;
        printf("%d ", i);
    }
    return 0;
}
```
### Explanation  
- Outer `i` controls loop: 3 iterations.  
- Inner `i=100`, decremented → 99 each time.  
- Prints `99 99 99`.  

### Output  
```
99 99 99
```

---

## Problem 50
**Program to find sum of odd digits and product of even digits in a number**

```c
#include<stdio.h>
int main()
{
    int num=12345;
    int sumOdd=0, prodEven=1, digit;
    int temp=num;

    while(temp>0)
    {
        digit=temp%10;
        if(digit%2==0)
            prodEven*=digit;
        else
            sumOdd+=digit;
        temp/=10;
    }

    printf("Number = %d\n",num);
    printf("Sum of odd digits = %d\n",sumOdd);
    printf("Product of even digits = %d\n",prodEven);

    return 0;
}
```

### Output  
```
Number = 12345
Sum of odd digits = 9
Product of even digits = 8
```

---
[🔼 Back to Top](#loop_statements-in-c) | [⬅ Back to Table of Contents](README.md)

---
