# C. Make Product Equal One

## Problem Statement

You are given an array of `n` integers `a1, a2, ..., an`.

In one operation, you can:
- Choose any element
- Increase or decrease it by `1`
- Cost of each operation = **1 coin**

Your goal is to make the product of all elements equal to `1`:


a1 × a2 × ... × an = 1


Return the minimum number of coins required.

---

## Idea / Key Insight

At first, the problem looks like a simple conversion of all numbers into `1` or `-1`.

However, the tricky part is handling **zero values**, which significantly affects the final answer.

### Observations

- Any number must eventually become either `1` or `-1`
- Cost to convert:
  - `x → 1` = `|x - 1|`
  - `x → -1` = `|x + 1|`
- `0` is special:
  - `0 → 1` costs `1`
  - It can help fix sign parity issues

---

## Important Edge Case

If there are **no zeros** and the number of negative elements is odd, we must pay an extra cost of `2`.

If there is at least one zero, we can adjust signs without extra penalty.

👉 This makes the problem more subtle than it appears.

Honestly, the handling of `0` is the part that impressed me the most — it completely changes how the final answer is determined. It’s not as simple or fast as it first looks.

---

## Algorithm

1. Read `n`
2. Initialize:
   - `ans = 0`
   - `check = 1` (tracks parity of negatives)
   - `countzero = 0`
3. For each element:
   - If `temp != 0`:
     - `ans += abs(1 - abs(temp))`
   - Else:
     - `ans += 1`
     - `countzero++`
   - If `temp < 0`, flip `check`
4. Final adjustment:
   - If `check == -1`:
     - If `countzero == 0`, add `2`
5. Output `ans`

---

## Complexity Analysis

- **Time Complexity:** `O(n)`
- **Space Complexity:** `O(1)` (excluding input storage)

---

## Code Implementation

```cpp
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    long long ans = 0;
    int check = 1;
    int temp;
    int countzero = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> temp;

        if (temp != 0)
            ans += abs(1 - abs(temp));
        else
        {
            ans += 1;
            countzero++;
        }

        if (temp < 0)
            check *= -1;
    }

    if (check == -1 && countzero == 0)
        ans += 2;

    cout << ans << "\n";
}
```
# Summary

This problem demonstrates how a seemingly simple greedy transformation hides an important global constraint: sign parity.

The presence of 0 is what makes the solution non-trivial — it changes the structure of the optimal strategy completely.