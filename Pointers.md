# C Pointers

This file contains 50 example programs to master `Pointers` in C.

---
[🔽 Go to Bottom](#program-50) | [⬅ Back to Table of Contents](README.md)

---

## 1. Increment and Pointer Arithmetic on `char*`

```c
#include<stdio.h>
int main()
{
    int x = 126;
    char *p = (char*)&x;
    printf("%d ", ++*p++);
    *p = 1;
    printf("%d", x);
}
```

**Output:** `127 382`

**Detailed Explanation:**

* `p` points to the first byte of integer `x`.
* `++*p++` increments the value of the first byte (126 → 127), then moves `p` to the next byte.
* `*p = 1` sets the second byte of `x` to 1.
* On little-endian systems, `x` is stored as bytes `[127, 1, 0, 0]` → decimal `382`.

---

## 2. Checking Sign Bit Using `char*`

```c
#include<stdio.h>
int main()
{
    int n = 404;
    char *b = (char*)&n;
    if (*b < 0)
        printf("hello");
    else
        printf("hai");
}
```

**Output:** `hai`

**Explanation:**

* `*b` accesses the least significant byte of `n`.
* On little-endian, LSB = 404 % 256 = 148.
* In signed `char`, 148 may be negative if `char` is signed; on most systems, it is positive → prints `hai`.

---

## 3. Invalid Pointer Assignment

```c
#include<stdio.h>
int main()
{
    int *i = (int*)255;
    printf("%p", i);
}
```

**Output:** `0x000000ff`

**Explanation:**

* Assigning an integer to a pointer stores that memory address.
* Not safe for dereferencing, but prints the pointer value.

---

## 4. Void Pointer Dereference (Error)

```c
#include<stdio.h>
int main()
{
    int a = 13;
    void *p = &a;
    // printf("%d", *p); // Error: cannot dereference void*
}
```

**Explanation:**

* `void*` has no data type, so dereferencing requires a cast: `printf("%d", *(int*)p);`

---

## 5. Difference Between Pointer Types

* `int *const p`: constant pointer to int (cannot point elsewhere; value can change).
* `int const *p`: pointer to constant int (value cannot change; pointer can move).

---

## 6. Size of Pointers

```c
#include<stdio.h>
int main()
{
    printf("%d\n", sizeof(int *));
    printf("%d\n", sizeof(char *));
    printf("%d\n", sizeof(double *));
}
```

**Output (64-bit system):**

```
8
8
8
```

**Explanation:** All pointers occupy 8 bytes on a 64-bit system, regardless of the type they point to.

---

## 7. Pointer Arithmetic on `void*`

```c
#include<stdio.h>
int main()
{
    void *p = (void*)5;
    printf("%p ", (int*)p + 1);
    printf("%p ", (long int*)p + 1);
    printf("%p ", (char*)p + 1);
}
```

**Output:** `0x9 0xd 0x6`

**Explanation:**

* Pointer arithmetic depends on type size.
* `(int*)p + 1` adds 4 bytes → 5 + 4 = 9.
* `(long int*)p + 1` adds 8 bytes → 5 + 8 = 13.
* `(char*)p + 1` adds 1 byte → 5 + 1 = 6.

---

## 8. Pointer to Float Declaration

```c
float f = 3.14;
float *ptr = &f;
```

**Explanation:** Standard pointer declaration for float type.

---

## 9. Short Pointer to Int (Undefined Behavior)

```c
#include<stdio.h>
int main()
{
    int p = 200;
    short int *a = (short int*)&p;
    *++a = 0;
    printf("%d", p);
}
```

**Output:** `0`

**Explanation:**

* `a` points to the first 2 bytes of `p`.
* `*++a = 0` sets the next 2 bytes of `p` to 0.
* Modifies `p`'s value directly.

---

## 10. Short Pointer to Char (Undefined Behavior)

```c
#include<stdio.h>
int main()
{
    char a = '3';
    char b = 1;
    short int *pt = (short int*)&a;
    printf("%d", *pt);
}
```

**Output (likely):** `51`

**Explanation:**

* Little-endian stores `a` in LSB.
* ASCII of '3' = 51, stored in lower byte of `short int`.
* Upper byte may be garbage or `b`, depends on memory alignment.

---

## 11. Invalid Pointer Assignments

```c
#include<stdio.h>
int main()
{
    int *p = (int*)20;
    printf("%p\n", p + 2);
    short int *q = (short int*)23;
    printf("%p\n", q + 3);
}
```

**Output:** `0x28 0x29`

**Explanation:**

* `p+2` → 2 \* sizeof(int) = 2\*4 = 8 → address 20+8=28 (0x28).
* `q+3` → 3 \* sizeof(short) = 3\*2 = 6 → address 23+6=29 (0x29).

---

## 12. Short Pointer Manipulation

```c
#include<stdio.h>
int main()
{
    short int a = 45;
    char *p = (char*)&a;
    *++p = 2;
    printf("%d\n", *--p);
    *p = 5;
    printf("%d\n", a);
}
```

**Output:**

```
45
517
```

**Explanation:**

* `*++p = 2` sets high byte → new short = 0x0202?
* `*--p` moves back to low byte → prints 45.
* `*p = 5` changes low byte → new `a = 0x0205 = 517`.

---

## 13. Void Pointer Increment

```c
#include<stdio.h>
int main()
{
    int i = 56;
    void *ptr = &i;
    printf("%p", ++((char*)ptr));
}
```

**Output:** `0x1001`

**Explanation:**

* Cast to `char*` to increment by 1 byte.
* `void*` arithmetic is invalid directly.

---

## 14. Pointer Subtraction

```c
#include<stdio.h>
int main()
{
    int x = 10, y = 20;
    char *p = (char*)&x;
    char *q = (char*)&y;
    printf("%ld", q - p);
}
```

**Output:** `4`

**Explanation:**

* Pointer subtraction gives difference in bytes.
* Address difference = 0x1004 - 0x1000 = 4.

---

## 15. Short Pointer to Int Manipulation

```c
#include<stdio.h>
int main()
{
    int x = 370;
    short *p = (short*)&x;
    *p >>= 2;
    *++p = 3;
    *p >>= 2;
    printf("%d", x);
}
```

**Output:** `9602`

**Explanation:**

* First short (LSB) of `x` = 370 & 0xFFFF → shift right 2.
* Second short (MSB) = 3 → shift right 2 → 0.
* Final `x` = combination of modified LSB and MSB → 9602.

---

# C Pointers: Detailed Examples, Outputs, and Explanations (16-30)

---

## 16. Pointer Initialized with Integer

```c
#include<stdio.h>
int main()
{
    int *p = (int*)'1';
    printf("%p ", p+1);
    char *q = (char*)2;
    printf("%p", q+1);
}
```

**Output:**

```
0x32 0x3
```

**Explanation:**

* Integer `'1'` = 49 stored as pointer address. `p+1` adds `sizeof(int)` = 4 bytes → 49 + 4 = 53 (0x35 in hex).
* `q` pointer arithmetic adds 1 byte → 2 + 1 = 3 (0x3). Unsafe to dereference.

---

## 17. Modifying Integer via Char Pointer

```c
#include<stdio.h>
int main()
{
    int num = 500;
    char *ptr = (char*)&num;
    int i;
    for(i = 0; i < 4; i++)
    {
        if(*ptr != 0)
            *ptr = 2;
        else
            break;
        ptr++;
    }
    printf("%d %d", i, num);
}
```

**Output:**

```
3 131074
```

**Explanation:**

* Modifies first three bytes of `num` to 2. Final integer = 0x00020002 (depends on little-endian).
* `i` = number of bytes modified = 3.

---

## 18. Dereferencing Invalid Pointer

```c
#include<stdio.h>
int main()
{
    int *p = (int*)'1';
    printf("%d ", *p);
    char *q = (char*)2;
    printf("%d", *q);
}
```

**Output:** Undefined / segmentation fault
**Explanation:**

* Pointer holds integer values, dereferencing causes undefined behavior.

---

## 19. Modifying Integer via Char Pointer

```c
#include<stdio.h>
int main()
{
    int a = 100;
    int *p = &a;
    *((char*)p + 1) = 2;
    printf("%d", *p);
}
```

**Output:**

```
356
```

**Explanation:**

* Modifies second byte of `a` from 0x64 → 0x02 → integer becomes 0x0164 = 356 (little-endian).

---

## 20. Void Pointer (`void*`)

**Explanation:**

* Generic pointer type to hold address of any data type.
* Cannot be dereferenced directly; must cast to specific type first.

---

## 21. Modifying Integer Bytes

```c
#include<stdio.h>
int main()
{
    int x = 348;
    char *ptr = (char*)&x;
    *ptr++ = 4;
    *(ptr+1) = 0;
    printf("%d %d", *ptr, x);
}
```

**Output:**

```
0 1028
```

**Explanation:**

* First byte set to 4, third byte set to 0 → integer becomes 0x0404 = 1028.
* `*ptr` after increment points to second byte = 0.

---

## 22. Null and Arbitrary Pointer Arithmetic

```c
#include<stdio.h>
int main()
{
    double *p = NULL;
    printf("%p\n", p);
    p = (double*)100;
    printf("%p", p+2);
}
```

**Output:**

```
0x0
0x110
```

**Explanation:**

* `p+2` adds 2\*sizeof(double) = 16 → 100 + 16 = 116 (0x110).

---

## 23. Pointer and Byte-Level Modifications

```c
#include<stdio.h>
int main()
{
    int x = 200;
    char *p = (char*)&x;
    short *q = (short*)&x;
    *(p+1) = 3;
    *q++ = 4;
    *(q+1) = 0;
    printf("%d %d", *p, *q);
}
```

**Output:** Undefined, depends on system memory alignment
**Explanation:**

* Modifies individual bytes via `char*` and `short*`. Printing `*p` and `*q` shows different values due to pointer type.

---

## 24. Accessing Bytes via Void Pointer

```c
#include<stdio.h>
int main()
{
    int x = 400;
    void *ptr = &x;
    printf("%d %d", *((char*)ptr+2), *((char*)ptr +1));
}
```

**Output:**

```
1 144
```

**Explanation:**

* Little-endian: x = 400 = 0x0190
* Byte 1 = 144, byte 2 = 1.

---

## 25. Short Pointer to Int (Undefined Behavior)

```c
#include<stdio.h>
int main()
{
    short int x = 556;
    short int y = 557;
    int *p = (int*)&x;
    *p = 15;
    printf("%d %d", x, y);
}
```

**Output:** Undefined, may print `15 557`
**Explanation:**

* Writing via `int*` may overwrite memory beyond `x` → undefined behavior.

---

## 26. Right Shift via Char Pointer

```c
#include<stdio.h>
int main()
{
    int n = 416;
    char *b = (char*)&n;
    *b = *b >> 2;
    printf("%d", *b);
}
```

**Output:**

```
64
```

**Explanation:**

* LSB = 416 % 256 = 160 → shifted 2 bits → 160>>2 = 40. Depending on signedness, output may vary.

---

## 27. Invalid Void Pointer Dereference

```c
#include<stdio.h>
int main()
{
    int x = 157;
    void *q = &x;
    printf("%p", (int*)*q);
}
```

**Output:** Undefined / segmentation fault
**Explanation:**

* Cannot dereference `void*` directly.

---

## 28. Mixed Pointer Types

```c
#include<stdio.h>
int main()
{
    int r = 300;
    char *p = (char*)&r;
    *++p = 1;
    short int *q = &r;
    q+1;
    printf("%d %d", *p, *q);
}
```

**Output:** Depends on system (little-endian), possible:

```
1 256
```

**Explanation:**

* Modifies second byte via `char*` → changes `r`. `*q` reads first 2 bytes.

---

## 29. Void Pointer and Casting

```c
#include<stdio.h>
int main()
{
    int t = 290;
    void *u = &t;
    printf("%d ", *(char*)u);
    printf("%d ", *(int *)u);
}
```

**Output:**

```
34 290
```

**Explanation:**

* LSB = 34, full int = 290 (little-endian).

---

## 30. Unsigned Char Pointer to Negative Int

```c
#include<stdio.h>
int main()
{
    int a = -3;
    unsigned char *p = (unsigned char*)&a;
    printf("%d", *p);
}
```

**Output:**

```
253
```

**Explanation:**

* LSB of -3 in two's complement = 0xFD = 253 as unsigned.

---

# C Pointers: Detailed Examples, Outputs, and Explanations (31-50)

---

## 31. Masking Integer Byte

```c
#include<stdio.h>
int main()
{
    int a = -24;
    char *p = (char*)&a;
    *p = *p & 0;
    printf("%d", a);
}
```

**Output:**

```
-256
```

**Explanation:**

* `*p & 0` sets LSB to 0, other bytes remain negative → -256 (little-endian).

---

## 32. Character Pointer Manipulation

```c
#include<stdio.h>
int main()
{
    char c = 'a';
    char *p = &c;
    p++;
    *(p-1) = 68;
    p--;
    printf("%c", *p);
}
```

**Output:**

```
D
```

**Explanation:**

* Modifies `c` via pointer arithmetic → ASCII 68 = 'D'.

---

## 33. Size of Variable Using Pointer

```c
#include<stdio.h>
int main()
{
    int x;
    int *p = &x;
    printf("%zu", sizeof(*p));
}
```

**Output:**

```
4
```

**Explanation:**

* `sizeof(*p)` returns size of the variable pointed to by `p` (int = 4 bytes on 32-bit/64-bit).

---

## 34. Pointer Arithmetic Beyond Char

```c
#include<stdio.h>
int main()
{
    char x = 'a';
    short int *p = &x + 3;
    printf("%p", p);
}
```

**Output:**

```
0x1006
```

**Explanation:**

* `&x + 3` moves 3 bytes beyond `x` (char\* → short\* arithmetic) → new address 0x1006.

---

## 35. Print Short Integer in Binary Using Pointer

```c
#include<stdio.h>
int main()
{
    short x = 5;
    unsigned short mask = 1 << (sizeof(x)*8 - 1);
    char *p = (char*)&x;
    for(int i = 0; i < 16; i++)
        printf("%d", (x & (1 << (15-i))) ? 1 : 0);
}
```

**Output:**

```
0000000000000101
```

**Explanation:** Prints binary representation of 16-bit short integer.

---

## 36. Pointer Subtraction

```c
#include<stdio.h>
int main()
{
    int x = 10, y = 20;
    short int *p = (short int*)&x;
    short int *q = (short int*)&y;
    printf("%ld", q - p);
}
```

**Output:**

```
2
```

**Explanation:**

* Subtraction of short pointers → difference in number of `short` elements. Address difference = 4 bytes / 2 = 2.

---

## 37. Size of Pointer and Dereferenced Value

```c
#include<stdio.h>
int main()
{
    int a = 30;
    int *p = &a;
    printf("%zu %zu", sizeof(*p), sizeof(p));
}
```

**Output:**

```
4 8
```

**Explanation:**

* `sizeof(*p)` = 4 (int), `sizeof(p)` = 8 (pointer on 64-bit system).

---

## 38. Constant Pointer Arithmetic (Invalid)

```c
#include<stdio.h>
int main()
{
    int const *x = 10;
    x += 10;
    printf("%p", x);
}
```

**Output:** Undefined / compiler error
**Explanation:**

* `int const* x = 10` invalid initialization. Cannot perform pointer arithmetic on literal.

---

## 39. Modifying Integer Bytes via Char Pointer

```c
#include<stdio.h>
int main()
{
    int x = 'f';
    char *y = (char*)&x;
    int i = 0;
    while(i<4)
    {
        *(y+i) = *y + i;
        i++;
    }
    printf("%c", *(y+2));
}
```

**Output:** Depends on system, likely `g`
**Explanation:**

* Modifies each byte of integer. Third byte = ASCII of 'g'.

---

## 40. Constant Char Pointer Modification (Invalid)

```c
#include<stdio.h>
int main()
{
    const char *pt = "a";
    *pt += 3;
    printf("%c", *pt);
}
```

**Output:** Compilation error
**Explanation:** Cannot modify value pointed to by `const char*`.

---

## 41. Constant Pointer to Int (Invalid Assignment)

```c
#include<stdio.h>
int main()
{
    int a = 11, b = 22;
    int *const t = &a;
    t = &b;
    printf("%d", *t);
}
```

**Output:** Compilation error
**Explanation:** `t` is a constant pointer; cannot point to another variable.

---

## 42. Invalid Pointer Type Conversion

```c
#include<stdio.h>
int main()
{
    char x = 20;
    int *p = (int*)&x;
    printf("%d", *p);
}
```

**Output:** Undefined / garbage
**Explanation:** Pointer type mismatch; reading beyond memory of `x`.

---

## 43. Pointer Increment Beyond Variable

```c
#include<stdio.h>
int main()
{
    int c = 40;
    int *d = &c;
    d++;
    printf("%d", *d);
}
```

**Output:** Undefined / garbage
**Explanation:** Incremented pointer beyond valid memory.

---

## 44. Pointer Arithmetic with Offset

```c
#include<stdio.h>
int main()
{
    int x = 50;
    int *p = &x + 2;
    printf("%p %p", &x, p);
}
```

**Output:**

```
0x1000 0x1008
```

**Explanation:** `int*` pointer arithmetic adds 2\*sizeof(int) = 8 bytes.

---

## 45. Pointer Subtraction Between Different Types

```c
#include<stdio.h>
int main()
{
    int x=10, y=20;
    char *p1=&x;
    short int *p2=&y;
    printf("%ld", p2 - (short int*)p1);
}
```

**Output:**

```
2
```

**Explanation:** Pointer subtraction counts number of elements of type `short int` between addresses.

---

## 46. Pointer Arithmetic with Short Int

```c
#include<stdio.h>
int main()
{
    int x=2, y=4;
    short int *p=(short int*)&x;
    p+=2;
    printf("%d", *p);
    p++;
    printf(" %d", *p);
}
```

**Output:** Undefined / garbage
**Explanation:** Pointer moves beyond valid memory of `x` and `y`.

---

## 47. Char and Short Pointer Combination

```c
#include<stdio.h>
int main()
{
    int r=540;
    char *p=(char*)&r;
    p++;
    short int *q=(short int*)p;
    printf("%d", *q);
}
```

**Output:** Depends on endianness, likely `1`
**Explanation:** Modifies pointer type and accesses overlapping memory.

---

## 48. Sizeof with Char Pointer to Int

```c
#include<stdio.h>
int main()
{
    int a=30;
    char *p=&a;
    printf("%zu %zu", sizeof(*p), sizeof(p));
}
```

**Output:**

```
1 8
```

**Explanation:** Dereferencing char pointer → 1 byte, pointer itself → 8 bytes (64-bit).

---

## 49. Constant Pointer to Constant Int

```c
#include<stdio.h>
int main()
{
    int m=89,n=90;
    const int *const p=&m;
    // p++ is invalid
    printf("%d", *p);
}
```

**Output:**

```
89
```

**Explanation:** `const int* const` → cannot modify pointer or value.

---

## 50. Set All Bits of Integer

```c
#include<stdio.h>
int main()
{
    int num=2, i;
    int *p=&num;
    for(i=31;i>=0;i--)
        *p |= 1<<i;
    printf("%d", num);
}
```

**Output:**

```
-1
```

**Explanation:** Sets all 32 bits → integer becomes all 1's → -1 in two's complement.

---

[🔼 Back to Top](#c-operators) | [⬅ Back to Table of Contents](README.md)

---
