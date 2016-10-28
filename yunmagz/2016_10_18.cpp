//Codeforces Round #376 (Div. 2)
//A - Night at the Museum
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int main(){
    string s;
    cin>>s;
    int n=s.size();
    int ans=min((s[0]-'a'+26)%26,('a'-s[0]+26)%26);
    for(int i=1;i<n;i++)
        ans+=min((s[i]-s[i-1]+26)%26,(s[i-1]-s[i]+26)%26);
    cout<<ans<<endl;
    return 0;
}
