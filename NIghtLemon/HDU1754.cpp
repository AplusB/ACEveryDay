#include<bits/stdc++.h>
using namespace std;
const int MAXN = 300000;
int a[MAXN],num[MAXN],n,m,k;
int lowbit(int x)
{
	return x & (-x);
}
int MAX(int a,int b){
	return a>b?a:b;
}
int query(int l,int r)
{
	int ans = num[r];  
	while(1)  
	{  
		ans = MAX(ans,num[r]);  
		if(l == r) break;  
		for(r -= 1;r-l >= lowbit(r);r -= lowbit(r))	
			ans = MAX(ans,a[r]);  
	}  
	return ans;  
}
void modify(int x,int y)//一维
{	
	num[x]=y;
	for(int i=x;i<=n;i+=lowbit(i))  
	{  
		a[i] = y;  
		for(int j=1;j<lowbit(i);j <<= 1)
			a[i] = MAX(a[i],a[i-j]);	
	}
	return;  
}

void init()
{
	memset(a,0,sizeof(a));
	for(int i=1;i<=n;i++)  
	{  
		scanf("%d",&a[i]); num[i]=a[i];
		for(int j=1;j<lowbit(i);j <<= 1)
			a[i] = MAX(a[i] , a[i-j]);
	}  
	return;
}

int main()
{
	while(scanf("%d%d",&n,&m)!=EOF){
		init();
		char q[3];int x,y;
		while(m--){
			scanf("%s %d %d",q,&x,&y);  
			if(q[0] == 'U') modify(x,y);  
			else printf("%d\n",query(x,y));
		}
	}
	return 0;
} 
