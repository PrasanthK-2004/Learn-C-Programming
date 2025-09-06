# C Pointers: Detailed Examples, Outputs, and Explanations

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
