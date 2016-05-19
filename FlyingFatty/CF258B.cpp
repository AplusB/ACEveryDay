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
#define MOD 1000000007

LL digit[15],sum[15],dp[15][15][15];
LL dfs(int pos,int pre,int sum,bool flag){
	if (pos==0) return pre==sum;
	if (flag&&dp[pos][pre][sum]!=-1) return dp[pos][pre][sum];
	int maxnumber=flag?9:digit[pos];
	LL ans=0;
	for(int i=0;i<=maxnumber;i++)
		ans+=dfs(pos-1,pre+(i==4||i==7),sum,flag||i<maxnumber);
	if (flag) dp[pos][pre][sum]=ans;
	return ans;
}

LL solve(int now,int res){
	LL ans=0;
	if (now==7) return 1;
	for(int i=0;i<=res;i++)
		if (sum[i]){
			sum[i]--;
			ans=(ans+(sum[i]+1)*solve(now+1,res-i))%MOD;
			sum[i]++;
		}
	return ans;
}

LL calc(LL n){
	int len=0;
	LL ans=0;
	while(n){
		digit[++len]=n%10;
		n/=10;
	}
	for(int i=0;i<=len;i++)
		sum[i]=dfs(len,0,i,0);
	sum[0]--;
	for(int i=1;i<=len;i++)
		ans=(ans+sum[i]*solve(1,i-1))%MOD;
	return ans;
}

int main(){
	//input;
	LL m;
	memset(dp,-1,sizeof(dp));
	while(scanf("%I64d",&m)!=EOF)
		printf("%I64d\n",calc(m));
	return 0;
}
