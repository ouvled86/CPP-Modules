# Scalar Converter Notes

## Overview
- Purpose: Explain `modf()`, iostream formatting (`std::fixed`, `std::setprecision`, `unsetf`), and provide a clear guide to C++ casting styles and operators with differences and compiler handling.
- Context: References the usage in [cpp06/ex00/MiniScalarConverter.cpp](cpp06/ex00/MiniScalarConverter.cpp).

## `modf()`
- What it is: A C math function declared in `<cmath>` that splits a floating-point number into its integer and fractional parts.
- Signature: `double modf(double x, double* iptr)` (also overloads for `float` and `long double`).
- Behavior:
  - Returns the fractional part of `x` with the same sign as `x`.
  - Stores the integer part of `x` (truncated toward zero) into `*iptr`.
  - Example: `x = 3.14` → returns `0.14`, writes `3` to `*iptr`; `x = -2.5` → returns `-0.5`, writes `-2` to `*iptr`.
- Why we use it: To detect if a parsed numeric value is integral (fractional part equals `0.0`). This drives whether to print `.0`/`.0f`.
- Notes:
  - Floating-point precision: Comparing the fractional part to `0.0` is generally safe for literals and `strtod` results used here; for arbitrary computations, consider an epsilon if needed.

## Iostream Formatting: `std::fixed`, `std::setprecision`, `unsetf`
- Location in code: See fixed-point formatting in [MiniScalarConverter.cpp: float printing](cpp06/ex00/MiniScalarConverter.cpp#L179) and in the double printer nearby.
- `std::fixed`:
  - A stream manipulator that sets the floatfield to fixed-point notation.
  - With `fixed`, the number of digits after the decimal point is controlled by `std::setprecision(n)`.
  - Without `fixed`, `setprecision(n)` controls significant digits, and the stream may choose scientific notation for large/small magnitudes.
- `std::setprecision(1)`:
  - A stream manipulator that sets the precision of floating output.
  - With `fixed`, `setprecision(1)` prints exactly 1 digit after the decimal (e.g., `10.0`).
  - Without `fixed`, it sets significant digits (e.g., `std::cout << 3.14159` with `setprecision(3)` could print `3.14`).
- `std::cout.unsetf(std::ios::fixed)`:
  - Clears the `fixed` flag so later prints return to the default floatfield (which allows scientific or default formatting as the stream deems appropriate).
  - This is important to avoid unintentionally affecting subsequent prints in the same program run.
- Quick example:
  - Fixed mode: `std::cout << std::fixed << std::setprecision(1) << 3.14` → `3.1`
  - Default mode: `std::cout << std::setprecision(3) << 123456.0` → `1.23e+05` (significant digits, scientific)

## Casting in C++: Differences and Compiler Handling

### Categories
- Implicit conversions: Performed automatically by the compiler when safe and well-defined.
- Explicit conversions: You ask the compiler to convert (via cast operators or constructors).
- C-style casts: Legacy `(T)expr` or `T(expr)` syntax that attempts multiple conversions in one step.
- C++ cast operators: `static_cast`, `dynamic_cast`, `const_cast`, `reinterpret_cast` — each has clear intent and rules.

### Implicit Conversions
- What happens:
  - Numeric promotions and usual arithmetic conversions (e.g., `int` to `double` when mixing types).
  - Derived-to-base pointer/reference upcasts.
  - Array-to-pointer decay (`int arr[]` → `int*`).
- Compiler handling:
  - Always compile-time; no runtime checks.
  - May narrow silently (e.g., `double` to `int` in assignment), but compilers typically don’t warn by default in C++98 unless extra flags (`-Wconversion`) are enabled.
- Example:
  - `double d = 3.14; int i = d; // i == 3 (fraction discarded)`
  - `Derived* dp = new Derived; Base* bp = dp; // implicit upcast`

### Explicit Conversions (Constructors / Operators)
- What happens:
  - You request a conversion via a constructor or explicit cast operator (e.g., `std::string s = std::string(42)` or user-defined `operator int()`).
- Compiler handling:
  - Checked at compile time for availability and access; no runtime type identity checks.
- Example:
  - `int i = static_cast<int>(3.14); // explicit, clear intent`
  - `std::string s = std::string("42");`

### C-Style Cast `(T)expr`
- How it works:
  - Attempts a sequence of conversions under the hood (roughly: `const_cast`, then `static_cast`; if those fail, tries `reinterpret_cast`; and in some contexts a combination like `static_cast` to a base plus `const_cast`).
- Risks:
  - Can drop `const` or perform a reinterpret silently.
  - Harder to audit and reason about; minimal diagnostics.
- Example:
  - `int& r = (int&)someConstInt; // removes const-qualification; writing is UB if object is truly const`
  - `long* p = (long*)voidPtr; // potentially misaligned or aliasing-violating`

### C++ Cast Operators

- `static_cast<T>(expr)`
  - Purpose: Compile-time checked conversions following language rules (numeric, `void*`→typed, upcasts, some downcasts in non-polymorphic hierarchies).
  - Checks: Compile-time only; no runtime RTTI.
  - Pitfalls: Allows narrowing if requested; non-polymorphic downcasts can compile yet be undefined if the dynamic type doesn’t match.
  - Example: `double d = 3.9; int i = static_cast<int>(d);`

- `dynamic_cast<T>(expr)`
  - Purpose: Runtime-checked cast in polymorphic hierarchies (requires at least one virtual function in the base).
  - Behavior: Pointer form returns `nullptr` on failure; reference form throws `std::bad_cast`.
  - Uses RTTI; adjusts pointers correctly for multiple/virtual inheritance.
  - Example: `if (Derived* p = dynamic_cast<Derived*>(basePtr)) { /* safe */ }`

- `const_cast<T>(expr)`
  - Purpose: Add/remove `const`/`volatile` qualifiers.
  - Rule: Does not change the underlying object’s constness; writing through a casted pointer to a truly const object is undefined behavior.
  - Example: `legacy(char*); const char* s = "hi"; legacy(const_cast<char*>(s)); // only safe if legacy doesn’t write`

- `reinterpret_cast<T>(expr)`
  - Purpose: Low-level re-interpretation of bits/pointers.
  - Behavior: No safety guarantees; subject to aliasing, alignment, and platform-specific rules.
  - Use sparingly: Primarily for pointer ↔ integer roundtrips and byte-level access.
  - Example: `std::uintptr_t id = reinterpret_cast<std::uintptr_t>(ptr);`

### Summary of Differences
- Intent clarity:
  - Prefer explicit C++ casts (static/dynamic/const/reinterpret) over C-style casts to communicate purpose and get appropriate checks.
- Safety:
  - `dynamic_cast` is the only cast that checks object identity at runtime.
  - `static_cast` is safe for upcasts and well-defined numeric conversions; risky for unchecked downcasts.
  - `const_cast` only changes type qualifiers; misuse yields UB.
  - `reinterpret_cast` is inherently unsafe without deep platform knowledge.
- Diagnostics:
  - C-style casts can hide dangerous operations; C++ casts yield clearer compile-time errors and more readable intent.

## Quick Examples
- Upcast vs Downcast:
  - Upcast: `Base* b = derivedPtr; // implicit` or `static_cast<Base*>(derivedPtr)`.
  - Downcast (polymorphic): `Derived* d = dynamic_cast<Derived*>(basePtr); // runtime-checked`.
- Formatting switch:
  - Fixed once, then reset: `std::cout << std::fixed << std::setprecision(1) << 10.0 << "\n"; std::cout.unsetf(std::ios::fixed);`
- Fraction check:
  - `double ip; bool integral = (std::modf(value, &ip) == 0.0);`

## Final Guidance
- Use `modf()` to decide integral vs fractional for formatting, then restore stream state using `unsetf` to avoid side effects.
- Prefer explicit C++ casts with clear intent; use `dynamic_cast` for safe downcasts in polymorphic hierarchies.
- Avoid C-style casts except in tightly controlled, well-understood cases.
