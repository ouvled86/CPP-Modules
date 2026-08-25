<div align="center">

# 💻 C++ Modules (00 - 09)

**A complete journey from C to C++, mastering Object-Oriented Programming (OOP), memory safety, template metaprogramming, and the Standard Template Library (STL)**

[![42 School](https://img.shields.io/badge/42-School_Project-000000?style=for-the-badge&logo=42&logoColor=white)](https://42.fr)
[![Language](https://img.shields.io/badge/Language-C++98-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)](https://en.wikipedia.org/wiki/C%2B%2B)
[![Standards](https://img.shields.io/badge/Standard-C++98_/_C++11-FF6F61?style=for-the-badge)](https://en.cppreference.com/w/)

> *Moving beyond procedural programming. This repository contains the complete 42 Network C++ curriculum consisting of 10 modules, designed to build a deep, production-grade understanding of low-level memory mechanics, robust class designs, type casting, polymorphism, and STL containers.*

</div>

---

## 📚 Curriculum Overview

| Module | Core Subject | Key Concepts Learned |
|---|---|---|
| 📦 **[CPP 00](file:///C:/Users/ouvle/OneDrive/Documents/GitHub/CPP/cpp00)** | **Namespaces & Classes** | Basic syntax, input/output streams (`std::cin`/`std::cout`), namespaces, class layout, member functions, initialization lists, const correctness, and static variables. |
| 🧠 **[CPP 01](file:///C:/Users/ouvle/OneDrive/Documents/GitHub/CPP/cpp01)** | **Memory & References** | Dynamic allocation (`new`/`delete`), pointers to member functions, references vs. pointers, stack vs. heap allocation, and the switch statement. |
| 📐 **[CPP 02](file:///C:/Users/ouvle/OneDrive/Documents/GitHub/CPP/cpp02)** | **Ad-hoc Polymorphism** | Fixed-point number representations, operator overloading (arithmetic, comparison, increment), and the **Orthodox Canonical Class Form (OCCF)**. |
| 🌳 **[CPP 03](file:///C:/Users/ouvle/OneDrive/Documents/GitHub/CPP/cpp03)** | **Inheritance** | Single & multiple inheritance, constructor/destructor execution chains, access specifiers (`public`, `protected`, `private`), and the Diamond Inheritance problem (solved via virtual inheritance). |
| 🎭 **[CPP 04](file:///C:/Users/ouvle/OneDrive/Documents/GitHub/CPP/cpp04)** | **Subtype Polymorphism** | Virtual functions, destructors in inheritance, abstract classes, interfaces, pure virtual functions, and deep vs. shallow copy mechanics. |
| 🛡️ **[CPP 05](file:///C:/Users/ouvle/OneDrive/Documents/GitHub/CPP/cpp05)** | **Exception Handling** | Robust error routing via `try`, `catch`, and `throw`, defining custom nested exception structures, and std::exception inheritance. |
| 🔀 **[CPP 06](file:///C:/Users/ouvle/OneDrive/Documents/GitHub/CPP/cpp06)** | **Type Casting** | C++ style casts (`static_cast`, `dynamic_cast`, `const_cast`, `reinterpret_cast`), type conversion rules, serialization, and Run-Time Type Information (RTTI). |
| 🧬 **[CPP 07](file:///C:/Users/ouvle/OneDrive/Documents/GitHub/CPP/cpp07)** | **Templates** | Generic function templates, class templates, specialization, and parameterizing data structures (e.g., creating custom Array containers). |
| 🗃️ **[CPP 08](file:///C:/Users/ouvle/OneDrive/Documents/GitHub/CPP/cpp08)** | **STL Basics** | standard container interfaces (vectors, lists, maps), iterator mechanics, and STL algorithm operations (searching, counting, inserting). |
| ⚡ **[CPP 09](file:///C:/Users/ouvle/OneDrive/Documents/GitHub/CPP/cpp09)** | **Advanced STL** | Algorithm optimization (Ford-Johnson Merge-Insertion sorting), reverse polish notation calculations, database parses, and custom container selections. |

---

## 🛠️ The 4 Pillars of OOP

Across these modules, C++ features are leverage to implement the four foundational pillars of Object-Oriented Programming:

1. **Encapsulation** — Binding variables and methods inside classes, protecting states with access specifiers (`private`/`protected`), and exposing limited control API interfaces.
2. **Inheritance** — Deriving child classes from base parents (e.g., `ClapTrap` ➔ `ScavTrap`), promoting code reuse and modular system layouts.
3. **Polymorphism** — Resolving behaviors dynamically via virtual tables (late binding) or statically using function/operator overload options.
4. **Abstraction** — Structuring interfaces and blueprints with pure virtual functions, defining behavior guidelines without enforcing state structures.

---

## 🛡️ Orthodox Canonical Class Form (OCCF)

To ensure memory safety and avoid leaks, double-frees, or undefined copy behaviors, every class in this repository (from Module 02 onwards) strictly complies with the **Orthodox Canonical Class Form**:

```cpp
class CanonicalClass {
public:
    CanonicalClass();                               // 1. Default Constructor
    CanonicalClass(const CanonicalClass& other);    // 2. Copy Constructor
    CanonicalClass& operator=(const CanonicalClass& other); // 3. Copy Assignment Operator
    ~CanonicalClass();                              // 4. Destructor
};
```

---

## ⚙️ VS Code Makefile Task Automation

To streamline workflow across many subfolders containing separate makefiles, a custom utility script is provided in the repository root:

- **[update_tasks.py](file:///C:/Users/ouvle/OneDrive/Documents/GitHub/CPP/update_tasks.py)**: Searches the folder structure for any file named `Makefile`, compiles an index list, and outputs/updates the VS Code configuration at `.vscode/tasks.json`.
- This enables users to select and build any exercise instantly from VS Code's "Run Build Task" command picker.

```bash
# Update build targets index in VS Code
python update_tasks.py
```

---

## 🏗️ Build & Run

### Compile a specific exercise

Every exercise contains a dedicated Makefile. You can compile them by navigating to the exercise directory:

```bash
# Navigate to C++ Module 04 - Exercise 00
cd cpp04/ex00

# Compile the project
make

# Run the executable
./Polymorphism
```

### Makefile Directives

Standard makefile commands implemented for each exercise:

- `make` — Compiles source files and creates the output binary.
- `make clean` — Removes temporary compilation objects (`.o` files).
- `make fclean` — Removes compilation objects and the compiled executable.
- `make re` — Triggers a full compilation from scratch.

---

<div align="center">

Made with 💻 at **[1337 School](https://1337.ma)** (42 Network)

</div>