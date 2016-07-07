//hdoj4869

#include<cstring>
#include<string>
#include<fstream>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cctype>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<ctime>
#include<cstdlib>
#include<functional>
#include<cmath>
using namespace std;
#define PI acos(-1.0)
#define MAXN 100100
#define eps 1e-7
#define MOD 1000000009
#define INF 0x7FFFFFFF
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
typedef long long ll;

ll c[MAXN];
ll mode(ll a,int n){
    ll t = a;
    ll ans = 1;
    while(n){
        if(n & 1){
            ans = ans * t % MOD;
        }
        n >>= 1;
        t =  t * t % MOD;
    }
     return ans;
}
int main(){
    int n,m,minm,maxm,i,j,x,p,q;
    while(scanf("%d%d",&n,&m)!=EOF){
        minm = maxm = 0;
        p = q = 0;
        for(i=0;i<n;i++){
            scanf("%d",&x);
            if(minm>=x)        p = minm - x;
            else if(maxm>=x)   p = ((x&1)==(minm&1))?0:1;
            else               p = x - maxm;
            if(maxm+x<=m)      q = maxm + x;
            else if(minm+x<=m) q = (((minm+x)&1)==(m&1))?m:m-1;
            else               q = 2 * m - (x + minm);
            minm = p;
            maxm = q;
        }
        ll ans = 0LL;
        c[0] = 1;
        for(i=1;i<=maxm;i++){
            if(m-i<i)   c[i] = c[m-i];
            else{
                c[i] = c[i-1] * (m-i+1) % MOD * mode((ll)i,MOD-2) % MOD;
            }
        }
        for(i=minm;i<=maxm;i+=2){
            ans += c[i];
            ans %= MOD;
        }
        cout<<ans<<endl;
    }
    return 0;
}


