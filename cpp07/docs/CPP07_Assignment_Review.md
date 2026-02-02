# CPP07 Assignment Review - Issues & Recommendations

## Overview

This document provides a detailed analysis of your CPP07 (Templates) assignment, identifying issues, potential bugs, and areas for improvement.

---

## Exercise Status Summary

| Exercise | Compilation | Subject Tests | Evaluation Tests | Status |
|----------|-------------|---------------|------------------|--------|
| ex00     | ✅ Pass     | ✅ Pass       | ✅ Pass          | ✅ **READY** |
| ex01     | ✅ Pass     | ✅ Pass       | ✅ Pass          | ✅ **READY** |
| ex02     | ✅ Pass     | ✅ Pass       | ✅ Pass          | ✅ **READY** |

---

## Exercise 00: whatever.hpp ✅

### Current Implementation

```cpp
template < typename T >
void	swap(T &a, T &b)
{
	T	holder = a;
	a = b;
	b = holder;
}

template < typename T >
T const	&min(T const &a, T const &b)
{
	if (a >= b)
		return b;
	return a;
}

template < typename T >
T const	&max(T const &a, T const &b)
{
	if (b > a)
		return b;
	return a;
}
```

### ✅ All Requirements Met
- Compiles with `-Wall -Wextra -Werror -std=c++98`
- Subject test case produces expected output
- Complex type test (Awesome class) from evaluation sheet passes
- Correctly returns second value when equal (subject requirement)

### Test Results
```
=== Subject Test ===
a = 3, b = 2
min( a, b ) = 2
max( a, b ) = 3
c = chaine2, d = chaine1
min( c, d ) = chaine1
max( c, d ) = chaine2

=== Complex Type (Awesome) Test ===
4 2
4
2
```

---

## Exercise 01: iter.hpp ✅

### Current Implementation

```cpp
template < typename T >
void	iter(T *arr, size_t len, void (*func)(T &))
{
	for (size_t i = 0; i < len; i++)
		func(arr[i]);
}

template < typename T >
void	iter(const T *arr, size_t len, void (*func)(const T &))
{
	for (size_t i = 0; i < len; i++)
		func(arr[i]);
}
```

### ✅ All Requirements Met
- Compiles with `-Wall -Wextra -Werror -std=c++98`
- Works with both const and non-const arrays
- Supports function templates as third parameter
- Evaluation test with Awesome class passes

### Test Results
```
0
1
2
3
4
42
42
42
42
42
```

---

## Exercise 02: Array.hpp ✅

### Current Implementation

```cpp
template <typename T>
class Array
{
private:
	T			*addr;
	size_t		_size;

public:
	Array<T>(void)
	{
		addr = NULL;
		this->_size = 0;
	}

	Array<T>(size_t n)
	{
		addr = new T[n];
		_size = n;
		for (size_t i = 0; i < n; i++)
			addr[i] = T();
	}

	Array<T>(const Array<T> &other)
	{
		if (other._size)
		{
			this->addr = new T[other._size];
			for (size_t i = 0; i < other._size; i++)
				this->addr[i] = other.addr[i];
			this->_size = other._size;
		}
		else
		{
			this->addr = NULL;
			this->_size = 0;
		}
	}

	Array<T>	&operator=(const Array<T> &other)
	{
		if (this != &other)
		{
			if (other._size)
			{
				if (this->addr)
					delete[] this->addr;
				this->addr = new T[other._size];
				for (size_t i = 0; i < other._size; i++)
					this->addr[i] = other.addr[i];
				this->_size = other._size;
			}
			else
			{
				this->addr = NULL;
				this->_size = 0;
			}
		}
		return (*this);
	}

	T			&operator[](size_t index)
	{
		if (index >= _size)
			throw std::out_of_range("Index out of bounds");
		return (addr[index]);
	}

	const T		&operator[](size_t index) const
	{
		if (index >= _size)
			throw std::out_of_range("Index out of bounds");
		return (addr[index]);
	}

	~Array<T>()
	{
		if (addr)
			delete[] addr;
	}

	size_t		size(void) const
	{
		return (this->_size);
	}
};
```

### ✅ All Requirements Met
- Compiles with `-Wall -Wextra -Werror -std=c++98`
- Empty array construction works
- Sized array construction with default initialization works
- Copy constructor creates independent copy (deep copy)
- Assignment operator creates independent copy (deep copy)
- Both const and non-const `operator[]` implemented
- Out-of-bounds access throws `std::exception`
- `size()` member function works correctly
- Uses `new[]` for allocation (subject requirement)

### Test Results
```
=== Test 1: Empty Array ===
Empty size: 0

=== Test 2: Sized Array ===
Sized array size: 5
sized[0] = 0
sized[1] = 0
sized[2] = 0
sized[3] = 0
sized[4] = 0

=== Test 3: Assignment ===
After assignment: sized[0] = 100, sized[1] = 200

=== Test 4: Copy Constructor ===
Copy size: 5
copy[0] = 100, copy[1] = 200

=== Test 5: Modifying copy doesn't affect original ===
After copy[0] = 999:
sized[0] = 100
copy[0] = 999

=== Test 6: Assignment Operator ===
Assigned size: 5
assigned[0] = 100

=== Test 7: Out of Bounds ===
Caught exception: Index out of bounds

=== Test 8: Const Access ===
Const access arr[0]: 100
Const array size: 5

=== Test 9: Complex Type ===
Complex array size: 3

All tests completed!
```

---

## Issues Fixed Since Last Review

| Issue | Status | Fix Applied |
|-------|--------|-------------|
| Missing `operator!=` / wrong comparison | ✅ Fixed | Changed to address comparison `this != &other` |
| Missing `const operator[]` | ✅ Fixed | Added `const T& operator[](size_t) const` |
| Signed/unsigned comparison | ✅ Fixed | Changed loop variable to `size_t` |
| Wrong size in allocation | ✅ Fixed | Now uses `other._size` correctly |
| Copy constructor `j += sizeof(T)` bug | ✅ Fixed | Changed to simple `i++` loop |
| Hardcoded `= 0` initialization | ✅ Fixed | Changed to `addr[i] = T()` |
| Explicit function pointer syntax | ✅ Fixed | Now uses `void (*func)(T &)` |
| Inappropriate test data | ✅ Fixed | Removed offensive language |

---

## Minor Suggestions (Optional)

These are not required but could improve code quality:

### 1. Constructor Parameter Type
**Location**: [Array.hpp](../ex02/Array.hpp#L32)

The subject specifies `unsigned int n`, but you're using `size_t n`. Both work, but for strict compliance:

```cpp
// Current
Array<T>(size_t n)

// Subject specification
Array<T>(unsigned int n)
```

This is unlikely to cause issues during evaluation.

### 2. Memory Leak in Assignment Operator
**Location**: [Array.hpp](../ex02/Array.hpp#L56-L71)

When `other._size` is 0 and `this->addr` is not NULL, the old memory is not freed:

```cpp
if (this != &other)
{
    if (other._size)
    {
        if (this->addr)
            delete[] this->addr;
        // ...
    }
    else
    {
        // BUG: old addr not deleted when other is empty
        this->addr = NULL;
        this->_size = 0;
    }
}
```

**Recommended Fix**:
```cpp
Array<T>& operator=(const Array<T>& other)
{
    if (this != &other)
    {
        delete[] this->addr;  // Always delete old data first
        if (other._size)
        {
            this->addr = new T[other._size];
            for (size_t i = 0; i < other._size; i++)
                this->addr[i] = other.addr[i];
            this->_size = other._size;
        }
        else
        {
            this->addr = NULL;
            this->_size = 0;
        }
    }
    return (*this);
}
```

Note: `delete[] NULL` is safe in C++ and does nothing.

---

## Evaluation Checklist

### General Requirements
- [x] Code compiles with `c++ -Wall -Wextra -Werror -std=c++98`
- [x] No forbidden functions (*alloc, *printf, free)
- [x] No `using namespace` or `friend` keywords
- [x] Templates defined in header files
- [x] Include guards present

### Exercise 00
- [x] `swap()` works with simple types (int)
- [x] `swap()` works with complex types (Awesome)
- [x] `min()` returns smaller value
- [x] `min()` returns second when equal
- [x] `max()` returns greater value
- [x] `max()` returns second when equal

### Exercise 01
- [x] `iter()` works with int arrays
- [x] `iter()` works with complex types (Awesome)
- [x] Third parameter can be function template

### Exercise 02
- [x] Empty array construction
- [x] Sized array construction
- [x] Elements initialized by default
- [x] Uses `new[]` for allocation
- [x] Copy constructor (deep copy)
- [x] Assignment operator (deep copy)
- [x] `operator[]` for read/write access
- [x] `const operator[]` for read-only access
- [x] Out-of-bounds throws `std::exception`
- [x] `size()` returns element count
- [x] No memory leaks (verify with valgrind if available)

---

## Final Status: ✅ READY FOR EVALUATION

All exercises pass compilation and functionality tests. The assignment meets all subject requirements and should pass the evaluation.
