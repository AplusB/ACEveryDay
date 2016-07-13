#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 50005;
int W[maxn], p[maxn], vis[maxn];
vector < int > w;

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &W[i]);
        w.push_back(W[i]);
    }
    w.push_back(0);
    sort(w.begin(), w.end());
    for(int i = 1; i <= n; i++){
        p[lower_bound(w.begin(), w.end(), W[i]) - w.begin()] = i;
    }
    LL ans = 0;
    for(int i = 1; i <= n; i++){
        if(vis[i] || p[i] == i) continue;
        LL sum = 0, mi = 2e9, cnt = 0;
        int j = i;
        while(!vis[j]){
            cnt++;
            sum += w[j];
            mi = min(mi, (LL)w[j]);
            vis[j] = 1;
            j = p[j];
        }
        ans += min(sum - mi + (cnt - 1) * mi, sum + (cnt + 1) * w[1] + mi);
    }
    printf("%lld\n", ans);
    return 0;
}
