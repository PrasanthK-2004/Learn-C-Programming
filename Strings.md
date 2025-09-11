# Strings in C 

---

[🔽 Go to Bottom](#the-end) | [⬅ Back to Table of Contents](README.md)

---
## 1.Program to find the length of a string without using the built-in strlen() function.

```c
#include <stdio.h>

int main() {
    char str[100];
    int i, length = 0;

    printf("Enter a string: ");
    scanf("%[^\n]", str);   // Reads input including spaces until newline

    // Using for loop to count characters
    for (i = 0; str[i] != '\0'; i++)
    {
        length++;
    }

    printf("Length of the string = %d\n", length);

    return 0;
}

```

**Output:**

```
Enter a string: Welcome To C
Length of the string = 12

```

---

## 2. Program to reverse a string character by character

```c
#include <stdio.h>

int main() {
    char str[100];
    int i, length = 0;

    printf("Enter a string: ");
    scanf("%[^\n]", str);   // Reads input including spaces

    for (i = 0; str[i]; i++);// Dummy loop to find length

    printf("Reversed string: ");
    // Print characters in reverse order
    for (i = i - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }

    printf("\n");
    return 0;
}

```

**Output:**

```
Enter a string: Hello World
Reversed string: dlroW olleH

```

---

## 3. Program to reverse a string and print it.

```c
#include <stdio.h>

int main() {
    char str[100], rev[100];
    int i, j, length = 0;

    printf("Enter a string: ");
    scanf("%[^\n]", str);   // Reads input including spaces

    // Find length of string
    for (i = 0; str[i]; i++);

    // Reverse and store into another string
    for (i = length - 1, j = 0; i >= 0; i--, j++) {
        rev[j] = str[i];
    }
    rev[j] = '\0';  // Null terminate

    // Print the reversed string
    printf("Reversed string: %s\n", rev);

    return 0;
}

```

**Output:**

```
Enter a string: Welcome To C
Reversed string: C oT emocleW

```

---

## 4. Program to change the case of alphabets in a string.

```c
#include <stdio.h>

int main() {
    char str[100];
    int i;

    printf("Enter a string: ");
    scanf("%[^\n]", str);   // Reads input including spaces

    for (i = 0; str[i]; i++)
    {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
        {
            str[i] = str[i] ^ 32;   // toggle case using bitwise XOR
        }
    }

    printf("Case changed string: %s\n", str);

    return 0;
}

```

**Output:**

```
Enter a string: EmBeDdEd C
Case changed string: eMbEdDeD c

```

---

## 5. Program to count the number of alphabets, digits, and special characters in a string.

```c
#include <stdio.h>

int main() {
    char str[200];
    int i, alphabets = 0, digits = 0, special = 0;

    printf("Enter a string: ");
    scanf("%[^\n]", str);   // Reads input including spaces

    for (i = 0; str[i]; i++)
  {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
        {
            alphabets++;
        }
        else if (str[i] >= '0' && str[i] <= '9')
        {
            digits++;
        }
        else {
            special++;
        }
    }

    printf("Alphabets: %d\n", alphabets);
    printf("Digits: %d\n", digits);
    printf("Special characters: %d\n", special);

    return 0;
}

```

**Output:**

```
Enter a string: Hello123@C!
Alphabets: 6
Digits: 3
Special characters: 2

```

---

## 6. Program to count the frequency of each character in a string.

```c
#include <stdio.h>

int main() {
    char str[200];
    int freq[26] = {0};   // Only 26 alphabets
    int i;

    printf("Enter a string: ");
    scanf("%[^\n]", str);   // Reads input including spaces

    // Count alphabets
    for (i = 0; str[i]; i++) 
    {
        if (str[i] >= 'A' && str[i] <= 'Z') 
        {
            freq[str[i] - 'A']++;   // Map A-Z → 0–25
        }
        else if (str[i] >= 'a' && str[i] <= 'z') 
        {
            freq[str[i] - 'a']++;   // Map a-z → 0–25
        }
    }

    // Print results
    printf("\nAlphabet frequencies:\n");
    for (i = 0; i < 26; i++) 
    {
        if (freq[i] > 0) 
        {
            printf("%c : %d\n", i + 'A', freq[i]);
        }
    }

    return 0;
}

```

**Output:**

```
Enter a string: Hello World
Alphabet frequencies:
D : 1
E : 1
H : 1
L : 3
O : 2
R : 1
W : 1

```

---

## 7. Program to check whether a string is a palindrome or not.

```c
#include <stdio.h>
#include <string.h>

int main() {
    char str[100];
    int i, length, flag = 1;

    printf("Enter a string: ");
    scanf("%[^\n]", str);

    length = strlen(str);

    for (i = 0; i < length / 2; i++) {
        if (str[i] != str[length - i - 1]) {
            flag = 0;
            break;
        }
    }

    if (flag == 1)
        printf("Palindrome\n");
    else
        printf("Not Palindrome\n");

    return 0;
}

```

**Output:**

```
Enter a string: malayalam
Palindrome

```

---

[🔼 Back to Top](#strings-in-c) | [⬅ Back to Table of Contents](README.md)

---
## The End
