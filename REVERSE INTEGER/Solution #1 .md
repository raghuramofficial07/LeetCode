# LeetCode #7 — Reverse Integer

> **Difficulty:** Medium | **Topic:** Math, Integer Overflow

-----

## Problem Summary

Given a signed 32-bit integer `x`, return `x` with its digits reversed.  
If the reversed value goes **outside** the range `[−2³¹, 2³¹ − 1]`, return `0`.

> ⚠️ You **cannot** use 64-bit integers.

**Examples:**

|Input|Output|
|-----|------|
|123  |321   |
|-123 |-321  |
|120  |21    |

-----

## Key Insight — Overflow Detection Without 64-bit

Since we can’t store 64-bit integers, we must detect overflow **before** it happens.

```
INT_MAX =  2147483647  →  2³¹ - 1
INT_MIN = -2147483648  →  -2³¹
```

Before doing `result = result * 10 + digit`, check:

- If `result > INT_MAX / 10` → overflow guaranteed
- If `result == INT_MAX / 10` and `digit > 7` → overflow (last digit of INT_MAX is 7)
- Mirror logic for negative side (last digit of INT_MIN is 8, but digit will be negative)

-----

## Approach 1 — Math (Pop & Push Digits)

**Strategy:** Extract digits one by one from the right using `% 10`, build the reversed number using `* 10 + digit`, and check for overflow before each push.

**Time:** O(log x) — number of digits  
**Space:** O(1)

-----

### Python

```python
class Solution:
    def reverse(self, x: int) -> int:
        INT_MAX = 2**31 - 1   # 2147483647
        INT_MIN = -2**31      # -2147483648

        result = 0
        sign = -1 if x < 0 else 1
        x = abs(x)

        while x != 0:
            digit = x % 10
            x //= 10

            # Overflow check before pushing
            if result > (INT_MAX - digit) // 10:
                return 0

            result = result * 10 + digit

        return sign * result
```

> 💡 Python integers are arbitrary precision, so we simulate 32-bit limits manually.

-----

### Java

```java
class Solution {
    public int reverse(int x) {
        int result = 0;

        while (x != 0) {
            int digit = x % 10;
            x /= 10;

            // Overflow check
            if (result > Integer.MAX_VALUE / 10 ||
               (result == Integer.MAX_VALUE / 10 && digit > 7)) return 0;
            if (result < Integer.MIN_VALUE / 10 ||
               (result == Integer.MIN_VALUE / 10 && digit < -8)) return 0;

            result = result * 10 + digit;
        }

        return result;
    }
}
```

> 💡 Java’s `%` on negative numbers preserves sign: `-123 % 10 = -3`. This handles negatives automatically!

-----

### JavaScript

```javascript
var reverse = function(x) {
    const MAX = 2**31 - 1;  // 2147483647
    const MIN = -(2**31);   // -2147483648

    let result = 0;

    while (x !== 0) {
        const digit = x % 10;  // preserves sign in JS too
        x = Math.trunc(x / 10); // trunc avoids float issues

        if (result > Math.trunc(MAX / 10) ||
           (result === Math.trunc(MAX / 10) && digit > 7)) return 0;
        if (result < Math.trunc(MIN / 10) ||
           (result === Math.trunc(MIN / 10) && digit < -8)) return 0;

        result = result * 10 + digit;
    }

    return result;
};
```

> ⚠️ Use `Math.trunc()` instead of `parseInt()` for division — avoids floating-point edge cases.

-----

### C++

```cpp
class Solution {
public:
    int reverse(int x) {
        int result = 0;

        while (x != 0) {
            int digit = x % 10;
            x /= 10;

            if (result > INT_MAX / 10 ||
               (result == INT_MAX / 10 && digit > 7)) return 0;
            if (result < INT_MIN / 10 ||
               (result == INT_MIN / 10 && digit < -8)) return 0;

            result = result * 10 + digit;
        }

        return result;
    }
};
```

> 💡 C++ `int` is exactly 32-bit on most platforms. `INT_MAX` and `INT_MIN` are from `<climits>`.

-----

## Approach 2 — String Reversal

**Strategy:** Convert to string, reverse it, parse back to integer, then check range.

**Time:** O(log x)  
**Space:** O(log x) — for the string

> ⚠️ Easier to code but uses extra space and is generally slower in practice.

-----

### Python

```python
class Solution:
    def reverse(self, x: int) -> int:
        sign = -1 if x < 0 else 1
        reversed_str = str(abs(x))[::-1]
        result = sign * int(reversed_str)

        if result < -(2**31) or result > 2**31 - 1:
            return 0
        return result
```

-----

### Java

```java
class Solution {
    public int reverse(int x) {
        boolean negative = x < 0;
        String s = Integer.toString(Math.abs(x));
        String rev = new StringBuilder(s).reverse().toString();

        try {
            int result = Integer.parseInt(rev);
            return negative ? -result : result;
        } catch (NumberFormatException e) {
            return 0;  // overflow
        }
    }
}
```

-----

### JavaScript

```javascript
var reverse = function(x) {
    const sign = x < 0 ? -1 : 1;
    const reversed = parseInt(String(Math.abs(x)).split('').reverse().join(''));
    const result = sign * reversed;

    if (result > 2**31 - 1 || result < -(2**31)) return 0;
    return result;
};
```

-----

### C++

```cpp
class Solution {
public:
    int reverse(int x) {
        string s = to_string(abs(x));
        std::reverse(s.begin(), s.end());

        try {
            long long result = stoll(s) * (x < 0 ? -1 : 1);
            if (result > INT_MAX || result < INT_MIN) return 0;
            return (int)result;
        } catch (...) {
            return 0;
        }
    }
};
```

> ⚠️ Technically uses `long long` for the check — valid only if the problem statement allows it implicitly for the boundary check step. Purists should use Approach 1.

-----

## Approach 3 — Recursive Digit Extraction

**Strategy:** Use recursion to peel off digits. More of an academic/interview variant.

**Time:** O(log x)  
**Space:** O(log x) — call stack

-----

### Python

```python
class Solution:
    def reverse(self, x: int) -> int:
        def helper(n, rev):
            if n == 0:
                return rev
            return helper(n // 10, rev * 10 + n % 10)

        sign = -1 if x < 0 else 1
        result = sign * helper(abs(x), 0)

        if result < -(2**31) or result > 2**31 - 1:
            return 0
        return result
```

-----

### Java

```java
class Solution {
    private int helper(int n, int rev) {
        if (n == 0) return rev;
        return helper(n / 10, rev * 10 + n % 10);
    }

    public int reverse(int x) {
        boolean neg = x < 0;
        long result = helper(Math.abs(x), 0) * (neg ? -1 : 1);
        if (result > Integer.MAX_VALUE || result < Integer.MIN_VALUE) return 0;
        return (int) result;
    }
}
```

-----

## Approach Comparison

|Approach         |Time    |Space   |64-bit Safe          |Best For                 |
|-----------------|--------|--------|---------------------|-------------------------|
|Math (Pop & Push)|O(log n)|O(1)    |✅ Yes                |Interviews, production   |
|String Reversal  |O(log n)|O(log n)|⚠️ Depends on language|Quick coding, readability|
|Recursive        |O(log n)|O(log n)|⚠️ Language-dependent |Academic exploration     |

-----

## Overflow Cheat Sheet

```
INT_MAX = 2147483647
    Last digit = 7

INT_MIN = -2147483648
    Last digit = -8 (when sign preserved)

Overflow condition before: result = result * 10 + digit
  → Positive: result > INT_MAX/10  OR  (result == INT_MAX/10 AND digit > 7)
  → Negative: result < INT_MIN/10  OR  (result == INT_MIN/10 AND digit < -8)
```

-----

## Language-Specific Notes

|Language  |% on negatives                |Division truncation  |32-bit int guaranteed           |
|----------|------------------------------|---------------------|--------------------------------|
|Python    |Always positive (floor)       |Use `//` carefully   |No — arbitrary precision        |
|Java      |Same sign as dividend         |Truncates toward zero|✅ Yes                           |
|JavaScript|Same sign as dividend         |Use `Math.trunc()`   |No — use `|0` or check          |
|C++       |Same sign as dividend (C++11+)|Truncates toward zero|Platform-dependent (usually yes)|

-----

## Recommended Approach Per Language

- **Python** → Math approach with manual `abs()` and sign tracking
- **Java** → Math approach; `%` handles negatives naturally
- **JavaScript** → Math approach with `Math.trunc()`
- **C++** → Math approach; cleanest and most efficient

-----

*Notes compiled for LeetCode #7 — Reverse Integer*
