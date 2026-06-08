# B. Long Jumps - Solution Review

## Problem Overview

Given an array `a` of length `n`, Polycarp can start from any index `i`.

For every move:

1. Add `a[i]` to the score.
2. Jump to index `i + a[i]`.
3. Continue until the position exceeds `n`.

The goal is to find the **maximum possible score** obtainable from an optimal starting position.

---

## Key Observation

Each position has **exactly one outgoing jump**:

```
i → i + a[i]
```

Since all values `a[i]` are positive, every jump moves strictly to the right.

This means:

* No cycles can exist.
* Every path eventually leaves the array.
* The score of a position depends only on the score accumulated before reaching it.

---

## Idea Behind This Solution

The solution uses a dynamic programming style propagation approach.

### Definition

`prefix[i]`

stores the maximum score that can be accumulated **before arriving at index `i`**.

Initially:

```cpp
vector<int> prefix(n+1, 0);
```

For every position `i`:

```cpp
prefix[i] + a[i]
```

represents the score obtained after collecting the value at `i`.

---

## State Transition

### Case 1: Jump stays inside the array

If:

```cpp
i + a[i] <= n
```

then we can continue the path.

Update the destination:

```cpp
prefix[i+a[i]] =
    max(prefix[i+a[i]], prefix[i] + a[i]);
```

This means:

* Reach position `i`
* Collect `a[i]`
* Move to `i + a[i]`
* Store the best score possible before reaching that destination

---

### Case 2: Jump leaves the array

If:

```cpp
i + a[i] > n
```

the game ends after collecting `a[i]`.

The final score is:

```cpp
prefix[i] + a[i]
```

Update the answer:

```cpp
ans = max(ans, prefix[i] + a[i]);
```

---

## Example

Input:

```text
5
7 3 1 2 3
```

Processing:

### i = 1

```cpp
1 + 7 > 5
```

Game ends immediately.

Score:

```cpp
0 + 7 = 7
```

```cpp
ans = 7
```

---

### i = 2

```cpp
2 + 3 = 5
```

Update:

```cpp
prefix[5] = 3
```

---

### i = 5

Current:

```cpp
prefix[5] = 3
```

Score:

```cpp
3 + 3 = 6
```

Game ends.

```cpp
ans = max(7, 6) = 7
```

Final answer:

```text
7
```

---

## Complexity Analysis

For each test case:

* Every index is processed exactly once.
* Each transition is O(1).

Therefore:

### Time Complexity

```text
O(n)
```

per test case.

Since:

```text
Σ n ≤ 2 × 10^5
```

the solution easily fits within limits.

### Space Complexity

```text
O(n)
```

for the `prefix` array.

---

## Correctness Argument

The algorithm maintains the invariant:

> `prefix[i]` always contains the maximum score obtainable before reaching index `i`.

When processing index `i`:

* The score after visiting `i` becomes `prefix[i] + a[i]`.
* If the jump remains inside the array, this score is propagated to the destination.
* If the jump exits the array, the path terminates and contributes a candidate answer.

Since all indices are processed once in increasing order and jumps only move right, every reachable state is considered exactly when needed.

Thus, every valid path score is evaluated, and the maximum terminating score is returned.

Therefore, the algorithm correctly computes the maximum score Polycarp can achieve.

---

## Code Review

### Strengths

✔ Linear-time solution.

✔ Uses the monotonic nature of jumps (always moving right).

✔ No recursion, avoiding stack overflow issues.

✔ Efficient enough for the maximum constraint (`2 × 10^5` elements).

### Possible Improvement

Because:

```cpp
a[i] ≤ 10^9
```

and scores are sums of many values,

using `long long` is safer:

```cpp
vector<long long> prefix(n + 1, 0);
long long ans = 0;
```

This avoids potential integer overflow in larger test cases.

---

## Final Verdict

This is an elegant **Dynamic Programming / DP Propagation** solution that exploits the fact that jumps only move forward. The approach computes the best score reaching every position and updates the answer whenever a path exits the array.

**Time Complexity:** `O(n)`
**Space Complexity:** `O(n)`
**Recommended Improvement:** Replace `int` with `long long` for full safety.
