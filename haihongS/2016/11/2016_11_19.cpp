#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=2e5+9;

string zhu,ke;
int a[maxn],b[maxn];

int main()
{
	while(cin>>zhu>>ke)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		int n;
		scanf("%d",&n);
		while(n--)
		{
			int t;
			scanf("%d",&t);
			char op[10];
			scanf("%s",op);
			int id;
			scanf("%d",&id);
			char cc[10];
			scanf("%s",cc);

			if(op[0]=='a')
			{
				if(cc[0]=='r')
				{
					if(b[id]<2)
						cout<<ke<<" "<<id<<" "<<t<<endl;
					b[id]=3;
				}
				else
				{
					b[id]+=1;
					if(b[id]==2)
						cout<<ke<<" "<<id<<" "<<t<<endl; 
				}
			}
			else
			{
				if(cc[0]=='r')
				{
					if(a[id]<2)
						cout<<zhu<<" "<<id<<" "<<t<<endl; 
					a[id]=3;
				}
				else
				{
					a[id]+=1;
					if(a[id]==2)
						cout<<zhu<<" "<<id<<" "<<t<<endl;
				}
			}
		}

	}

	return 0;
}
