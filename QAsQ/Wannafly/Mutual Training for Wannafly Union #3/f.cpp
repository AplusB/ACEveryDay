#include<bits/stdc++.h>
using namespace std;
#define LL long long 

int sig(LL x,LL y,LL a,LL b,LL c){
    return a * x + b * y + c < 0;
}

int main(){
    ios::sync_with_stdio(false);
    LL x1,y1,x2,y2;
    LL a,b,c;
    int ans = 0;
    cin>>x1>>y1>>x2>>y2;
    int n;
    cin>>n;
    while(n--){
        cin>>a>>b>>c;
        ans += sig(x1,y1,a,b,c) ^ sig(x2,y2,a,b,c);
    }
    cout<<ans<<endl;
    return 0;
}
