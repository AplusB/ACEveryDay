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
函数解释：
getnewstatus：
LIS的O(nlogn)

getonenum:
计算s中有多少个1 
*/

int digit[50],K;
__int64 dp[50][1<<12][12];
__int64 L,R;

int getnewstatus(int x,int s){
	for(int i=x;i<10;i++)
		if (s&(1<<i)) return (s^(1<<i))|(1<<x);
	//如果在某个高位有可以替代的值
	//用x这位去替代i这一位
	//数值会是更小的 
	return s|(1<<x);
	//找不到的话，就把第x这位添加进去 
}

int getonenum(int s){
	//实参代入时为status 
	int num=0;
	while(s){
		if (s%2) num++;
		s>>=1; 
	}
	return num;
}

__int64 dfs(int pos,int status,bool flag,bool zero){
	if (pos==0) return getonenum(status)==K;
	if (flag&&dp[pos][status][K]!=-1) return dp[pos][status][K];
	int num=flag?9:digit[pos];
	__int64 ans=0;
	for(int i=0;i<=num;i++)
	//注意到0这个特殊数值 
		ans+=dfs(pos-1,zero&&(i==0)?0:getnewstatus(i,status),flag||i<num,zero&&(i==0));
	if (flag) dp[pos][status][K]=ans;
	return ans;
}

__int64 calc(__int64 n){
	int len=0;
	while(n){
		digit[++len]=n%10;
		n/=10;
	}
	return dfs(len,0,0,1);
}

int main(){
	//input;
	memset(dp,-1,sizeof(dp));
	int T;
	scanf("%d",&T);
	for(int Case=1;Case<=T;Case++){
		memset(digit,0,sizeof(digit));
		scanf("%I64d%I64d%d",&L,&R,&K);
		printf("Case #%d: %I64d\n",Case,calc(R)-calc(L-1));
	}
	return 0;
}
