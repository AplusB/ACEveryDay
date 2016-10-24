#include<bits/stdc++.h>
using namespace std;
const int maxn = 3000;

#define LL long long 

set<int> S;

LL sum(LL x){
    return x * (x - 1) / 2;
}

bool inS(int v){
    for(auto x : S){
        if(v % x == 0) return true;
    }
    return false;
}

int pri[maxn],cnt[maxn];

int main(){
    int T,icase = 1;
    scanf("%d",&T);
    int n; LL m;
    while(T-- && ~scanf("%d %I64d",&n,&m)){
        LL x;
        S.clear();
        while(n--){
            scanf("%I64d",&x);
            S.insert(__gcd(x,m));
        }
        int len = 0;
        for(LL i = 1;i * i <= m;i++){
            if(m % i == 0){
                pri[len++] = i;
                pri[len++] = m / i;
            }
        }
        sort(pri,pri+len);
        len = unique(pri,pri+len) - pri;
        LL ans = 0;
        for(int i=0;i<len;i++) cnt[i] = 1;
        for(int i=0;i<len;i++){
            if(inS(pri[i])){
                ans += sum(m/pri[i]) * pri[i] * cnt[i];
                for(int j = i + 1;j<len;j++)
                    if(pri[j] % pri[i] == 0)
                        cnt[j]-=cnt[i];
            }
        }
        printf("Case #%d: %I64d\n",icase++,ans);
    }
    return 0;
}

