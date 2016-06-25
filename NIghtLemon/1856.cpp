#include<bits/stdc++.h>
#define MAXN 10000007
using namespace std;

int Fa[MAXN],sum[MAXN];
int n,a,b,ans;

int ff(int x){
	int i=x,j=x,k;
	while(i!=Fa[i]) i=Fa[i];
	while(j!=Fa[j]){
		k = j;
		j = Fa[j];
		Fa[k] = i; 
	}
	return i;
}

void Conb(){
	a = ff(a);
	b = ff(b);
	if(a!=b){
		Fa[b] = a;
		sum[a] += sum[b];
		if(sum[a] >ans) ans = sum[a];
	}
}

int main()
{
	while(scanf("%d",&n)!=EOF){
		memset(Fa,0,sizeof(Fa));
		memset(sum,0,sizeof(sum));
		ans = 1;
		while(n--) {
			scanf("%d%d",&a,&b);
			if(!Fa[a]){
				Fa[a] = a;
				sum[a] = 1;
			}
			if(!Fa[b]){
				Fa[b] = b;
				sum[b] = 1;
			}
			Conb();
		}
		printf("%d\n",ans);
	}
	return 0;
}
