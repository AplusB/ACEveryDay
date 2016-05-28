#include <cstdio>
#include <cstring>
int g[110][100];
void Min(int &x, int y)
{
        if(x == -1 || y < x) {
                x = y;
        }
}
int main() {
        int T, ca = 1, n, m;
        scanf("%d", &T);
        while(T--) {
                scanf("%d%d", &n, &m);
                int a, b, c;
                memset(g, -1, sizeof(g));
                for(int i = 0; i < m; i++) {
                        scanf("%d%d%d", &a, &b, &c);
                        if(g[a][b] == -1 || c < g[a][b]) {
                                g[a][b] = g[b][a] = c;
                        }
                }
                for(int i = 1; i <= n; i++) {
                        for(int j = 1; j <= n; j++) {
                                for(int k = 1; k <= n; k++) if(~g[j][i] && ~g[i][k]){
                                        Min(g[j][k], g[j][i] + g[i][k]);
                                }
                        }
                }
                printf("Case %d: ", ca++);
                if(g[1][n] == -1) {
                        puts("Impossible");
                } else {
                        printf("%d\n", g[1][n]);
                }
        }
        return 0;
}
