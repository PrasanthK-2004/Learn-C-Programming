# Sorting Algorithm in C 

---

[🔽 Go to Bottom](#the-end) | [⬅ Back to Table of Contents](README.md)

---
## 1. Bubble Sort

```c
#include <stdio.h>

int main() {
    int a[50];
    int n, i, j, temp;

    // Input array size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Bubble sort algorithm
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                // Swap
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    // Display sorted array
    printf("\nArray after Bubble Sort (ascending order):\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}

```

**Output:**

```
Enter number of elements: 6
Enter 6 integers:
30 10 50 20 40 25

Array after Bubble Sort (ascending order):
10 20 25 30 40 50

```

---

## 1. Selection Sort

```c
#include <stdio.h>

int main() {
    int a[50];
    int n, i, j, minIndex, temp;

    // Input array size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Selection sort algorithm
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the minimum element with the first unsorted element
        temp = a[i];
        a[i] = a[minIndex];
        a[minIndex] = temp;
    }

    // Display sorted array
    printf("\nArray after Selection Sort (ascending order):\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}

```

**Output:**

```
Enter number of elements: 6
Enter 6 integers:
30 10 50 20 40 25

Array after Selection Sort (ascending order):
10 20 25 30 40 50

```

---

[🔼 Back to Top](#sorting-algorithm-in-c) | [⬅ Back to Table of Contents](README.md)

---
## The End
