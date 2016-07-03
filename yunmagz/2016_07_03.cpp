//CF#360 (Div. 2)
//A - Opponents
#include <bits/stdc++.h>
using namespace std;
int n,d;
bool ok(string s){
	for(int i=0;i<n;i++)
		if(s[i]=='0') return 1;
	return 0;
}
int main() {
	string s;
	cin>>n>>d;
	int ans=0,tmp=0;
	while(d--){
		cin>>s;
		if(ok(s)) tmp++;
		else tmp=0;
		ans=max(ans,tmp);
	}
	cout<<ans<<endl;
	return 0;
}
//B - Lovely Palindromes
#include <bits/stdc++.h>
using namespace std;
int main() {
	string s,ss;
	cin>>s;
	ss=s;
	reverse(ss.begin(),ss.end());
	cout<<s<<ss<<endl;
	return 0;
}
//C - NP-Hard Problem
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
vector<int>e[100010],a,b;
int f[100010];
int vis[100010];
bool dfs(int x,int s){
	vis[x]=1;
	f[x]=s;
	for(int i=0;i<e[x].size();i++){
		if(!vis[e[x][i]]&& !dfs(e[x][i],s^1))
			return 0;
		if(vis[e[x][i]]&&f[e[x][i]]==s)
			return 0;
	}
	return 1;
}
int main() {
	int n,m,u,v;
	cin>>n>>m;
	while(m--){
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		if(!vis[i]&& !dfs(i,0)){
			puts("-1");
			return 0;
		}
	for(int i=1;i<=n;i++){
		if(f[i]) a.pb(i);
		else b.pb(i);
	}
	cout<<a.size()<<endl;
	for(int i=0;i<a.size();i++) cout<<a[i]<<" ";
	puts("");
	cout<<b.size()<<endl;
	for(int i=0;i<b.size();i++) cout<<b[i]<<" ";
	
	return 0;
}
//D - Remainders Game
#include <bits/stdc++.h>
using namespace std;
#define LL long long
LL lcm(LL a,LL b){
	return a/__gcd(a,b)*b;
}
int main() {
	int n;
	LL k,c,ans=1;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		scanf("%I64d",&c);
		ans=__gcd(k,lcm(ans,c));
	}
	if(ans==k) puts("Yes");
	else puts("No");
	return 0;
}
//E - The Values You Can Make
#include <bits/stdc++.h>
using namespace std;
int dp[1010][1010],a[510];
int main() {
	int n,k;
	cin>>n>>k;
	dp[0][0]=1;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++)
		for(int j=k;j>=0;j--)
			for(int h=j;h>=0;h--)
				if(dp[j][h]){
					dp[j+a[i]][h]=1;
					dp[j+a[i]][h+a[i]]=1;
				}
	int cnt=0;
	for(int i=0;i<=k;i++)
		if(dp[k][i]) cnt++;
	cout<<cnt<<endl;
	for(int i=0;i<=k;i++)
		if(dp[k][i]) cout<<i<<" ";
	return 0;
}
