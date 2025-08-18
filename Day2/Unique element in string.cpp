# LeetCode 387 - First Unique Character in a String

## Problem Statement
Given a string `s`, find the **first non-repeating character** in it and return its **index**.  
If it does not exist, return `-1`.

### Example 1
```
Input: s = "leetcode"
Output: 0
Explanation: 'l' is the first non-repeating character.
```

### Example 2
```
Input: s = "loveleetcode"
Output: 2
Explanation: 'v' is the first non-repeating character.
```

### Example 3
```
Input: s = "aabb"
Output: -1
Explanation: There is no non-repeating character.
```

---

## Approaches

We’ll go step by step from the **Brute Force** to the **Optimized solution**.

---

### 1. Brute Force Approach
- For each character in the string, scan the entire string to check if it occurs again.
- If we find exactly one occurrence, return its index.
- If no unique character is found, return `-1`.

#### Code
```cpp
class Solution {
public:
    int firstUniqChar(string s) {
        for (int i = 0; i < s.size(); i++) {
            bool isUnique = true;
            for (int j = 0; j < s.size(); j++) {
                if (i != j && s[i] == s[j]) {
                    isUnique = false;
                    break;
                }
            }
            if (isUnique) return i;
        }
        return -1;
    }
};
```

#### Complexity
- **Time:** O(n²) – for each character, we scan the string.  
- **Space:** O(1).

---

### 2. Better Approach (Using Hash Map / Unordered Map)
- Use an **unordered_map** to store frequency of each character.
- First pass: count occurrences of each character.
- Second pass: check which character’s frequency is 1 and return its index.

#### Code
```cpp
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> mp;

        // Step 1: Count frequency of each character
        for (char c : s) {
            mp[c]++;
        }

        // Step 2: Find first char with frequency 1
        for (int i = 0; i < s.size(); i++) {
            if (mp[s[i]] == 1) {
                return i;
            }
        }

        return -1;
    }
};
```

#### Complexity
- **Time:** O(n) – one pass to count, another to check.  
- **Space:** O(k), where `k` is number of unique characters (at most 26 for lowercase letters).

---

### 3. Optimized Approach (Using Frequency Array)
Since the string only contains lowercase letters (`'a'` to `'z'`),  
we can use an **array of size 26** instead of a hash map.

#### Code
```cpp
class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26] = {0};

        // Count frequency
        for (char c : s) {
            freq[c - 'a']++;
        }

        // Find first character with frequency 1
        for (int i = 0; i < s.size(); i++) {
            if (freq[s[i] - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }
};
```

#### Complexity
- **Time:** O(n).  
- **Space:** O(1) (fixed array of size 26).  

This is the **most optimal solution**.

---

## Summary
| Approach       | Time Complexity | Space Complexity | Notes |
|----------------|-----------------|------------------|-------|
| Brute Force    | O(n²)           | O(1)             | Compare each character with all others |
| Hash Map       | O(n)            | O(k)             | General approach, works with any charset |
| Frequency Array| O(n)            | O(1)             | Best for lowercase letters |

---

✅ **Recommended Solution:** Use the **frequency array** for optimal performance when input is lowercase letters.  
