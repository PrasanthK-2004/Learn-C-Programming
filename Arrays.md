# Basic Programs in C 

---

[🔽 Go to Bottom](#the-end) | [⬅ Back to Table of Contents](README.md)

---
## 1. Program to print the first n Fibonacci numbers

```c
#include <stdio.h>

int main() {
    int n1 = 0, n2 = 1, next;
    int i, n;

    printf("Enter how many Fibonacci numbers to print: ");
    scanf("%d", &n);

    printf("First %d Fibonacci numbers:\n", n);

    for(i = 1; i <= n; i++) {
        printf("%d ", n1);
        next = n1 + n2;
        n1 = n2;
        n2 = next;
    }

    return 0;
}

```
**Output:**
```
Enter how many Fibonacci numbers to print: 10
First 10 Fibonacci numbers:
0 1 1 2 3 5 8 13 21 34
```
---
