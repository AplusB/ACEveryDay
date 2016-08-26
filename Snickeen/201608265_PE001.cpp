#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long  LL;
LL t,n,m,ans;

int main() {
    cin>>t;
    while(t--){
        ans=0;
        cin>>n;n--;
        m=n/3;
        ans+=(3*(1+m)*m/2);
        m=n/5;
        ans+=(5*(1+m)*m/2);
        m=n/15;
        ans-=(15*(1+m)*m/2);
        cout<<ans<<endl;
    }
    return 0;
}
