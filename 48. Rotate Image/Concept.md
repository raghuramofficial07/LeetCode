# » CodeBook .Md — Rotating a 2D Matrix by 90 Degrees (Clockwise)

<!-- GitHub Project Banner -->
<p align="center">
  <img src="https://github.com/user-attachments/assets/501c98ee-809c-4376-b32d-6d38ae07c489" alt="Project Banner" width="100%">
</p>

![Difficulty: Medium](https://img.shields.io/badge/Difficulty-Medium-orange?style=flat)
---

## » Table of Contents

* Introduction
* Problem Statement
* Approach Overview
* Code Explanation
* Dry Run Example
* Concept Highlights
* Real-World Use Cases
* Quick Reference Table
* Author Footer

---

## » Introduction

This CodeBook explains the logic behind rotating a 2D matrix (square) by 90 degrees clockwise using **an extra matrix**. This is a common coding interview question used to test understanding of matrix manipulation and coordinate transformation.

---

## » Problem Statement

Given an `n x n` 2D matrix, rotate it **90 degrees clockwise**.

> Example:

```
Input:
[
 [1, 2, 3],
 [4, 5, 6],
 [7, 8, 9]
]

Output:
[
 [7, 4, 1],
 [8, 5, 2],
 [9, 6, 3]
]
```

---

## » Approach Overview

The logic uses a temporary matrix called `ans` to store the rotated result.
We follow the rule:

```
matrix[i][j] → ans[j][n - 1 - i]
```

This moves the value at row `i` and column `j` of the original matrix to the correct rotated position in `ans`.

---

## » Code Explanation

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size(); // Get size of matrix (assumes square matrix)

        // Create a new n x n matrix filled with 0
        vector<vector<int>> ans(n, vector<int>(n));

        // Step 1: Fill 'ans' with rotated values
        for (int i = 0; i < n; i++) {       // Row in original
            for (int j = 0; j < n; j++) {   // Column in original
                ans[j][n - 1 - i] = matrix[i][j]; // Rotate logic
            }
        }

        // Step 2: Copy rotated matrix back to original
        matrix = ans;
    }
};
```

---

## » Dry Run Example

Let's dry run the rotation on this matrix:

### Input:

```
matrix =
[
 [1, 2, 3],
 [4, 5, 6],
 [7, 8, 9]
]
```

### Rotation Logic:

```
ans[j][n - 1 - i] = matrix[i][j]
```

### Step-by-step Fill of `ans`:

| i | j | matrix[i][j] | ans[j][n-1-i] becomes |
| - | - | ------------ | --------------------- |
| 0 | 0 | 1            | ans[0][2] = 1         |
| 0 | 1 | 2            | ans[1][2] = 2         |
| 0 | 2 | 3            | ans[2][2] = 3         |
| 1 | 0 | 4            | ans[0][1] = 4         |
| 1 | 1 | 5            | ans[1][1] = 5         |
| 1 | 2 | 6            | ans[2][1] = 6         |
| 2 | 0 | 7            | ans[0][0] = 7         |
| 2 | 1 | 8            | ans[1][0] = 8         |
| 2 | 2 | 9            | ans[2][0] = 9         |

### Final Rotated Matrix:

```
[
 [7, 4, 1],
 [8, 5, 2],
 [9, 6, 3]
]
```

---

## » Concept Highlights

| Concept               | Description                                            |
| --------------------- | ------------------------------------------------------ |
| `matrix[i][j]`        | Original matrix element                                |
| `ans[j][n - 1 - i]`   | Rotated position of that element                       |
| `vector<vector<int>>` | 2D matrix in C++ using `std::vector`                   |
| `matrix = ans`        | Copying the rotated result back to the original matrix |

---

## » Real-World Use Cases

* **Image processing:** Rotating a pixel matrix of an image.
* **Game development:** Board transformations in Tetris, Sudoku, etc.
* **Matrix-based simulations:** Like rotating terrain maps or simulation boards.

---

## » Quick Reference Table

| Term                | Meaning                              |
| ------------------- | ------------------------------------ |
| `n`                 | Size of the matrix                   |
| `ans[j][n - 1 - i]` | Final position of `matrix[i][j]`     |
| `matrix = ans`      | Replace original with rotated matrix |

---

## » Author Footer

> Prepared by `RaghuRam`
> #BeyondCertifications #CodeWithRaghuRam #IndustryOriented
> For use in interviews, GitHub documentation, or DSA revision.

---
