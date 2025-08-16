# 🧩 Problem: Maximum 69 Number (LeetCode 1323)

## 📖 Problem Statement
You are given a positive integer `num` consisting only of the digits **6** and **9**.  

Your task is to **maximize the number** by changing **at most one digit**:
- You can change a `6` to a `9`, or
- A `9` to a `6`.

Return the maximum possible number after at most one change.

---

## ✅ Example Scenarios

### Example 1
**Input:**  num = 9669

    **Process:**  
- Change the 1st digit → `6669`  
- Change the 2nd digit → `9969` ✅  
- Change the 3rd digit → `9699`  
- Change the 4th digit → `9666`  

**Output:**  9969




//Solution

class Solution {
public:
    int maximum69Number (int num) {
      
        string str = to_string(num);// convert to string

        for(int i=0; i<str.size(); i++){
            if(str[i] == '6'){
                str[i] = '9';
                break;
            }
        }
        return stoi(str); //string to int
    }
};
