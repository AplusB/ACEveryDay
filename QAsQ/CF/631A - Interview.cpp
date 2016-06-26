#include<bits/stdc++.h>
using namespace std;

const int maxn = 1100;
#define LL long long 

LL a[maxn],b[maxn];

int main(){
    int n;
    cin>>n;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    LL x;
    for(int i=1;i<=n;i++){
        cin>>x;
        a[i] = a[i-1]|x;
    }
    for(int i=1;i<=n;i++){
        cin>>x;
        b[i] = b[i-1]|x;
    }
    LL ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            ans = max(ans,(a[j]^a[i-1])+(b[j]^b[i-1]));
        }
    }
    cout<<ans<<endl;
    return 0;
}

    
