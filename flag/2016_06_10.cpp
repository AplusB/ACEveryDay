#include <bits/stdc++.h>
using namespace std;
#define mkp make_pair
typedef long long LL;
typedef pair < int, LL > pii;

LL get(LL x) { return x * x * x; }

LL fnd(LL x){
    LL l = 1, r = 1e5, mid;
    while(l < r){
        mid = (l + r + 1) >> 1;
        if(get(mid) <= x)
            l = mid;
        else
            r = mid - 1;
    }
    return r;
}

pii best;
void dfs(int cnt, LL sum, LL left){
    if(left == 0){
        best = max(best, mkp(cnt, sum));
        return;
    }
    LL x = fnd(left);
    dfs(cnt + 1, sum + get(x), left - get(x));
    if(x > 1)
        dfs(cnt + 1, sum + get(x - 1), get(x) - 1 - get(x - 1));
}

int main(){
    LL m;
    cin >> m;
    best = mkp(0, 0);
    dfs(0, 0, m);
    cout << best.first << ' ' << best.second << '\n';
    return 0;
}
