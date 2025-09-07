
# Bitwise Operators in C 

---

## 1. Set, Clear, and Toggle a Bit  

```c
#include <stdio.h>

int main() {
    int num = 10, pos = 1; // Binary: 1010

    // a) Set a bit
    int setBit = num | (1 << pos);

    // b) Clear a bit
    int clearBit = num & ~(1 << pos);

    // c) Toggle a bit
    int toggleBit = num ^ (1 << pos);

    printf("Original : %d\n", num);
    printf("Set Bit at %d : %d\n", pos, setBit);
    printf("Clear Bit at %d : %d\n", pos, clearBit);
    printf("Toggle Bit at %d : %d\n", pos, toggleBit);

    return 0;
}
```

**Output**
```
Original : 10
Set Bit at 1 : 10
Clear Bit at 1 : 8
Toggle Bit at 1 : 8
```

---

## 2. Check Even or Odd  

```c
#include <stdio.h>
int main() {
    int num = 7;
    if (num & 1)
        printf("%d is Odd\n", num);
    else
        printf("%d is Even\n", num);
    return 0;
}
```

**Output**
```
7 is Odd
```

---

## 3. Positive or Negative  

```c
#include <stdio.h>
int main() {
    int num = -12;
    if (num >> 31 & 1)
        printf("%d is Negative\n", num);
    else
        printf("%d is Positive\n", num);
    return 0;
}
```

**Output**
```
-12 is Negative
```

---

## 4. Swap Two Numbers  

```c
#include <stdio.h>
int main() {
    int a = 5, b = 9;
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    printf("After Swap: a = %d, b = %d\n", a, b);
    return 0;
}
```

**Output**
```
After Swap: a = 9, b = 5
```

---

## 5. Check Power of 2  

```c
#include <stdio.h>
int main() {
    int num = 16;
    if (num && !(num & (num - 1)))
        printf("%d is Power of 2\n", num);
    else
        printf("%d is NOT Power of 2\n", num);
    return 0;
}
```

**Output**
```
16 is Power of 2
```

---

## 6. Divisible by 8  

```c
#include <stdio.h>
int main() {
    int num = 40;
    if ((num & 7) == 0)
        printf("%d is divisible by 8\n", num);
    else
        printf("%d is NOT divisible by 8\n", num);
    return 0;
}
```

**Output**
```
40 is divisible by 8
```

---

## 7. Bit Rotation  

```c
#include <stdio.h>
#define INT_BITS 32

unsigned int rotateRight(unsigned int n, unsigned int d) {
    return (n >> d) | (n << (INT_BITS - d));
}

unsigned int rotateLeft(unsigned int n, unsigned int d) {
    return (n << d) | (n >> (INT_BITS - d));
}

int main() {
    unsigned int num = 11; // binary: 000...1011
    int d = 2;

    printf("Original number : %u\n", num);
    printf("Right Rotate %u by %d : %u\n", num, d, rotateRight(num, d));
    printf("Left Rotate %u by %d : %u\n", num, d, rotateLeft(num, d));

    return 0;
}

```
**Output**
```
Original number : 11
Right Rotate 11 by 2 : 3221225474
Left Rotate 11 by 2 : 44
```

---

## 8. Upper to Lower and Lower to Upper  

```c
#include <stdio.h>
int main() {
    char c1 = 'a', c2 = 'Z';

    c1 = c1 ^ 32; // toggle case
    c2 = c2 ^ 32;

    printf("Before Converted: %c\n",c1);
    printf("After Converted: %c\n",c2);
    return 0;
}
```
**Output**
```
Before Converted: A
After Converted: a

---

## 9. Reverse Bits  

```c
#include <stdio.h>
unsigned int reverseBits(unsigned int num) {
    unsigned int rev = 0;
    for (int i = 0; i < 32; i++) {
        rev <<= 1;
        rev |= (num & 1);
        num >>= 1;
    }
    return rev;
}

int main() {
    unsigned int num = 5; // 000...0101
    printf("Reversed Bits: %u\n", reverseBits(num));
    return 0;
}
```
**Output**
```
Reversed Bits: 2684354560
```
---

## 10. One-Line Compare  

```c
#include <stdio.h>
int main() {
    int a = 10, b = 20;
    printf("%s\n", !(a ^ b) ? "Equal" : "Not Equal");
    return 0;
}
```
**Output**
```
Not Equal
```
---

## 11. Print Float Binary Formation  

```c
#include <stdio.h>

int main() {
    float f = 5.75;
    unsigned int *p = (unsigned int *)&f;  // interpret float bits as int

    printf("Float: %f\nBinary: ", f);

    for (int i = 31; i >= 0; i--) {   // 32 bits
        printf("%d", (*p >> i) & 1);
        if (i % 8 == 0) printf(" "); // spacing every byte
    }

    printf("\n");
    return 0;
}

```
**Output**
```
Float: 5.750000
Binary: 01000001 10111000 00000000 00000000
```
---

## 12. Swap Adjacent Bytes  

```c
#include <stdio.h>
int main() {
    unsigned int num = 0x1234;
    unsigned int swapped = ((num & 0xFF) << 8) | ((num & 0xFF00) >> 8);
    printf("0x%X -> 0x%X\n", num, swapped);
    return 0;
}
```

**Output**
```
0x1234 -> 0x3412
```

---

## 13. Delete Bits from Position  

```c
#include <stdio.h>
int main() {
    int num = 100, pos = 4, n = 2;
    int mask1 = (1 << pos) - 1;
    int mask2 = ~((1 << (pos + n)) - 1);
    int result = (num & mask1) | ((num & mask2) >> n);
    printf("Result : %d\n", result);
    return 0;
}
```
**Output**
```
Result : 20
```
---

## 14. Swap First and Last Nibbles  

```c
#include <stdio.h>
int main() {
    unsigned int num = 10;
    unsigned int first = num & 0xF;
    unsigned int last = (num >> 28) & 0xF;
    unsigned int middle = num & 0x0FFFFFF0;
    unsigned int result = (first << 28) | (last) | middle;
    printf("Result: %X\n", result);
    return 0;
}
```
**Output**
```
0000000A  →  A0000000
```

---

## 15. Extract P Bits from Position N  

```c
#include <stdio.h>
int main() {
    int M = 0b110101101, N = 3, P = 4;
    int mask = ((1 << P) - 1) << N;
    int result = (M & mask) >> N;
    printf("Extracted Bits: %d\n", result);
    return 0;
}
```
**Output**
```
Extracted Bits: 5
```
---

## 16. Macro to Clear a Bit  

```c
#include <stdio.h>
#define CLEAR_BIT(M,N) (M & ~(1 << N))

int main() {
    int num = 15;
    printf("After Clear : %d\n", CLEAR_BIT(num, 1));
    return 0;
}
```
**Output**
```
After Clear : 13
```

---

## 17. Store 48 bits into Two Integers  

```c
#include <stdio.h>
#include <string.h>

int main() {
    unsigned char buf[6] = {0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC};
    unsigned int high = 0, low = 0;

    memcpy(&high, buf, 4);
    memcpy(&low, buf + 4, 2);

    printf("High = 0x%X\n", high);
    printf("Low  = 0x%X\n", low);

    return 0;
}
```

**Output**
```
High = 0x78563412
Low  = 0xBC9A
```
