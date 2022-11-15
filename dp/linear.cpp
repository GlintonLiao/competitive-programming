/*
    Longest Increasing Subsequence(LIS)

    for j < i, if a[j] < a[i], means
    f[j] can be transfer from f[j]
    f[i] = max(f[i], f[j] + 1) for every possible j
*/
int lis(vector<int>& nums) {
    int n = nums.size();
    vector<int> f(n, 1);  // minimum length is itself, 1
    for (int i = 0; i < n; i++)
        for (int j = 0; j < i; j++)
            if (nums[j] < nums[i])  // meets the requirement
                f[i] = max(f[i], f[j] + 1);
    return f[n - 1];
}


/*
    Longest Common Subsequences(LCS)

    Two string a, b
    f[i][j] indicates LCS for a[1] to a[i], b[1] to b[i]

    if a[i] == b[j], we can remove a[i] and b[j],
    state will be f[i - 1][j - 1]

    if not, f[i][j] = max(f[i - 1][j], f[i][j - 1])
*/
int lcs(string a, string b) {
    a = " " + a, b = " " + b;
    int n = a.size(), m = b.size();
    vector<vector<int>> f(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            f[i][j] = max(f[i][j - 1], f[i - 1][j]);
            if (a[i] == b[j])
                f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
        }
    return f[n][m];
}


/*
    Edit distance

    Given string a, b

    Each time we can add, delete or change a character
    Return the minimum operation time to make a and b equal

    f[i][j] indicates min time to make a[1...i], b[1...j] equal

    1. a[i] == b[j], f[i][j] = f[i - 1][j - 1]
    2. a[i] != b[j], f[i][j] = f[i - 1][j - 1] + 1 (change)
    3. add a[i], f[i][j] = f[i][j - 1] + 1
    3. delete a[i], f[i][j] = f[i - 1][j] + 1
*/
int editDistance(string a, string b) {
    a = " " + a;
    b = " " + b;
    n = a.size(), m = b.size();
    vector<vector<int>> f(n + 1, vector<int>(m + 1));

    // init
    for (int i = 1; i <= n; i++) f[i][0] = i;
    for (int j = 1; j <= m; j++) f[0][j] = j;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            f[i][j] = max(f[i - 1][j], f[i][j - 1]) + 1;
            f[i][j] = max(f[i][j], f[i - 1][j - 1]) + (a[i] == b[j] ? 0 : 1);
        }
    return f[n][m];
}
