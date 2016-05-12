#include<bits/stdc++.h>
using namespace std;

int n,m,ans,T,tot,sumv;
int A[107];
int a[100007];
int v[100007];

int main()
{
	while(scanf("%d%d",&n,&m) && n){
		memset(a,0,sizeof(a));
		memset(v,0,sizeof(v));
		tot = 0; ans = 0; sumv = 0;
		for(int i=1 ; i<=n; i++) scanf("%d",&A[i]);
		for(int i=1 ; i<=n; i++){
			int j=1;
			scanf("%d",&T);
			while(T){
				a[++tot] = j*A[i];
				T -=j;				
				j = j + j;
				if(T<j) break;
			}
			if(T) {
				a[++tot] = T*A[i];
			}
		}
		v[0] = 1;
		for(int i=1 ; i<=tot ;i++){
			sumv += a[i];
			T = min(sumv,m);
			for(int j=T;j>=a[i];j--)
				v[j] = (v[j] || v[j-a[i]]);
		}
		T = min(sumv,m);
		for(int i=1;i<=T;i++) ans+=v[i];
		printf("%d\n",ans);
	}
	return 0;
}
