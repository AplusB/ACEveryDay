#include<bits/stdc++.h>
using namespace std;
int n,tot,dp[1024][2],dup[1024][2];
map<string,int>mp;
vector<int>v[1024];

void dfs(int x) {
	for(int i=0; i<v[x].size(); i++) {
		int y=v[x][i];
		dfs(y);
		dp[x][0]+=max(dp[y][1],dp[y][0]);
		dp[x][1]+=dp[y][0];

		if(dp[y][1]>dp[y][0]&&dup[y][1]==0) dup[x][0]=0;
		if(dp[y][1]<dp[y][0]&&dup[y][0]==0) dup[x][0]=0;
		if(dp[y][1]==dp[y][0]) dup[x][0]=0;
		if(dup[y][0]==0) dup[x][1]=0;
	}
}

int main() {
	string s1,s2;
	while(~scanf("%d",&n)) {
		if(n==0) break;
		for(int i=0; i<=n; i++) {
			v[i].clear();
			dp[i][1]=1;
			dp[i][0]=0;
			dup[i][1]=dup[i][0]=1;
		}
		mp.clear();
		tot=1;
		cin>>s1;
		mp[s1]=tot;
		tot++;
		for(int i=0; i<n-1; i++) {
			cin>>s1>>s2;
			if(mp[s1]==0) {
				mp[s1]=tot;
				tot++;
			}
			if(mp[s2]==0) {
				mp[s2]=tot;
				tot++;
			}
			int a=mp[s1];
			int b=mp[s2];
			v[b].push_back(a);
		}
		dfs(1);
		printf("%d ",max(dp[1][0],dp[1][1]));
		int f;
		//printf("%d %d\n",dp[1][0],dp[1][1]);
		if(dp[1][0]>dp[1][1]) f=0;
		else if(dp[1][0]<dp[1][1]) f=1;
		else f=-1;
		
		if(f==-1) printf("No\n");
		else if(dup[1][f]) printf("Yes\n");
		else printf("No\n");

	}
	return 0;
}
