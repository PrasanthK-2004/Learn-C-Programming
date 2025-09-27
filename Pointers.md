# C Pointers

This file contains 50 example programs to master `Pointers` in C.

---
[🔽 Go to Bottom](#the-end) | [⬅ Back to Table of Contents](README.md)

---

## Problem 1. Increment and Pointer Arithmetic on `char*`

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

**Output:** 
```
127 383
```
**Explanation:**

* `p` points to the first byte of integer `x`.
* `++*p++` increments the value of the first byte (126 → 127), then moves `p` to the next byte.
* `*p = 1` sets the second byte of `x` to 1.
* On little-endian systems, `x` is stored as bytes `[127, 1, 0, 0]` → decimal `383`.

---

## Problem 2. Checking Sign Bit Using `char*`

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

**Output:** `
```
hello
```

**Explanation:**

* n = 404 → stored in memory as bytes: [148, 1, 0, 0] (since 404 in hex = 0x0194).
* b points to the first byte (least significant byte) = 148.
* *b < 0 checks if the first byte is negative.
* On most systems, char is signed, so 148 is interpreted as -108.
* Condition is true → prints "hello".
---

## Problem 3. Invalid Pointer Assignment

```c
#include<stdio.h>
int main()
{
    int *i = (int*)255;
    printf("%p", i);
}
```

**Output:** 
```
0xff
```

**Explanation:**

* i = (int*)255 → pointer initialized with address 255 (not a valid memory location in normal programs).
* printf("%p", i); prints the pointer value (the address).
* This does not dereference i, so no crash occurs.

---

## Problem 4. Void Pointer Dereference (Error)

```c
#include<stdio.h>
int main()
{
    int a = 13;
    void *p = &a;
    // printf("%d", *p); // Error: cannot dereference void*
}
```
**Output:**
```
Error
```
**Explanation:**

* `void*` has no data type, so dereferencing requires a cast: `printf("%d", *(int*)p);`

---

## Problem 5. What is the difference between int *const p and int const *p

# int *const p
* p is a constant pointer to an int.
* The address stored in p cannot change.
* The value at that address can change.
```
int a = 10, b = 20;
int *const p = &a;   // p always points to a
*p = 15;             // OK (value at a changes)
p = &b;              // ❌ Error (p cannot change address)
```

# int const *p (same as const int *p)

* p is a pointer to a constant int.
* The value at that address cannot change through p.
* The address stored in p can change.
```
int a = 10, b = 20;
int const *p = &a;   // p points to a
*p = 15;             // ❌ Error (cannot modify a through p)
p = &b;              // OK (p can point to b)
```

---

## Problem 6. Size of Pointers

```c
#include<stdio.h>
int main()
{
    printf("%d\n", sizeof(int *));
    printf("%d\n", sizeof(char *));
    printf("%d\n", sizeof(double *));
}
```

**Output:**
On 64-bit system

```
8
8
8
```

**Explanation:**
* The size of a pointer depends on the system architecture (not on the type it points to).

* On a 32-bit system, all pointers are 4 bytes.

* On a 64-bit system, all pointers are 8 bytes.

---

## Problem 7. Pointer Arithmetic on `void*`

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

**Output:** `
```
0x9 0xd 0x6
```

**Explanation:**

* Pointer arithmetic depends on type size.
* `(int*)p + 1` adds 4 bytes → 5 + 4 = 9.
* `(long int*)p + 1` adds 8 bytes → 5 + 8 = 13.
* `(char*)p + 1` adds 1 byte → 5 + 1 = 6.

---

## Problem 8. How do you declare a pointer that can store the address of a float variable?

* A pointer that can store the address of a float must be declared as float *.
```
#include<stdio.h>
int main()
{
    float f = 3.14;
    float *p = &f;   // p stores the address of f

    printf("Value = %.2f\n", *p);   // prints 3.14
}
```

---

## Problem 9. Short Pointer to Int 

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

**Output:** 
```
200
```

**Explanation:**

* p = 200 → hex = 0x00C8 → bytes [200, 0, 0, 0]
* a = (short int*)&p → points to first two bytes of p.
* ++a → moves pointer to the next short (second two bytes of p).
* *a = 0 → sets those two bytes to 0.
* Now bytes of p = [200, 0, 0, 0] → decimal still 200.
  
---

## Problem 10. Short Pointer to Char (Undefined Behavior)

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

**Output (likely):** 
```
Random integer value

```

**Explanation:**

* a and b are two separate char variables.
* C does not guarantee that b is stored right after a in memory.
* short int *pt = (short int*)&a; treats memory starting at a as a 2‑byte short integer.
* Because memory layout is compiler-dependent, the second byte read by *pt is unpredictable (could be padding or another variable’s data).
* Therefore, the value of *pt is indeterminate — it will give random values depending on compiler, optimization, and memory layout.

---

## Problem 11. Invalid Pointer Assignments

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

**Output:** 
```
0x1c
0x1d

```

**Explanation:**

* Pointer arithmetic depends on the size of the type the pointer points to.
# First part:
* p = (int*)20; → p points to address 20.
* p + 2 → moves the pointer by 2 × sizeof(int) bytes.
* On most systems, sizeof(int) = 4 bytes → p + 2 moves by 8 bytes.
* So address becomes: 20 + 8 = 28.
# Second part:
* q = (short int*)23; → q points to address 23.
* q + 3 → moves the pointer by 3 × sizeof(short int) bytes.
* sizeof(short int) = 2 bytes → moves by 6 bytes.
* So address becomes: 23 + 6 = 29.

---

## Problem 12. Short Pointer Manipulation

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

a = 45 → hex 0x002D → bytes [0x2D, 0x00].

p = (char*)&a → points to first byte (0x2D).

*++p = 2;

++p moves pointer to second byte of a (MSB).

Sets second byte to 2 → bytes now [0x2D, 0x02].

printf("%d\n", *--p);

--p moves pointer back to first byte → *p = 0x2D = decimal 45.

Prints 45.

*p = 5;

First byte set to 5 → bytes now [0x05, 0x02].

Final value of a:

Little-endian: 0x0205 → decimal 517.

---

## Problem 13. Void Pointer Increment

```c
#include<stdio.h>
int main()
{
    int i = 56;
    void *ptr = &i;
    printf("%p", ++((char*)ptr));
}
```

**Output:** 
```
error: lvalue required as increment operand
```

**Explanation:**

* In C, the ++ operator requires an lvalue (a modifiable object with an address).
* (char*)ptr is a cast expression → it produces a temporary value, not a variable.
* You cannot increment a cast expression directly because it’s not an lvalue.

---

## Problem 14. Pointer Subtraction

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

**Output:** 
```
-4
```

**Explanation:**

* x and y are local variables, stored on the stack.
* On most systems, stack grows downward, so y is stored at a lower address than x.
* Example addresses (hypothetical):

* &x = 0x1008  
* &y = 0x1004
* p = (char*)&x → points to the first byte of x.
* q = (char*)&y → points to the first byte of y.
* q - p → (address of y) - (address of x) = 0x1004 - 0x1008 = -4.

---

## Problem 15. Short Pointer to Int Manipulation

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

**Output:** 
```
92
```

**Explanation:**

* x = 370 → bytes [0x72, 0x01, 0x00, 0x00].
* *p >>= 2 → first two bytes change → value becomes 92.
* *++p = 3 → second two bytes set to 3.
* *p >>= 2 → second two bytes become 0.
* Final bytes: [0x5C, 0x00, 0x00, 0x00] → decimal 92.

---

## Problem 16. Pointer Initialized with Integer

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
0x35 0x3
```

**Explanation:**

* '1' → ASCII value = 49.
* p = (int*)49 → pointer to address 49.
* p+1 → moves by sizeof(int) bytes (usually 4 bytes).
* → address = 49 + 4 = 53.
* q = (char*)2 → pointer to address 2.
* q+1 → moves by sizeof(char) = 1 byte.
* → address = 2 + 1 = 3.

---

## Problem 17. Modifying Integer via Char Pointer

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
2 514
```

**Explanation:**

num = 500 → hex = 0x01F4 → bytes [0xF4, 0x01, 0x00, 0x00].

ptr = (char*)&num → points to first byte of num.

Loop runs up to 4 times, checking if the byte pointed by ptr is not 0.

Iteration details:

i = 0 → *ptr = 0xF4 → not zero → set to 2 → bytes: [0x02, 0x01, 0x00, 0x00].

i = 1 → next byte 0x01 → not zero → set to 2 → bytes: [0x02, 0x02, 0x00, 0x00].

i = 2 → next byte 0x00 → zero → loop breaks.

Loop ran 2 times (i = 2).

Final bytes: [0x02, 0x02, 0x00, 0x00] → integer value = 0x0202 = 514.

---

## Problem 18. Dereferencing Invalid Pointer

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

**Output:** 
```
Undefined /segmentation fault
```
**Explanation:**

* Casting integers to pointers and dereferencing them without a valid allocated address leads to undefined behavior.

---

## Problem 19. Modifying Integer via Char Pointer

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
612
```

**Explanation:**

a = 100 → hex = 0x00000064 → bytes [0x64, 0x00, 0x00, 0x00].

p = &a → points to a.

(char*)p + 1 → points to second byte of a.

*((char*)p + 1) = 2 → sets second byte to 0x02.

Now bytes of a: [0x64, 0x02, 0x00, 0x00] → hex = 0x00000264.

This means a = 0x0264 = 612 decimal.

---

## Problem 20. What is void pointer(void*)?

**Explanation:**

* A void pointer is a special type of pointer that can hold the address of any data type, but it does not have a type itself.
* Because it is untyped, you cannot directly dereference it without casting it to a specific pointer type.

* Syntax: void *ptr;

# Example:
```
#include <stdio.h>

int main() {
    int a = 10;
    char b = 'A';

    void *ptr; // Void pointer declaration

    ptr = &a; // Point to int
    printf("Value of a = %d\n", *(int*)ptr); // Cast to int* to dereference

    ptr = &b; // Point to char
    printf("Value of b = %c\n", *(char*)ptr); // Cast to char* to dereference

    return 0;
}
```

# Output:
```
Value of a = 10
Value of b = A
```

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
1 260
```

**Explanation:**

x = 348 → hex = 0x015C.
Memory layout (4 bytes on little‑endian):
```
Byte0: 0x5C (92 decimal)
Byte1: 0x01
Byte2: 0x00
Byte3: 0x00
```

ptr = (char*)&x → points to Byte0.

*ptr++ = 4

Sets Byte0 to 0x04.

ptr++ moves ptr to Byte1.

New memory:
```
Byte0: 0x04
Byte1: 0x01
Byte2: 0x00
Byte3: 0x00
```

*(ptr+1) = 0

ptr is at Byte1 → ptr+1 points to Byte2.

Sets Byte2 to 0x00 (already 0, so no change here).

printf("%d %d", *ptr, x);

*ptr = Byte1 = 0x01 = decimal 1.

x now = bytes [0x04, 0x01, 0x00, 0x00] → 0x0104 = decimal 260.

---

## Problem 22. Null and Arbitrary Pointer Arithmetic

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
(nil)
0x74

```

**Explanation:**

double *p = NULL; → p is a pointer to double, initially pointing to NULL (address 0).

printf("%p\n", p); → prints 0x0 (NULL pointer).

p = (double*)100; → sets pointer p to address 100 (integer cast to pointer).

p+2 → moves pointer by 2 × sizeof(double) bytes.
On most systems, sizeof(double) = 8 bytes → moves by 16 bytes.
→ new address = 100 + 16 = 116.

---

## Problem 23. Pointer and Byte-Level Modifications

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

**Output:** 
```
4 0

```
**Explanation:**

x = 200 → hex = 0x00C8.

Memory layout (4 bytes):
```
Byte0: 0xC8 (200 decimal)
Byte1: 0x00
Byte2: 0x00
Byte3: 0x00
```

p = (char*)&x → points to first byte.

q = (short*)&x → points to first 2 bytes of x.

*(p+1) = 3 → sets Byte1 to 0x03.

Memory:
```
Byte0: 0xC8
Byte1: 0x03
Byte2: 0x00
Byte3: 0x00
````

*q++ = 4

*q = first short (Byte0 + Byte1) = 0x03C8 → overwritten to 4 (hex 0x0004).

This changes Byte0 and Byte1:
```
Byte0: 0x04
Byte1: 0x00
Byte2: 0x00
Byte3: 0x00
```

Then q++ → moves q to next short (Byte2).

*(q+1) = 0

q now points to Byte2; q+1 points to Byte4 (out of x’s range — part of undefined behavior).

It writes 0 at that location. May not affect x depending on memory layout.

printf("%d %d", *p, *q);

*p = Byte0 = 0x04 = 4.

*q = short starting at Byte2 = 0x0000 = 0.

---

## Problem 24. Accessing Bytes via Void Pointer

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
0 1
```

**Explanation:**

x = 400 → hex = 0x00000190.
Memory layout (4 bytes on little‑endian system):
```
Byte0: 0x90 (144 decimal)
Byte1: 0x01 (1 decimal)
Byte2: 0x00 (0 decimal)
Byte3: 0x00 (0 decimal)
```

ptr = &x → void* pointing to x.

(char*)ptr+2 → moves pointer to Byte2 of x.

Byte2 = 0x00 = decimal 0.

(char*)ptr+1 → moves pointer to Byte1 of x.

Byte1 = 0x01 = decimal 1.

printf("%d %d", *((char*)ptr+2), *((char*)ptr+1));
→ prints: 0 1.

---

## Problem 25. Short Pointer to Int (Undefined Behavior)

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

**Output:** 
```
5 0
```

**Explanation:**

x = 556 → hex = 0x022C.

y = 557 → hex = 0x022D.

Variables x and y are stored consecutively in memory (stack).
Memory layout (little‑endian, assuming 2 bytes per short int):
```
Byte0: lower byte of x  
Byte1: higher byte of x  
Byte2: lower byte of y  
Byte3: higher byte of y
```

p = (int*)&x → p now points to both x and y as a single int.

*p = 15 → overwrites both x and y bytes with 15 (hex 0x0000000F).

New memory:
```
Byte0: 0x0F  
Byte1: 0x00  
Byte2: 0x00  
Byte3: 0x00
```

→ x = 0x000F = 15, y = 0x0000 = 0.

printf("%d %d", x, y); → prints: 15 0

---

## Problem 26. Right Shift via Char Pointer

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
-24
```

**Explanation:**

n = 416 → hex: 0x000001A0

Little-endian memory layout (4 bytes):
```
Byte0: 0xA0 (160 decimal)
Byte1: 0x01
Byte2: 0x00
Byte3: 0x00
```

b = (char*)&n → points to Byte0 (value = 0xA0).

*b = *b >> 2:

*b is of type char.

On most systems, char is signed, so 0xA0 = -96 (signed decimal).

Right-shifting a signed value preserves the sign (arithmetic shift).

-96 >> 2 = -24


So, *b becomes -24 (0xE8 in hex).

printf("%d", *b):

Prints the signed value of *b, which is -24.

---

## Problem 27. Invalid Void Pointer Dereference

```c
#include<stdio.h>
int main()
{
    int x = 157;
    void *q = &x;
    printf("%p", (int*)*q);
}
```

**Output:** 
```
error: invalid use of void expression

```
**Explanation:**

int x = 157; → x is stored somewhere in memory.

void *q = &x; → q points to x.

(int*)*q → problem:

*q tries to dereference a void*.

void* is an incomplete type, meaning you cannot dereference it directly in C.

This will cause a compile-time error.

---

## Problem 28. Mixed Pointer Types

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

**Output:** 

```
Error
```

**Explanation:**

The error happens because:

short int *q = &r;

Here, r is of type int, and &r is of type int*. You cannot directly assign an int* to a short int* without casting, because the pointer types are incompatible.

---

## Problem 29. Void Pointer and Casting

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

int t = 290;
Decimal 290 → hex = 0x0122.

Memory layout (little‑endian, 4 bytes):
```
Byte0: 0x22 (34 decimal)
Byte1: 0x01 (1 decimal)
Byte2: 0x00
Byte3: 0x00
```

void *u = &t;
→ u points to t.

*(char*)u

Casts u to char* → points to Byte0.

Byte0 = 0x22 = decimal 34.

*(int*)u

Casts u to int* → points to entire t.

Value = 290.

---

## Problem 30. Unsigned Char Pointer to Negative Int

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

int a = -3;

In two’s complement (32-bit), -3 is stored as:

0xFFFFFFFD


Little‑endian memory layout (4 bytes):
```
Byte0: 0xFD (253 decimal)
Byte1: 0xFF
Byte2: 0xFF
Byte3: 0xFF
```

unsigned char *p = (unsigned char*)&a;

Casts &a to unsigned char*, pointing to Byte0.

*p

Reads first byte (Byte0) = 0xFD = decimal 253 (unsigned).

printf("%d", *p);

Prints 253.

---

## Problem 31. Masking Integer Byte

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

## Problem 32. Character Pointer Manipulation

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

## Problem 33. Size of Variable Using Pointer

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

## Problem 34. Pointer Arithmetic Beyond Char

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

## Problem 35. Print Short Integer in Binary Using Pointer

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

## Problem 36. Pointer Subtraction

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

## Problem 37. Size of Pointer and Dereferenced Value

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

## Problem 38. Constant Pointer Arithmetic (Invalid)

```c
#include<stdio.h>
int main()
{
    int const *x = 10;
    x += 10;
    printf("%p", x);
}
```

**Output:** 
```
Undefined / compiler error
```
**Explanation:**

* `int const* x = 10` invalid initialization. Cannot perform pointer arithmetic on literal.

---

## Problem 39. Modifying Integer Bytes via Char Pointer

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

**Output:** 
```
Depends on system, likely `g`
```
**Explanation:**

* Modifies each byte of integer. Third byte = ASCII of 'g'.

---

## Problem 40. Constant Char Pointer Modification (Invalid)

```c
#include<stdio.h>
int main()
{
    const char *pt = "a";
    *pt += 3;
    printf("%c", *pt);
}
```

**Output:** 
```
Compilation error
```
**Explanation:** Cannot modify value pointed to by `const char*`.

---

## Problem 41. Constant Pointer to Int (Invalid Assignment)

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

**Output:** 
```
Compilation error
```
**Explanation:** `t` is a constant pointer; cannot point to another variable.

---

## Problem 42. Invalid Pointer Type Conversion

```c
#include<stdio.h>
int main()
{
    char x = 20;
    int *p = (int*)&x;
    printf("%d", *p);
}
```

**Output:** 
```
Undefined / garbage
```
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

**Output:** 
```
Undefined / garbage
```
**Explanation:** Incremented pointer beyond valid memory.

---

## Problem 44. Pointer Arithmetic with Offset

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

## Problem 45. Pointer Subtraction Between Different Types

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

## Problem 46. Pointer Arithmetic with Short Int

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

**Output:** 
```
Undefined / garbage
```

**Explanation:** Pointer moves beyond valid memory of `x` and `y`.

---

## Problem 47. Char and Short Pointer Combination

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

**Output:** 
```
Depends on endianness, likely `1`
```
**Explanation:** Modifies pointer type and accesses overlapping memory.

---

## Problem 48. Sizeof with Char Pointer to Int

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

## Problem 49. Constant Pointer to Constant Int

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

## Problem 50. Set All Bits of Integer

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

[🔼 Back to Top](#c-pointers) | [⬅ Back to Table of Contents](README.md)

---

## The End
