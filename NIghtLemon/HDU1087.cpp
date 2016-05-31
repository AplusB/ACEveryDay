#include<bits/stdc++.h>
#define N 1007
using namespace std;
int n;
int a[N],b[N],MA,ans;

void init()
{
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i] = a[i];
	}
}
int main()
{
	while(scanf("%d",&n) && n!=0){
		init(); ans = 0;
		for(int i=2;i<=n;i++){
			MA = 0;
			for(int j=1;j<i;j++) if(a[j]<a[i] && b[j]>MA)
				MA = b[j];
			b[i] = MA + a[i];
			if(b[i]>ans) ans =b[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
