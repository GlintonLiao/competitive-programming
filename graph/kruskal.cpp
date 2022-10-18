/*
    Given n points, m edges
    Return the value of all edges 
    in its minimum spanning tree.

    Sort the edges by its value
    Traverse all edges, if this two points are not connected
    connect them, and update the result

    If the edges connected are smaller than n - 1
    Then no solution.
*/
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 100010, M = 200010, INF = 0x3f3f3f3f;
int p[N];
int n, m;

struct Edge {
    int a, b, w;
    bool operator< (const Edge& e) const {
        return w < e.w;
    }
} edges[M];

int find(int x) {
    if (p[x] != x) p[x] = find(p[x]);
    else return p[x];
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edges[i] = {a, b, c};
    }

    sort(edges, edges + m);

    // init union find
    for (int i = 0; i <= n; i++) p[i] = i;

    int res = 0, cnt = 0;
    // traverse each edges
    for (int i = 0; i < m; i++) {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = find(a), b = find(b);
        if (a != b) {
            p[a] = b;
            res += w;
            cnt++;
        }
    }

    if (cnt != n - 1) puts("impossible");
    else cout << res << endl;

    return 0;
}
