/*
    n points, m edges
    could have multiple edges or self cycle, edge weight could be negative

    return the shortest distance from 1 to n, which have maximum k edges
*/
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 510, M = 10010;

struct {
    int a, b, w;
} edges[M];

int n, m, k;
int dist[N], last[N];

void bellman_ford() {
    // init
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    // travese k times
    for (int i = 0; i < k; i++) {
        // each time copy an array from the last time
        memcpy(last, dist, sizeof dist);
        // travese every edges
        for (int j = 0; j < m; j++) {
            auto& e = edges[j];
            dist[e.b] = min(dist[e.b], last[e.a] + e.w);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edges[i] = {a, b, c};
    }

    bellman_ford();

    if (dist[n] > 0x3f3f3f3f / 2) puts("impossible");
    else printf("%d", dist[n]);

    return 0;
}
