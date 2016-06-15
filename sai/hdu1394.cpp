#include<iostream>
#include<math.h>
#include<algorithm>
#include<string.h>
using namespace std;

#define inf 0x3f3f3f3f

int tree[5005];
int num[5005];

int sum(int x)
{
	int s=0;
	while(x>0)
	{
		s+=tree[x];
		x-=(x&(-x));
	}
	return s;
}

void add(int i,int x)
{
	while(i<5005)
	{
		tree[i]+=x;
		i+=(i&(-i));
	}
}

int main()
{
	int n;
	while(cin>>n)
	{
		memset(tree,0,sizeof(tree));
		int ans=0;

		for(int i=1;i<=n;i++)
		{
			cin>>num[i];
			num[i]++;
			ans+=sum(5005)-sum(num[i]);
			add(num[i],1);
		}

		int minx=inf;
        for(int i=1;i<=n;i++)
        {
        	//cout<<ans<<endl;
            ans=ans-(num[i]-1)+(n-num[i]);
            minx=min(ans,minx);
        }
        cout<<minx<<endl;
	}
	return 0;
}
