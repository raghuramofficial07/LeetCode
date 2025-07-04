<!-- GitHub Project Banner -->
<p align="center">
  <img src="https://github.com/user-attachments/assets/501c98ee-809c-4376-b32d-6d38ae07c489" alt="Project Banner" width="100%">
</p>

# Majority Element – Sorting & Counting Approach

## 🟢 Problem Statement
Given an array `nums` of size `n`, return the majority element.  
The majority element is the element that appears more than ⌊ n/2 ⌋ times.  
You may assume that the majority element always exists in the array.

---

## 🟡 Approach (My Custom Strategy)
1. **Sort** the array in ascending order.
2. Initialize two counters:
   - `count1`: tracks the highest frequency observed so far.
   - `count2`: counts occurrences of the current element.
3. Use a loop:
   - Compare each element with the next.
   - If they are the same, increment `count2`.
   - If different (or at the end), check if `count2` exceeds `count1`.
   - If it does, update `count1` and record the current element as the majority candidate.
4. After completing the loop, return the element stored as the majority.

---

## 🟣 Time Complexity
**O(n log n)**  
- The sorting step dominates the complexity.

---

## 🟢 C++ Implementation

```cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int count1 = 0;
        int count2 = 0;
        int majority = nums[0];

        for (int i = 0; i < n;) {
            int current = nums[i];
            count2 = 0;
            while (i < n && nums[i] == current) {
                count2++;
                i++;
            }
            if (count2 > count1) {
                count1 = count2;
                majority = current;
            }
        }
        return majority;
    }
};
```
