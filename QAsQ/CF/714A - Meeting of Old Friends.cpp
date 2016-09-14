#include<bits/stdc++.h>
using namespace std;

#define LL long long 

LL cal(LL l,LL r,LL k){
    if(r < l) return 0;
    LL ans = r - l + 1;
    if(l <= k && k <= r)
        ans--;
    return ans;
}

int main(){
    LL l1,l2,r1,r2,k;
    cin>>l1>>r1>>l2>>r2>>k;
    LL l = max(l1,l2);
    LL r = min(r1,r2);
    cout<<cal(l,r,k)<<endl;
    return 0;
}
