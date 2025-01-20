void floyd_warshall(int n, vector<vector<int>>& D, vector<vector<int>>& Q) {
    for (int k = 0; k < n; ++k) {
        for (int a = 0; a < n; ++a) {
            for (int b = 0; b < n; ++b) {
                if (D[a][k] != INF && D[k][b] != INF && D[a][k] + D[k][b] < D[a][b]) {
                    D[a][b] = D[a][k] + D[k][b];
                    Q[a][b] = k;
                }
            }
        }
    }
}
