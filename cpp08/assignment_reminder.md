# C++ Module 08 — Assignment Reminder

> **Theme**: Templated containers, iterators, and algorithms (STL)

---

## General Rules

| Rule | Details |
|---|---|
| Standard | **C++98** only |
| Compiler flags | `-Wall -Wextra -Werror -std=c++98` |
| Class form | Orthodox Canonical (default ctor, copy ctor, copy assign, destructor) |
| Forbidden | `malloc`, `free`, `printf`, `using namespace`, `friend`, Boost, C++11+ |
| Templates | May live in `.hpp` or `.tpp` — header inclusion is mandatory |
| Memory | Zero leaks allowed |

---

## Exercise 00 — Easy find

| Item | Requirement |
|---|---|
| Files | `Makefile`, `main.cpp`, `easyfind.hpp` (+ optional extras) |
| Function | `easyfind(T, int)` — templated, works with any integer container |
| Behavior | Find first occurrence of `int` in container `T` |
| Not found | Throw an exception **or** return an error value |
| **Critical** | **Must use STL algorithms** (`std::find`). Manual iterator loops = **fail** |

---

## Exercise 01 — Span

| Item | Requirement |
|---|---|
| Files | `Makefile`, `main.cpp`, `Span.{hpp,cpp}` |
| Constructor | `Span(unsigned int N)` — max capacity of N integers |
| `addNumber(int)` | Add one number, throw if full |
| `shortestSpan()` | Smallest absolute difference between any two stored numbers |
| `longestSpan()` | Largest difference (`max - min`) |
| Exceptions | Throw if < 2 elements stored |
| **Range insert** | Must provide a way to add many numbers at once via **iterator range** |
| **Testing** | Must test with **at least 10,000 numbers** |
| **Critical** | Use STL algorithms as much as possible |

---

## Exercise 02 — MutantStack

| Item | Requirement |
|---|---|
| Files | `Makefile`, `main.cpp`, `MutantStack.{hpp,tpp}` (or header-only) |
| Class | `MutantStack<T>` inheriting from `std::stack<T>` |
| Features | All `std::stack` member functions + **iterators** (`begin`, `end`) |
| Validation | Output must match an equivalent `std::list` using the same operations |
| **Testing** | Main must have **more tests** than the subject's example |

---

## Compliance Review of Your Code

### ✅ What's Good

- All three exercises compile with `-std=c++98` flags
- Correct use of `std::find` in ex00 (STL algorithm — required by correction sheet)
- `Span` class has Orthodox Canonical Form
- `shortestSpan()` correctly sorts then checks adjacent differences
- `longestSpan()` uses `max - min` approach
- `addRange()` method provided for bulk insertion
- `MutantStack` inherits from `std::stack` and exposes iterators via `this->c`

### ⚠️ Issues Found

#### Ex00 — `easyfind.hpp`

1. **No exception thrown on not-found** — The subject says *"throw an exception or return an error value"*. You return `1`/`0` (int), which works but is weak. An **iterator return** or **exception** is more idiomatic and expected by evaluators.
2. **`std::string` test in main** — `easyfind(s, 10)` on a `std::string` is technically valid (string is a container of `char`), but might raise evaluator questions since the subject says "container of integers".

#### Ex01 — `Span`

3. **Default constructor sets `_size` to `-1` (i.e. `UINT_MAX`)** — `_size` is `unsigned int`, so `Span()` creates a span with capacity 4,294,967,295. This is technically undefined/misleading. Consider setting it to `0`.
4. **`shortestSpan()` is not `const`** — It mutates internal state (sorts `_cnt`). The correction sheet might not flag this, but it's worth noting.
5. **No test with 10,000+ numbers** — The subject explicitly requires this. Your `main.cpp` only tests with 7 numbers. **This is a fail condition.**
6. **`addRange` only accepts `std::vector<int>::const_iterator`** — Should be templated to accept any iterator type for generality (the subject/correction emphasize using iterator ranges).

#### Ex02 — `MutantStack.hpp`

7. **Iterator names are swapped** — `iterator` is aliased to `reverse_iterator` of the underlying deque, and `reverse_iterator` is aliased to `iterator` of the deque. The names are **backwards**. `begin()` returns `rbegin()` and `end()` returns `rend()`. This means iteration goes in LIFO order (stack top first) which is a deliberate design choice to match stack semantics, but the naming of types is confusing.
8. **Copy constructor has a bug** — `this->c(original.c)` should be in the initializer list or use assignment. As written, it's calling `operator()` on `this->c` with `original.c` as argument, which won't copy the contents.
9. **Assignment operator missing `return *this`** — `operator=` has return type `MutantStack&` but no return statement. This is **undefined behavior**.
10. **No const iterators for `begin()`/`end()`** — `const_iterator` types are defined but no `const` overloads of `begin()`/`end()` exist.
11. **Tests are minimal** — The correction sheet says main must have *more tests than the subject example*. Your main uses exactly the subject's example with no additions.
