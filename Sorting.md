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

## 2. Selection Sort

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

## 3. Insertion Sort

```c
#include <stdio.h>

int main() {
    int a[50];
    int n, i, j, key;

    // Input array size
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // Input array elements
    printf("Enter %d integers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Insertion sort algorithm
    for (i = 1; i < n; i++) {
        key = a[i];
        j = i - 1;

        // Move elements of a[0..i-1] that are greater than key one position ahead
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }

    // Display sorted array
    printf("\nArray after Insertion Sort (ascending order):\n");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}

```

**output:**

```
Enter number of elements: 6
Enter 6 integers:
30 10 50 20 40 25

Array after Insertion Sort (ascending order):
10 20 25 30 40 50

```

---

## 4. Merge Sort

```c
#include <stdio.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Bottom-up Merge Sort (iterative, no functions)
    int curr_size;  // size of subarrays to merge
    int left_start; // starting index of left subarray

    for (curr_size = 1; curr_size <= n - 1; curr_size = 2 * curr_size) {
        for (left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
            int mid = left_start + curr_size - 1;
            int right_end = (left_start + 2 * curr_size - 1 < n - 1) ? left_start + 2 * curr_size - 1 : n - 1;

            // Merge two subarrays arr[left_start..mid] and arr[mid+1..right_end]
            int n1 = mid - left_start + 1;
            int n2 = right_end - mid;
            int L[n1], R[n2];
            for (int i = 0; i < n1; i++)
                L[i] = arr[left_start + i];
            for (int j = 0; j < n2; j++)
                R[j] = arr[mid + 1 + j];

            int i = 0, j = 0, k = left_start;
            while (i < n1 && j < n2) {
                if (L[i] <= R[j])
                    arr[k++] = L[i++];
                else
                    arr[k++] = R[j++];
            }

            while (i < n1)
                arr[k++] = L[i++];
            while (j < n2)
                arr[k++] = R[j++];
        }
    }

    printf("\nArray after Merge Sort (ascending order):\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

```

**output:**

```
Enter number of elements: 6
Enter 6 integers:
30 10 50 20 40 25

Array after Merge Sort (ascending order):
10 20 25 30 40 50

```

---

## 5. Quick Sort

```c
#include <stdio.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Quick Sort logic using iterative approach
    int stack[n];
    int top = -1;

    // Push initial values of low and high
    int low = 0, high = n - 1;
    stack[++top] = low;
    stack[++top] = high;

    while (top >= 0) {
        high = stack[top--];
        low = stack[top--];

        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                i++;
                int temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
            }
        }

        int temp = arr[i + 1]; arr[i + 1] = arr[high]; arr[high] = temp;
        int pi = i + 1;

        // Push left subarray
        if (pi - 1 > low) {
            stack[++top] = low;
            stack[++top] = pi - 1;
        }

        // Push right subarray
        if (pi + 1 < high) {
            stack[++top] = pi + 1;
            stack[++top] = high;
        }
    }

    printf("\nArray after Quick Sort (ascending order):\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

```

**output:**

```
Enter number of elements: 6
Enter 6 integers:
30 10 50 20 40 25

Array after Quick Sort (ascending order):
10 20 25 30 40 50

```

---

## 6. Heap Sort

```c
#include <stdio.h>

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        int parent = i;
        while (1) {
            int largest = parent;
            int left = 2 * parent + 1;
            int right = 2 * parent + 2;

            if (left < n && arr[left] > arr[largest])
                largest = left;
            if (right < n && arr[right] > arr[largest])
                largest = right;

            if (largest != parent) {
                int temp = arr[parent];
                arr[parent] = arr[largest];
                arr[largest] = temp;
                parent = largest;
            } else {
                break;
            }
        }
    }

    // Extract elements from heap
    for (int i = n - 1; i > 0; i--) {
        // Swap root with last element
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Heapify reduced heap
        int parent = 0;
        while (1) {
            int largest = parent;
            int left = 2 * parent + 1;
            int right = 2 * parent + 2;

            if (left < i && arr[left] > arr[largest])
                largest = left;
            if (right < i && arr[right] > arr[largest])
                largest = right;

            if (largest != parent) {
                int temp2 = arr[parent];
                arr[parent] = arr[largest];
                arr[largest] = temp2;
                parent = largest;
            } else {
                break;
            }
        }
    }

    // Display sorted array
    printf("\nArray after Heap Sort (ascending order):\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

```

**output:**

```
Enter number of elements: 6
Enter 6 integers:
30 10 50 20 40 25

Array after Heap Sort (ascending order):
10 20 25 30 40 50

```

---

[🔼 Back to Top](#sorting-algorithm-in-c) | [⬅ Back to Table of Contents](README.md)

---
## The End
