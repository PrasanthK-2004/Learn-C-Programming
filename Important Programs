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

## 2. Program to print the Fibonacci series up to a number n.

```c
#include <stdio.h>

int main() {
    int n1 = 0, n2 = 1, next;
    int n;  // maximum number from user

    printf("Enter the maximum number for Fibonacci series: ");
    scanf("%d", &n);

    printf("Fibonacci series up to %d:\n", n);

    for(next = n1; next <= n; ) {
        printf("%d ", next);
        next = n1 + n2;
        n1 = n2;
        n2 = next;
    }

    return 0;
}
```

**Output:**
```
Enter the maximum number for Fibonacci series: 100
Fibonacci series up to 100:
0 1 1 2 3 5 8 13 21 34 55 89
```

## 3. Program to check whether a number entered by the user is prime or not.

```c
#include <stdio.h>

int main() {
    int n, i, isPrime = 1;

    // Get input from user
    printf("Enter a number: ");
    scanf("%d", &n);

    if(n <= 1) {
        isPrime = 0;  // 0 and 1 are not prime
    } else {
        // Check for factors from 2 to sqrt(n)
        for(i = 2; i * i <= n; i++) {
            if(n % i == 0) {
                isPrime = 0;  // Not prime
                break;
            }
        }
    }

    if(isPrime)
        printf("%d is a prime number.\n", n);
    else
        printf("%d is not a prime number.\n", n);

    return 0;
}
```

**Output:**
```
Enter a number: 17
17 is a prime number.
```
---
## 4.Program to print all prime numbers series between two numbers.

```c
#include <stdio.h>

int main() {
    int start, end, i, j, isPrime;

    // Input range from user
    printf("Enter the starting number: ");
    scanf("%d", &start);
    printf("Enter the ending number: ");
    scanf("%d", &end);

    printf("Prime numbers between %d and %d are:\n", start, end);

    for(i = start; i <= end; i++) {
        if(i <= 1) continue; // skip 0 and 1

        isPrime = 1; // assume i is prime

        for(j = 2; j < i; j++) {
            if(i % j == 0) {
                isPrime = 0; // not prime
                break;
            }
        }

        if(isPrime)
            printf("%d ", i);
    }

    return 0;
}
```
**Output:**
```
Enter the starting number: 10
Enter the ending number: 30
Prime numbers between 10 and 30 are:
11 13 17 19 23 29
```

---

## 5. 

```c
#include<stdio.h>   
int main()     
{     
int n, rem; 
int sum=0; 
int temp;   
printf("Enter number to check palindrome or not\n");     
scanf("%d",&n); 
temp = n;     
while(n>0)     
{     
rem = n%10;     
sum = (sum*10)+rem;     
n = n/10;     
}     
if(temp == sum)     
printf("Number is palindrome \n");     
else     
printf("Number is NOT palindrome\n");    
return 0;   
}
```
**Output:**
Case 1:
```
Enter number to check palindrome or not
121
Number is palindrome
```
Case 2:
```
Enter number to check palindrome or not
123
Number is NOT palindrome
```
---






