#include <bits/stdc++.h>
using namespace std;
#define pub push_back
typedef long long LL;
const int md = 1000000007;
const int maxn = 1005;
const int maxv = 805;
int dp[maxn][maxv];
vector < LL > p;
LL a[maxn];
int tol;

int id(LL x){
    return lower_bound(p.begin(), p.end(), x) - p.begin();
}

void add(int &a, int b){
    a += b;
    if(a >= md) a -= md;
}

int main(){
    int T, n, K;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d", &n, &K);
        p.clear();
        for(int i = 1; (LL)i * i <= K; i++){
            if(K % i == 0){
                p.pub(i);
                if(K / i != i) p.pub(K / i);
            }
        }
        sort(p.begin(), p.end());
        int tol = 0;
        for(int i = 1; i <= n; i++){
            scanf("%lld", &a[i]);
            if(p[id(a[i])] == a[i])
                a[++tol] = a[i];
        }
        n = tol;
        memset(dp, 0, sizeof dp);
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++){
            for(int j = 0; j < p.size(); j++)if(dp[i - 1][j]){
                add(dp[i][j], dp[i - 1][j]);
                int x = id(a[i] * p[j]);
                if(p[x] == a[i] * p[j])
                    add(dp[i][x], dp[i - 1][j]);
            }
        }
        printf("%d\n", dp[n][p.size() - 1]);
    }
    return 0;
}

