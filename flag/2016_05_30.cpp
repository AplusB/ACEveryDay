#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 1e4 + 5;
const int Node = maxn * 31;

struct Trie{
    int nxt[Node][2];
    int num[Node];
    int rt, tol;

    int newNode(){
        num[++tol] = 0;
        memset(nxt[tol], 0, sizeof nxt[tol]);
        return tol;
    }

    void init(){
        tol = 0;
        num[0] = 0;
        memset(nxt[0], 0, sizeof nxt[0]);
        rt = newNode();
    }

    void ins(int x){
        int p = rt;
        for(int i = 30, c; i >= 0; i--){
            c = x >> i & 1;
            if(!nxt[p][c])
                nxt[p][c] = newNode();
            p = nxt[p][c];
            num[p]++;
        }
    }

    void del(int x){
        int p = rt;
        for(int i = 30, c; i >= 0; i--){
            c = x >> i & 1;
            if(!nxt[p][c]) return;
            p = nxt[p][c];
            num[p]--;
        }
    }

    bool fnd(int x, int up){
        int p = rt;
        for(int i = 30, c1, c2; i >= 0; i--){
            c1 = x >> i & 1;
            c2 = up >> i & 1;
            if(!c2 && num[nxt[p][c1 ^ 1]]){
                return true;
            }else if(num[nxt[p][c1 ^ c2]]){
                p = nxt[p][c1 ^ c2];
            }else{
                return false;
            }
        }
        return true;
    }

}gao;
bool dp[11][maxn];
int a[maxn], sum[maxn];
int N, M, L;

bool ok(int x){
    memset(dp, false, sizeof dp);
    dp[0][0] = true;
    for(int i = 1; i <= M; i++){
        gao.init();
        if(dp[i - 1][0]) gao.ins(0);
        for(int j = 1; j <= N; j++){
            if(j - L - 1 >= 0 && dp[i - 1][j - L - 1]){
                gao.del(sum[j - L - 1]);
            }
            if(gao.fnd(sum[j], x)){
                dp[i][j] = true;
            }
            if(dp[i - 1][j]){
                gao.ins(sum[j]);
            }
        }
    }
    return dp[M][N];
}

int main(){
    //freopen("data.in", "r", stdin);
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; cas++){
        scanf("%d%d%d", &N, &M, &L);
        for(int i = 1; i <= N; i++){
            scanf("%d", &a[i]);
            sum[i] = sum[i - 1] ^ a[i];
        }
        int l = 0, r = 1e9, mid;
        while(l < r){
            mid = (l + r + 1) >> 1;
            if(ok(mid))
                l = mid;
            else
                r = mid - 1;
        }
        printf("Case #%d:\n%d\n", cas, r);
    }
    return 0;
}
