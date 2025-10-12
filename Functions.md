# Functions in C 

---

[🔽 Go to Bottom](#the-end) | [⬅ Back to Table of Contents](README.md)

---

## 1. No Return Type (Void Function) without Arguments

```c
#include <stdio.h>

void greet();//Funtion Declaration (prototype)

int main() {
    greet(); // Call
    return 0;
}

// Definition
void greet() {
    printf("Hello!\n");
}
```

**Output:**

```
Hello!
```

---

## 2. No Return Type (Void Function) with Arguments

```c
#include <stdio.h>

void greetUser(char name[], int age); // Function declaration 

int main() 
{
    char name[50];
    int age;
    printf("Enter your name: ");
    scanf(" %[^\n]s", name);  // Read full line including spaces

    printf("Enter your age: ");
    scanf("%d", &age);

    greetUser(name, age); // Function call

    return 0;
}

void greetUser(char name[], int age) // Function definition
{
    printf("Hello %s! You are %d years old.\n", name, age);
}

```

**Output:**

```
Enter your name: Prasanth
Enter your age: 21
Hello Prasanth! You are 21 years old.
```

---

## 3. Return Type without Arguments

```c
#include <stdio.h>

int getNumber();// Function declaration 

int main() 
{
    int num;

    num = getNumber();// Function call

    printf("You entered: %d\n", num);

    return 0;
}

int getNumber() // Function definition
{
    int x;
    printf("Enter a number: ");
    scanf("%d", &x);
    return x;
}

```

**Output:**

```
Enter a number: 100
You entered: 100
```

---

## 4. Return Type with Arguments

```c
#include <stdio.h>

int addNumbers(int a, int b);// Function declaration 

int main()
{
    int num1, num2, sum;
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    sum = addNumbers(num1, num2);// Function call

    printf("Sum = %d\n", sum);
    return 0;
}

int addNumbers(int a, int b) // Function definition
{
    return a + b;
}

```

**Output:**

```
Enter first number: 10
Enter second number: 20
Sum = 30
```

---

## 5. Recursive Function 

* A recursive function is a function that calls itself to solve a problem.
* It must have a base case to stop recursion.
* Useful for problems that can be broken into smaller subproblems.

**Factorial of a Number:**

```c
#include <stdio.h>

int factorial(int n); // Function declaration

int main() 
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    int fact = factorial(num); //Function Call
    printf("Factorial of %d = %d\n", num, fact);

    return 0;
}

int factorial(int n) // Recursive function definition
{
    if (n == 0)      // Base case
        return 1;
    else
        return n * factorial(n - 1);  // Recursive call
}

```

**Output:**

```
Enter a number: 5
Factorial of 5 = 120
```

---

## 6. Inline Function

* An `inline function` is a function for which the compiler suggests substituting the function's code directly into the calling code, rather than performing a traditional function call.
* This process, known as `"inlining"` reduces the overhead of function calls by avoiding the need to push arguments onto the stack, transfer control to the function, and then return.
* While the inline keyword is a suggestion, the compiler ultimately decides whether to inline a function based on factors like function size and optimization settings.
* We can use the `static` keyword before the `inline function`. This forces the compiler to treat the function with internal linkage and ensures that it is considered during the linking process, allowing the program to compile and run successfully.
* Though the inlining still depends on the compiler’s optimization level.

### Square of a Number
```c
#include <stdio.h>

static inline int square(int x) // Inline function declaration and definition
{
    return x * x;
}

int main() 
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("Square = %d\n", square(num));  // Function call replaced by code
    return 0;
}


```

**Output:**

```
Enter a number: 5
Square = 25
```

---

## 7. Program to design a basic calculator using functions.

```c
#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

float divide(int a, int b) {
    return (float)a / b;
}

int modulus(int a, int b) {
    return a % b;
}
int main() 
{
    int num1, num2, choice;
    
    printf("Enter first number: ");
    scanf("%d", &num1);
    printf("Enter second number: ");
    scanf("%d", &num2);

    printf("\nChoose operation:\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Modulus\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice) {
        case 1:
            printf("Result: %d + %d = %d\n", num1, num2, add(num1, num2));
            break;
        case 2:
            printf("Result: %d - %d = %d\n", num1, num2, subtract(num1, num2));
            break;
        case 3:
            printf("Result: %d * %d = %d\n", num1, num2, multiply(num1, num2));
            break;
        case 4:
            if(num2 != 0)
                printf("Result: %d / %d = %.2f\n", num1, num2, divide(num1, num2));
            else
                printf("Error: Division by zero!\n");
            break;
        case 5:
            if(num2 != 0)
                printf("Result: %d %% %d =  %d\n", num1, num2, modulus(num1, num2));
            else
                printf("Error: Division by zero!\n");
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}



```

**Output:**

```
Enter first number: 10
Enter second number: 5

Choose operation:
1. Addition
2. Subtraction
3. Multiplication
4. Division
5. Modulus
Enter your choice: 2
Result: 10 - 5 = 5
```

---

## 8.

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

---

[🔼 Back to Top](#functions-in-c) | [⬅ Back to Table of Contents](README.md)

---
## The End
