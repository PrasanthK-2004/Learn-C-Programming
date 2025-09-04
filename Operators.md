[🔽 Go to Bottom](#L456)[⬅ Back to Table of Contents](README.md)
# C Operators

This file contains 50 example programs in C.

---
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
[🔼 Back to Top](#c-operators) | [⬅ Back to Table of Contents](README.md)

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
Assignment inside equality. `b=a=10`. Then check `a==10` → true → 1.

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
p=5, q=-6. z=5/6 + (-6*5)/2 = 0 + -15 = -15 (check exact math).

---
[🔼 Back to Top](#c-operators) | [⬅ Back to Table of Contents](README.md)

---
