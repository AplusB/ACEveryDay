#include<bits/stdc++.h>
using namespace std;
#define LL long long 

const int maxn = 112345;

LL arr[maxn],ans[maxn];

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    LL anw = 0;
    for(int i=n;i>=1;i--){
        ans[i] = max(0ll,anw +1 - arr[i]);
        anw = max(arr[i],anw);
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<(i<n?" ":"\n");
    return 0;
}
    
