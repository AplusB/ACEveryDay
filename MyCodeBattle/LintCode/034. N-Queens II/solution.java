class Solution {
    /**
     * Get all distinct N-Queen solutions
     * @param n: The number of queens
     * @return: All distinct solutions
     * For example, A string '...Q' shows a queen on forth position
     */
    int ans;
    private int n;

    private boolean check(int pos, int v) {
        return ((v >> pos) & 1) != 1;
    }

    private void dfs(int layer, int columnVis, int lVis, int rVis) {
        if (layer == n) {
            ++ans;
            return;
        }
        for (int i = 0; i < n; ++i) if (check(i, columnVis) && check(i - layer + n, lVis) && check(i + layer, rVis)) {
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < n; ++j) sb.append('.');
            dfs(layer + 1, columnVis|(1<<i), lVis|(1<<(i-layer+n)), rVis|(1<<(i+layer)));
        }
    }

    public int totalNQueens(int n) {
        this.n = n;
        if (n == 0)
            return ans;
        dfs(0, 0, 0, 0);
        return ans;
    }
};

