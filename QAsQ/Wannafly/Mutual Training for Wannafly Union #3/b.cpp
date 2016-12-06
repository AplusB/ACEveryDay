#include<bits/stdc++.h>
using namespace std;

const int maxn = 112345;
#define LL long long 

LL b[maxn],p[maxn];
LL ned(int k){
    LL ret = 0;
    for(int i = 0 ; i < k ; i ++){
        ret += max(0ll,p[i]-b[k-i-1]);
    }
    return ret;
}
LL a;
int getans(int n){
    int l = 0 , r = n;
    int ans = -1;
    while(l <= r){
        int mid = (l + r) / 2;

        if(ned(mid) > a){
            r = mid - 1;
        }
        else{
            l = mid + 1;
            ans = mid;
        }
    }
    return ans;
}

LL nedans(int k){
    LL ret = 0;
    for(int i = 0 ; i < k ; i ++){
        ret += p[i];
    }
    return ret;
}
int main(){
    int n,m;
    scanf("%d %d %I64d",&n,&m,&a);
    for(int i = 0 ; i < n ; i ++) scanf("%I64d",&b[i]);
    for(int i = 0 ; i < m ; i ++) scanf("%I64d",&p[i]);
    sort(b,b+n,[](LL a,LL b){return a > b;});
    sort(p,p+m);
    int peo = getans(min(n,m));
    printf("%d %lld\n",peo,max(0ll,nedans(peo) - a));
    return 0;
}
