# Control Statements in C

This file contains 50 example programs to master `Control Statements` in c

---
[🔽 Go to Bottom](#problem-50) | [⬅ Back to Table of Contents](README.md)

---

## Problem 1: Bitwise Shift and AND

```c
#include<stdio.h> 
int main() 
{ 
    int num = 45; 
    if(num >> 3 & 4) 
        num = num << 2; 
    else 
        num = num >> 5; 
    printf("%d", num); 
}
```

**Output:**

```
180
```

**Explanation:**

`num >> 3` shifts 45 right by 3 bits → 5
`5 & 4` performs bitwise AND → 4 (true)
Since condition is true, `num = num << 2` → 45 << 2 = 180

---

## Problem 2:Invalid code

```c
#include<stdio.h> 
int main() 
{ 
    int r, s = 25; 
    if(r++ = s++) 
        printf("%d", r); 
    else 
        printf("%d", s); 
}
```

**Output:**

```
Compilation Error
```

**Explanation:**

Assignment to `r++` is invalid; cannot assign to an increment expression.

---

## Problem 3: Nested if

```c
#include<stdio.h> 
int main() 
{ 
    int x = -1; 
    if(x) 
    { 
        x = 1; 
        if(!x) 
            printf("Joy"); 
        else 
            printf("Happy"); 
    } 
    else 
    { 
        printf("Blissful"); 
    } 
}
```

**Output:**

```
Happy
```

**Explanation:** 

`x = -1` is true; inside first `if`, `x = 1`; `!x` is false, so `else` prints `Happy`.

---

## Problem 4
**What is the purpose of using break statement in c and where it can be used?**

**Explanation:**

* The `break` statement in C is used to **immediately terminate** a loop or a `switch` statement.  
When the program encounters a `break`, it **jumps out** of the loop/switch and continues execution from the next statement after it.

### Where it is used
1. **Inside Loops (`for`, `while`, `do...while`)**  
   - To exit a loop early when a specific condition is met.  
   - Useful when continuing the loop is unnecessary.

2. **Inside `switch` Statement**  
   - To stop execution after a matching `case`.  
   - Prevents *fall-through* into the next case.

### 📌 Key Points
- `break` can only be used inside loops and switch statements.  
- It exits **only one level** of loop/switch (not all nested levels).  
- If you want to skip only the current iteration instead of exiting, use `continue`.  

---

## Problem 5: Char Overflow

```c
#include<stdio.h>  
int main()  
{  
    char ch = 259; 
    int x = 2; 
    if(ch == ++x) 
        printf("ABC"); 
    else 
        printf("DEF"); 
}
```

**Output:**

```
ABC
```

**Explanation:** 

- `char ch = 259`;
- A char can store values from -128 to 127 (signed) or 0 to 255 (unsigned).
- Assigning 259 wraps around modulo 256 → 259 % 256 = 3.
- So ch = 3.
- ++x
- x is initially 2.
- `++x` increments it by 1 → x = 3.
- if(ch == ++x)
- Becomes `if(3 == 3)` → true.
- Therefore, the if block executes → prints: `ABC`

---

## Problem 6: Assignment inside if

```c
#include <stdio.h> 
int main() { 
    int a = 20, b = 6; 
    if(a = 5)  
        b++; 
    printf("%d %d", ++a, b++); 
}
```

**Output:**

```
6 7
```

**Explanation:** 

Assignment `a = 5` is true, increments `b` to 7; `++a = 6`, `b++ = 7`.

---

## Problem 7: Semicolon after if

```c
#include<stdio.h> 
int main() 
{ 
    int x = 99, y = 87; 
    if(y++, x > 100); 
    printf("Hello"); 
    printf("Hi"); 
}
```

**Output:**

```
HelloHi
```

**Explanation:** 

Semicolon after `if` ends the statement; `printf`s execute regardless.

---

## Problem 8: Assignment in if

```c
#include <stdio.h> 
int main() { 
    int val1, val2 = 100, num = 500; 
    if(val1 = val2 % 2) 
        num = 200; 
    printf("%d %d %d", val1, val2, num); 
}
```

**Output:**

```
0 100 500
```

**Explanation:** 

`val2 % 2 = 0`; assignment to `val1` makes condition false; `num` remains 500.

---

## Problem 9: Leap Year Check

```c
#include <stdio.h>
int main() {
    int year;
    printf("Enter year: ");
    scanf("%d", &year);

    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        printf("%d is a leap year\n", year);
    else
        printf("%d is not a leap year\n", year);
}
```

**Output:**

Checks leap year: divisible by 4 but not 100, or divisible by 400.

**Case 1:**
```
Enter year: 2024
2024 is a leap year
```

(Because 2024 % 4 == 0 and not divisible by 100)

**Case 2:**
```
Enter year: 1900
1900 is not a leap year
```

(Because 1900 % 100 == 0 but not divisible by 400)

**Case 3:**
```
Enter year: 2000
2000 is a leap year
```

(Because 2000 % 400 == 0)

**Case 4:**
```
Enter year: 2023
2023 is not a leap year
```
(Because 2023 % 4 != 0 also not divisible by 400)

---

## Problem 10: Nested if without braces

```c
#include<stdio.h> 
int main() 
{ 
    int x = 0; 
    if (x == 1) 
        if (x >= 0) 
            printf("true\n"); 
        else 
            printf("false\n"); 
}
```

**Output:**

```
(no output)
```

**Explanation:** 
`x == 1` is false, nothing executes.

---

## Problem 11: Comma Operator

```c
#include<stdio.h>  
int main(){  
    int i = 0, j = 1, k = 0;  
    if(++k, j, i++)  
        printf("%d %d %d", i, j, k);  
    return 0;  
}  
```

**Output:**

```
(no output)
```

**Explanation:**
Comma operator evaluates all but last value; `i++` is 0 → false, so nothing prints.

---

## Problem 12: Switch Statement

```c
#include<stdio.h>  
int main()  
{  
    int i = 65;  
    switch(i)  
    {  
        case 65:  
            printf("Integer 65");  
            break;  
        case 'A':  
            printf("Char 65");  
            break;  
        default:  
            printf("Bye");  
    }  
    return 0;  
}  
```

**Output:**

```
Error
```

**Explanation:**
- 'A' in ASCII = 65.
- `case 65`: is already defined.
- In a C switch statement, all case labels must be unique.
- Since case 'A': is the same as case 65:, the compiler gives a duplicate case value error.

---

## Problem 13: Comparison and Assignment

```c
#include<stdio.h>  
int main()  
{  
    int i = 5, j = 6, k = 7;  
    if(i > j == k)  
        printf("%d %d %d", i++, ++j, --k);  
    else  
        printf("%d %d %d", i, j, k);  
    return 0;  
}  
```

**Output:**

```
5 6 7
```

**Explanation:** 
`(i > j)` is 0; `0 == 7` is false → else block executes.

---

## Problem 14: Operator Precedence

```c
#include<stdio.h>  
int main()  
{  
    int i = 5;  
    if(i = i - 5 > 4)  
        printf("inside if block");  
    else  
        printf("inside else block");  
    return 0;  
} 
```

**Output:**

```
inside else block
```

**Explanation:** 
`i - 5 > 4` → `0 > 4` → false (0); assignment `i = 0`; condition false → else executes.

---

## Problem 15: Switch without break

```c
#include<stdio.h>  
int main()  
{  
    switch(2/2)  
    {  
        case 1:  
            printf("case 1 executed ");  
        case 2:  
            printf("case 2 executed ");  
            break;  
        default:  
            printf("Default block executed");  
    }  
    return 0;  
}  
```

**Output:**

```
case 1 executed case 2 executed
```

**Explanation:** 
`2/2 = 1` matches `case 1`; no break → fall-through to `case 2`.

---

## Problem 16: goto statement

```c
#include<stdio.h> 
int main()  
{  
    printf("%d ", 1);  
    goto l1;  
    printf("%d ", 2);  
    l1:goto l2;  
    printf("%d ", 3);  
    l2:printf("%d ", 4);  
} 
```

**Output:**

```
1 4
```

**Explanation:** 
`goto l1` skips `printf(2)` and jumps to `l1`; then `goto l2` jumps to `l2` and prints 4.

---

## Problem 17: continue in if (Invalid)

```c
#include<stdio.h> 
int main()  
{  
    int i = 0;  
    if (i == 0)  
    {  
        printf("Hello");  
        continue;  
    }  
} 
```

**Output:**

```
Compilation Error
```

**Explanation:**
`continue` cannot be used outside loops.

---

## Problem 18: Comma operator with goto

```c
#include<stdio.h> 
int main() 
{ 
    int i=10,j=20; 
    if(i++,i++,j<20) 
    { 
        printf("hai"); 
        goto l; 
    } 
    else 
        printf("hi"); 
    l:printf(" %d",i); 
} 
```

**Output:**

```
hai 12
```

**Explanation:**
Comma operator evaluates `i++`, `i++`, `j<20` → `20<20` false → `else` skipped? Actually `j<20` false, else executes? Need careful evaluation. Correct output: ` 12` (prints from label) after goto.

---

## Problem 19: Bitwise OR and logical AND

```c
#include<stdio.h> 
int main() 
{ 
    int a=0,b=2,c=3,d=1; 
    if(b|a&&d) 
        printf("hai\n"); 
    if(a|--d&&c) 
        printf("hello"); 
    else 
        printf("bye"); 
} 
```

**Output:**

```
hai
hello
```

**Explanation:**
Operator precedence: `&&` before `|`; evaluates conditions accordingly.

---

## Problem 20: Switch with expressions

```c
#include<stdio.h> 
int main() 
{ 
    int a=5,b=6; 
    switch(a&b) 
    { 
        case 2+2:printf("One"); 
        case 5*1  :printf("Two");break; 
        case 20/5-1:printf("Three"); 
        default:printf("def");break; 
    } 
} 
```

**Output:**

```
OneTwo
```

**Explanation:** 
`a&b = 4`; matches `case 2+2`
- Switch finds the first matching case: case 4 → executes `printf("One")`;
- No break after `case 2+2:` execution falls through to the next case.
- `case 5*1:` executes → `printf("Two")`; and then break; stops the switch.
- `case 20/5-1` and `default` are skipped.

---

## Problem 21: Switch multiple cases

```c
#include<stdio.h> 
int main() 
{ 
    int res=1; 
    switch(res/5) 
    { 
        case 1:printf("case 1\n"); 
        case 0:printf("case 0\n"); 
        case 2:printf("case 2\n");break; 
        default:printf("def\n"); 
    } 
} 
```

**Output:**

```
case 0
case 2
```

**Explanation:** 
`res/5 = 0`; starts at `case 0`, prints `case 0` and falls through `case 2`,because no break after `case 0:`

---

## Problem 22: Bitwise with shift

```c
#include<stdio.h> 
int main() 
{ 
    int p=-1; 
    p>>=2; 
    if(p&~p<<3) 
      printf("if"); 
    else if(p) 
            printf("else if"); 
    else 
            printf("else"); 
} 
```

**Output:**

```
else if
```

**Explanation:**
After shifts, `p` is non-zero, first condition false, second true → prints `else if`.

---

## Problem 23: Arithmetic in if

```c
#include<stdio.h> 
int main() 
{ 
    int a=10; 
    if(a-=a*a-a) 
        printf("Good\n"); 
    else 
        printf("Better\n"); 
    printf("%d",a); 
} 
```

**Output:**

```
Good
-80
```

**Explanation:**
- `a -= a*a - a` → updates `a` to `10 - (10*10 - 10) = -80`.
- In C, any non-zero value in if is true, so `"Good"` is printed.
- Finally, `a` is `-80`, so `printf("%d", a)` prints `-80`.

---

## Problem 24: Label and goto

```c
#include<stdio.h> 
int main() 
{ 
    int i=0,l=10; 
label: 
    i+=2; 
    printf("%d ",i); 
    if(i++<l) 
        goto label; 
    printf("%d ",i); 
} 
```

**Output:**

```
2 5 8 11 12
```

**Explanation:**
| Step | i before i+=2 | i after i+=2 | Print i | Condition `i++<10` | i after i++ | Goto? |
| ---- | ------------- | ------------ | ------- | ------------------ | ----------- | ----- |
| 1    | 0             | 2            | 2       | 2<10 ✅             | 3           | Yes   |
| 2    | 3             | 5            | 5       | 5<10 ✅             | 6           | Yes   |
| 3    | 6             | 8            | 8       | 8<10 ✅             | 9           | Yes   |
| 4    | 9             | 11           | 11      | 11<10 ❌            | 12          | No    |

- Now loop ends, execute final `printf("%d ", i)` → prints `12`.
---

## Problem 25: Switch with float (Invalid)

```c
#include<stdio.h> 
int main() 
{ 
    int c=55.0; 
    switch(c) 
    { 
        case 54:printf("English"); 
            break; 
        case 55.0:printf("Maths"); 
            break;  
    } 
} 
```

**Output:**

```
Compilation Error
```

**Explanation:** 
Switch case cannot take float values; only integer constant expressions.

---

## Problem 26: Label with expression (Invalid)

```c
#include<stdio.h> 
int main() 
{ 
    int s=5; 
    s*s:printf("Hi "); 
    printf("Hello\n"); 
    if(8>>3+5) 
        goto s*s; 
} 
```

**Output:**

```
Compilation Error
```

**Explanation:** 
Labels must be identifiers, not expressions.

---

## Problem 27: Float comparison

```c
#include<stdio.h> 
int main() 
{ 
    float f=5.6; 
    if(f==5.6) 
        printf("hi\n"); 
    else if(f==(float)5.6) 
        printf("hello\n"); 
    else if(f==5.6f) 
        printf("hai"); 
} 
```

**Output:**

```
hello
```

**Explanation:** 
`f==(float)5.6` true due to explicit cast; first comparison fails due to double-float mismatch.

---

## Problem 28: Label and break (Invalid)

```c
#include<stdio.h> 
int main() 
{ 
    char a='A',b='B'; 
q: 
    printf("%c",a-18); 
    printf("%c\n",b-19); 
    break; 
    goto q; 
} 
```

**Output:**

```
Compilation Error
```

**Explanation:**
`break` cannot be used outside loops or switch.

---

## Problem 29: Switch with comma operator

```c
#include<stdio.h> 
int main() 
{ 
    int num='1'; 
    switch(--num,num++) 
    { 
        default:printf("default\n"); 
        case 47:printf("case 47\n"); 
        case 48:printf("case 48\n"); 
        case 49:printf("case 49\n"); 
    } 
} 
```

**Output:**

```
case 48
case 49
```

**Explanation:**
- Comma operator evaluates to `num++` → returns 48, then num updated to 49 in memory.
- case 48: → prints "case 48\n"
- Falls through to case 49: → prints "case 49\n"
- There is no break, but default is before the cases, so it won’t execute.

---

## Problem 30: if with else after statement (Invalid)

```c
#include<stdio.h> 
int main() 
{ 
    if('\0') 
        printf("hi"); 
    printf("hello"); 
    else 
        printf("bye"); 
} 
```

**Output:**

```
Compilation Error
```

**Explanation:** 

`else` must follow immediately after `if` statement; here `printf` breaks structure.

---

### Problem 31

```c
#include<stdio.h> 
int main() 
{ 
    int a = 1; 
    if(a--) 
        printf("A"); 
    if(a++) 
        printf("B"); 
    if(!a) 
        printf("C"); 
    if(!!a) 
        printf("D"); 
} 
```

**Output:** 
```
AD
```

**Explanation:** 
| Statement | Value of a before | Condition | Prints | a after |
| --------- | ----------------- | --------- | ------ | ------- |
| `if(a--)` | 1                 | true      | A      | 0       |
| `if(a++)` | 0                 | false     |        | 1       |
| `if(!a)`  | 1                 | false     |        | 1       |
| `if(!!a)` | 1                 | true      | D      | 1       |

---

### Problem 32

```c
#include<stdio.h> 
int main() 
{ 
    int x1=5,x2=6,x3=6; 
    if(x1<x2>>1) 
        printf("yes"); 
    if(x3<=x2>>0) 
        if(x1=3,x2=0) 
            printf("%d",x2); 
        else 
            printf("%d",x1); 
} 
```

**Output:** 
```
3
```

**Explanation:** 
| Step | Expression         | Value / Result               |
| ---- | ------------------ | ---------------------------- |
| 1    | x1 < x2 >> 1       | 5 < 3 → false                |
| 2    | x3 <= x2 >> 0      | 6 <= 6 → true                |
| 3    | if(x1 = 3, x2 = 0) | last expr = 0 → false → else |
| 4    | printf("%d", x1)   | prints 3                     |

---

### Problem 33

```c
#include<stdio.h> 
int main() 
{ 
    double d=12.7; 
    int i=d; 
    switch(d++,i++) 
    { 
        case 10:printf("One"); 
        case 11:printf("Two"); 
        case 12:printf("Three"); 
    } 
} 
```

**Output:** 
```
Three
```

**Explanation:** 
`switch` evaluates to last expression `i++` → `12`. So case 12 matches, prints `Three`.

---

### Problem 34

```c
#include<stdio.h> 
int main() 
{ 
    int a=5; 
label1: 
    if(a--,++a) 
        printf("%d ",a); 
    a++; 
    if(a==10) 
        goto label2; 
    goto label1; 
label2: 
    a/=a+3; 
    printf("%d",a); 
} 
```

**Output:** 
```
5 6 7 8 9 0
```

**Explanation:** 
- a starts at 5.
- if(a--, ++a) uses comma operator → last value (++a) is the condition.
- For first iteration: a-- → 4, ++a → 5 → true → prints 5.
- a++ increments a for the next iteration.
- if(a == 10) → when a reaches 10, jumps to label2.
- Loop repeats, printing 5 6 7 8 9.
- At label2: a /= a + 3;   10 / 13 → 0

---

### Problem 35

```c
#include<stdio.h> 
int main() 
{ 
    if((sizeof(0)==sizeof('0'))) 
        printf("Equal"); 
    else 
        printf("Not equal"); 
} 
```

**Output:** 
```
Equal
```

**Explanation:**

`sizeof(0)` is `int` (4 bytes). `'0'` is `int` in C (also 4). 

---

### Problem 36

```c
#include<stdio.h> 
int main() 
{ 
    l: 
    goto m; 
    s: 
    printf("hi"); 
    m: 
    goto s; 
} 
```

**Output:** 
```
Infinite loop .
```

**Explanation:** 

Labels form infinite jump, leading to undefined behavior.

---

### Problem 37

```c
#include<stdio.h> 
int main() 
{ 
    int i=5,j=6; 
    if(i++<--j) 
        if(0,--i>j++,i-=5) 
            printf("c"); 
        else if(++i) 
            printf("c++"); 
        else 
            printf("python"); 
} 
```

**Output:**
```
<no output>
```
**Explanation:** 

- i++ → post-increment: uses 5, then i = 6
- --j → pre-decrement: j = 5
- Compare: 5 < 5 → false
- Since the first if is false, the inner if blocks are skipped entirely.

---

### Problem 38

```c
#include<stdio.h>  
int main()  
{  
    int i = 0;  
    switch(++i)  
    {  
        case 0 : i++;  
        case 1 : i++ +2;  
        case 2 : ++i;  
    }  
    pritnf("%d",i++);  
    return 0; 
} 
```

**Output:** 
```
Compilation error (typo: `pritnf`).
```
**Explanation:**

`pritnf` is a typo, it should be `printf`. Otherwise, compilation error.

If you fix the typo (printf), the program runs and outputs 3.

Initially i = 0.

switch(++i) → pre-increment, so i = 1.

→ Switch expression value = 1.

Control jumps to case 1.

i++ + 2; → evaluates the expression but result is unused.

i was 1 → post-increment makes i = 2.

(No break, so fall-through happens.)

case 2 : ++i; → increments i from 2 to 3.

End of switch.

printf("%d", i++);

Prints current value of i (3).

Then increments i to 4 (but increment not shown in output).

---

### Problem 39

```c
#include<stdio.h>  
int main()  
{  
    switch(25)  
    {  
        case 25L:  
            printf("25L");  
            break;  
        case 26:  
            printf("26");  
            break;  
        default:  
            printf("Nothing");  
            break;  
    }  
    return 0;  
} 
```

**Output:** 
```
25L
```

**Explanation:** 

Case `25L` matches integer constant promotion.

---

### Problem 40

**Write a program to find the second largest number using nested if.**

```c
#include<stdio.h>
int main(){
    int a=10,b=20,c=15;
    if(a>b){
        if(a>c){
            if(b>c) printf("%d",b);
            else printf("%d",c);
        }
    }else{
        if(b>c){
            if(a>c) printf("%d",a);
            else printf("%d",c);
        }
    }
}
```

**Output:** 
```
15
```

---

### Problem 41

```c
#include<stdio.h>  
int main(){  
    int n = 4;  
    switch(n)  
    {  
        case 1:  
            printf("Hai case 1 ");  
        default:  
            printf("Hai default ");  
        case 2:  
            printf("Hai case 2 ");  
        case 3:  
            printf("Hai case 3 ");  
    }  
    return 0;  
} 
```

**Output:** 
```
Hai default Hai case 2 Hai case 3
```

**Explanation:**

`case 4:` not there, so print's default case, then no break present and execute upto case 3.

---

### Problem 42

```c
#include<stdio.h> 
int main() 
{ 
    int m=10,n=20; 
    if(m/n/m) 
        goto o; 
    printf("Operating "); 
    o: 
    printf("System\n"); 
} 
```

**Output:** 
```
Operating System
```
**Explanation:**
- m / n / m → 10 / 20 / 10 → integer division → 0 / 10 = 0
- Condition is false, so goto o is not executed.
- printf("Operating "); executes → prints "Operating "
- Label o: → program continues → printf("System\n"); prints "System"

---

### Problem 43

**Q:** Difference between `if-else` and `switch`?

**A:**

* `if-else`: Works with ranges, complex conditions, multiple datatypes.
* `switch`: Works with discrete constant values (int, char, enum).

---

### Problem 44

**Q:** Which datatype can accept the switch statement? 
a) int 

b) char 

c) long 

d) all of the mentioned 

* **Answer:** `d) all of the mentioned`

---

### Problem 45

```c
#include <stdio.h> 
int main() 
{ 
    int a = 1, b = 1; 
    switch (a) 
    { 
        case a*b: 
            printf("yes "); 
        case a-b: 
            printf("no\n"); 
            break; 
    } 
} 
```

**Output:** 
```
Compilation error (case labels must be constant).
```

---

### Problem 46

```c
#include<stdio.h>  
int main(){  
    switch(true)  
        case true:  
            printf("Hai. This is True");  
            break;  
        case false:  
            printf("Hai. This is False");  
            break;  
        default:  
            printf("Bye.");  
            break;  
    return 0;  
} 
```

**Output:** 
```
Compilation error (`true/false` not defined in C).
```

---

### Problem 47

```c
#include <stdio.h> 
int main() 
{ 
    printf("%d ",1); 
    goto l1; 
    printf("%d ", 2); 
    l1:l2: 
    printf("%d\n", 3); 
    goto l2; 
} 
```

**Output:** 
```
Infinite loop printing `1 3 3 3...`
```

**Explanation:**
Prints 1 

goto l1;

Program jumps to label l1.

The line printf("%d ", 2); is skipped.

Label l1: l2:

Two labels together → program continues here.

printf("%d\n", 3);

Prints 3 

goto l2;

Jumps to label l2 → infinite loop

Program keeps printing 3 forever.

---

### Problem 48

```c
#include <stdio.h> 
int main() 
{ 
    int i = 0; 
    if (i == '0') 
    { 
        goto label; 
    } 
    label: printf("Hello"); 
} 
```

**Output:**
```
Hello
```

**Explanation:** 
`'0'` ASCII value is 48. `i==0`, so condition false, but label still executes.

---

### Problem 49

```c
#include<stdio.h> 
int main() 
{ 
    int m=15,n=25,p=0; 
    if(1>0?m<n?m++,n++:m++,p++:m++,p++) 
        printf("true\n"); 
    printf("%d %d %d",m,n,p); 
} 
```

**Output:** 
```
true
16 26 2
```

**Explanation:** 
Initial values: m = 15, n = 25, p = 0

Outer ternary: 1 > 0 ? (m < n ? m++, n++ : m++), p++ : m++, p++

1 > 0 → true → evaluate true branch: (m < n ? m++, n++ : m++), p++

Inner ternary: m < n ? m++, n++ : m++, p++

m < n → 15 < 25 → true → execute m++, n++

m++ → m = 16

n++ → n = 26

Outer comma operator:

After inner ternary, p++ executes → p = 1

Due to evaluation order, p++ executes again → p = 2

if condition:

Value of last expression (p++) is non-zero → true → prints "true"

Prints updated values: 16 26 2

---

### Problem 50

```c
#include<stdio.h>  
int main()  
{  
    int i = 0;  
    if(++i)  
    {  
        i == --i?i = 0:i = 1;  
    }  
    printf("%d", i);  
    return 0;  
}  
```

**Output:**
```
compilation error
```

**Explanation:** 
The ternary operator (? :) has higher precedence than = in C.

So the compiler parses it as:

i == (--i ? i = 0 : i) = 1;  // This is invalid


The left side of = must be an lvalue (something you can assign to), but here it is not → compilation error.

---

[🔼 Back to Top](#control-statements-in-c) | [⬅ Back to Table of Contents](README.md)

---
