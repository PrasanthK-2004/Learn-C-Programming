
# Bitwise Operators in C 

---

[🔽 Go to Bottom](#output) | [⬅ Back to Table of Contents](README.md)

---

## 1. Write a prorgram for the following one.
##    a) Set a bit      b) Clear a bit    c) Toggle a  bit  
 

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

## 2. WAP to find the given number is even or odd using bitwise operators  

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

## 3. WAP to find the given number is +ve or -ve using bitwise operators.  

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

## 4. WAP to swap two numbers using bitwise operators.  

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

## 5. WAP to find the given number is power of 2 or not.  

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

## 6. WAP to find the given number is divisble by 8 or not using bitwise operators  

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

## 7. Write a program to rotate the bits. Input  the no.of  rotations, at runtime.
    Ex : binary  :  10000000000000000000000000001011
       rotations : suppose 3 times right,  then
    	result   :  01110000000000000000000000000001

         binary  :  10000000000000000000000000001011
       rotations : suppose 4 times left,  then
	      result :   00000000000000000000000010111000
 

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

## 8. Convert the characters Upper to Lower and Lower to Upper using bitwise operators.  

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
```

---

## 9. Write a program to reverse the bits of a given number. 
Note : not just reverse printing.

```c
#include <stdio.h>
int main() {
    unsigned int num = 5;   // 000...0101
    unsigned int rev = 0;

    for (int i = 0; i < 32; i++) {
        rev <<= 1;          // shift result left
        rev |= (num & 1);   // copy LSB of num
        num >>= 1;          // shift num right
    }

    printf("Reversed Bits: %u\n", rev);
    return 0;
}
```

**Output**
```
Reversed Bits: 2684354560
```
---

## 10. Write a one line code to compare two numbers equal or not using bitwise operators.  

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

## 11. Write a program to print float binay formation using char *ptr. 

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

## 12. Write a program to swap the adjucent bytes of  a given 4-digit hexadecimal number.
      Ex : given number  = 0x1234;
	       after swap    = 0x3412;
  

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
    int num, pos, n;

    printf("Enter number: ");
    scanf("%d", &num);

    printf("Enter position to start deleting bits: ");
    scanf("%d", &pos);

    printf("Enter number of bits to delete: ");
    scanf("%d", &n);

    int mask1 = (1 << pos) - 1;               // keep lower bits (below pos)
    int mask2 = ~((1 << (pos + n)) - 1);      // keep higher bits (above pos+n)
    int result = (num & mask1) | ((num & mask2) >> n);

    printf("Result after deleting bits: %d\n", result);

    return 0;
}

```
**Output**
```
Enter number: 127
Enter position to start deleting bits: 5
Enter number of bits to delete: 4
Result after deleting bits: 31

```
---

## 14. Write a programme for swapping first and last nibbles in a given integer.
      Ex: Suppose num = 10

      It's Binary is    0000000000000000000000000001010
      After swap        1010000000000000000000000000000
    

```c
#include <stdio.h>

int main() {
    unsigned int num;
    printf("Enter a number: ");
    scanf("%u", &num);

    unsigned int first = (num >> 28) & 0xF;   // extract highest nibble
    unsigned int last  = num & 0xF;           // extract lowest nibble
    unsigned int middle = num & 0x0FFFFFF0;   // keep middle 28 bits

    unsigned int result = (last << 28) | (first) | middle;

    printf("Original : %u (0x%X)\n", num, num);
    printf("After Swap: %u (0x%X)\n", result, result);

    return 0;
}

```
**Output**
```
Original : 10 (0xA)
After Swap: 2684354560 (0xA0000000)

```

---

## 15. Write a logic to extract  P bits from Posion N in an integer M  

```c
#include <stdio.h>

int main() {
    unsigned int M;
    int N, P;

    printf("Enter number M: ");
    scanf("%u", &M);

    printf("Enter starting position N: ");
    scanf("%d", &N);

    printf("Enter number of bits P to extract: ");
    scanf("%d", &P);

    // Create mask with P ones
    unsigned int mask = ((1U << P) - 1) << N;

    // Extract bits and shift to LSB
    unsigned int extracted = (M & mask) >> N;

    printf("Extracted %d bits from position %d: %u\n", P, N, extracted);

    return 0;
}

```
**Output**
```
Extracted 4 bits from position 3: 5

```
---

## 16. Write a macro to clear a bit at the position N in an integer M.  

```c
#include <stdio.h>

#define CLEAR_BIT(M, N) ((M) & ~(1U << (N)))

int main() {
    unsigned int num = 15; // binary: 1111
    int pos = 1;           // bit position to clear (0-based)

    unsigned int result = CLEAR_BIT(num, pos);

    printf("Original: %u\n", num);
    printf("After clearing bit %d: %u\n", pos, result);

    return 0;
}

```
**Output**
```
Original: 15 
After clearing bit 1: 13 

```

---

## 17. There are 48 bits are stored in an array of character buffer and store them into 2 integer variables.
 

```c
#include <stdio.h>

int main() {
    unsigned char buffer[6] = {0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC}; // example 48 bits
    unsigned int int1 = 0, int2 = 0;

    // Pack first 4 bytes (32 bits) into int1
    int1 = (buffer[0] << 24) | (buffer[1] << 16) | (buffer[2] << 8) | buffer[3];

    // Pack remaining 2 bytes into int2 (upper 16 bits) 
    int2 = (buffer[4] << 8) | buffer[5];

    printf("Buffer bytes: ");
    for(int i=0; i<6; i++)
        printf("%02X ", buffer[i]);
    printf("\n");

    printf("Integer 1: 0x%X\n", int1);
    printf("Integer 2: 0x%X\n", int2);

    return 0;
}

```

## Output
```
Buffer bytes: 12 34 56 78 9A BC 
Integer 1: 0x12345678
Integer 2: 0x9ABC

```
---
[🔼 Back to Top](#bitwise-operators-in-c) | [⬅ Back to Table of Contents](README.md)

---

<p align="center">
  .....The End.....
</p>

