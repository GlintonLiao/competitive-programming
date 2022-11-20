#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> PII;

const int N = 150010;

int h[N], e[N], w[N], ne[N], idx;
int n, m;
int st[N], dist[N];

int add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

int dijkstra() {

    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    priority_queue<PII, vector<PII>, greater<PII>> heap;

    // distance, index
    heap.push({0, 1});

    while (heap.size()) {
        auto t = heap.top();
        heap.pop();

        int u = t.second, distance = t.first;
        if (st[u]) continue;

        st[u] = true;
        for (int j = h[u]; j != -1; j = ne[j]) {
            int t = e[j];
            if (dist[t] > dist[u] + w[j]) {
                dist[t] = dist[u] + w[j];
                heap.push({dist[t], t});
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f) return -1;
    return dist[n];

}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    while (m -- ) {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }

    cout << dijkstra() << endl;
    return 0;
}
