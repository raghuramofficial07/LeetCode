<!-- GitHub Project Banner -->
<p align="center">
  <img src="https://github.com/user-attachments/assets/501c98ee-809c-4376-b32d-6d38ae07c489" alt="Project Banner" width="100%">
</p>

# » Pascal's Triangle Single Row Extraction

## » Table of Contents
- Introduction
- Pattern Identification
- Approach Explanation
- Under The Hood (Step by Step)
- Code Example
- Concept Highlights
- Real-World Use Case
- Quick Reference Table
- Author Footer

---

## » Introduction
This document explains how to extract a specific row from Pascal’s Triangle using a **2D array construction approach**.  
We incrementally build each row based on the known recurrence relation, but only return the row of interest instead of the entire triangle.

---

## » Pattern Identification
**Identified Pattern:**
- Each element in Pascal’s Triangle follows:
```
pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j]
```
- The edge elements are always:
```
pascal[i][0] = 1
pascal[i][i] = 1
```
- All interior elements depend on the sum of the two elements directly above.

**How We Got Rid of Unnecessary Layers:**
- Normally, generating Pascal’s Triangle involves storing all rows in a `vector<vector<int>>`.
- Here, we build all rows in a fixed-size 2D array but **only copy the final row into the result**.
- This avoids keeping all previous rows in the output structure.

**How We Understand This:**
- The triangle grows row by row.
- Because each row depends only on the immediately previous row, you don’t need to store all rows permanently.
- We take advantage of this by copying only the desired row when we reach it.

---

## » Approach Explanation
1. **Initialization:**
 - Define a 2D array `pascal[rowIndex + 1][rowIndex + 1]` to hold the computed elements.
 - Define a `result` vector of size `rowIndex + 1` for the output row.

2. **Row Construction Loop:**
 - For each `i` from `0` to `rowIndex`:
   - For each `j` in `0...i`:
     - If `j` is at the edge (`0` or `i`), assign `1`.
     - Otherwise, compute as:
       ```
       pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j]
       ```
     - If `i` equals `rowIndex`, assign `pascal[i][j]` to `result[j]`.

3. **Return the Result:**
 - Once all rows are computed, return `result`.

---

## » Under The Hood (Step by Step)
```
Example: rowIndex = 3

Iteration i=0:
j=0:
pascal[0][0]=1

Iteration i=1:
j=0:
pascal[1][0]=1
j=1:
pascal[1][1]=1

Iteration i=2:
j=0:
pascal[2][0]=1
j=1:
pascal[2][1]=pascal[1][0]+pascal[1][1]=1+1=2
j=2:
pascal[2][2]=1

Iteration i=3:
j=0:
pascal[3][0]=1
result[0]=1
j=1:
pascal[3][1]=pascal[2][0]+pascal[2][1]=1+2=3
result[1]=3
j=2:
pascal[3][2]=pascal[2][1]+pascal[2][2]=2+1=3
result[2]=3
j=3:
pascal[3][3]=1
result[3]=1

Final Output: [1,3,3,1]
```

---

## » Code Example

```cpp
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int pascal[rowIndex + 1][rowIndex + 1];
        vector<int> result(rowIndex + 1);

        for (int i = 0; i <= rowIndex; i++) {
            for (int j = 0; j <= i; j++) {
                if (j == 0 || j == i)
                    pascal[i][j] = 1;
                else
                    pascal[i][j] = pascal[i - 1][j - 1] + pascal[i - 1][j];

                if (i == rowIndex) {
                    result[j] = pascal[i][j];
                }
            }
        }
        return result;
    }
};
```
» Concept Highlights

Pascal’s Triangle is defined by a recurrence relation.
Edge elements are always 1.
All other elements are sums of the two numbers directly above.
By copying only the target row, we avoid extra memory usage for storing all rows in a separate structure.
» Real-World Use Case

Calculating binomial coefficients (n choose k).
Modeling combinatorial structures.
Generating polynomial expansions in algebra.

» Quick Reference Table

| Term           | Meaning                                            |
| -------------- | -------------------------------------------------- |
| pascal\[i]\[j] | Element at row `i`, column `j`.                    |
| rowIndex       | The desired row index (0-based).                   |
| Edge Elements  | Always `1` at start and end of each row.           |
| Recurrence     | pascal\[i]\[j]=pascal\[i-1]\[j-1]+pascal\[i-1]\[j] |

---

## » Author Footer

_Curated and documented by Vemparala Sri Satya RaghuRam — #BeyondCertifications #IndustryOriented #CodeWithRaghuRam_


