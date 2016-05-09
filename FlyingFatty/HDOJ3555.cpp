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

/*
dp[len][0]:前len位不含49且第len位不是4
dp[len][1]:前len位不含49且第len位为9（在加高位的4就可以符合题意了）
dp[len][2]:前len位已有49 
*/

__int64 n;
int digit[20];
__int64 dp[20][5];

__int64 dfs(int pos,int status,bool flag){
	if (pos==0) return status==2;
	if (flag&&dp[pos][status]!=-1) return dp[pos][status];
	int num=flag?9:digit[pos];
	__int64 ans=0;
	for(int i=0;i<=num;i++){
		//如果前len位已经有了49，或者加上这次枚举的高位的4有了49 
		if (status==2||(status==1&&i==9)) ans+=dfs(pos-1,2,flag||i<num);
		else if (i==4) ans+=dfs(pos-1,1,flag||i<num);
		else ans+=dfs(pos-1,0,flag||i<num);
	}
	if (flag) dp[pos][status]=ans;
	return ans;
}

__int64 calc(__int64 n){
	int pos=0;
	while(n){
		digit[++pos]=n%10;
		n/=10;
	}
	return dfs(pos,0,0);
}

int main(){
	//input;
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%I64d",&n);
		memset(digit,0,sizeof(digit));
		memset(dp,-1,sizeof(dp));
		printf("%I64d\n",calc(n));
	}
	return 0;
}
