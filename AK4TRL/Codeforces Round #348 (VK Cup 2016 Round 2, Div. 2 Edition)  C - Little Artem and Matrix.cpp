//模拟题，行倒推列倒推
#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int a[1005][1005];
int t[10005],r[10005],c[10005],x[10005];
int main(){
#ifdef _CONSOLE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	int n,m,q;
	while(~scanf("%d%d%d",&n,&m,&q)){
		for(int i = 1; i <= q; ++i){
			scanf("%d",&t[i]);
			if(t[i]==1)
				scanf("%d",&r[i]);
			else if(t[i]==2)
				scanf("%d",&c[i]);
			else
				scanf("%d%d%d",&r[i],&c[i],&x[i]);
		}
		for(int i = q; i >= 1; i--){
			if(t[i]==3)
				a[r[i]][c[i]] = x[i];
			else if(t[i] == 1){//left
				int tmp = a[r[i]][m];
				for(int j = m; j >= 2; j--)
					a[r[i]][j] = a[r[i]][j-1];
				a[r[i]][1] = tmp;
			}
			else {
				int tmp = a[n][c[i]];//down
				for(int j = n; j >= 2; j--)
					a[j][c[i]] = a[j-1][c[i]];
				a[1][c[i]] = tmp;
			}
		}
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= m; ++j)
				printf("%d ",a[i][j]);
			cout << endl;
		}
	}

	return 0;
}
