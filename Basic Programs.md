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
        for(i = 2; i <= n / 2; i++) {
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

## 6. Program to reverse a number.

```c
#include <stdio.h>

int main() {
    int n, rem, reversed = 0;

    printf("Enter a number to reverse:\n");
    scanf("%d", &n);

    while(n > 0) {
        rem = n % 10;                     // get last digit
        reversed = (reversed * 10) + rem; // build reversed number
        n = n / 10;                     // remove last digit
    }

    printf("Reversed number is: %d\n", reversed);

    return 0;
}
```
**Output:**
```
Enter a number to reverse:
1234
Reversed number is: 4321
```
---

## 6. Check if number is palindrome or not 

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

## 7.  Find factorial of the number 

```c
#include<stdio.h>   
int main()     
{     
int i; 
int fact=1; 
int number;     
printf("Enter a number: \n");     
scanf("%d",&number);     
for(i = 1; i <= number; i++) 
{     
fact=fact*i;     
}     
printf("Factorial of %d is: %d\n",number,fact);     
return 0;   
} 
```

**Output:**
```
Enter a number: 
5
Factorial of 5 is: 120

```

---

## 8.  Check if a number is Armstrong number 

```c
#include<stdio.h>   
int main()     
{     
int n; 
int r; 
int sum=0; 
int temp;     
printf("Enter a number \n");     
scanf("%d",&n);     
temp=n;     
while(n>0)     
{     
r=n%10;     
sum=sum+(r*r*r);     
n=n/10;     
}     
if(temp == sum)     
printf("Number is a armstrong number\n");     
else     
printf("Number is NOT a armstrong number\n");     
return 0;   
} 
```

**Output:**
Case 1:
```
Enter a number 
153
Number is a armstrong number
```
Case 2:
```
Enter a number 
123
Number is NOT a armstrong number

```
---

## 9. program to print all Armstrong numbers within a given range
```c
#include <stdio.h>
#include <math.h>

int main() {
    int start, end, num, temp, r, sum;

    // Input range from user
    printf("Enter starting number: ");
    scanf("%d", &start);
    printf("Enter ending number: ");
    scanf("%d", &end);

    printf("Armstrong numbers between %d and %d are:\n", start, end);

    for(num = start; num <= end; num++) {
        temp = num;
        sum = 0;

        while(temp > 0) {
            r = temp % 10;
            sum += r * r * r; // cube of digit
            temp /= 10;
        }

        if(sum == num) {
            printf("%d ", num);
        }
    }

    return 0;
}

```

**Output:**
```
Enter starting number: 100
Enter ending number: 500
Armstrong numbers between 100 and 500 are:
153 370 371 407

```

---


## 10. Program to count the number of digits

```c
#include <stdio.h>

int main() {
    int n, count = 0;

    printf("Enter number:\n");
    scanf("%d", &n);

    if(n == 0) {
        count = 1; // 0 has 1 digit
    } else {
        while(n > 0) {
            count++;     // increment count
            n = n / 10; // remove last digit
        }
    }

    printf("Number of digits = %d\n", count);

    return 0;
}

```

**Output:**
```
Enter number:
12345
Number of digits = 5

```

---

## 11. Program to find sum of digits.

```c
#include<stdio.h>   
int main()     
{     
int n; 
int sum=0; 
int rem;     
printf("Enter number:\n");     
scanf("%d",&n);     
while(n>0)     
{     
rem = n%10;     
sum = sum+rem;     
n = n/10;     
}     
printf("Sum is = %d\n",sum);     
return 0;   
}

```

**Output:**
```
Enter number:
123
Sum is = 6

```

---

## 12. Program to swap numbers

**Using Three Variables:**
```c
#include <stdio.h>

int main() {
    int a, b, temp;

    printf("Enter two numbers:\n");
    scanf("%d %d", &a, &b);

    printf("Before swapping: a = %d, b = %d\n", a, b);

    // Swap using third variable
    temp = a;
    a = b;
    b = temp;

    printf("After swapping: a = %d, b = %d\n", a, b);

    return 0;
}

```
**Using Two Variables:**
```c
#include <stdio.h>

int main() {
    int a, b;

    printf("Enter two numbers:\n");
    scanf("%d %d", &a, &b);

    printf("Before swapping: a = %d, b = %d\n", a, b);

    // Swap without third variable
    a = a + b;  
    b = a - b;  
    a = a - b;  

    printf("After swapping: a = %d, b = %d\n", a, b);

    return 0;
}

```
**Using Bitwise:**
```c
#include <stdio.h>

int main() {
    int a, b;

    printf("Enter two numbers:\n");
    scanf("%d %d", &a, &b);

    printf("Before swapping: a = %d, b = %d\n", a, b);

    // Swap using bitwise XOR
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    printf("After swapping: a = %d, b = %d\n", a, b);

    return 0;
}

```

**Output:**
```
Enter two numbers:
5 10
Before swapping: a = 5, b = 10
After swapping: a = 10, b = 5

```

---

## 13. Program to print decimal to binary

```c
#include <stdio.h>

int main() {
    int n;
    int *p;

    printf("Enter a decimal number: ");
    scanf("%d", &n);

    p = &n; // pointer to the number

    printf("binary of %d is: ", n);

    for(int i = 31; i >= 0; i--) {
        printf("%d", (*p >> i) & 1); // shift and mask each bit
        if(i % 8 == 0) printf(" ");  
    }

    printf("\n");

    return 0;
}

```

**Output:**
```
Enter a decimal number: 13
32-bit binary of 13 is: 00000000 00000000 00000000 00001101 

```

---

## 14. Program to find greatest of 3 numbers 

```c
#include<stdio.h> 
int main() 
{ 
int num1,num2,num3; 
printf("\nEnter value of num1, num2 and num3:\n"); 
scanf("%d %d %d",&num1,&num2,&num3); 
if((num1>num2)&&(num1>num3)) 
printf("\n Number1 is greatest\n"); 
else if((num2>num3)&&(num2>num1)) 
printf("\n Number2 is greatest\n"); 
else 
printf("\n Number3 is greatest\n"); 
return 0; 
} 
```

**Output:**
```
Enter value of num1, num2 and num3:
12 18 40
Number3 is greatest

```

---

## 15. Program to get ascii value  

```c
#include <stdio.h> 
int main() 
{ 
char ch; 
printf("Enter character:\n"); 
scanf("%c", &ch); 
printf("ASCII value of character %c is: %d\n", ch, ch); 
return 0; 
} 
```

**Output:**
```
Enter character:
A
ASCII value of character A is: 65

```

---

## 16. Program to demonstrate sizeof function 

```c
#include<stdio.h> 
int main() 
{ 
printf("Size of char: %ld byte\n",sizeof(char)); 
printf("Size of int: %ld bytes\n",sizeof(int)); 
printf("Size of float: %ld bytes\n",sizeof(float)); 
printf("Size of double: %ld bytes\n", sizeof(double)); 
return 0; 
}
```

**Output:**
```
Size of char: 1 byte
Size of int: 4 bytes
Size of float: 4 bytes
Size of double: 8 bytes

```

---

## 17. Program to check whether a year is a leap year or not

```c
#include <stdio.h>

int main() {
    int year;

    printf("Enter a year: ");
    scanf("%d", &year);

    if((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
        printf("%d is a Leap Year\n", year);
    } else {
        printf("%d is NOT a Leap Year\n", year);
    }

    return 0;
}

```

**Output:**
Case 1:
```
Enter a year: 2024
2024 is a Leap Year
```
Case 2:
```
Enter a year: 1900
1900 is NOT a Leap Year

```

---

## 18. Print all leap years in a given range 
```c
#include <stdio.h>

int main() {
    int start, end;

    printf("Enter start year: ");
    scanf("%d", &start);

    printf("Enter end year: ");
    scanf("%d", &end);

    printf("Leap years between %d and %d are:\n", start, end);

    for(int year = start; year <= end; year++) {
        if((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
            printf("%d ", year);
        }
    }
    printf("\n");

    return 0;
}

```

**Output:**
```
Enter start year: 2000
Enter end year: 2024
Leap years between 2000 and 2024 are:
2000 2004 2008 2012 2016 2020 2024

```

---

## 19. Program toggle (convert) uppercase letters to lowercase and lowercase to uppercase using bitwise operators 

```c
#include <stdio.h>

int main() {
    char ch;

    printf("Enter a character: ");
    scanf("%c", &ch);

    // Toggle case using bitwise XOR with space (32)
    ch = ch ^ 32;

    printf("Opposite case: %c\n", ch);

    return 0;
}

```

**Output:**
```
Enter a character: A
Opposite case: a

```

---

## 20. Program calculate the power of a number 

```c
#include <stdio.h>

int main() {
    int base, exp;
    result = 1;

    printf("Enter base: ");
    scanf("%d", &base);

    printf("Enter exponent: ");
    scanf("%d", &exp);

    for(int i = 1; i <= exp; i++) {
        result = result * base;
    }

    printf("%d^%d = %d\n", base, exp, result);

    return 0;
}

```

**Output:**
```
Enter base: 2
Enter exponent: 5
2^5 = 32

```

---


## 21. Basic Calculator using switch

```c
#include <stdio.h>

int main() {
    char op;
    double num1, num2, result;

    printf("Enter an operator (+, -, *, /): ");
    scanf(" %c", &op);  // space before %c to ignore newline

    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);

    switch(op) {
        case '+':
            result = num1 + num2;
            printf("%.2lf + %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '-':
            result = num1 - num2;
            printf("%.2lf - %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '*':
            result = num1 * num2;
            printf("%.2lf * %.2lf = %.2lf\n", num1, num2, result);
            break;
        case '/':
            if(num2 != 0)
                printf("%.2lf / %.2lf = %.2lf\n", num1, num2, num1 / num2);
            else
                printf("Error! Division by zero.\n");
            break;
        default:
            printf("Invalid operator!\n");
    }

    return 0;
}

```

**Output:**
```
Enter an operator (+, -, *, /): +
Enter two numbers: 10 20
10.00 + 20.00 = 30.00

```

---


## 22. Program to print the multiplication table of a number

```c
#include <stdio.h>

int main() {
    int n;

    printf("Enter a number to print its multiplication table: ");
    scanf("%d", &n);

    printf("Multiplication table of %d:\n", n);

    for(int i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", n, i, n * i);
    }

    return 0;
}

```

**Output:**
```
Enter a number to print its multiplication table: 5
Multiplication table of 5:
5 x 1 = 5
5 x 2 = 10
5 x 3 = 15
5 x 4 = 20
5 x 5 = 25
5 x 6 = 30
5 x 7 = 35
5 x 8 = 40
5 x 9 = 45
5 x 10 = 50

```

---

## 23. Program to check whether a number is perfect number or not 

```c
#include <stdio.h>

int main() {
    int n, sum = 0;

    printf("Enter a number: ");
    scanf("%d", &n);

    for(int i = 1; i <= n/2; i++) {
        if(n % i == 0) {
            sum += i;
        }
    }

    if(sum == n && n != 0)
        printf("%d is a Perfect Number\n", n);
    else
        printf("%d is NOT a Perfect Number\n", n);

    return 0;
}

```

**Output:**
Case 1:
```
Enter a number: 28
28 is a Perfect Number

```
Case 2:

```
Enter a number: 20
20 is NOT a Perfect Number
```

---

## 24. Program to print all perfect numbers in a given range

```c
#include <stdio.h>

int main() {
    int start, end;

    printf("Enter start of range: ");
    scanf("%d", &start);

    printf("Enter end of range: ");
    scanf("%d", &end);

    printf("Perfect numbers between %d and %d are:\n", start, end);

    for (int n = start; n <= end; n++) {
        int sum = 0;

        for (int i = 1; i <= n / 2; i++) {
            if (n % i == 0) {
                sum += i;
            }
        }

        if (sum == n && n != 0) {
            printf("%d ", n);
        }
    }

    return 0;
}
```

**Output:**
```
Enter start of range: 1
Enter end of range: 1000
Perfect numbers between 1 and 1000 are:
6 28 496

```

---

## 26. Program to find Strong number or not

```c
#include <stdio.h>

int main() {
    int num, temp, sum = 0, r, fact, i;

    printf("Enter a number: ");
    scanf("%d", &num);

    temp = num;

    while (num > 0) {
        r = num % 10;

        // factorial of digit
        fact = 1;
        for (i = 1; i <= r; i++) {
            fact *= i;
        }

        sum += fact;
        num /= 10;
    }

    if (sum == temp)
        printf("%d is a Strong number\n", temp);
    else
        printf("%d is NOT a Strong number\n", temp);

    return 0;
}

```

**Output:**
Case 1:
```
Enter a number: 145
145 is a Strong number

```
Case 2:
```
Enter a number: 123
123 is NOT a Strong number

```

---

## 27. Program to Print a range of Strong numbers

```c
#include <stdio.h>

int main() {
    int start, end;

    printf("Enter start of range: ");
    scanf("%d", &start);

    printf("Enter end of range: ");
    scanf("%d", &end);

    printf("Strong numbers between %d and %d are:\n", start, end);

    for (int num = start; num <= end; num++) {
        int temp = num;
        int sum = 0;

        while (temp > 0) {
            int r = temp % 10;
            int fact = 1;

            // factorial of digit
            for (int i = 1; i <= r; i++) {
                fact *= i;
            }

            sum += fact;
            temp /= 10;
        }

        if (sum == num) {
            printf("%d ", num);
        }
    }

    return 0;
}

```

**Output:**
```
Enter start of range: 1
Enter end of range: 500
Strong numbers between 1 and 500 are:
1 2 145

```

---

## 

```c

```

**Output:**
```

```

---

## 

```c

```

**Output:**
```

```

---

## 

```c

```

**Output:**
```

```

---

## 

```c

```

**Output:**
```

```

---

## 

```c

```

**Output:**
```

```

---

## 

```c

```

**Output:**
```

```

---

## 

```c

```

**Output:**
```

```

---

## 

```c

```

**Output:**
```

```

---
[🔼 Back to Top](#basic-programs-in-c) | [⬅ Back to Table of Contents](README.md)

---
## The End

