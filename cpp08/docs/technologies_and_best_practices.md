# C++ Module 08 — Technologies & Best Practices

## Technologies Used

### 1. Function Templates

Templates let you write generic code that works with **any type** the caller provides.

```cpp
template <typename T>
int easyfind(const T &cnt, int target) {
    // Works with vector<int>, list<int>, deque<int>, etc.
    if (std::find(cnt.begin(), cnt.end(), target) != cnt.end())
        return 0;
    throw std::runtime_error("Not found");
}
```

**How it works**: The compiler generates a separate version of the function for each type you use it with. `easyfind<vector<int>>` and `easyfind<list<int>>` become two distinct compiled functions.

**Best practice**: Always put template implementations in header files (`.hpp` or `.tpp`) — the compiler needs to see the full body at the point of instantiation.

---

### 2. STL Containers

The Standard Template Library ships three families of containers:

| Family | Containers | Strengths |
|---|---|---|
| **Sequence** | `vector`, `deque`, `list` | Ordered collections |
| **Associative** | `set`, `map`, `multiset`, `multimap` | Fast key lookups (balanced BST) |
| **Adapters** | `stack`, `queue`, `priority_queue` | Restrict interface of underlying containers |

**Key containers in this module**:

- **`std::vector<T>`** — Dynamic array. O(1) random access, O(1) amortized push_back. Best default choice.
- **`std::list<T>`** — Doubly-linked list. O(1) insert/remove anywhere, no random access.
- **`std::stack<T>`** — LIFO adapter. Wraps a `deque` by default; only exposes `push`, `pop`, `top`, `size`, `empty`.

**Best practice**: Prefer `vector` unless you have a specific reason not to (frequent mid-container insertions → `list`, LIFO semantics → `stack`).

---

### 3. STL Algorithms

The `<algorithm>` header provides ~80 algorithms that operate on iterator ranges:

```cpp
// Finding
std::find(first, last, value);       // linear search
std::binary_search(first, last, val); // requires sorted range

// Sorting
std::sort(first, last);              // O(n log n) introsort
std::stable_sort(first, last);       // preserves equal-element order

// Min/Max
std::min_element(first, last);
std::max_element(first, last);
```

**Best practice**: Always prefer STL algorithms over hand-written loops. They are:
- **Correct** — battle-tested implementations
- **Optimized** — often use SIMD, cache-friendly patterns
- **Readable** — `std::find` communicates intent better than a raw loop

---

### 4. Iterators

Iterators are the **glue** between containers and algorithms. They abstract pointer-like traversal.

| Category | Operations | Examples |
|---|---|---|
| Input | `++`, `*`, `==` | `istream_iterator` |
| Forward | + multi-pass | `forward_list::iterator` |
| Bidirectional | + `--` | `list::iterator`, `set::iterator` |
| Random Access | + `[]`, `+n`, `<` | `vector::iterator`, `deque::iterator` |

**Best practice**: When writing generic code, require the **weakest** iterator category you need. This maximizes compatibility.

---

### 5. Class Inheritance & Adapter Pattern

`MutantStack` demonstrates **extending** a restricted interface:

```cpp
template <typename T>
class MutantStack : public std::stack<T> {
public:
    // Expose the protected container 'c' via iterators
    typedef typename std::deque<T>::iterator iterator;
    iterator begin() { return this->c.begin(); }
    iterator end()   { return this->c.end(); }
};
```

**How `std::stack` works internally**: It holds a protected member `c` (a `deque` by default). `push()` calls `c.push_back()`, `pop()` calls `c.pop_back()`, `top()` returns `c.back()`.

**Best practice**: Inherit from standard containers **cautiously** — they have no virtual destructors. Public inheritance is acceptable here because `stack` is an adapter, and we're extending its interface.

---

### 6. Orthodox Canonical Form (OCF)

Every well-behaved C++ class should provide four things:

```cpp
class Span {
public:
    Span();                            // Default constructor
    Span(const Span& other);           // Copy constructor
    Span& operator=(const Span& rhs);  // Copy assignment operator
    ~Span();                           // Destructor
};
```

**Why it matters**: If your class manages resources (heap memory, file handles, sockets), failing to implement any of these correctly leads to:
- **Double-free** (missing/wrong copy ctor)
- **Memory leaks** (missing destructor)
- **Dangling pointers** (missing/wrong assignment operator)

**Best practice**: Follow the **Rule of Three** — if you define any one of {destructor, copy ctor, copy assignment}, define all three.

---

### 7. Exception Handling

```cpp
void Span::addNumber(int num) {
    if (_current_size == _size)
        throw std::length_error("Span capacity exceeded");
    // ...
}
```

**Standard exception hierarchy**:
- `std::exception` (base)
  - `std::logic_error` → `std::length_error`, `std::out_of_range`, `std::invalid_argument`
  - `std::runtime_error` → `std::overflow_error`, `std::underflow_error`

**Best practice**: Throw specific exception types (not plain strings or ints). Catch by `const` reference.

---

## Common Pitfalls

| Pitfall | Why it's bad | Fix |
|---|---|---|
| `using namespace std;` | Pollutes global namespace, causes ambiguity | Use `std::` prefix everywhere |
| Forgetting `return *this` in `operator=` | Undefined behavior on chained assignment | Always return `*this` |
| Template code in `.cpp` files | Linker errors (undefined symbols) | Put in `.hpp` or `.tpp` |
| Not testing edge cases | Evaluator will catch 0/1 element spans | Test empty, single, max, duplicate values |
| Sorting in `const` methods | `const` method can't modify members | Use `mutable` or compute without sorting |
