#include<bits/stdc++.h>
using namespace std;

int a[2100000],vis[21],ans;
int dfs(int x){
	memset(vis,0,sizeof(vis));
	for(int i=0;i<20;i++) if(x & (1<<i)){
		int tmp=x;
		for(int j=i+1;j<20;j++)if(!(x & (1<<j))){
			tmp^=((1<<i)^(1<<j));
			vis[a[tmp]] = true;
			break;
		}
	}
	for(int i=0;i<=20;i++) if(!vis[i]) return i;
	return 0;
}

void init(){
	memset(a,0,sizeof(a));
	for(int i=1048575;i>=0;i--) a[i] = dfs(i);
}

void check(){
	int t=0,n,k;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&k);
		t |= (1<<(k-1));
	}
	ans ^= a[t];
}

int main()
{
	init();
	int T,n,N;
	init();
	scanf("%d",&T);
	while(T--){
		ans =0;
		scanf("%d",&N);
		while(N--) check();
		if(ans) printf("YES\n");else printf("NO\n");
	}
	return 0;
}
