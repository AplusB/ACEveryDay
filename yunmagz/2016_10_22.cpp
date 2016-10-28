//沈阳热身C
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
int main(){
    string s;
    int q,x,y;
    cin>>s>>q;
    int n=s.size();
    while(q--){
        cin>>x>>y;
        if(s[x]!=s[y]) puts("0");
        else {
            int l=1,r=n-max(x,y);
            int ans=1;
            while(l<=r){
                int mid=(l+r)>>1;
                if(s.substr(x+ans,mid-ans)==s.substr(y+ans,mid-ans)){
                    ans=mid;
                    l=mid+1;
                }
                else r=mid-1;
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}
