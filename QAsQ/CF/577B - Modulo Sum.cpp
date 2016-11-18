#include<bits/stdc++.h>
using namespace std;

const int maxn = 2123;
bitset<maxn> dp;

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int x;
    for(int i = 0 ; i < n ; i ++){
        scanf("%d",&x);
        x %= m;
        dp |= dp << x;
        dp |= dp >> m;
        dp[x] = true;
    }
    puts(dp[0] ? "YES":"NO");
}
