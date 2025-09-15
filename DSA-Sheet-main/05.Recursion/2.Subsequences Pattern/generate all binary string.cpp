
**Question:**
Generate all binary strings of length `n` such that no two consecutive `1`s appear.

---

**Keypoints that summarize the approach:**

* Use **recursion + backtracking**.
* At each step, you can always place `'0'`.
* You can place `'1'` **only if the last character is not `'1'`**.
* Continue until the current string length = `n`.
* Store the string when a valid one is formed.

---

**Example:**

Input: `n = 3`
Valid binary strings (no consecutive 1s):

```
000  
001  
010  
100  
101
```

Output: `["000", "001", "010", "100", "101"]`

---

**Code:**

```cpp
// User function Template for C++

class Solution {
  public:
    vector<string> generateBinaryStrings(int n) {
        vector<string> res;
        string cur;
        generateNoConsec(n, cur, res);
        return res;
    }
    
  private:
    void generateNoConsec(int n, string &cur, vector<string> &res) {
        if ((int)cur.size() == n) {
            res.push_back(cur);
            return;
        }
        // Always allow '0'
        cur.push_back('0');
        generateNoConsec(n, cur, res);
        cur.pop_back();

        // Allow '1' only if last character isn't '1'
        if (cur.empty() || cur.back() != '1') {
            cur.push_back('1');
            generateNoConsec(n, cur, res);
            cur.pop_back();
        }
    }
};
```

---

**Time Complexity:** O(2^n) in worst case (though fewer strings are valid).
**Space Complexity:** O(n) recursion stack.

---

✅ Your code is correct.
Would you like me to also draw the **recursion tree for n=3** so you can see how strings like `101` and `010` are formed?
