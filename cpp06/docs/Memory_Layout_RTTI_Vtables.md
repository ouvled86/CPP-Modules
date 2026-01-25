# Memory Layout: RTTI, Vtables, and Diamond Inheritance

## The Big Picture

When your C++ program runs, two things happen for polymorphic objects:

1. **Your object lives on the heap/stack** (contains actual data + hidden vptrs)
2. **RTTI and vtables live in .rodata** (read-only memory, shared by all objects)

The object's hidden vptrs **point to** the RTTI/vtables in .rodata.

---

## Simple: Single Inheritance First

```cpp
struct Base { virtual void foo() {} };
struct Derived : Base { void foo() override {} };

Derived d;           // Object on stack
Base* bp = &d;       // Pointer to object
dynamic_cast<Derived*>(bp);  // Runtime type check
```

**Memory picture:**
- `d` on stack: `[vptr | data]`
- vptr → points to Derived's vtable in .rodata
- Vtable in .rodata: `[offset-to-top | type_info* | foo() | ...]` where:
  - `offset-to-top`: signed distance (bytes) from the vptr's location back to the start of the most-derived object. For the primary base (single inheritance), this is 0.
  - `type_info*`: points to the RTTI record for the most-derived type (here, Derived). `dynamic_cast` reads this to know the real type at runtime.
  - `foo() | ...`: one function pointer slot per virtual function in declaration order (as seen from this subobject's view). Each points to the override that should run.
- type_info in .rodata: Contains name "Derived" and base class info

**How dynamic_cast works:**
1. Follow vptr → lands in Derived's vtable (in .rodata)
2. Read type_info → "This is Derived"
3. Check: "Is Derived what we want?" → Yes/No
4. Return pointer or nullptr

---

## Diamond Inheritance: The Tricky Part

```cpp
struct Base { virtual void do_it() {} };
struct Left : virtual Base {};
struct Right : virtual Base {};
struct Diamond : Left, Right { void do_it() override {} };

Diamond d;
Left* lp = &d;   // Points to LEFT part of Diamond
Right* rp = &d;  // Points to RIGHT part of Diamond (different address!)
Base* bp = &d;   // Ambiguous: which base?
```

The issue: **Diamond contains multiple copies of subobjects at different memory locations.**

---

## Diamond Object Layout in Memory

```
Diamond instance on stack (e.g., starts at 0x1000):

Address 0x1000: [vptr_Left]        ← Points to Left's vtable in .rodata
Address 0x1008: [Left's data]      ← (if any)

Address 0x1010: [vptr_Right]       ← Points to Right's vtable in .rodata
Address 0x1018: [Right's data]     ← (if any)

Address 0x1020: [Base subobject]   ← Shared (only ONE copy, no vptr)

Key: TWO vptrs in one Diamond object!
     lp = 0x1000  (points to Left part)
     rp = 0x1010  (points to Right part)
     Different addresses!
```

---

## Why Multiple vptrs?

Because Left and Right are **different base classes** in different locations:
- vptr_Left (at 0x1000) needs to know: "I'm in the Left part, go back 0 bytes to Diamond start"
- vptr_Right (at 0x1010) needs to know: "I'm in the Right part, go back 16 bytes to Diamond start"

Each vptr has its own vtable variant with the correct offset-to-top.

---

## What's Inside a Vtable?

```
Vtable for Diamond_as_Left (in .rodata):
┌─────────────────────────────────┐
│ [0] offset-to-top: 0            │ "No offset, we're at start"
│ [8] type_info* → (Diamond)      │ "This object is a Diamond"
│ [16] Diamond::do_it (function)  │ "Virtual function pointer"
│ [24] ... more virtuals ...      │
└─────────────────────────────────┘

Vtable for Diamond_as_Right (in .rodata):
┌─────────────────────────────────┐
│ [0] offset-to-top: -16          │ "Go back 16 bytes to reach Diamond start"
│ [8] type_info* → (Diamond)      │ "Still a Diamond, just from Right perspective"
│ [16] Diamond::do_it (function)  │
│ ...
└─────────────────────────────────┘
```

**offset-to-top:** How many bytes back from this vptr to reach the real object start.

---

## RTTI Metadata (in .rodata)

```
type_info (Diamond):
  name: "Diamond"
  base_classes: [ Left, Right, Base ]
  
Class Hierarchy Descriptor:
  "Diamond has 3 bases"
  
Base Class Array:
  [0] Left:  offset=0,  virtual=false
  [1] Right: offset=16, virtual=false
  [2] Base:  offset=32, virtual=true
```

This info lives in .rodata and is **shared by ALL Diamond instances**.

---

## How dynamic_cast Actually Works

```
Code:
  Left* lp = &diamond_d;
  Right* rp = dynamic_cast<Right*>(lp);

Step 1: Follow vptr
  lp → 0x1000 → vptr_Left → VTable_Diamond_as_Left in .rodata

Step 2: Read type_info from vtable
  Read offset 8 in vtable → type_info*
  type_info says: "This is a Diamond"

Step 3: Check class hierarchy
  Look up type_info → find ClassHierarchyDescriptor
  Search for Right: "Found at offset 16"

Step 4: Adjust pointer
  rp = (char*)lp + 16
  rp now points to the Right part of the same Diamond

Step 5: Return adjusted pointer
  return rp (or nullptr if Right is not a base)
```

---

## The Memory Regions

```
┌──────────────────────────────────────────────┐
│  .rodata (Read-Only)                        │
│  ────────────────────────────────────────  │
│  • Vtables (pointers to functions)          │
│  • type_info (class names, base lists)      │
│  • Class hierarchy descriptors              │
│  • Base class arrays (offsets)              │
│                                              │
│  ONE copy per type, shared forever          │
└──────────────────────────────────────────────┘

┌──────────────────────────────────────────────┐
│  Heap / Stack (Runtime)                     │
│  ────────────────────────────────────────  │
│  • Your actual objects                      │
│  • Hidden vptrs inside (point to .rodata)   │
│  • Data members                             │
│                                              │
│  Each instance is unique (but references    │
│  shared metadata in .rodata)                │
└──────────────────────────────────────────────┘
```

---

## Key Takeaways

1. **Objects are lightweight**: Just vptrs and data. All type info is in .rodata.

2. **RTTI is shared**: One type_info per class, shared by all instances. Not duplicated.

3. **Diamond has multiple vptrs**: Left and Right subobjects each have a vptr. Both point to vtables that know the offset back to Diamond start.

4. **Pointer adjustment is automatic**: dynamic_cast uses offset-to-top and hierarchy info to adjust pointers between bases. That's why `(Left*)d != (Right*)d` — they point to different parts of the same object.

5. **Static_cast is compile-time**: No pointer adjustment, just trust. `static_cast<Right*>((Left*)d)` is undefined behavior if Left is not at the start.

6. **dynamic_cast is safe**: It checks the type_info and adjusts pointers. Returns nullptr if the cast is impossible.

---

## Visual Summary

```
In .rodata (Fixed at compile time):
- Vtable_Diamond_as_Left     → { offset: 0,  type_info, functions }
- Vtable_Diamond_as_Right    → { offset: 16, type_info, functions }
- type_info(Diamond)         → "bases: Left(0), Right(16), Base(32)"

On Stack (Runtime):
- Diamond d
  - [0x1000] vptr → Vtable_Diamond_as_Left
  - [0x1010] vptr → Vtable_Diamond_as_Right
  - [0x1020] Base subobject

dynamic_cast does this:
  Follow vptr → Read type_info → Find offset → Adjust pointer
```

---

## One More Thing: Why No vptr in Base?

Base is a **virtual base**. All Diamond instances share ONE copy of Base, embedded at a fixed location. Since it's not replicated, it doesn't need its own vptr. Instead, the offset information in the vtables tells the runtime where to find it.

If Base were a normal (non-virtual) base, it would be duplicated in both Left and Right, and each copy would have its own vptr.
