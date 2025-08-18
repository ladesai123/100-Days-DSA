/*
# Two Sum Problem (C++)

## Problem:
You are given an array of integers `nums` and an integer `target`.
Return the indices of the two numbers such that they add up to `target`.

You may assume that each input has **exactly one solution**, and you may not use the same element twice.
You can return the answer in any order.

---

## Example:
Input: nums = [2,7,11,15], target = 9  
Output: [0,1]  
Explanation: Because nums[0] + nums[1] == 9.

---

## Approaches:

### 1. Brute Force (O(n^2)):
- Check every pair (i, j).
- If nums[i] + nums[j] == target, return {i, j}.

### 2. Better (Using Hashing but with Two Passes, O(n)):
- First, store all elements in a map with value -> index.
- Then loop again and check if target - nums[i] exists in the map.

### 3. Optimal (One Pass Hashing, O(n)):
- Use a hashmap while traversing:
    - For each element, calculate the "needed" value = target - nums[i].
    - If "needed" already exists in the map, return the indices.
    - Otherwise, store nums[i] with its index in the map.

This way, you find the answer in a single loop.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // ---------- 1. Brute Force ----------
    vector<int> twoSumBrute(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j}; // found the pair
                }
            }
        }
        return {};
    }

    // ---------- 2. Better Approach ----------
    vector<int> twoSumBetter(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // value -> index
        int n = nums.size();

        // Store all elements in map
        for (int i = 0; i < n; i++) {
            mp[nums[i]] = i;
        }

        // Check for complement
        for (int i = 0; i < n; i++) {
            int needed = target - nums[i];
            if (mp.find(needed) != mp.end() && mp[needed] != i) {
                return {i, mp[needed]};
            }
        }
        return {};
    }

    // ---------- 3. Optimal Approach ----------
    vector<int> twoSumOptimal(vector<int>& nums, int target) {
        unordered_map<int, int> mp; // value -> index
        for (int i = 0; i < nums.size(); i++) {
            int needed = target - nums[i];

            // If we already saw the "needed" value, return answer
            if (mp.find(needed) != mp.end()) {
                return {mp[needed], i};
            }

            // Otherwise, store current value with its index
            mp[nums[i]] = i;
        }
        return {};
    }
};

// ---------- Main Function for Testing ----------
int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    // Brute Force
    vector<int> ans1 = sol.twoSumBrute(nums, target);
    cout << "Brute Force: [" << ans1[0] << ", " << ans1[1] << "]\n";

    // Better
    vector<int> ans2 = sol.twoSumBetter(nums, target);
    cout << "Better: [" << ans2[0] << ", " << ans2[1] << "]\n";

    // Optimal
    vector<int> ans3 = sol.twoSumOptimal(nums, target);
    cout << "Optimal: [" << ans3[0] << ", " << ans3[1] << "]\n";

    return 0;
}

/*
---
## Complexity:
- Brute Force: O(n^2), no extra space
- Better: O(n), O(n) space (two passes)
- Optimal: O(n), O(n) space (one pass)

✅ Optimal is the best solution.
*/
