# RTTI, Vtables, and Polymorphism

## Overview
- Goal: Explain Run-Time Type Information (RTTI), how it works, its relation to vtables, and a quick refresher on polymorphism — with analogies and examples.
- Scope: Practical details you need for `dynamic_cast`, `typeid`, and class hierarchies.

## What Is RTTI?
- Definition: Runtime metadata that lets C++ discover an object’s actual (dynamic) type when the static type is a base (e.g., `Base*`).
- APIs that use RTTI:
  - `dynamic_cast<T>(ptr)` and `dynamic_cast<T&>(ref)` — runtime-checked casts in polymorphic hierarchies.
  - `typeid(obj)` — returns a `std::type_info` for the dynamic type when `obj` is polymorphic.

## How RTTI Works Under the Hood
- Static vs dynamic type:
  - Static type: The type known to the compiler (e.g., `Base*`).
  - Dynamic type: The most-derived type of the actual object (e.g., `A`, `B`, or `C`).
- Polymorphism prerequisite:
  - RTTI requires the type to be polymorphic (has at least one `virtual` function). Non-polymorphic types don’t have a vtable/vptr, so RTTI features for downcasting are not available.
- Where RTTI lives:
  - Each polymorphic object holds a hidden pointer (vptr) to a class-specific vtable.
  - Compilers/ABIs attach type metadata to the vtable (or nearby) so runtime queries can resolve the dynamic type.

## Vtables Refresher
- Vtable: A per-class table of pointers to virtual functions (the override set for that class).
- Vptr: A hidden pointer inside each polymorphic object that points to its class’s vtable.
- Runtime dispatch:
  - Calling a `virtual` function via a base pointer is resolved by following vptr → vtable → function pointer.
- Relation to RTTI:
  - The vtable is the anchor to both virtual dispatch and RTTI metadata; RTTI uses vtable-linked type info to validate casts and report type names.

## What RTTI Metadata Typically Contains
- Type identity: A canonical runtime type object (often referenced by `std::type_info`).
- Name representation: Implementation-defined string for `typeid(T).name()` (often mangled). Some platforms provide demangling.
- Inheritance graph:
  - Immediate and virtual bases.
  - For multiple inheritance, a list of base descriptors with flags (public/private, virtual) and offsets.
- Subobject layout info:
  - Offsets from the most-derived object to each base subobject (used to adjust pointers correctly during `dynamic_cast`, including cross-casts and virtual inheritance).
- Access/Ambiguity flags:
  - Whether inheritance paths are public and unambiguous (needed for `dynamic_cast` to succeed).

## Practical APIs and Behavior
- `dynamic_cast<T*>(p)`:
  - Success: Returns a non-null pointer to the `T` subobject, applying pointer adjustment as needed.
  - Failure: Returns `nullptr`.
  - Null-in → null-out: If `p` is `nullptr`, result is `nullptr`.
- `dynamic_cast<T&>(r)`:
  - Success: Binds a `T&` to the correct subobject.
  - Failure: Throws `std::bad_cast`.
- `typeid(*p)`:
  - Returns the dynamic type’s `type_info` when `p` points to a polymorphic object.
  - `typeid(T)` (on a type) returns the static type’s `type_info`.

## Examples

### Polymorphic Hierarchy and Safe Downcast
```cpp
struct Base { virtual ~Base() {} };
struct A : Base { void fa() const {} };
struct B : Base { void fb() const {} };

void use(Base* p) {
    if (A* pa = dynamic_cast<A*>(p)) {
        pa->fa(); // p is actually A
    } else if (B* pb = dynamic_cast<B*>(p)) {
        pb->fb(); // p is actually B
    } else {
        // nullptr or unrelated type
    }
}
```

### typeid for Logging
```cpp
#include <typeinfo>
#include <iostream>

void log_type(Base* p) {
    if (!p) { std::cout << "null" << std::endl; return; }
    std::cout << typeid(*p).name() << std::endl; // mangled name (implementation-defined)
}
```

### Multiple Inheritance Pointer Adjustment
```cpp
struct A { virtual ~A() {} };
struct B { virtual ~B() {} };
struct D : A, B { void fd() const {} };

void cross(A* a) {
    if (B* b = dynamic_cast<B*>(a)) { // cross-cast via D
        if (D* d = dynamic_cast<D*>(b)) { d->fd(); }
    }
}
```

## Analogy
- Library card + catalog:
  - The vptr is the library card attached to each book (object). It points to the catalog (vtable), which includes the book’s official title (type metadata) and chapter list (virtual functions).
  - `typeid` reads the title; `dynamic_cast` checks whether the book is a specific edition and, if so, guides you to the correct section (pointer adjustment).

## Pitfalls and Notes
- RTTI disabled: Compiling with `-fno-rtti` disables `dynamic_cast` (to derived) and dynamic `typeid`; avoid for polymorphism-heavy code.
- Non-polymorphic types: `dynamic_cast` on non-polymorphic bases is ill-formed; use `static_cast` only with external guarantees (unsafe otherwise).
- Performance: RTTI checks are small but present; avoid in hot loops or cache results if needed.
- Portability: Exact metadata layout is ABI-specific (e.g., Itanium ABI vs MSVC ABI); the semantics of `dynamic_cast` and `typeid` remain consistent across conforming compilers.

## Quick Polymorphism Recap
- Virtual functions enable runtime dispatch and RTTI.
- Vtables store addresses of overrides; vptr selects the right table for each object.
- RTTI ties into the vtable to enable safe downcasts and dynamic type queries.

## Takeaways
- Use `dynamic_cast` for safe downcasts and cross-casts in polymorphic hierarchies.
- Use `typeid` for runtime type queries and logging.
- Remember: vtables are the mechanism; RTTI is the metadata; polymorphism is the prerequisite.
