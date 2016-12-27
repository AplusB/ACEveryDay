#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=1e2+60;
const ll inf=2e9+9;

int lt[maxn],rt[maxn];
int post[maxn],in[maxn];

int deal(int p1,int p2,int i1,int i2);
void output(int root);

int main()
{
	int n;
	while(~scanf("%d",&n))
	{
		for(int i=1;i<=n;i++)
			scanf("%d",&post[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&in[i]);
		memset(lt,-1,sizeof(lt));
		memset(rt,-1,sizeof(rt));
		int root=deal(1,n,1,n);
		output(root);
	}
	return 0;
}

void output(int root)
{
	int flag=0;
	queue<int> aha;
	while(!aha.empty()) aha.pop();
	aha.push(root);
	while(!aha.empty())
	{
		int tp=aha.front();aha.pop();
		if(lt[tp]!=-1) aha.push(lt[tp]);
		if(rt[tp]!=-1) aha.push(rt[tp]);
		if(flag==1) printf(" ");
		flag=1;
		printf("%d",tp);
	}
	printf("\n");
}

int deal(int p1,int p2,int i1,int i2)
{
	if(p2<p1 || i2<i1) return -1;
	int root=post[p2];
	int pos=-1;
	for(int i=i1;i<=i2;i++)
	{
		if(in[i]==root) 
		{
			pos=i;break;
		}
	}
	int len=pos-i1+1;
	lt[root]=deal(p1,p1+len-2,i1,i1+len-2);
	rt[root]=deal(p1+len-1,p2-1,pos+1,i2);
	return root;
}
