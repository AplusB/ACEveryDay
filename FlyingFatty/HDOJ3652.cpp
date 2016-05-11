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

__int64 m,n;
int digit[20];
__int64 dp[20][5][15];

__int64 dfs(int pos,int status,int mod,bool flag){
	if (pos==0) return (status==2&&mod==0);
	if (flag&&dp[pos][status][mod]!=-1) return dp[pos][status][mod];
	int num=flag?9:digit[pos];
	__int64 ans=0;
	for(int i=0;i<=num;i++){
		int nowmod=(mod*10+i)%13;
		if (status==2||(status==1&&i==3)) ans+=dfs(pos-1,2,nowmod,flag||i<num);
		else if (i==1) ans+=dfs(pos-1,1,nowmod,flag||i<num);
		else ans+=dfs(pos-1,0,nowmod,flag||i<num);
	}
	if (flag) dp[pos][status][mod]=ans;
	return ans;
}

__int64 calc(__int64 n){
	//标准格式
	//将n分解成各个数位，从高到低
	memset(digit,0,sizeof(digit));
	int pos=0;
	while(n){
		digit[++pos]=n%10;
		n/=10;
	}
	return dfs(pos,0,0,0);
}

int main(){
	//input;
	memset(dp,-1,sizeof(dp));
	while(scanf("%I64d",&n)!=EOF)
		printf("%I64d\n",calc(n));
	return 0;
}
