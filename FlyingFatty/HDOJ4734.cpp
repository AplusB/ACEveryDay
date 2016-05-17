#include<map>
#include<set>
#include<math.h>
#include<time.h>
#include<iostream>
#include<cstdio>
#include<queue>
#include<stack>
#include<stdio.h>
#include<cstring>
#include<string.h>
#include<algorithm>
#include<cstdlib>
using namespace std;

#define lson rt<<1,l,mid
#define rson rt<<1|1,mid+1,r
#define ll rt<<1
#define rr rt<<1|1
#define LL long long
#define ULL unsigned long long
#define maxn 1050
#define maxnum 1000050
#define eps 1e-6
#define input freopen("input.txt","r",stdin)
#define output freopen("output.txt","w",stdout)

int a,b,digit[20];
int dp[20][100000];

int dfs(int pos,int x,bool flag){
	if (pos==0) return x>=0;
	if (x<0) return 0;
	if (flag&&dp[pos][x]!=-1) return dp[pos][x];
	int ans=0;
	int maxnumber=flag?9:digit[pos];
	for(int i=0;i<=maxnumber;i++)
		ans+=dfs(pos-1,x-i*(1<<(pos-1)),flag||i<maxnumber);
	if (flag) dp[pos][x]=ans;
	return ans;
}

int F(int x){
	int ret=0,len=0;
	while(x){
		ret+=(x%10)*(1<<len);
		len++;
		x/=10;
	}
	return ret;
}

int calc(int a,int b){
	int len=0;
	while(b){
		digit[++len]=b%10;
		b/=10;
	}
	return dfs(len,F(a),0);
}

int main(){
	//input;
	int T;
	scanf("%d",&T);
	memset(dp,-1,sizeof(dp));
	for(int Case=1;Case<=T;Case++){
		scanf("%d%d",&a,&b);
		printf("Case #%d: %d\n",Case,calc(a,b));
	}
	return 0;
}
