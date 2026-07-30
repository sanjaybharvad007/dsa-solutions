<div align="center">

# 🧩 DSA Solutions

**My worked solutions to data-structures & algorithms problems.**

Each solution is clean, tested, and explained — approach, intuition, and
time/space complexity in the file itself.

`Python` · `pytest` · updated regularly

</div>

---

## How this repo is organized

Solutions are grouped by topic. Every file starts with a comment block
explaining the **approach**, the **intuition**, and the **complexity** — the
same way I'd talk through it in an interview.

```
solutions/
├── arrays/
│   ├── two_sum.py
│   └── max_subarray.py
├── linked_lists/
│   └── reverse_list.py
├── trees/
│   └── level_order.py
├── dynamic_programming/
│   └── climb_stairs.py
└── graphs/
    └── num_islands.py
tests/
└── test_solutions.py
```

---

## Progress

| Topic | Solved |
|---|---|
| Arrays & Hashing | 2 |
| Linked Lists | 1 |
| Trees | 1 |
| Dynamic Programming | 1 |
| Graphs | 1 |
| **Total** | **6** |

*Adding new solutions regularly as I work through problems.*

---

## Featured solutions

| Problem | Difficulty | Technique | Complexity |
|---|---|---|---|
| Two Sum | Easy | Hash map, one pass | O(n) time, O(n) space |
| Maximum Subarray | Medium | Kadane's algorithm | O(n) time, O(1) space |
| Reverse Linked List | Easy | In-place pointer reversal | O(n) time, O(1) space |
| Level Order Traversal | Medium | BFS with a queue | O(n) time, O(n) space |
| Climbing Stairs | Easy | Bottom-up DP | O(n) time, O(1) space |
| Number of Islands | Medium | DFS / flood fill | O(rows·cols) time |

---

## Running the tests

Every solution is verified by a test suite, so each one is known-correct:

```bash
pip install -r requirements.txt
python -m pytest -q
```

CI runs the tests automatically on every push.

---

## Why I keep this repo

Working through these consistently is how I prepare for technical interviews.
Writing each solution up — not just solving it, but explaining the approach and
complexity — is what makes the patterns stick.
