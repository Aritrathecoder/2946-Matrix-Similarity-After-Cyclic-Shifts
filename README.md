# Matrix-Similarity-After-Cyclic-Shifts
You are given an m x n integer matrix mat and an integer k. The matrix rows are 0-indexed.  The following proccess happens k times:  Even-indexed rows (0, 2, 4, ...) are cyclically shifted to the left.Odd-indexed rows (1, 3, 5, ...) are cyclically shifted to the right.

2573. Find the String with LCP
Solved
Hard
Topics
premium lock icon
Companies
Hint
We define the lcp matrix of any 0-indexed string word of n lowercase English letters as an n x n grid such that:

lcp[i][j] is equal to the length of the longest common prefix between the substrings word[i,n-1] and word[j,n-1].
Given an n x n matrix lcp, return the alphabetically smallest string word that corresponds to lcp. If there is no such string, return an empty string.

A string a is lexicographically smaller than a string b (of the same length) if in the first position where a and b differ, string a has a letter that appears earlier in the alphabet than the corresponding letter in b. For example, "aabd" is lexicographically smaller than "aaca" because the first position they differ is at the third letter, and 'b' comes before 'c'.

 

Example 1:

Input: lcp = [[4,0,2,0],[0,3,0,1],[2,0,2,0],[0,1,0,1]]
Output: "abab"
Explanation: lcp corresponds to any 4 letter string with two alternating letters. The lexicographically smallest of them is "abab".
Example 2:

Input: lcp = [[4,3,2,1],[3,3,2,1],[2,2,2,1],[1,1,1,1]]
Output: "aaaa"
Explanation: lcp corresponds to any 4 letter string with a single distinct letter. The lexicographically smallest of them is "aaaa". 
Example 3:

Input: lcp = [[4,3,2,1],[3,3,2,1],[2,2,2,1],[1,1,1,3]]
Output: ""
Explanation: lcp[3][3] cannot be equal to 3 since word[3,...,3] consists of only a single letter; Thus, no answer exists.
 

Constraints:

1 <= n == lcp.length == lcp[i].length <= 1000
0 <= lcp[i][j] <= n

<img width="1643" height="966" alt="Screenshot 2026-03-31 235811" src="https://github.com/user-attachments/assets/ea58f17a-2ca3-48d8-85dc-6a0f3fe204ee" />


## 💡 Approach

Instead of simulating k operations, we observe that shifting a row k times is equivalent to shifting it by:

k % n

- Even-indexed rows → left shift
- Odd-indexed rows → right shift

We directly compare the final position of each element with the original.

## ⏱ Complexity
- Time: O(m × n)
- Space: O(1)


## 💻 C Solution

```c
#include <stdbool.h>

bool areSimilar(int** mat, int matSize, int* matColSize, int k) {
    int m = matSize;
    int n = matColSize[0];

    int shift = k % n;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int newIndex;

            if (i % 2 == 0) {
                newIndex = (j + shift) % n;
            } else {
                newIndex = (j - shift + n) % n;
            }

            if (mat[i][j] != mat[i][newIndex]) {
                return false;
            }
        }
    }

    return true;
}



---

## 4. 🌟 Add Example Section

```md
## 📌 Example

Input:
mat = [[1,2,3],[4,5,6],[7,8,9]], k = 4

Output:
false

![Language](https://img.shields.io/badge/Language-C-blue)
![Difficulty](https://img.shields.io/badge/LeetCode-Medium-orange)

DSA/
 ├── Arrays/
 │    └── Matrix-Similarity/
 ├── Strings/
 ├── Graphs/
