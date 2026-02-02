# C++ Templates Guide - Module 07

## Table of Contents
1. [Introduction to Templates](#introduction-to-templates)
2. [Function Templates](#function-templates)
3. [Class Templates](#class-templates)
4. [Template Instantiation & Memory Layout](#template-instantiation--memory-layout)
5. [Template Best Practices](#template-best-practices)
6. [Common Patterns & Idioms](#common-patterns--idioms)
7. [C++98 Specific Considerations](#c98-specific-considerations)

---

## Introduction to Templates

Templates are one of C++'s most powerful features, enabling **generic programming**. They allow you to write code that works with any data type without sacrificing type safety or performance.

### What Are Templates?

Templates are blueprints for creating functions or classes. The compiler generates the actual code when the template is **instantiated** with a specific type.

```cpp
// Template definition - NOT actual code yet
template <typename T>
T add(T a, T b) {
    return a + b;
}

// Instantiation - NOW the compiler generates actual code
int result = add<int>(5, 3);      // Generates: int add(int a, int b)
double d = add<double>(1.5, 2.5); // Generates: double add(double, double)
```

### Why Use Templates?

| Benefit | Description |
|---------|-------------|
| **Type Safety** | Unlike macros, templates are type-checked at compile time |
| **Performance** | No runtime overhead - code is generated at compile time |
| **Code Reuse** | Write once, use with any type that supports required operations |
| **DRY Principle** | Don't Repeat Yourself - avoid duplicate code for different types |

---

## Function Templates

### Basic Syntax

```cpp
template <typename T>
T functionName(T parameter) {
    // function body
}
```

The `typename` keyword can be replaced with `class` (they are equivalent in this context):

```cpp
template <class T>  // Same as template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}
```

### Multiple Template Parameters

```cpp
template <typename T, typename U>
T convert(U value) {
    return static_cast<T>(value);
}

// Usage
int i = convert<int, double>(3.14);  // Explicit
int j = convert<int>(3.14);          // U deduced from argument
```

### Return Type Considerations

When returning by reference, ensure the referenced object outlives the reference:

```cpp
// CORRECT: Returns reference to one of the parameters
template <typename T>
T const& min(T const& a, T const& b) {
    return (a < b) ? a : b;
}

// Subject requirement: if equal, return second parameter
template <typename T>
T const& min(T const& a, T const& b) {
    return (a >= b) ? b : a;  // b returned when a == b
}
```

### Function Template Overloading

```cpp
// Generic version
template <typename T>
void iter(T* arr, size_t len, void (*func)(T&)) {
    for (size_t i = 0; i < len; i++)
        func(arr[i]);
}

// Overload for const arrays
template <typename T>
void iter(const T* arr, size_t len, void (*func)(const T&)) {
    for (size_t i = 0; i < len; i++)
        func(arr[i]);
}
```

---

## Class Templates

### Basic Syntax

```cpp
template <typename T>
class Array {
private:
    T* data;
    size_t size;

public:
    Array(size_t n);
    ~Array();
    T& operator[](size_t index);
    const T& operator[](size_t index) const;  // const version
    size_t getSize() const;
};
```

### Defining Member Functions Outside the Class

```cpp
template <typename T>
Array<T>::Array(size_t n) : size(n) {
    data = new T[n]();  // () ensures default-initialization
}

template <typename T>
Array<T>::~Array() {
    delete[] data;
}

template <typename T>
T& Array<T>::operator[](size_t index) {
    if (index >= size)
        throw std::out_of_range("Index out of bounds");
    return data[index];
}
```

### Orthodox Canonical Form for Class Templates

Class templates must still follow OCF:

```cpp
template <typename T>
class Array {
private:
    T* _data;
    size_t _size;

public:
    // Default constructor
    Array() : _data(NULL), _size(0) {}
    
    // Parameterized constructor
    Array(unsigned int n) : _data(new T[n]()), _size(n) {}
    
    // Copy constructor (deep copy)
    Array(const Array& other) : _data(NULL), _size(0) {
        *this = other;
    }
    
    // Assignment operator (deep copy)
    Array& operator=(const Array& other) {
        if (this != &other) {
            delete[] _data;
            _size = other._size;
            if (_size > 0) {
                _data = new T[_size];
                for (size_t i = 0; i < _size; i++)
                    _data[i] = other._data[i];
            } else {
                _data = NULL;
            }
        }
        return *this;
    }
    
    // Destructor
    ~Array() {
        delete[] _data;
    }
};
```

---

## Template Instantiation & Memory Layout

### How Templates Work Under the Hood

```
Source Code                    Compilation                    Object Code
+--------------+              +-------------+              +----------------+
| template<T>  |              |             |              | int add(int,int)|
| T add(T,T)   |  ========>   |  Compiler   |  ========>   | float add(...) |
|              |              |             |              | string add(...)|
+--------------+              +-------------+              +----------------+
      ^                             |
      |                             v
      +-------- Instantiation ------+
                add<int>(1,2)
                add<float>(1.0,2.0)
                add<string>("a","b")
```

### Template Instantiation Types

1. **Implicit Instantiation**: Compiler automatically generates code when template is used
   ```cpp
   std::vector<int> v;  // Compiler generates vector<int> class
   ```

2. **Explicit Instantiation**: Force compiler to generate code
   ```cpp
   template class Array<int>;  // Generate Array<int> here
   ```

### Memory Layout for Template Classes

```
Array<int> with 3 elements:

Stack:                          Heap:
+------------------+            +---+---+---+
| Array<int> obj   |            | 0 | 1 | 2 |  <- int[3]
|   _data ---------|----------->+---+---+---+
|   _size: 3       |               12 bytes
+------------------+
     16 bytes
   (8 ptr + 8 size_t)


Array<double> with 3 elements:

Stack:                          Heap:
+------------------+            +-------+-------+-------+
| Array<double>obj |            |  0.0  |  1.0  |  2.0  |  <- double[3]
|   _data ---------|----------->+-------+-------+-------+
|   _size: 3       |                    24 bytes
+------------------+
     16 bytes
```

### Code Bloat Consideration

Each instantiation generates separate code:

```cpp
void swap<int>(int&, int&);      // ~20 bytes of code
void swap<double>(double&, double&);  // ~20 bytes of code
void swap<std::string>(...);     // ~100+ bytes of code
// ... each type = more code
```

---

## Template Best Practices

### 1. Use `const` References for Read-Only Parameters

```cpp
// GOOD: No unnecessary copy
template <typename T>
T const& min(T const& a, T const& b);

// BAD: Creates copies
template <typename T>
T min(T a, T b);
```

### 2. Provide Both const and Non-const Versions

```cpp
template <typename T>
class Array {
public:
    // For non-const objects (allows modification)
    T& operator[](size_t i);
    
    // For const objects (read-only access)
    const T& operator[](size_t i) const;
};
```

### 3. Use `size_t` Consistently for Sizes/Indices

```cpp
// GOOD: Consistent types, no sign warnings
for (size_t i = 0; i < _size; i++)

// BAD: Mixed types cause warnings with -Wextra
for (int i = 0; i < _size; i++)  // Warning: signed/unsigned comparison
```

### 4. Self-Assignment Check in operator=

```cpp
template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this != &other) {  // Prevent self-assignment
        // ... copy logic
    }
    return *this;
}
```

### 5. Initialize Pointers to NULL

```cpp
template <typename T>
Array<T>::Array() : _data(NULL), _size(0) {}  // GOOD

// This allows safe delete[] in destructor/assignment
```

### 6. Use Default-Initialization with new[]

```cpp
// GOOD: Elements are default-initialized
_data = new T[n]();  // Note the ()

// int: 0, double: 0.0, pointers: NULL, objects: default ctor

// NOT IDEAL: Elements may have garbage values for POD types
_data = new T[n];
```

### 7. Templates Must Be in Header Files

```cpp
// whatever.hpp - Template definition MUST be here
template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

// WRONG: Cannot separate template implementation into .cpp
// (unless using explicit instantiation)
```

---

## Common Patterns & Idioms

### Swap Idiom

```cpp
template <typename T>
void swap(T& a, T& b) {
    T holder = a;
    a = b;
    b = holder;
}
```

### Iterator Pattern with Function Pointers

```cpp
template <typename T>
void iter(T* arr, size_t len, void (*func)(T&)) {
    for (size_t i = 0; i < len; i++)
        func(arr[i]);
}

// With const elements
template <typename T>
void iter(const T* arr, size_t len, void (*func)(const T&)) {
    for (size_t i = 0; i < len; i++)
        func(arr[i]);
}
```

### Accepting Template Function as Parameter

```cpp
// The function parameter can itself be a template
template <typename T>
void print(const T& value) {
    std::cout << value << std::endl;
}

int arr[] = {1, 2, 3};
iter(arr, 3, print<int>);  // Explicit instantiation required
```

### RAII with Templates

```cpp
template <typename T>
class Array {
private:
    T* _data;
    
public:
    Array(size_t n) : _data(new T[n]()) {}
    ~Array() { delete[] _data; }  // Automatic cleanup
    
    // Copy and assignment also manage memory
};
```

---

## C++98 Specific Considerations

### No `nullptr` - Use `NULL`

```cpp
// C++98
_data = NULL;
if (_data != NULL)

// C++11 and later (NOT allowed in this module)
_data = nullptr;
```

### No `auto` Keyword

```cpp
// C++98 - Must specify type
for (size_t i = 0; i < len; i++)

// C++11 (NOT allowed)
for (auto i = 0u; i < len; i++)
```

### No Range-Based For Loops

```cpp
// C++98 - Traditional for loop
for (size_t i = 0; i < arr.size(); i++)
    process(arr[i]);

// C++11 (NOT allowed)
for (const auto& elem : arr)
    process(elem);
```

### No `std::initializer_list`

```cpp
// C++98 - Must initialize elements individually
Array<int> arr(3);
arr[0] = 1;
arr[1] = 2;
arr[2] = 3;

// C++11 (NOT allowed)
Array<int> arr = {1, 2, 3};
```

### Template Syntax Note

```cpp
// Nested template closing brackets need space in C++98
std::vector<std::vector<int> >  // Note the space

// C++11 allows
std::vector<std::vector<int>>   // No space needed
```

---

## Summary Table

| Concept | Key Points |
|---------|------------|
| **Function Template** | Generic function, type deduced from arguments |
| **Class Template** | Generic class, type specified at instantiation |
| **Template Parameter** | `typename T` or `class T` |
| **Instantiation** | Compiler generates specific code for each type used |
| **const References** | Avoid copies, enable read-only access |
| **OCF with Templates** | Same rules: default ctor, copy ctor, operator=, destructor |
| **Header Files** | Template code must be in header (or .tpp included in .hpp) |

---

## Quick Reference Card

```cpp
// Function template
template <typename T>
T max(T const& a, T const& b) {
    return (a > b) ? a : b;
}

// Class template
template <typename T>
class Container {
    T* data;
public:
    Container();
    Container(const Container& other);
    Container& operator=(const Container& other);
    ~Container();
    T& operator[](size_t i);
    const T& operator[](size_t i) const;
    size_t size() const;
};

// Usage
Container<int> intContainer;
Container<std::string> strContainer;
int result = max(5, 10);  // Type deduced
```
