#include<bits/stdc++.h>
using namespace std;
#define LL long long

int main(){
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    int ans = n * a;
    ans = min(ans,n/m * b + n % m * a);
    ans = min(ans,(n/m + (n%m!=0)) * b);
    cout<<ans<<endl;
    return 0;
}
