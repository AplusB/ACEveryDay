//hihocoder挑战赛21
//A
#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
    int n,i;
    cin>>n;
    int mn=INT_MAX,ans=0;
    while(n--){
        cin>>s;
        int cnt=0;
        for(i=0;i<s.size();i++){
            if(s[i]!='x')
                break;
        }
        for(;i<s.size();i++){
            if(s[i]=='x') cnt++;
            ans++;
        }
        mn=min(mn,cnt);
    }
    if(mn!=INT_MAX) ans+=mn;
    cout<<ans<<endl;
    return 0;
}
//B
#include <bits/stdc++.h>
using namespace std;
int dp[210][210][210],A[210],n;
const int mod=1e9+7;
int main(){
	cin>>n;
	for (int i=1;i<=n;i++) cin>>A[i];
	dp[0][0][0]=1;
	for (int i=1;i<=n;i++)
		for (int j=0;j<=i;j++)
			for (int k=0;k<=i;k++){
				dp[i][j+1][k]=(dp[i][j+1][k]+1ll*(1000-A[i])*dp[i-1][j][k])%mod;
				dp[i][j][max(k+1,j+1)]=(dp[i][j][max(k+1,j+1)]+1ll*A[i]*dp[i-1][j][k])%mod;
			}
	int ans=0;
	for (int i=0;i<=n;i++)
		for (int j=0;j<=n;j++)
			ans=(ans+1ll*max(i,j)*dp[n][i][j])%mod;
	cout<<ans<<endl;
	return 0;
}
