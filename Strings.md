# Strings in C 

---

[🔽 Go to Bottom](#the-end) | [⬅ Back to Table of Contents](README.md)

---
## 1. Program to find the length of a string without using the built-in strlen() function.

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

## 3. Program to reverse a string and store it into another string 

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

## 4. Program to reverse a string in the same array (without using another array).

```c
#include <stdio.h>
#include <string.h>

int main() {
    char str[100],temp;
    int i, j, length;

    printf("Enter a string: ");
    scanf("%[^\n]", str);   // Reads input including spaces

    length = strlen(str);

    // Reverse in-place by swapping
    for (i = 0, j = length - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }

    printf("Reversed string: %s\n", str);

    return 0;
}

```

**Output:**

```
Enter a string: Welcome To C
Reversed string: C oT emocleW

```

---

## 5. Program to change the case of alphabets in a string.

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

## 6. Program to count the number of alphabets, digits, and special characters in a string.

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

## 7. Program to count the frequency of each character in a string.

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

## 8. Program to check whether a string is a palindrome or not.

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

## 9. Program to reverse the words in a given string.

```c
#include <stdio.h>
#include <string.h>

int main() {
    char str[200];
    int i, start, end;

    printf("Enter a string: ");
    scanf("%[^\n]", str);   // Read input including spaces

    end = strlen(str) - 1;

    printf("Reversed (word by word):\n");

    for (i = end; i >= 0; i--) {
        // When we reach a space or start of string → word boundary
        if (str[i] == ' ' || i == 0) {
            // Word starts from i (if i==0) else i+1
            start = (i == 0) ? 0 : i + 1;

            // Print the word
            for (int j = start; j <= end; j++) {
                printf("%c", str[j]);
            }
            printf(" ");

            // Update end to character before current space
            end = i - 1;
        }
    }

    printf("\n");
    return 0;
}

```

**Output:**

```
Enter a string: I Love C Programming
Reversed (word by word):
Programming C Love I 

```

---

## 10. Program using to reverse each word in a given string while keeping the word order unchanged.

```c
#include <stdio.h>
#include <string.h>

int main() {
    char str[200];
    int i, j, start, end, len;

    printf("Enter a string: ");
    scanf("%[^\n]", str);   // read input including spaces

    len = strlen(str);

    for (i = 0; i <= len; i++) {
        // when space or end of string → end of a word
        if (str[i] == ' ' || str[i] == '\0') {
            end = i - 1;

            // reverse the word using a for loop
            for (j = start, end; j < end; j++, end--) {
                char temp = str[j];
                str[j] = str[end];
                str[end] = temp;
            }

            // move start to the next word
            start = i + 1;
        }
    }

    printf("Reversed (word by word):\n%s\n", str);

    return 0;
}

```

**Output:**

```
Enter a string: I Love C Programming
Reversed (word by word):
I evoL C gnimmargorP
```

---

## 11. Program to concatenate two strings with a space in between.
```c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[200], str2[100];

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    strcat(str1, " ");   // add space
    strcat(str1, str2);  // append str2

    printf("Concatenated string: %s\n", str1);

    return 0;
}

```

**Output:**
```
Enter first string: Good
Enter second string: Morning
Concatenated string: Good Morning
```

---

## 12. Program to compare two strings.

```c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    int result;

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    // strcmp returns:
    // 0   → strings are equal
    // < 0 → str1 is smaller than str2 (lexicographically)
    // > 0 → str1 is greater than str2
    result = strcmp(str1, str2);

    if (result == 0)
        printf("Strings are equal.\n");
    else if (result < 0)
        printf("First string is smaller than second.\n");
    else
        printf("First string is greater than second.\n");

    return 0;
}

```

**Output:**

```
Enter first string: Hello
Enter second string: Hello
Strings are equal.
```

---

## 13. Program to remove all duplicate characters from a string.

```c
#include <stdio.h>
#include <string.h>

int main() {
    char str[200];
    int i, j, k;
    int len;

    printf("Enter a string: ");
    scanf("%[^\n]", str);   // read full line including spaces

    len = strlen(str);

    // Traverse each character
    for (i = 0; i < len; i++) {
        for (j = i + 1; j < len; j++) {
            if (str[i] == str[j]) {
                // Shift all characters left by 1
                for (k = j; k < len; k++) {
                    str[k] = str[k + 1];
                }
                len--;   // decrease string length
                j--;     // recheck same index after shifting
            }
        }
    }

    printf("String after removing duplicates: %s\n", str);

    return 0;
}

```

**Output:**

```
Enter a string: Programming
String after removing duplicates: Progamin
```

---

## 14. Program to check if two strings are anagrams of each other.

```c
#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    int freq[256] = {0};   // frequency array for all ASCII characters
    int i;

    printf("Enter first string: ");
    scanf("%s", str1);

    printf("Enter second string: ");
    scanf("%s", str2);

    // If lengths differ → not anagrams
    if (strlen(str1) != strlen(str2)) {
        printf("Not Anagrams\n");
        return 0;
    }

    // Count frequency for str1
    for (i = 0; str1[i] != '\0'; i++) {
        freq[(unsigned char)str1[i]]++;
    }

    // Subtract frequency for str2
    for (i = 0; str2[i] != '\0'; i++) {
        freq[(unsigned char)str2[i]]--;
    }

    // Check if all counts are zero
    for (i = 0; i < 256; i++) {
        if (freq[i] != 0) {
            printf("Not Anagrams\n");
            return 0;
        }
    }

    printf("Anagrams\n");
    return 0;
}

```

**Output:**

```
Enter first string: listen
Enter second string: silent
Anagrams
```

---

## 15. Program to print the first non-repeating character in a string. 

```c
#include <stdio.h>
#include <string.h>

int main() {
    char str[200];
    int freq[256] = {0};  // frequency table for all ASCII characters
    int i;

    printf("Enter a string: ");
    scanf("%[^\n]", str);   // read input including spaces

    // Count frequency of each character
    for (i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;
    }

    // Find first character with frequency 1
    for (i = 0; str[i] != '\0'; i++) {
        if (freq[(unsigned char)str[i]] == 1) {
            printf("First non-repeating character: %c\n", str[i]);
            return 0;
        }
    }

    printf("No non-repeating character found.\n");
    return 0;
}
```

**Output:**

```
Enter a string: swiss
First non-repeating character: w
```

---

## 16. Program to extract numbers from a string and find their sum.  

```c
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
    char str[200];
    int i = 0, sum = 0;
    char num[20];   // to store digits of a number
    int j;

    printf("Enter a string: ");
    scanf("%[^\n]", str);  // read string with spaces

    while (str[i] != '\0') {
        if (isdigit((unsigned char)str[i])) {
            j = 0;
            // extract the full number
            while (isdigit((unsigned char)str[i])) {
                num[j++] = str[i++];
            }
            num[j] = '\0';
            sum += atoi(num);   // convert string to int and add
        } else {
            i++;
        }
    }

    printf("Sum of numbers in the string: %d\n", sum);
    return 0;
}

```

**Output:**

```
Enter a string: I have 12 apples and 8 oranges
Sum of numbers in the string: 20

```

---

## 17.Program to find the longest substring without repeating characters.

```c
#include <stdio.h>
#include <string.h>

int main() {
    char str[200];
    int lastIndex[256];   // stores last index of characters
    int i, start = 0, maxLen = 0, maxStart = 0;
    int len;

    printf("Enter a string: ");
    scanf("%[^\n]", str);

    len = strlen(str);

    // Initialize all lastIndex to -1
    for (i = 0; i < 256; i++)
        lastIndex[i] = -1;

    for (i = 0; i < len; i++) {
        unsigned char ch = (unsigned char)str[i];

        // If character seen before, update start
        if (lastIndex[ch] >= start)
            start = lastIndex[ch] + 1;

        // Update max length
        if (i - start + 1 > maxLen) {
            maxLen = i - start + 1;
            maxStart = start;
        }

        // Update last index of current character
        lastIndex[ch] = i;
    }

    printf("Longest substring without repeating characters: ");
    for (i = maxStart; i < maxStart + maxLen; i++)
        printf("%c", str[i]);
    printf("\nLength: %d\n", maxLen);

    return 0;
}

```

**Output:**

```
Enter a string: abcabcbb
Longest substring without repeating characters: abc
Length: 3

```

---

## 18. Program to remove all whitespaces (spaces, tabs) from a string.

```
#include <stdio.h>

int main() {
    char str[100], result[100];
    int i = 0, j = 0;

    printf("Enter a string: ");
    scanf(" %[^\n]s", str);  // Reads the whole line including spaces

    // Remove whitespaces
    while (str[i] != '\0') {
        if (str[i] != ' ' && str[i] != '\t') {
            result[j++] = str[i];
        }
        i++;
    }
    result[j] = '\0';

    printf("String without whitespaces: %s\n", result);

    return 0;
}

```

**Output:**
```
Enter a string: I   Love     C     Programming
String without whitespaces: ILoveCProgramming
```
---

## 19. Program to read a string from the user and removes all extra spaces, leaving only one space between words.

```
#include <stdio.h>

int main() 
{
    char str[200], result[200];
    int i = 0, j = 0;
    int flag = 0;  // 1 if previous char was space

    printf("Enter a string: ");
    scanf(" %[^\n]s", str);  // Read full line including spaces

    while (str[i] != '\0') 
    {
        if (str[i] != ' ') 
        {
            result[j++] = str[i];
            flag = 0;
        } else 
        {
            if (flag == 0) 
            { // first space
                result[j++] = ' ';
                flag = 1;
            }
            // else skip extra spaces
        }
        i++;
    }
    result[j] = '\0';

    printf("String with single spaces: %s\n", result);

    return 0;
}

```

**Output:**
```
Enter a string: I   Love     C     Programming
String with single spaces: I Love C Programming
```

---

[🔼 Back to Top](#strings-in-c) | [⬅ Back to Table of Contents](README.md)

---
## The End
