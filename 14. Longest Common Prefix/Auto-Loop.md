# C++ Range-Based For Loop Example

This README explains how the following C++ loop works **under the hood**:

```cpp
for (const auto& wd : str) {
    // do something with wd
}
```

---

## 🧠 What Does This Loop Do?

This is called a **range-based for loop**.  
It **iterates** over each element in the container `str` (which can be an array, `std::vector`, etc.).  
On each iteration, the variable `wd` refers to the **current element**.

---

## 🛠️ Breakdown of Each Part

✅ **1. `auto`**

- `auto` tells the compiler:
  > *"Figure out the actual type automatically."*
- If `str` is an array of `std::string`, then `wd` is of type `std::string`.

✅ **2. `&` (Reference)**

- The `&` makes `wd` a **reference** to the original element.
- This avoids copying data on each iteration.
- If you omit `&`, each iteration **creates a copy** of the element.

✅ **3. `const`**

- `const` ensures you **cannot modify** the element through `wd`.
- Protects the data from accidental changes.
- Example: You **cannot** do `wd = "New String";` because `wd` is `const`.

✅ **4. `str`**

- This is the container you are looping over.
- It can be:
  - An array: `std::string str[] = {"A", "B", "C"};`
  - A vector: `std::vector<std::string> str = {...};`
  - Any container that supports iteration.

---

## 🔍 Example in Action

**Full example that prints each string and its length:**

```cpp
#include <iostream>
#include <string>

int main() {
    std::string str[] = {"Flower", "Fire", "RR"};

    for (const auto& wd : str) {
        std::cout << "String: " << wd
                  << ", Length: " << wd.length()
                  << std::endl;
    }
}
```

**Output:**
```
String: Flower, Length: 6
String: Fire, Length: 4
String: RR, Length: 2
```

---

## ⚖️ Comparison Table

| Syntax                 | What It Means                                                |
|------------------------|--------------------------------------------------------------|
| `auto wd`              | A **copy** of each element.                                  |
| `auto& wd`             | A **modifiable reference** to each element.                  |
| `const auto& wd`       | A **read-only reference** to each element (safest & fastest).|

---

## 🛡️ Why Use `const auto&`?

- **No Copies:** Faster, especially for big objects like `std::string`.
- **No Accidental Modification:** Keeps data safe.
- **Cleaner Code:** You don’t need to write the type explicitly.

---

## ✨ Quick Tips

✅ Use `const auto&` when you:
- Just need to read data.
- Want performance.
- Want safer code.

✅ Use `auto&` if you plan to **modify** elements inside the loop.

✅ Use `auto` if you need a **copy** (rare in most cases).

---

## 🧩 Under the Hood

This loop is roughly equivalent to:

```cpp
for (auto it = std::begin(str); it != std::end(str); ++it) {
    const std::string& wd = *it;
    // do something with wd
}
```

---

Feel free to copy-paste this README into your project to understand or document your C++ code more easily.
