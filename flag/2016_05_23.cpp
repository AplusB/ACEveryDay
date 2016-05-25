#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 100005;
int a[maxn], res[maxn];
LL ans[maxn];

template < class T >
void cmax(T &a, T b){
    if(a < b) a = b;
}

void solve(int l, int r){
    if(l > r) return;
    int m = l;
    for(int i = l + 1; i <= r; i++){
        if(a[i] < a[m]) m = i;
    }
    int len = r - l + 1;
    for(int i = 1; i <= len; i++) res[i] = 0;
    int mx = 0;
    for(int i = m; i >= l; i--){
        cmax(mx, a[i]);
        cmax(res[m - i + 1], mx);
    }
    mx = 0;
    for(int i = m; i <= r; i++){
        cmax(mx, a[i]);
        cmax(res[i - m + 1], mx);
    }
    for(int i = 1; i <= len; i++){
        cmax(res[i], res[i - 1]);
        cmax(ans[i], (LL)res[i] * a[m]);
    }
    solve(l, m - 1);
    solve(m + 1, r);
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }
        memset(ans, 0, sizeof ans);
        solve(1, n);
        for(int i = 1; i <= n; i++){
            printf("%lld\n", ans[i]);
        }
    }
    return 0;
}

