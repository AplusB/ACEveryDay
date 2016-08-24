#include<bits/stdc++.h>
using namespace std;

int main(){
    int ans = 0;
    int n;
    cin>>n;
    int x1,x2,y1,y2;
    while(n--){
        cin>>x1>>y1>>x2>>y2;
        ans += (x2-x1+1) * (y2-y1+1);
    }
    cout<<ans<<endl;
    return 0;
}
