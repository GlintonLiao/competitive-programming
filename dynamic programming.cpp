/*
    Given an array, divide it into d groups
    return minimum sum of maximum value in each group
*/
int minDifficulty(vector<int> &w, int d)
{
    int n = w.size(), INF = 1e8;
    vector<vector<int>> f(n + 1, vector<int>(d + 1, INF));
    f[0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= d; j++)
        {
            int cost = 0;
            for (int k = 1; k <= i; k++)
            {
                cost = max(cost, w[i - k]);
                f[i][j] = min(f[i][j], f[i - k][j - 1] + cost);
            }
        }
    if (f[n][d] == INF)
        return -1;
    else
        return f[n][d];
}
