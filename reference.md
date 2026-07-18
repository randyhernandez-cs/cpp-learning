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
