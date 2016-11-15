#include<bits/stdc++.h>
using namespace std;

const int maxn = 212345;

#define LL long long 

LL a[maxn],b[maxn],c[maxn],d[maxn];
pair<LL,LL> v;

int main(){
    ios::sync_with_stdio(false);
    int n,m,k;
    cin>>n>>m>>k;
    LL x,s;
    cin>>x>>s;
    for(int i = 0 ; i < m ; i ++) cin>>a[i];
    for(int i = 0 ; i < m ; i ++) cin>>b[i];
    for(int i = 0 ; i < k ; i ++) cin>>c[i];
    for(int i = 0 ; i < k ; i ++) cin>>d[i];
    LL ans = x * n;
    for(int i = 0 ; i < m ; i ++){
        LL lef = s - b[i];
        LL bud = n;
        if(lef < 0) continue;
        if(lef >= d[0]){
            int st = upper_bound(d,d+k,lef) - d - 1;
            bud = max(0ll,bud - c[st]);
        }
        ans = min(ans,bud * a[i]);
    }
    if(s >= d[0]){
        int st = upper_bound(d,d+k,s) - d - 1;
        ans = min(ans,x * max(0ll,n - c[st]));
    }
    cout<<ans<<endl;
    return 0;
}
