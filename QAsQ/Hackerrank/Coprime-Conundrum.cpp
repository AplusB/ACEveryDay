#include<bits/stdc++.h>
using namespace std;

#define LL long long 
const int maxn = 112345;

LL count(LL v,LL st,LL ed){
    return ed / v - st / v;
}

int mu[maxn];
vector<int> fac[maxn];

LL cal(LL v,LL ed){
    LL ret = 0;
    for(auto x : fac[v]){
        ret += mu[x] * count(x,v,ed);
    }
    return ret;
}

int main(){
    memset(mu,0,sizeof(mu));
    mu[1] = 1;
    for(int i=1;i<maxn;i++){
        for(int j=i*2;j<maxn;j+=i){
            mu[j] -= mu[i];
        }
    }
    for(int i=1;i<maxn;i++){
        if(mu[i])
            for(int j=i;j<maxn;j+=i)
                fac[j].push_back(i);
    }
    LL n;
    cin>>n;
    LL ans = 0;
    for(LL i = 2;i * i <= n;i++){
        ans += cal(i,n / i);
    }
    cout<<ans<<endl;
    return 0;
}

