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

## Function Parameters: What to Pass By

### The Rule of Thumb

| Type | Pass By | Example |
|---|---|---|
| Fundamental types (`int`, `double`, `char`, `bool`) | Value | `void foo(int x)` |
| Class types (`std::string`, `std::vector`, structs) | `const` reference | `void foo(const std::string& s)` |
| Need to modify the original | Non-const reference | `void foo(int& x)` |

### Why

| Pass By Value | Pass By Const Reference |
|---|---|
| Makes a copy — safe, but slow for large objects | No copy — fast, and can't accidentally modify |
| Best for small types (int, double, char) | Best for strings, vectors, and structs |

### Other Cases

**Pass by value:**
- Enumerated types
- Views and spans (`std::string_view`, `std::span`)
- Cheap-to-copy class types (`std::pair`, `std::optional`)

**Pass by reference:**
- Arguments that need to be modified by the function
- Non-copyable types (`std::ostream`, `std::unique_ptr`)
- Types with virtual functions (to avoid object slicing)

### Strings Specifically

Prefer `std::string_view` (by value) for read-only string parameters, unless you need a C-style string or a `std::string` object.

### When in Doubt

Pass by `const` reference. It's always safe and avoids unexpected copies.

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

---## Floating-Point Comparison Safety

Floating-point numbers (`float`, `double`) can't represent every decimal value exactly. The computer stores the closest approximation, creating tiny rounding errors.

### The Problem
```cpp
double a{0.1 + 0.2};  // Might be 0.30000000000000004, not exactly 0.3
double b{0.3};

if (a == b)  // ❌ May fail due to tiny difference
```

### Why Precision Varies by Type

| Type | Typical Size | Significant Digits |
|---|---|---|
| `float` | 4 bytes | ~7 digits |
| `double` | 8 bytes | ~15-16 digits |
| `long double` | 8-16 bytes | ~18+ digits |

`double` is the default choice for most calculations.

## Inline Functions

An inline function is a hint to the compiler: "Instead of calling this function, copy its code directly to where it's called."

```cpp
inline int add(int x, int y)
{
    return x + y;
}
```

The compiler may or may not honor the hint. Modern compilers inline automatically when beneficial. Use `inline` only when defining functions in header files to avoid linker errors.

## Loops

Loops repeat a block of code multiple times. C++ has three loop types.

### While Loop
Repeats **while** a condition is true. Checks the condition first — may run zero times.

```cpp
while (condition)
{
    // body executes as long as condition is true
}
```

**Use when:** You don't know how many iterations you need.

### Do-While Loop
Like `while`, but checks the condition **after** the body. Always runs at least once.

```cpp
do
{
    // body executes first, then condition is checked
} while (condition);
```

**Use when:** The code must run at least once.

### For Loop
Runs a specific number of times. Initialization, condition, and increment all in one line.

```cpp
for (initialization; condition; increment)
{
    // body executes each iteration
}
```

**Example:**
```cpp
for (int i{0}; i < 10; ++i)
{
    std::cout << i << ' ';  // prints 0 1 2 ... 9
}
```

**Use when:** You know how many times to loop.

### Choosing the Right Loop

| Loop | Use When |
|---|---|
| `while` | Unknown number of iterations, condition-driven |
| `do-while` | Must execute at least once |
| `for` | Known number of iterations (arrays, strings, ranges) |

### Common Pattern: Looping Through a String
```cpp
std::string word{"hello"};
for (int i{0}; i < word.length(); ++i)
{
    // word[i] gives each character in order
}
```

### Loop Control: `break`, `continue`, and `return`

| Keyword | What It Does | Exits What? |
|---|---|---|
| `break` | Exits the loop immediately | The loop only — code after the loop still runs |
| `continue` | Skips the rest of this iteration, goes to next | Nothing — loop keeps running |
| `return` | Exits the entire function | The function — no code after it runs |

**Examples:**

```cpp
for (int i{0}; i < 10; ++i)
{
    if (i == 5)
        break;       // Loop ends at i=5. Code after loop runs.
    
    if (i == 3)
        continue;    // Skips printing 3, but loop continues to 4, 5...
    
    std::cout << i;  // Prints 0 1 2 4 (3 skipped, stops at 5)
}
// break sends you here
```
## Pointers

A pointer stores a memory address.

| Concept | Syntax | Meaning |
|---|---|---|
| Declare pointer | `int* p{&x};` | p holds x's address |
| Dereference | `*p = 5;` | Change x through p |
| Null pointer | `int* p{nullptr};` | Points to nothing — always initialize |
| Address-of | `&x` | Gets x's memory address |

### Pointer and Const

| Type | Change Value? | Change Address? |
|---|---|---|
| `int*` | ✅ | ✅ |
| `const int*` | ❌ | ✅ |
| `int* const` | ✅ | ❌ |
| `const int* const` | ❌ | ❌ |

### References vs Pointers

| | Reference (`&`) | Pointer (`*`) |
|---|---|---|
| Reassignable | ❌ No | ✅ Yes |
| Can be null | ❌ No | ✅ Yes — `nullptr` |
| Syntax to access | Just use name | Dereference `*p` |
| Safety | Safer | More dangerous |

## Function Parameters: In, Out, In/Out

| Role | Syntax | Direction |
|---|---|---|
| In (read only) | `int x` or `const int& x` | Caller → Function |
| Out (write) | `int& x` | Function → Caller |
| In/out (read + write) | `int& x` | Both directions |

## Structs

A struct is a custom type that bundles multiple variables together.

### Defining a Struct
```cpp
struct Point
{
    double x{0.0};   // default member initializer
    double y{0.0};
};
```
### Creating Instances
```cpp
Point origin{};           // defaults: x=0.0, y=0.0
Point center{5.0, 3.0};   // overrides: x=5.0, y=3.0
Point copy{center};       // copy of center
```
### Accessing Members
```cpp
std::cout << center.x;    // prints 5.0
center.y = 7.0;           // changes y to 7.0
```
### Passing Structs to Functions

| Parameter Type | When to Use |
|---|---|
| `Point p` | Small struct, need a copy |
| `const Point& p` | Read-only, no copy — most common |
| `Point& p` | Function needs to modify the struct |

### Returning Structs
```cpp
Point makePoint(double x, double y)
{
    return {x, y};   // creates and returns a Point
}
```
Point p{makePoint(1.0, 2.0)};   // p receives the returned Point

### Key Rule
- Use `const Type&` for read-only struct parameters.
- Use `Type&` when the function modifies the struct.
- Return by value for new structs — it's safe and simple.