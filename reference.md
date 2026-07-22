# C++ Reference & Design Guide

## How to Start a Program Without Freezing

### The Problem
Staring at a blank file with a big goal ("build a password validator") causes paralysis. The fix: think first, code second.

### The Process

1. **Define the goal** — One sentence. What does the user get?
   - *"Tell the user if their password meets security requirements."*

2. **List requirements** — What must the program do? Each requirement becomes a function.
   - Check length (8+ characters)
   - Check for uppercase letter
   - Check for digit
   - Check for special character

3. **Break into functions** — One function per requirement.
   - `isLongEnough(password)` → bool
   - `hasUpperCase(password)` → bool
   - `hasDigit(password)` → bool
   - `hasSpecialChar(password)` → bool

4. **Sequence the steps** — What order does main() call things?
   - Get password → check length → check uppercase → check digit → check special → display results

5. **Outline main()** — Write comments first, then fill in code.
   - Start with `// get password from user`
   - Then `// call each check function`
   - Then `// display results`

6. **Implement one function at a time** — Build, test, commit. Then the next one.
   - Don't write all functions at once. Finish one, verify it works, move on.

### The Rule
**Never start typing until you know what function you're writing and what it should return.** The outline is your map. The function is just one small step.

## Operators

An operator is a symbol that performs an action on one or more operands (values).

### Arithmetic Operators
Used for math calculations.

| Operator | Symbol | Example | Result |
|---|---|---|---|
| Addition | `+` | `x + y` | Sum of x and y |
| Subtraction | `-` | `x - y` | Difference of x and y |
| Multiplication | `*` | `x * y` | Product of x and y |
| Division | `/` | `x / y` | Quotient of x and y |
| Remainder (modulus) | `%` | `x % y` | Remainder of x / y (integers only) |

**Key rules:**
- Integer division drops the decimal: `7 / 2` = `3`, not `3.5`
- Use `%` for even/odd checks: `number % 2 == 0` means even
- Compound assignment: `x += 5` is shorthand for `x = x + 5`

### Relational Operators
Used for comparing values. Return `true` or `false`.

| Operator | Meaning | Example |
|---|---|---|
| `==` | Equal to | `x == y` |
| `!=` | Not equal to | `x != y` |
| `<` | Less than | `x < y` |
| `>` | Greater than | `x > y` |
| `<=` | Less than or equal | `x <= y` |
| `>=` | Greater than or equal | `x >= y` |

**Key rules:**
- Don't use `==` with floating-point numbers (precision errors)
- Use `>=` or `<=` to include the boundary value
- `if (boolVar)` is cleaner than `if (boolVar == true)`

### Logical Operators
Used for combining or flipping conditions.

| Operator | Symbol | Example | Meaning |
|---|---|---|---|
| Logical NOT | `!` | `!x` | True if x is false |
| Logical AND | `&&` | `x && y` | True if BOTH are true |
| Logical OR | `||` | `x || y` | True if EITHER is true |

**Key rules:**
- `!` has high precedence — always parenthesize: `!(condition)`
- De Morgan's Law: `!(x && y)` equals `!x || !y`. Don't distribute `!` mentally. Just flip the whole condition.
- `&&` and `||` work anywhere a `bool` is expected (if, while, return, assignment)

### Conditional Operator (`?:`)
A compact if/else that returns a value.

**Example:** `int max = (x > y) ? x : y;`

**Key rules:**
- Both branches must return the same type
- Parenthesize the whole thing in compound expressions: `std::cout << (x > y ? x : y);`
- Best for simple value selection. Use `if`/`else` for complex logic.

## Parentheses Rules: `()`, `{}`, and `[]`

These three bracket types look similar but have completely different jobs. Using the wrong one causes compile errors.

### `()` — Parentheses
Used for **functions** — declaring them, calling them, and controlling expression order.

| Context | Example | What It Does |
|---|---|---|
| Function declaration | `int foo(int x)` | "foo takes an int parameter" |
| Function call | `foo(5)` | "Call foo with argument 5" |
| Grouping expressions | `(x + y) * z` | Forces addition before multiplication |
| Wrapping conditions | `if (x > 5)` | Required around if/while conditions |
| `static_cast` | `static_cast<double>(x)` | Type conversion |

### `{}` — Braces (Curly Brackets)
Used for **initialization** and **code blocks**.

| Context | Example | What It Does |
|---|---|---|
| Variable initialization | `int x{5}` | Creates x with value 5 (preferred modern style) |
| Empty initialization | `int x{}` | Creates x with default value (0) |
| Function body | `int foo() { return 5; }` | Contains the function's code |
| If/else blocks | `if (x) { ... }` | Contains conditional code |

**Key rule:** `std::string name{};` creates an empty string. `std::string name();` declares a FUNCTION — classic C++ gotcha. Always use `{}` for variables.

### `[]` — Square Brackets
Used for **indexing** into strings and arrays.

| Context | Example | What It Does |
|---|---|---|
| String indexing | `name[0]` | First character of the string |
| String indexing | `name[i]` | Character at position i |
| Arrays (later) | `arr[0]` | First element of an array |

**Key rule:** `name[0]` gives a character. `name(0)` tries to call name as a function — not the same thing.

---

## `const` vs `constexpr`

Both create values that can't be changed. The difference is **when** the value is known.

| Keyword | Meaning | When Value Is Set | Example |
|---|---|---|---|
| `const` | "Won't change after initialization" | Can be runtime (user input, calculation) | `const int x{userInput};` |
| `constexpr` | "Known at compile time" | Must be compile-time (literal, constexpr) | `constexpr double gravity{9.8};` |

### Key Rules
- All `constexpr` variables are implicitly `const`
- `constexpr` requires a compile-time constant initializer
- Use `const` by default. Use `constexpr` for true compile-time constants (physics values, fixed limits)
- Function parameters can be `const` but never `constexpr`

### Examples
```cpp
const int a{5};              // ✅ 5 is a literal
const int b{userInput};      // ✅ Value from user, locked after
constexpr int c{5};          // ✅ 5 is compile-time
constexpr int d{userInput};  // ❌ userInput not known at compile time 
```

## Floating-Point Comparison Safety

Floating-point numbers (`float`, `double`) can't represent every decimal value exactly. Just like 1/3 in decimal is 0.3333... with infinite digits, some simple decimals like 0.1 are infinite in binary. The computer stores the closest approximation, creating tiny rounding errors.

### The Problem
```cpp
double a{0.1 + 0.2};  // Might be 0.30000000000000004, not exactly 0.3
double b{0.3};

if (a == b)  // ❌ May fail due to tiny difference

### Why Precision Varies by Type

Each floating-point type has limited "space" for significant digits:

| Type | Typical Size | Significant Digits |
|---|---|---|
| `float` | 4 bytes | ~7 digits |
| `double` | 8 bytes | ~15-16 digits |
| `long double` | 8-16 bytes | ~18+ digits |

A `float` runs out of precision after about 7 digits — any extra digits are rounding noise. A `double` gives you roughly double the space before precision loss occurs. This is why `double` is the default choice for most calculations.

## Inline Functions

An inline function is a hint to the compiler: "Instead of calling this function, copy its code directly to where it's called." This can make programs faster by avoiding function call overhead.

### How It Works

```cpp
inline int add(int x, int y)  // inline keyword suggests inlining
{
    return x + y;
}

int main()
{
    int result{add(3, 5)};  // Compiler may replace this with: int result{3 + 5};
    return 0;
}