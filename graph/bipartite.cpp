#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 100010, M = 2 * N;
int n, m;
int e[M], ne[M], h[N], idx;
int color[N];

using namespace std;

int add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

bool dfs(int u, int c) {
    color[u] = c;
    for (int i = h[u]; i != -1; i = ne[i]) {
        int j = e[i];
        // core part
        // 3 - c ensure dfs between 1 and 2
        if (!color[j]) {
            if (!dfs(j, 3 - c)) return false;
        } else {
            if (color[j] == c) return false;
        }
    }
    return true;
}

int main()
{
    cin >> n >> m;
    memset(h, 0xff, sizeof h);
    while (m --) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }

    bool flag = true;
    for (int i = 1; i <= n; i++) {
        if (!color[i]) {
            if (!dfs(i, 1)) {
                flag = false;
                break;
            }
        }
    }

    if (flag) puts("Yes");
    else puts("No");

    return 0;
}
