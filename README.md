# Competitive Programming
Selected algorithm templates and solutions

```cpp
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
    return 0;
}
```

### Choosing Algorithms Based on Data Scale

1. `n ≤ 30`, DFS + Pruning，BitMask DP
2. `n ≤ 100` => `O(n^3)`, floyd，DP，Gaussian Elimination
3. `n ≤ 1000` => `O(n2)`, `O(n^2logn)`, DP, BinarySearch，Dijkstra-B, Prim-B, Bellman-Ford
4. `n ≤ 10000` => `O(n√n)`，Unrolled Linked List, Block Partition, Mo's Algorithm
5. `n ≤ 100000` => `O(nlogn)` => Sort, Segment Tree, Binary Indexed Tree, Set/Map, Heap, TopoSort, Dijkstra-H, Prim-H, Kruskal, SPFA, Convex Hull, BinarySearch, CDQ, Suffix array, Heavy Path Decomposition, LCT
6. `n ≤ 1000000` => `O(n)`, and low constant `O(nlogn)` => PriorityQueue, Hash, Two Pointers, Union Find, KMP, Aho–Corasick, or Sort、Binary Indexed Tree、Heap、Dijkstra、SPFA
7. `n ≤ 10000000` => `O(n)`, Two Pointers、KMP、Aho–Corasick、Sieve Prime
8. `n ≤ 10^9` => `O(√n)`，Sieve Prime
9. `n ≤ 10^18` => `O(logn)`，GCD, Binary Exponentiation, Decimal DP
10. `n ≤ 10^1000` => `O((logn)^2)`, High Precision
11. `n ≤ 10100000` => `O(logk×loglogk)`, k means bits, High Precision +/-、FFT/NTT
