#include<bits/stdc++.h>
using namespace std;

const int maxn = 1123456;
#define LL long long
LL pri[maxn];
LL unp[maxn];

void sieve(){
    memset(pri,-1,sizeof(pri));
    pri[1] = 1;
    unp[1] = 1;
    for(LL i=2;i<maxn;i++){
        if(pri[i] == -1){
            pri[i] = i;
            unp[i] = i*i;
            for(int j=i*2;j<maxn;j+=i){
                if(pri[j] == -1) pri[j] = i,unp[j] = i*i;
                else pri[j] *= i,unp[j] *= i*i;
            }
            int cnt = 1;
            for(LL j=i*i;j<maxn;j*=i){
                cnt++;
                for(LL k=1;k*j<maxn;k++){
                    if(cnt % 3 == 1){
                        pri[k*j] *= i;
                        unp[k*j] *= i*i;
                    }
                    if(cnt % 3 == 2){
                        pri[k*j] *= i;
                        unp[k*j] /= i;
                    }
                    if(cnt % 3 == 0){
                        pri[k*j] /= i*i;
                        unp[k*j] /= i;
                    }
                }
            }
        }
    }
}

int Hash[maxn];

int main(){
    int T;
    sieve();
    scanf("%d",&T);
    int n;
    while(T-- && ~scanf("%d",&n)){
        int x;
        LL ans = 0;
        memset(Hash,0,sizeof(Hash));
        while(n--){
            scanf("%d",&x);
            if(unp[x] < maxn)
                ans += Hash[unp[x]];
            Hash[pri[x]]++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
