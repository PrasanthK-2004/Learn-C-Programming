# Data Types
---

[🔽 Go to Bottom](#c-operator-precedence-and-order-of-evaluation) | [⬅ Back to Table of Contents](README.md)

| Datatype        | Size (bytes) | Range (Typical)                                                                                                      | Format Specifier                       | Description                      |
| --------------- | ------------ | -------------------------------------------------------------------------------------------------------------------- | -------------------------------------- | -------------------------------- |
| `char`          | 1            | -128 to 127 (`signed`) <br> 0 to 255 (`unsigned`)                                                                    | `%c`                                   | Stores a single character        |
| `int`           | 4            | -2,147,483,648 to 2,147,483,647 (`signed`) <br> 0 to 4,294,967,295 (`unsigned`)                                      | `%d` (signed) <br> `%u` (unsigned)     | Stores integers                  |
| `short int`     | 2            | -32,768 to 32,767 (`signed`) <br> 0 to 65,535 (`unsigned`)                                                           | `%hd` (signed) <br> `%hu` (unsigned)   | Smaller integers                 |
| `long int`      | 4 or 8       | -2,147,483,648 to 2,147,483,647 (`signed 4B`) <br> 0 to 4,294,967,295 (`unsigned 4B`)                                | `%ld` (signed) <br> `%lu` (unsigned)   | Larger integers                  |
| `long long int` | 8            | -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 (`signed`) <br> 0 to 18,446,744,073,709,551,615 (`unsigned`) | `%lld` (signed) <br> `%llu` (unsigned) | Very large integers              |
| `float`         | 4            | 1.2E-38 to 3.4E+38 (approx)                                                                                          | `%f`                                   | Single-precision decimal numbers |
| `double`        | 8            | 2.3E-308 to 1.7E+308 (approx)                                                                                        | `%lf`                                  | Double-precision decimal numbers |
| `long double`   | 12 or 16     | 3.4E-4932 to 1.1E+4932 (approx)                                                                                      | `%Lf`                                  | Extended precision decimal       |


### ⚠Note:
1. Exact ranges may differ slightly depending on the compiler and platform. `sizeof()` can be used to check size in bytes at runtime.
2. Format specifiers must match the datatype exactly. Using the wrong specifier can lead to undefined behavior.
---

# C Operator Precedence and Order of Evaluation

This table shows C operators, their precedence, and associativity.

| Operator                            | Associativity  | Note |
|-------------------------------------|----------------|-------|
| `() [] -> . ++ --`                  | left to right  | [1]   |
| `! ~ ++ -- + - (type) * & sizeof`   | right to left  | [2]   |
| `* / %`                             | left to right  |       |
| `+ -`                               | left to right  |       |
| `<< >>`                             | left to right  |       |
| `< <= > >=`                         | left to right  |       |
| `== !=`                             | left to right  |       |
| `&`                                 | left to right  |       |
| `^`                                 | left to right  |       |
| `\|`                                | left to right  |       |
| `&&`                                | left to right  |       |
| `\|\|`                              | left to right  |       |
| `?:`                                | right to left  |       |
| `= += -= *= /= %= <<= >>= &= ^= \|=`| right to left  |       |
| `,`                                 | left to right  |       |

---
### ⚠Note:
1. The `++` and `--` operators at this precedence level are the **postfix** versions.  
2. The `++` and `--` operators at this precedence level are the **prefix** versions.  

---

[🔼 Back to Top](#data-types) | [⬅ Back to Table of Contents](README.md)

---
