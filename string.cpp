#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

/*
 * String Hash
 */
typedef unsigned long long ULL;

const int N = 100010, P = 131;
ULL h[N], p[N];

ULL get(int l, int r) {
    return h[r] - h[l - 1] * p[r - l + 1];
}

// init
int main() {
    p[0] = 1;
    string s = "abcdef";
    s = ' ' + s;
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + s[i];  // if didn't add ' ' at front, will be s[i - 1]
    }
}
