# C Operators

This file contains 50 example programs in C.

---
[🔽 Go to Bottom](#bit-is-not-set) | [⬅ Back to Table of Contents](README.md)

# C Operator Precedence and Order of Evaluation

This table shows C operators, their precedence, and associativity.

| Operator                            | Associativity  | Notes |
|-------------------------------------|----------------|-------|
| `() [] -> . ++ --`                  | left to right  | [1]   |
| `! ~ ++ -- + - (type) * & sizeof`   | right to left  | [2]   |
| `* / %`                             | left to right  |       |
| `+ -`                               | left to right  |       |
| `<< >>`                             | left to right  |       |
| `< <= > >=`                         | left to right  |       |
| `== !=`                             | left to right  |       |
| `&`                                 | left to right  |       |
| `^`                                 | left to right  |       |
| `\|`                                | left to right  |       |
| `&&`                                | left to right  |       |
| `\|\|`                              | left to right  |       |
| `?:`                                | right to left  |       |
| `= += -= *= /= %= <<= >>= &= ^= \|=`| right to left  |       |
| `,`                                 | left to right  |       |

---

### Notes
1. The `++` and `--` operators at this precedence level are the **postfix** versions.  
2. The `++` and `--` operators at this precedence level are the **prefix** versions.  

---

## Program 1

```c
#include<stdio.h>
int main() 
{ 
    char name='E';
    name=name+'A'-13;
    printf("%c",name);
}
```

**Output:**
```
y
```

**Explanation:**  
`'E'` is ASCII 69, `'A'` is 65. `69 + 65 - 13 = 121`, which is `'y'`.

---

## Program 2

```c
#include <stdio.h>
int main() 
{ 
    int _1a=023, _1b=0x75; 
    int _1c= _1a + _1b +5; 
    printf("%d",_1a); 
}
```

**Output:**
```
19
```

**Explanation:**  
Octal 023 = 19. Hex 0x75 = 117. `_1c = 141` but not printed. Output is 19.

---

## Program 3

```c
#include <stdio.h>
void main()
{
    int x=8;
    int y;
    y=x++ + ++4;
    printf("%d",y);
}
```

**Output:**
```
Compilation Error
```

**Explanation:**  
`++4` is invalid. Constants cannot be incremented.

---

## Program 4

```c
#include <stdio.h>
int main()
{
    int x = 5, y = 2;
    x /= x / y;
    printf("%d\n", x);
    return 0;
}
```

**Output:**
```
2
```

**Explanation:**  
`x / y = 5/2 = 2`. Then `x = 5/2 = 2`. Prints 2.

---

## Program 5

```c
#include <stdio.h>
int main()
{
    int x = 2, y = 0;
    int z = (y++) ? y == 1 && x : 5;
    printf("%d\n", z);
    return 0;
}
```

**Output:**
```
5
```

**Explanation:**  
`y++` is false (y=0). 
So ternary chooses else branch → z=5.

---

## Program 6

```c
#include<stdio.h>
int main() 
{ 
    int x=6; 
    int y=sizeof(x=x+5); 
    printf("%d %d\n",x,y); 
}
```

**Output:**
```
6 4
```

**Explanation:**  
`sizeof` is compile-time, so assignment doesn’t run.
x=6. 
sizeof(int)=4.

---

## Program 7

```c
#include<stdio.h>
int main()
{
    int s=5;
    int t=-s<<2>>3;
    printf("%d",t);
}
```

**Output:**
```
-1
```

**Explanation:**  
`s=5 → -s=-5`
Shift left by 2 = -20
Shift right by 3 = -3 or -1 (depends on compiler). 
Typically prints -1.

---

## Program 8

```c
#include <stdio.h>
int main() {
    int flag=1;
    !flag;
    flag&=!flag;
    printf("%d",flag);
}
```

**Output:**
```
0
```

**Explanation:**  
`!flag` is calculated but not stored. 
Then `flag &= !flag → 1 & 0 = 0`.

---

## Program 9

```c
#include <stdio.h>
void main()
{
    int a = 10, b = -11, c = 0, d;
    d = ++a && ++b || ++c;
    printf("%d %d %d %d", a, b, c, d);
}
```

**Output:**
```
11 -10 0 1
```

**Explanation:**  
`++a=11` true. Then `++b=-10` true (nonzero). 
So left side true. `||` short-circuits.
d=1 and c not incremented.

---

## Program 10

```c
#include <stdio.h>
void main()
{
    int a = 10;
    a<<2;
    a>>2;
    a++;
    printf("%d",a);
}
```

**Output:**
```
11
```

**Explanation:**  
Shifts are unused (results discarded).
Only a++ runs. 10 becomes 11.

---

## Program 11

```c
#include <stdio.h>
void main()
{
    char x=566;
    x++;
    printf("%d",x);
}
```

**Output:**
```
55
```

**Explanation:**  
566 mod 256 = 54 (char overflow). 
After increment, x=55.

---

## Program 12

```c
#include <stdio.h>
int main() {
    int i=4,j=-5,k;
    k=~j&~i;
    printf("%d",k);
}
```

**Output:**
```
4
```

**Explanation:**  
~j = ~(-5)=4
~i=~4=-5
4 & -5 = 4

---

## Program 13

```c
#include <stdio.h>
int main() {
    int var=076;
    var|=3;
    var&=4;
    printf("%d",var);
}
```

**Output:**
```
4
```

**Explanation:**  
076 (octal)=62 decimal
62|3=63
63&4=4.

---

## Program 14

```c
#include <stdio.h>
void main()
{
    int a = 10, b= 20;
    int c;
    c=a==b=a;
    printf("%d",c);
}
```

**Output:**
```
1
```

**Explanation:**  
Assignment inside equality. `b=a=10`. 
Then check `a==10` → true → 1.

---

## Program 15

**Task:** Write a program to divide an integer number by 2 using bitwise operators.

```c
#include<stdio.h>
int main(){
    int n=10;
    printf("%d", n>>1);
}
```

**Output:**
```
5
```

**Explanation:**  
Right shift by 1 divides an integer by 2.

---

## Program 16

```c
#include <stdio.h>
void main()
{
    int x=5;
    int y;
    y=x++==++x;
    printf("%d ",y);
    y=++x==x;
    printf("%d",y);
}
```

**Output:**
```
0 1
```

**Explanation:**  
First comparison false (undefined but usually false). Second comparison true.

---

## Program 17

```c
#include <stdio.h>
int main() 
{ 
    int a; 
    a=sizeof(!(!17.5)); 
    printf("%d",a); 
}
```

**Output:**
```
4
```

**Explanation:**  
`!(!17.5)` is int. sizeof(int)=4.

---

## Program 18

```c
#include<stdio.h>
int main() 
{ 
    int p=4,q=-5,y=2,x=6,z; 
    z=++p/x + --q*p/y; 
    printf("%d\n",z); 
}
```

**Output:**
```
-15
```

**Explanation:**
++p → increases p from 4 to 5.
++p / x = 5 / 6 → integer division → 0

--q → decreases q from -5 to -6.
--q * p / y = (-6) * 5 / 2 = -30 / 2 = -15

Add both parts: 0 + (-15) = -15

---

## Program 19

```c
#include <stdio.h>
int main()
{
    int a=2,b;
    b=-+a -+a + -(-a);
    printf("%d",b);
}
```

**Output:**

```
-2
```

**Explanation:**
`-+a = -2`, `-(-a) = 2` → `-2 -2 +2 = -2`

---

## Program 20

```c
#include <stdio.h>
int main()
{
    int a=10;
    printf("%d %d %d",a==5,a=5,++a);
}
```

**Output:**

```
0 6 6
```

**Explanation:**

`a==5` → false → 0
 `a=5` → assigns 5 → 5
 `++a` → increments → 6

---

## Program 21

```c
#include <stdio.h>
int main()
{
    int p = 3;
    float q = 4.5;
    printf("%d\n",sizeof(p+q));
    printf("%d\n",sizeof(sizeof(6.7)));
}
```

**Output:**

```
8
8
```

**Explanation:**

 `p+q` → promoted to `float` → 8 bytes on 64-bit systems
 `sizeof(sizeof(6.7))` → `sizeof(size_t)` → 8 bytes

---

## Program 22

```c
#include<stdio.h>
int main()
{
    unsigned char x=0x75;
    int y=~x<<2;
    printf("%x",y);
}
```

**Output:**

```
ffffff8a
```

**Explanation:**

 `~0x75 = 0x8a` → left shift by 2 → `0x228`
 Printed as signed 32-bit int in hex: `ffffff8a`

---

## Program 23

```c
#include<stdio.h>
int main()
{
    int x,y=25;
    x=(y/=2) + (y=y/2);
    printf("%d",x);
}
```

**Output:**

```
18
```

**Explanation:**

 `y/=2` → 12, `y=y/2` → 6, sum → 18

---

## Program 24

```c
#include<stdio.h>
int main()
{
    int a=6,b=5,c=1;
    printf("%d",a>b>=c);
}
```

**Output:**

```
1
```

**Explanation:**

 `a>b` → 1 (true)
 `1 >= c` → 1

---

## Program 25

```c
#include<stdio.h>
int main()
{
    int x=5;
    printf("%d %d %d",x^32,x|7,~x);
}
```

**Output:**

```
37 7 -6
```

**Explanation:**

 `x^32` → toggle bits → 37
 `x|7` → OR operation → 7
 `~x` → bitwise NOT → -6

---

## Program 26
Which operator is used to toggle a particular bit in a number?

**Answer:** `^` (XOR) toggles a particular bit in a number.
```
num = num ^ (1 << n);
```

---

## Program 27

```c
#include<stdio.h>
int main()
{
    float x=9/2;
    float y=2.5;
    float z=x+y/2;
    printf("%f",z);
}
```

**Output:**

```
5.250000
```

**Explanation:**

`9/2` → integer division → 4 → converted to float 4.0
 `z = 4.0 + 2.5/2 = 4.0 + 1.25 = 5.25`

---

## Program 28

```c
#include<stdio.h>
int main()
{
    int a=0xab;
    int b=0xab<<4;
    b=c>>8; 
    printf("%d\n",b);
}
```

**Output:** Compile error due to `c` undefined.

---

## Program 29

```c
#include<stdio.h>
int main()
{
    char a=-25;
    a||=2;
    a&&=2;
    printf("%d",a);
}
```

**Output:**

```
2
```

**Explanation:**

 `a ||= 2` → sets `a` to 1 if non-zero → 1
 `a &&=2` → evaluates to 2

---

## Program 30

```c
#include<stdio.h>
int main()
{
    printf("%x\n",-1023);
    printf("%o\n",-63);
}
```

**Output:**

```
fffffc01
37777777775
```

**Explanation:**

Prints signed negative numbers in hex/octal using 2’s complement.

---

## Program 31

```c
#include<stdio.h>
int main()
{
    int i=-7,j=8,k=10,l;
    l=i>>2  +  j++ || ++k;
    printf("%d %d %d %d\n",i,j,k,l);
}
```

**Output:**

```
-7 9 10 1
```

**Explanation:**

 `i>>2 + j++` → evaluates left, then `|| ++k` → logical OR → 1

---

## Program 32

```c
#include <stdio.h>
int main()
{
    int i = 5;
    printf("%d", ++(++i));
    return 0;
}
```

**Output:** Compile error: cannot apply `++` to rvalue.

---

## Program 33

```c
#include <stdio.h>
int main()
{
    int num = 5;
    num|=04<<6+1-2&0xaf;
    printf("%d", num);
    return 0;
}
```

**Output:**

```
5
```

**Explanation:**

Operator precedence: `<<` before `+`
Result ANDed with 0xaf → OR with 5 → 5

---

## Program 34

```c
#include <stdio.h>
int main()
{
    int x,y,z,w;
    x=y=z=w=12;
    x*=w+4;
    y+=z*=3;
    printf("x=%d ,y=%d",x,y);
}
```

**Output:**

```
x=192 ,y=48
```

**Explanation:**

 `x = 12 * (12+4) = 192`
 `z*=3 → 36`, `y+=36 → 48`

---

## Program 35

```c
#include<stdio.h>
int main()
{
    int ab=5,cd=6;
    ab=ab & cd;
    cd =ab | cd;
    printf("%d %d",ab,cd);
}
```

**Output:**

```
4 6
```

**Explanation:**

5 & 6 → 0101 & 0110 → 0100 → 4

4 | 6 → 0100 | 0110 → 0110 → 6

---

## Program 36

```c
#include<stdio.h>
int main()
{
    int a=4, b=8 ,c=3, d=9,z;
    z=a++ + ++b *c-- - --d;
    printf("%d %d %d %d %d",a,b,c,d,z);
}
```

**Output:**

```
5 9 2 8 25
```

**Explanation:**

a++=4 (then a=5), ++b=9, c--=3 (then c=2), --d=8

z = 4 + 9*3 - 8 = 23

---

## Program 37

```c
#include<stdio.h>
int main()
{
    float f=5/16,g=0.45;
    int h=(f<g)<<3;
    printf("%d",h);
}
```

**Output:**

```
8
```

**Explanation:**

 `f=0` (integer division)
 `0<0.45` → 1 → shift left 3 → 8

---

## Program 38

```c
#include<stdio.h>
int main()
{
    int x=1,y=0;
    int z=x--?y==0&&x<5:3;
    printf("%d\n",z);
}
```

**Output:**

```
1
```

**Explanation:**

x-- ? → true (x=1)

y==0 && x<5 → 1 && 0<5 → 1

---

## Program 39

```c
#include<stdio.h>
int main()
{
    int n = 12, k;
    printf("%d", (k = sizeof( n + 12.0)));
    return 0;
}
```

**Output:**

```
8
```

**Explanation:**

n + 12.0 → double → sizeof(double) = 8

---

## Program 40

```c
#include<stdio.h>
int main()
{
    int a = 10, b = 2, c;
    a = !( c = c == c) && ++b;
    c += ( a + b--);
    printf(" %d %d %d", a,b,c);
    return 0;
}
```

**Output:**

```
0 1 3
```

**Explanation:**

c = c==c → 1, !(c) → 0 → a=0

c += (a+b--) → 1 + (0+2) = 3

b-- → b=1

---

## Program 41

```c
#include<stdio.h>
int main()
{
    int x = 012 | 0x12;
    int y = 021 & 021;
    printf("%d %d",x,y);
}
```

**Output:**

```
26 17
```

**Explanation:**

012 octal = 10, 0x12 hex = 18 → 10|18=26

021 & 021 → 17 & 17 = 17

---

## Program 42

```c
#include<stdio.h>
int main()
{
    unsigned int x = 45 ;
    char y = -23;
    int z=x>y;
    printf("%d ",z);
}
```

**Output:**

```
0
```

**Explanation:**

y promoted to unsigned → large value → x<y → 0

---

## Program 43

```c
#include <stdio.h>
int main() {
    int a=0x1<<sizeof('a')*8-1;
    printf("%x\n",a);
    a>>=sizeof(int)*4-1;
    printf("%x\n",a);
}
```

**Output:**

```
80000000
4000
```

**Explanation:**

'a' as int → 4 bytes → 1<<31=0x80000000

a >>= 15 → 0x10000

---

## Program 44

```c
#include<stdio.h>
int main() {
    int num=20, pos=3;
    if(num & (1<<(pos-1)))
        printf("Bit is set");
    else
        printf("Bit is not set");
}
```

**Output:**

```
Bit is set
```

**Explanation:**

5=0101 → 2nd bit (count from 0) is 1

---

## Program 45

```c
#include <stdio.h>
int main()
{
    int p=5,q=-6;
    q^=p^=p-q;
    p^=-p;
    printf("%d %d",p,q);
}
```

**Output:**

```
-5 6
```

**Explanation:**

XOR-based swapping trick

---

## Program 46

```c
#include<stdio.h>
int main()
{
    int a = 1, b = 2, c = 3;
    printf("%d", a +=(a += 3, 5, a)) ;
}
```

**Output:**

```
5
```

**Explanation:**

a += 3 → a = 1 + 3 = 4

5 → ignored, just evaluated

a → current value of a is 4 → this is the result of the comma operator

So, (a += 3, 5, a) evaluates to 4.

---

## Program 47

```c
#include<stdio.h>
int main()
{
    int a=10,b=20,c=30;
    int res;
    res=a/b?b/c?a:b:c;
    printf("%d",res);
}
```

**Output:**

```
20
```

**Explanation:**

a/b = 10/20=0 → false → select c=30

---

## Program 48

```c
x %= 7.0 % 2
```

**Explanation:**

* Invalid in C: `%` works only on integers. For floats, use `fmod()`.

---

## Program 49

```c
#include <stdio.h>
int main() {
    int a=0x2<<sizeof('a')*8-1;
    printf("%x\n",a);
    a>>=sizeof(int)*4-1;
    printf("%x\n",a);
}
```

**Output:**

```
40000000
2000
```

**Explanation:**

0x2 << 31 = 0x40000000

Shift right 15 → 0x2000

---

## Program 50

Write a program to check whether the particular bit is set or not in a given integer.

```c
#include <stdio.h>
int main() {
    int num, bit;
    // Input number and bit position
    printf("Enter an integer: ");
    scanf("%d", &num);
    printf("Enter bit position to check (0 for LSB): ");
    scanf("%d", &bit);
    // Check if the bit is set
    if (num & (1 << bit)) {
        printf("Bit %d is SET in %d\n", bit, num);
    } else {
        printf("Bit %d is NOT SET in %d\n", bit, num);
    }

    return 0;
}
```

**Output:**

```
Enter an integer: 5
Enter bit position to check (0 for LSB): 2
Bit 2 is SET in 5
```

**Explanation:**

(1 << bit) → creates a mask with only the desired bit set.

num & mask → performs bitwise AND:

If result ≠ 0 → bit is set

If result = 0 → bit is not set

---

[🔼 Back to Top](#c-operators) | [⬅ Back to Table of Contents](README.md)

---
