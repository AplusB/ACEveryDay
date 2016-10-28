//Codeforces Round #376 (Div. 2)
//F - Video Cards
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int p[200010],v[200010];
int main() {
    ll ans=0,mx=0,a,n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a;
        v[a]++;
        mx=max(a,mx);
    }
    for(int i=1;i<=mx;i++) p[i]=p[i-1]+v[i];
    for(int i=1;i<=mx;i++){
        if(p[i]==p[i-1]) continue;
        ll cnt=0;
        for(ll j=i;j<=mx;j+=i) cnt+=j*(p[min(mx,j+i-1)]-p[j-1]);
        ans=max(ans,cnt);
    }
    cout<<ans<<endl;
	return 0;
}
