# 📘 C Theory Questions with Explanations & Programs

This document covers important **C language theory questions**, detailed explanations, code examples, outputs, and notes.  
It is designed in **Markdown format** for GitHub.

---

## 🔹 1) What are the compilation stages and its commands?

In C, compilation happens in **four stages**.

| Stage          | File Produced | Command | Description |
|----------------|--------------|---------|-------------|
| Preprocessing  | `.i` file    | `gcc -E file.c -o file.i` | Expands macros, includes headers, removes comments. |
| Compilation    | `.s` file    | `gcc -S file.i -o file.s` | Converts preprocessed code into **assembly code**. |
| Assembly       | `.o` file    | `gcc -c file.s -o file.o` | Converts assembly into **object code**. |
| Linking        | Executable   | `gcc file.o -o file.out`  | Links object file with libraries → final program. |

### Flow
```
.c → Preprocessor (.i) → Compiler (.s) → Assembler (.o) → Linker → Executable
```

✅ Example:
```bash
gcc test.c -o test.out
./test.out
```

---

## 🔹 2) What are the types of errors that occur in C?

| Type of Error  | Description | Example |
|----------------|-------------|---------|
| Syntax Error   | Rule violation in grammar. | `if(x 5)` |
| Semantic Error | Meaning mistake, correct syntax. | Using undeclared variable. |
| Logical Error  | Runs but gives wrong output. | Using `a+b` instead of `a-b`. |
| Runtime Error  | Error while execution. | Division by zero. |
| Linker Error   | Missing definitions. | Declared but not defined function. |

---

## 🔹 3) What is code optimization? What are advantages?

**Code Optimization** → Improving program efficiency without changing output.

**Advantages:**
- Faster execution
- Less memory usage
- Energy efficiency (important for embedded systems)

✅ Example:
```c
inline int square(int x) {
    return x * x;
}
```

---

## 🔹 4) Program to set, clear, and complement a bit

```c
#include <stdio.h>
int main() {
    int num = 5;   // 0101
    int pos = 1;

    num = num | (1 << pos);  // Set
    printf("Set bit: %d\n", num);

    num = num & ~(1 << pos); // Clear
    printf("Clear bit: %d\n", num);

    num = num ^ (1 << pos);  // Toggle
    printf("Toggle bit: %d\n", num);

    return 0;
}
```

---

## 🔹 5) One-line code to compare two integers using bitwise

```c
int result = (a ^ b) ? 0 : 1;   // 1 if equal, 0 if not
```

---

## 🔹 6) Convert Lower to Upper and Upper to Lower using bitwise

```c
#include <stdio.h>
int main() {
    char ch;
    scanf("%c", &ch);

    if (ch >= 'a' && ch <= 'z')
        printf("%c\n", ch & ~32);
    else if (ch >= 'A' && ch <= 'Z')
        printf("%c\n", ch | 32);
    return 0;
}
```

---

## 🔹 7) What is typecasting? Types with example

**Typecasting** = Converting one data type to another.

- **Implicit (Type Conversion):** Compiler converts automatically.
- **Explicit (Type Casting):** Programmer specifies conversion.

✅ Example:
```c
int a = 5;
float b = (float)a / 2;  // Explicit
```

---

## 🔹 8) Format specifier to print address

```
%p
```

✅ Example:
```c
printf("%p", &x);
```

---

## 🔹 9) Restrictions of switch case

❌ You cannot use:
- `float` or `double` as case values
- Variables or expressions (only constant integral)
- `case x: ...` with duplicate values

✅ Only `int` or `char` constants allowed.

---

## 🔹 11) Program to satisfy both if and else (using goto)

```c
#include <stdio.h>
int main() {
    int x = 1;
    if (x)
        goto label;
    else
        goto label;

label:
    printf("Both if and else executed!\n");
    return 0;
}
```

---

## 🔹 12) Swap two integers using bitwise

```c
a = a ^ b;
b = a ^ b;
a = a ^ b;
```

---

## 🔹 13) Minimum no. of iterations for while loop?

✅ **0 iterations** (if condition is false at start).

---

## 🔹 14) What is volatile keyword?

- Tells compiler: *Don’t optimize this variable*.
- Used for **hardware registers, shared memory, interrupts**.

✅ Example:
```c
volatile int flag;
```

---

## 🔹 19) Difference between Arrays & Pointers

| Arrays | Pointers |
|--------|----------|
| Fixed size, contiguous memory | Can point to any memory |
| Name gives base address | Can be reassigned |
| `int arr[5]` | `int *p` |

---

## 🔹 20) sizeof(char *)

Answer: **Size of pointer = 4 bytes (32-bit) / 8 bytes (64-bit)**  
(Depends on architecture, not type).

---

## 🔹 21) Values of sizeof

a) `sizeof 123456` → `int` → typically 4 bytes  
b) `sizeof "123456"` → String literal of 7 chars (`6+1 null`) → 7 bytes

---

## 🔹 22) Array of Pointers

```c
char *arr[] = {"one", "two", "three"};
```

---

## 🔹 23) Pointer to an Array

```c
int arr[5];
int (*p)[5] = &arr;
```

---

## 🔹 24) Difference between Array of Pointers & Pointer to Array

| Array of Pointers | Pointer to Array |
|-------------------|------------------|
| Multiple pointers | Single pointer to whole array |
| `char *arr[5]` | `int (*p)[5]` |

---

## 🔹 25) Function & Advantages

**Function** = Block of code for a task.

**Advantages:**
- Code reuse
- Modularity
- Easy debugging

---

## 🔹 26) Call by Value vs Call by Reference

| Call by Value | Call by Reference |
|---------------|------------------|
| Copy passed | Address passed |
| Changes not reflected | Changes reflect |

---

## 🔹 27) Function Pointer & Advantage

Pointer storing address of function.

✅ Example:
```c
void hello() { printf("Hello"); }
void (*fp)() = hello;
fp();
```

Advantage: Callback mechanisms.

---

## 🔹 28) Command line arguments

Allow input at program run.

```c
int main(int argc, char *argv[])
```

✅ Example:
```bash
./a.out hello
```

---

## 🔹 29) By default command line arguments type?

✅ **Strings**

---

## 🔹 30) Storage Classes

| Storage Class | Scope | Lifetime | Default Value | Storage |
|---------------|-------|----------|---------------|---------|
| auto          | Block | Until block ends | Garbage | Stack |
| static        | Block | Until program ends | 0 | Data segment |
| register      | Block | Until block ends | Garbage | CPU register |
| extern        | Global | Until program ends | 0 | Data segment |

---

## 🔹 31) Default storage class

- Local variable → `auto`  
- Global variable → `extern`

---

## 🔹 32) Memory leak

Allocated memory not freed → waste.

---

## 🔹 33) Can register variable be global?

❌ No, only local.

---

## 🔹 34) Can we access address of register?

❌ Not guaranteed (compiler dependent).

---

## 🔹 35) Static function

Function with scope limited to file.

---

## 🔹 36) Default storage class of function

✅ `extern`

---

## 🔹 37) Recursion function

Function calls itself.  

**Advantages:** Elegant, reduces code.  
**Disadvantages:** Stack overhead, slower.

---

## 🔹 38) malloc vs calloc

| malloc | calloc |
|--------|--------|
| Allocates without init | Initializes to 0 |
| Single block | Multiple blocks |

---

## 🔹 39) Return type of malloc

✅ `void *`

---

## 🔹 40) Use of realloc

Resize allocated memory.

---

## 🔹 41) Allocate memory without malloc/calloc

✅ Using `alloca()` (stack allocation).

---

## 🔹 42) Free memory without free()

✅ By setting pointer to `NULL` (but better is `free()`).

---

## 🔹 43) Memory leak

(Same as Q32)

---

## 🔹 44) Dangling pointer

Pointer pointing to freed/deallocated memory.  
✅ Avoid by setting to `NULL`.

---

## 🔹 45) Structure & Array difference

Structure: Different data types.  
Array: Same type only.

---

## 🔹 46) Structure padding

Compiler adds bytes for alignment.  
✅ Use `#pragma pack(1)` to avoid.

---

## 🔹 47) Find sizeof structure without sizeof

```c
#define SIZEOF(var) ((char*)(&var+1) - (char*)(&var))
```

---

## 🔹 48) When memory is created for structure?

When variable is defined.

---

## 🔹 49) Return values of strcmp

- 0 if equal  
- <0 if str1 < str2  
- >0 if str1 > str2  

---

## 🔹 50) One-line code to copy string

```c
strcpy(dest, src);
```

---

## 🔹 51) Types of qualifiers

- `const`  
- `volatile`  
- `restrict`

---

## 🔹 52) Self-referential structure pointer

Structure containing pointer to itself.

```c
struct node {
    int data;
    struct node *next;
};
```

---

## 🔹 53) enum & Advantages

```c
enum color { RED, GREEN, BLUE };
```

Advantages: Readability, symbolic constants.

---

## 🔹 54) typedef & Advantages

Alias for type.

```c
typedef unsigned int uint;
```

Advantage: Readability.

---

## 🔹 55) FILE in C & Size

`FILE` = Structure for file handling.  
Size is implementation dependent.

---

## 🔹 56) Union & Advantages

Union = Shared memory for members.  
Adv: Efficient memory usage.

---

## 🔹 57) Structure vs Union

| Structure | Union |
|-----------|-------|
| All members have memory | Memory shared |
| Size = sum | Size = largest |

---

## 🔹 58) Macros vs Functions

| Macros | Functions |
|--------|-----------|
| Preprocessor replace | Runtime call |
| No type checking | Type checking |

---

## 🔹 59) #define vs typedef

| #define | typedef |
|---------|---------|
| Text replacement | Type alias |
| Preprocessor | Compiler |

---

## 🔹 60) Default file pointers

- `stdin`  
- `stdout`  
- `stderr`

---

## 🔹 61) strcpy vs memcpy

| strcpy | memcpy |
|--------|--------|
| For strings | For any data |
| Stops at `\0` | Copies exact bytes |

---

## 🔹 62) Header files vs Libraries

- Header: Function declarations, macros.  
- Library: Actual definitions (compiled code).  

---
