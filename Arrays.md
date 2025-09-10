# Array Programs in C 

---

[🔽 Go to Bottom](#the-end) | [⬅ Back to Table of Contents](README.md)

---
## 1. Program to scan 5 integers into an array and display it.

```c
#include <stdio.h>

int main() {
    int arr[5];
    int i;

    // Input 5 integers
    printf("Enter 5 integers:\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }

    // Display the array
    printf("\nYou entered:\n");
    for (i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

```
**Output:**
```
Enter 5 integers:
10 25 30 45 50

You entered:
10 25 30 45 50

```

---

## 2. Program to read 5 integers into an array and print them in reverse order.

```c
#include <stdio.h>

int main() {
    int arr[5];
    int i;

    // Input 5 integers
    printf("Enter 5 integers:\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }

    // Display in reverse
    printf("\nArray in reverse order:\n");
    for (i = 4; i >= 0; i--) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

```

**Output:**
```
Enter 5 integers:
10 20 30 40 50

Array in reverse order:
50 40 30 20 10

```

---

## 3. program to reverse the elements of a given array. After reversing, display the array.

```c
#include <stdio.h>

int main() {
    int arr[10];
    int n, i, temp;

    // Input size of array
    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Reverse array in-place
    for (i = 0; i < n / 2; i++) {
        temp = arr[i];
        arr[i] = arr[n - 1 - i];
        arr[n - 1 - i] = temp;
    }

    // Display reversed array
    printf("\nArray after reversing:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

```

**Output:**
```
Enter number of elements in array: 6
Enter 6 integers:
10 20 30 40 50 60

Array after reversing:
60 50 40 30 20 10

```

---

## 4. Write a program to enter 10 elements into an array and check whether a given element is present in the array or not. If it is present, display how many times it occurs.

```c
#include <stdio.h>

int main() {
    int arr[10];
    int i, search, count = 0;

    // Input 10 integers
    printf("Enter 10 integers:\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    // Input element to search
    printf("\nEnter element to search: ");
    scanf("%d", &search);

    // Search and count
    for (i = 0; i < 10; i++) {
        if (arr[i] == search) {
            count++;
        }
    }

    // Display result
    if (count > 0) {
        printf("\n%d is present %d times in the array.\n", search, count);
    } else {
        printf("\n%d is not present in the array.\n", search);
    }

    return 0;
}

```

**Output:**
```
Enter 10 integers:
5 8 3 5 2 7 5 9 1 5

Enter element to search: 5

5 is present 4 time(s) in the array.

```

---

## 5. Program to check that given array is palindrome format or not.

```c
#include <stdio.h>

int main() {
    int arr[10];
    int n, i, flag = 1;

    // Input size of array
    printf("Enter number of elements in array: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Check palindrome array
    for (i = 0; i < n / 2; i++) {
        if (arr[i] != arr[n - 1 - i]) {
            flag = 0;
            break;
        }
    }

    // Display result
    if (flag == 1) {
        printf("\nThe array is a palindrome.\n");
    } else {
        printf("\nThe array is not a palindrome.\n");
    }

    return 0;
}

```

**Output:**
```
Enter number of elements in array: 5
Enter 5 integers:
1 2 3 2 1

The array is a palindrome.

```

---

## 6. Program to check whether each element present in an array is a palindrome number or not.

```c
#include <stdio.h>

int main() {
    int arr[5];
    int i;

    // Input array elements
    printf("Enter 5 integers:\n");
    for (i = 0; i < 5; i++) {
        scanf("%d", &arr[i]);
    }

    // Check palindrome for each element
    printf("\nChecking palindrome status of array elements:\n");
    for (i = 0; i < 5; i++) {
        int num = arr[i];
        int original = num;
        int reversed = 0, digit;

        while (num > 0) {
            digit = num % 10;
            reversed = reversed * 10 + digit;
            num /= 10;
        }

        if (original == reversed) {
            printf("%d is a palindrome\n", original);
        } else {
            printf("%d is not a palindrome\n", original);
        }
    }

    return 0;
}

```

**Output:**
```
Enter 5 integers:
121 345 454 787 90

Checking palindrome status of array elements:
121 is a palindrome
345 is not a palindrome
454 is a palindrome
787 is a palindrome
90 is not a palindrome

```

---

## 7. Program to find how many times each element is present in a given array. Display the frequency of each distinct element. 

```c
#include <stdio.h>

int main()
{
    int a[50];   // maximum size
    int i, j, c, n;

    // Get array size from user
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Get array elements from user
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Print array
    printf("\nArray elements:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    // Frequency calculation
    for (i = 0; i < n; i++)
    {
        // Check if element already appeared
        for (j = 0; j < i; j++) {
            if (a[i] == a[j])
                break;
        }

        // If element is new, count its occurrences
        if (j == i)
        {
            for (j = i + 1, c = 1; j < n; j++)
                if (a[i] == a[j])
                    c++;

            printf("%d ----> %d times\n", a[i], c);
        }
    }

    return 0;
}

```

**Output:**
```
Enter number of elements: 10
Enter 10 integers:
5 3 5 2 3 5 7 2 9 3

Array elements:
5 3 5 2 3 5 7 2 9 3 

5 ----> 3 times
3 ----> 3 times
2 ----> 2 times
7 ----> 1 time
9 ----> 1 time

```

---

## 8. Program to display only the repeated elements from a given array. The program should ignore unique elements and print only those values that occur more than once.

```c
#include <stdio.h>

int main()
{
    int a[50];
    int n, i, j, c;

    // Input array size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Print original array
    printf("\nArray elements:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    printf("\nRepeated elements:\n");

    // Check for repeated elements
    for (i = 0; i < n; i++) {
        // Check if already appeared
        for (j = 0; j < i; j++) {
            if (a[i] == a[j])
                break;
        }

        // If first time occurrence, count frequency
        if (j == i) {
            for (j = i + 1, c = 1; j < n; j++) {
                if (a[i] == a[j])
                    c++;
            }

            // Print only repeated elements
            if (c > 1) {
                printf("%d ", a[i]);
            }
        }
    }

    printf("\n");

    return 0;
}

```

**Output:**
```
Enter number of elements: 10
Enter 10 integers:
5 3 5 2 3 5 7 2 9 3

Array elements:
5 3 5 2 3 5 7 2 9 3 

Repeated elements:
5 3 2

```

---

## 9. Program in to copy all elements from one array into another array and display both arrays.

```c
#include <stdio.h>

int main()
{
    int a[50], b[50];
    int n, i;

    // Input size of array
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Copy elements from a[] to b[]
    for (i = 0; i < n; i++) {
        b[i] = a[i];
    }

    // Display original array
    printf("\nOriginal array (a):\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    // Display copied array
    printf("\nCopied array (b):\n");
    for (i = 0; i < n; i++) {
        printf("%d ", b[i]);
    }

    printf("\n");

    return 0;
}

```

**Output:**
```
Enter number of elements: 5
Enter 5 integers:
10 20 30 40 50

Original array (a):
10 20 30 40 50
Copied array (b):
10 20 30 40 50

```

---

## 10. Program in to find the number of even and odd numbers from the elements of a given array.

```c
#include <stdio.h>

int main()
{
    int a[50];
    int n, i, even = 0, odd = 0;

    // Input array size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Count even and odd numbers
    for (i = 0; i < n; i++) {
        if (a[i] % 2 == 0)
            even++;
        else
            odd++;
    }

    // Display results
    printf("\nNumber of even numbers: %d\n", even);
    printf("Number of odd numbers: %d\n", odd);

    return 0;
}

```

**Output:**
```
Enter number of elements: 8
Enter 8 integers:
10 25 30 47 50 61 72 83

Number of even numbers: 4
Number of odd numbers: 4

```

---

## 11. Program in to find the prime numbers from the elements of a given array. Display all prime numbers and also display the total count of prime numbers.

```c
#include <stdio.h>

int main()
{
    int a[50];
    int n, i, j, count, primeCount = 0;

    // Input array size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("\nPrime numbers in the array:\n");

    // Check each element
    for (i = 0; i < n; i++) {
        if (a[i] <= 1) continue;  // skip 0 and 1

        count = 1; // assume prime
        for (j = 2; j <= a[i] / 2; j++) {
            if (a[i] % j == 0) {
                count = 0; // not prime
                break;
            }
        }

        if (count == 1) {
            printf("%d ", a[i]);
            primeCount++;
        }
    }

    printf("\nTotal prime numbers: %d\n", primeCount);

    return 0;
}

```

**Output:**
```
Enter number of elements: 10
Enter 10 integers:
5 10 13 20 17 22 29 30 7 8

Prime numbers in the array:
5 13 17 29 7
Total prime numbers: 5

```

---

## 12. Program in to delete an element from an array based on its index (position). After deletion, shift the remaining elements and display the updated array.

```c
#include <stdio.h>

int main()
{
    int a[50];
    int n, i, pos;

    // Input array size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Input position to delete
    printf("Enter the index (position starting from 0) of element to delete: ");
    scanf("%d", &pos);

    if (pos < 0 || pos >= n) {
        printf("Invalid index!\n");
    } else {
        // Shift elements to left
        for (i = pos; i < n - 1; i++) {
            a[i] = a[i + 1];
        }
        n--;  // reduce array size

        // Display updated array
        printf("\nArray after deletion:\n");
        for (i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }

    return 0;
}

```

**Output:**

```
Enter number of elements: 6
Enter 6 integers:
10 20 30 40 50 60
Enter the index (position starting from 0) of element to delete: 2

Array after deletion:
10 20 40 50 60

```

---

## 13. Program in to insert an element into an array at a given index (position). After insertion, shift the remaining elements and display the updated array.

```c
#include <stdio.h>

int main()
{
    int a[50];
    int n, i, pos, ele;

    // Input array size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Input element and position
    printf("Enter the element to insert: ");
    scanf("%d", &ele);
    printf("Enter the index (position starting from 0) to insert at: ");
    scanf("%d", &pos);

    if (pos < 0 || pos > n) {
        printf("Invalid index!\n");
    } else {
        // Shift elements to right
        for (i = n; i > pos; i--) {
            a[i] = a[i - 1];
        }

        // Insert element
        a[pos] = ele;
        n++;  // increase array size

        // Display updated array
        printf("\nArray after insertion:\n");
        for (i = 0; i < n; i++) {
            printf("%d ", a[i]);
        }
        printf("\n");
    }

    return 0;
}

```

**Output:**
```
Enter number of elements: 5
Enter 5 integers:
10 20 30 40 50
Enter the element to insert: 25
Enter the index (position starting from 0) to insert at: 2

Array after insertion:
10 20 25 30 40 50

```

## 14. Program in to find the biggest (maximum) element from the elements of a given array.

```c
#include <stdio.h>

int main()
{
    int a[50];
    int n, i, max;

    // Input array size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Assume first element is the biggest
    max = a[0];

    // Compare with other elements
    for (i = 1; i < n; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }

    // Display the biggest element
    printf("\nThe biggest element in the array is: %d\n", max);

    return 0;
}

```

**Output:**

```
Enter number of elements: 6
Enter 6 integers:
10 25 5 40 30 15

The biggest element in the array is: 40

```

---

## 15. Program in to find the second largest (second biggest) element in a given array. The program should handle cases where the largest element may appear more than once.

```c
#include <stdio.h>

int main() {
    int a[50];
    int n, i;
    int max, secondMax;

    // Input array size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Initialize max and secondMax
    if (n < 2) {
        printf("Array must have at least 2 elements.\n");
        return 0;
    }

    if (a[0] > a[1]) {
        max = a[0];
        secondMax = a[1];
    } else {
        max = a[1];
        secondMax = a[0];
    }

    // Traverse the rest of the array
    for (i = 2; i < n; i++) {
        if (a[i] > max) {
            secondMax = max;
            max = a[i];
        } else if (a[i] > secondMax && a[i] != max) {
            secondMax = a[i];
        }
    }

    printf("\nThe second biggest element in the array is: %d\n", secondMax);

    return 0;
}

```

**Output:**

```
Enter number of elements: 6
Enter 6 integers:
10 25 5 40 30 15

The second biggest element in the array is: 30

```

---
[🔼 Back to Top](#array-programs-in-c) | [⬅ Back to Table of Contents](README.md)

---
## The End
---
