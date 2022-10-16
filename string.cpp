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

/*
    Reverse each word in a string
    "The sky is blue" -> "blue is sky The"

    1. reverse it -> "eulb si yks ehT"
    2. reverse each word -> "blue is sky The"

    need to trim white space
*/
int reverseWord(string s) {
    int k = 0;
    for (int i = 0; i < s.size();)
    {
        int j = i;
        while (j < s.size() && s[j] == ' ') j ++ ;
        if (j == s.size()) break;
        i = j;
        while (j < s.size() && s[j] != ' ') j ++ ;
        reverse(s.begin() + i, s.begin() + j);
        if (k) s[k ++ ] = ' ';
        while (i < j) s[k ++ ] = s[i ++ ];
    }
    s.erase(s.begin() + k, s.end());
    reverse(s.begin(), s.end());

    return s;
}
