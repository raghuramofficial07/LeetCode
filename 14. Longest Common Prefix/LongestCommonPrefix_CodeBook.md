<!-- GitHub Project Banner -->
<p align="center">
  <img src="https://github.com/user-attachments/assets/501c98ee-809c-4376-b32d-6d38ae07c489" alt="Project Banner" width="100%">
</p>

# » Topic Title
Longest Common Prefix - Leetcode Problem 14

# » Table of Contents
- Introduction
- Code Example with Explanation
- Concept Highlights
- Real-World Use Cases
- Quick Reference Table
- Author Footer

# » Introduction
This document explains a clear approach to solving the Longest Common Prefix problem. The strategy is to first identify the shortest string among the inputs and then compare each character position across all strings to efficiently detect any mismatches. This prevents unnecessary comparisons beyond the length of the shortest word.

# » Code Example with Explanation

```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        // Find the shortest string to use as reference
        string word = strs[0];
        for (const string& s : strs) {
            if (s.length() < word.length()) {
                word = s;
            }
        }

        // Compare characters of the reference word with all others
        for (int i = 0; i < word.length(); ++i) {
            char c = word[i];
            for (const string& s : strs) {
                if (s[i] != c) {
                    // Mismatch found; return prefix up to this point
                    return word.substr(0, i);
                }
            }
        }

        // All characters matched; return entire shortest word
        return word;
    }
};
```
Explanation:

If the input vector is empty, return an empty string.
Identify the shortest string (word) as the reference.
Loop through each character in word.
For each character position, compare it across all strings.
Return the substring up to the first mismatch, or the full word if all characters match.
» Concept Highlights

The longest common prefix cannot be longer than the shortest word.
Early termination occurs when a mismatch is detected.
Time complexity: O(N * M), where N is the number of strings and M is the length of the shortest string.
Space complexity: O(1), excluding the returned string.
» Real-World Use Cases

Auto-completion in code editors or search bars.
Suggesting prefixes in text prediction systems.
Grouping items by common prefixes in sorted datasets.
» Quick Reference Table
| Aspect           | Details                                       |
| ---------------- | --------------------------------------------- |
| Problem          | Longest Common Prefix                         |
| Approach         | Shortest string as reference, char comparison |
| Time Complexity  | O(N \* M)                                     |
| Space Complexity | O(1)                                          |
| Language         | C++                                           |

» Author Footer

Crafted and documented by RR
#BeyondCertifications #IndustryOriented #CodeWithRaghuRam
