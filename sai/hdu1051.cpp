#include<iostream>
#include<algorithm>
using namespace std;

struct stick{
	int l,w,flag;
}s[5005];

bool cmp(stick a,stick b)
{
	return a.l<b.l||(a.l==b.l&&a.w<b.w);
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int cnt=0;
		for(int i=0;i<5005;i++)
			s[i].flag=0;

		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>s[i].l;
			cin>>s[i].w;
		}
		sort(s,s+n,cmp);

		int k;
		for(int i=0;i<n;i++)
		{
            if(s[i].flag==1)continue;
            cnt++;
            k=i;
            for(int j=i+1;j<n;j++)
			{
				if(s[j].l>=s[k].l&&s[j].w>=s[k].w&&s[j].flag==0)
				{
					s[j].flag=1;
					k=j;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
