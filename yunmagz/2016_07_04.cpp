//CF#359 (Div. 2)
//A - Free Ice Cream
#include <bits/stdc++.h>
using namespace std;
#define LL long long
int main() {
	int n,x,a;
	string s;
	cin>>n>>x;
	LL cnt=0,now=x;
	for(int i=0;i<n;i++){
		cin>>s>>a;
		if(s=="+"){
			now+=a;
		}
		else {
			if(now<a){
				cnt++;
			}
			else {
				now-=a;
			}
		}
	}
	cout<<now<<" "<<cnt<<endl;
	return 0;
}
//B - Little Robber Girl's Zoo
#include <bits/stdc++.h>
using namespace std;
#define LL long long
int a[100];
int main() {
	int n,x;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	int cnt=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			if(a[j]>a[j+1]){
			 	swap(a[j],a[j+1]);
			 	printf("%d %d\n",j+1,j+2);
			}
		}
	}
	return 0;
}
//C - Robbers' watch
#include <bits/stdc++.h>
using namespace std;
#define LL long long
int a[100];
int u[25],v[25],vis[8],q[15];
int solve(int x){
	int cnt=0;
	if(!x) cnt++;
	while(x){
		x/=7;
		cnt++;
	}
	return cnt;
}
bool check(int x,int y,int wn,int wm) {  
    int w=wn;
    while (x) {  
        a[w]=x%7;x/=7;w--;  
    }  
    while (w) { a[w]=0;w--; }  
    w=wm;  
    while (y) {  
        a[wn+w]=y%7;y/=7;w--;  
    }  
    while (w) { a[wn+w]=0;w--; }  
    for (int i=1;i<wn+wm;i++)  
        for (int j=i+1;j<=wn+wm;j++)  
        if (a[i]==a[j]) return 0;  
    return 1;  
}  
int main() {
	int n,m,ans=0;
	cin>>n>>m;
	int ni=solve(n-1),mi=solve(m-1);
	int l=ni+mi;
	if(l>7) puts("0");
	else {
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++){
				if(check(i,j,ni,mi)) ans++;
			}
		cout<<ans<<endl;
	}
	return 0;
}
//D - Kay and Snowflake
#include <bits/stdc++.h>
using namespace std;
vector<int>g[300010];
int f[300010],cnt[300010],ans[300010];
void dfs(int u){
	ans[u]=u;
	cnt[u]=1;
	int maxn=0;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		dfs(v);
		cnt[u]+=cnt[v];
		if(cnt[v]>cnt[maxn]) maxn=v;
	}
	if(cnt[maxn]*2>cnt[u]){
		int m=ans[maxn];
		while((cnt[u]-cnt[m])*2>cnt[u]) m=f[m];
		ans[u]=m;
	}
}
int main() {
	int n,q;
	cin>>n>>q;
	for(int i=2;i<=n;i++){
		cin>>f[i];
		g[f[i]].push_back(i);
	}
	dfs(1);
	while(q--){
		cin>>n;
		cout<<ans[n]<<endl;
	}
	return 0;
}
