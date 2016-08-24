#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
typedef long long LL;

int t,n,m,ans;
int cnt[111][10005],num[3];

void add(int x,int y){
	int i,j,k,l,res,tmp=0;
	l=max(cnt[x][0],cnt[y][0]);
	for(i=1;i<=l;i++){
		cnt[x][i]+=cnt[y][i]+tmp;
		tmp=cnt[x][i]/10;
		cnt[x][i]%=10;
	}
	while(tmp){
		cnt[x][++l]=tmp%10;
		tmp/=10;
	}
	cnt[x][0]=l;
}

int main()
{
	int i,j,k,l,res;
	while(~scanf("%d%d%d",&num[0],&num[1],&num[2])){
		memset(cnt,0,sizeof(cnt));
		for(i=0;i<3;i++){
			while(num[i]){
				cnt[i][++cnt[i][0]]=num[i]%10;
				num[i]/=10;
			}
		}
		for(i=3;i<100;i++){
			for(j=1;j<=3;j++)add(i,i-j);
		}
		for(i=cnt[99][0];i;i--)printf("%d",cnt[99][i]);
		puts("");
	}
	return 0;
}
