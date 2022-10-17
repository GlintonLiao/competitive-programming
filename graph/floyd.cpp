/*
    Based on dp
*/
void floyd() {
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
}

// init
int d[N][N], INF = 1e9;
int main() {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
          if (i == j) d[i][j] = 0;
          else d[i][j] = INF; 
}