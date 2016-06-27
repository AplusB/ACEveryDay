#include<bits/stdc++.h>
using namespace std;

#define LL long long 

int main(){
    LL a,b,c,n;
    cin>>n>>a>>b>>c;
    LL bc = b-c;
    LL ans = 0;
    if(a < bc){
        ans = n / a;
    }
    else{
        while(n >= b){
            if(n >= b+bc){
                LL temp = n - b;
                n = temp % bc + b;
                ans += temp / bc;
            }
            else{
                n-=bc;
                ans++;
            }
        }
        ans += n / a;
    }
    cout<<ans<<endl;
    return 0;
}
