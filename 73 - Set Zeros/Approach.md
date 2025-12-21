<!-- GitHub Project Banner -->
<p align="center">
  <img src="https://github.com/user-attachments/assets/501c98ee-809c-4376-b32d-6d38ae07c489" alt="Project Banner" width="100%">
</p>

<p align="center">
  <img src="https://img.shields.io/badge/LeetCode-Set%20Matrix%20Zeroes-black?logo=leetcode&logoColor=white&labelColor=black&color=black">
  <img src="https://img.shields.io/badge/Built%20by-RaghuRam-black?labelColor=black&color=black">
</p>

# Set Matrix Zeroes — Logic & Keyword Decomposition

## » Table of Contents
- Introduction: The Mission
- Code Breakdown: Keyword Analysis
- The Story of Execution
- Implementation & Syntax
- Real-World Use Case
- Quick Reference Table
- Tags
- Author Footer

## » Introduction: The Mission
Imagine a massive grid representing a city's power lines. If a single transformer fails (`0`), the entire street (row) and cross‑avenue (column) must be shut down.

## » Code Breakdown: Keyword Analysis
- `vector<vector<int>>& mat` → In‑place modification
- `vector<pair<int,int>> zeros` → Memory bank for original zeroes

## » Implementation & Syntax
```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<pair<int,int>> zeros;

        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(mat[i][j]==0)
                    zeros.push_back({i,j});

        for(auto &p: zeros){
            for(int j=0;j<m;j++) mat[p.first][j]=0;
            for(int i=0;i<n;i++) mat[i][p.second]=0;
        }
    }
};
```

## » Author Footer
Created By: Vemparala Sri Satya RaghuRam  
License: MIT  
Platform: C++ (DSA)
