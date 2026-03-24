# C++ Cast Operators

Mastery of C++ type conversion system: implicit/explicit conversions, static_cast, dynamic_cast, reinterpret_cast, const_cast, and type detection via RTTI — plus a scalar type convertor exercise.

## Cast Types

### static_cast
Compile-time checked conversions between related types:
```cpp
double d = 3.14;
int i = static_cast<int>(d);  // 3 — no UB, checked at compile time
```

### dynamic_cast
Runtime-safe downcasting in polymorphic hierarchies:
```cpp
Base *b = new Derived();
Derived *d = dynamic_cast<Derived*>(b);  // succeeds
Wrong   *w = dynamic_cast<Wrong*>(b);    // returns nullptr (safe)
```

### reinterpret_cast
Bitwise type reinterpretation (low-level, unsafe):
```cpp
uintptr_t addr = reinterpret_cast<uintptr_t>(ptr);
```

### const_cast
Add or remove `const` qualifier:
```cpp
const char *cstr = "hello";
char *str = const_cast<char*>(cstr);
```

## Scalar Converter Exercise

Parses a string literal into `char`, `int`, `float`, and `double` with edge case handling:

```
./convert "42.0f"
char:   *
int:    42
float:  42.0f
double: 42.0

./convert "nan"
char:   impossible
int:    impossible
float:  nanf
double: nan
```

## Tech Stack

`C++98` `RTTI` `dynamic_cast` `static_cast` `Type Conversion` `Polymorphism`

