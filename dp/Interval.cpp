/*
    Generally, f[i, j] indicates an interval from i to j
    and f[i, j] can be divided into several smaller parts
    these part can form the f[i, j]

    Given several bunch of stones
    each time can merge two parts next to which are next to each other, the cost will be the sum of these two parts

    Return the minimum cost to merge all parts into one part

    for a part from i to j
    we can divide it into 
    [i, i], [i + 1][j]
    [i, i + 1], [i + 2][j]
    ...
    [i, j - 1][j]
    the minimum cost will be the min cost of merging these sub intervals + the sum from i to j
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 310;
int f[N][N];
int s[N];

int main()
{
    int n; 
    cin >> n;
    // init prefix sum
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        s[i] += s[i - 1];
    }
    
    // common to traverse length for interval dp
    for (int len = 2; len <= n; len++) {
        for (int i = 1; i + len - 1 <= n; i++) {
            int j = i + len - 1;
            f[i][j] = 1e8;
            for (int k = i; k < j; k++) {
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
            }
        }
    }
    cout << f[1][n] << endl;
    return 0;
}