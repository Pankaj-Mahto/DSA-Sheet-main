**Question:**
Generate all binary strings of length `N`.

**Keypoints that summarize the approach:**

* Use **recursion + backtracking**.
* At each index, you can place either `'0'` or `'1'`.
* Recurse until the string length = `N`, then print/store it.
* This ensures all `2^N` possible binary strings are generated.

---

**Example:**

Input: `N = 3`
Possible binary strings:

```
000  
001  
010  
011  
100  
101  
110  
111
```

Output: `["000", "001", "010", "011", "100", "101", "110", "111"]`

---

**Code:**

#include <bits/stdc++.h>
using namespace std;

void generateBinary(int n, string current, vector<string>& result) {
    if (current.size() == n) {
        result.push_back(current);
        return;
    }
    generateBinary(n, current + "0", result);
    generateBinary(n, current + "1", result);
}

vector<string> generateAllBinaryStrings(int n) {
    vector<string> result;
    generateBinary(n, "", result);
    return result;
}

int main() {
    int n = 3;
    vector<string> res = generateAllBinaryStrings(n);
    for (auto &str : res)
        cout << str << " ";
    return 0;
}
```

---

**Time Complexity:** O(2^N) → Each binary string is generated.
**Space Complexity:** O(N) (recursion stack depth).

