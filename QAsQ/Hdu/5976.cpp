#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
#define LL long long 
const int maxn = 112345;
LL fun[maxn];
LL sum[maxn];


int main(){
    fun[2] = sum[2] = 2;
    int len = 3;
    while(sum[len-1] < 1e9){
        sum[len] = sum[len-1] + len;
        fun[len] = (fun[len-1] * len) % mod;
        len++;
    }
    int T;
    scanf("%d",&T);
    LL n;
    while(T-- && ~scanf("%I64d",&n)){
        LL ans = 1;
        if(n <= 4) ans = n;
        else{
            int st = lower_bound(sum+2,sum+len,n) - sum - 1;
            if(n-sum[st] <= st) st--;
            if(n-sum[st]) ans = (fun[st] * (n - sum[st]) ) % mod;
            else ans = fun[st];
            printf("%I64d ",ans);

            ans = 1;
            int tot = 2;
            while(tot * 2 < n){
                (ans *= tot) %= mod;
                n -= tot;
            }
            if(n) (ans *= n ) %= mod;
        }
        printf("%I64d\n",ans);
    }
    return 0;
}

