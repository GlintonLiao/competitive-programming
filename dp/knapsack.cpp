/*
    01 pack
*/
int maxW(vector<int>& w, vector<int>& v, int m, int n) {
    vector<int> f(m + 1);
    for (int i = 0; i < n; i++)
        for (int j = m; j >= v[i]; j--)
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    return f[m];
}

/*
    Complete pack
*/
int maxW(vector<int>& w, vector<int>& v, int m, int n) {
    vector<int> f(m + 1);
    for (int i = 0; i < n; i++) 
        for (int j = v[i]; j <= m; j++)
            f[j] = max(f[j], f[j - v[i]] + w[i])
    return f[m];
}

/*
    Multi pack
*/
int maxV(vector<int>& w, vector<int>& v, vector<int> s, int m, int n) {
    vector<int> f(m + 1);
    for (int i = 0; i < n; i++)
        for (int j = m; j >= 0; j--)
            for (int k = 0; k <= s[i] && k * v[i] <= j; k++)
                f[j] = max(f[j], f[j - k * v[i]] + k * w[i]);
    return f[m];
}
