#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6 + 5;

map<int,int> index;
int num[MAXN];
int n;
set<int> pos;
set<int> neg;

int main()
{
	while(scanf("%d",&n) == 1)
	{
		pos.clear();
		neg.clear();
		
		int i;
		for(i = 0;i < n;i++)
		{
			scanf("%d",&num[i]);
			index[num[i]] = i;
		}
		
		pos.insert(num[0]);
		neg.insert(-num[0]);
		for(i = 1;i < n;i++)
		{
			 
			int a = -1,b = -1;
			if(pos.lower_bound(num[i]) != pos.end())
			{
				a = index[*pos.lower_bound(num[i])];
			}
			if(neg.lower_bound(-num[i]) != neg.end())
			{
				b = index[-*neg.lower_bound(-num[i])];
			}
			
			cout << num[max(a,b)] << " ";
			pos.insert(num[i]);
			neg.insert(-num[i]); 
		}
		cout << endl;
	}
	return 0;
}
