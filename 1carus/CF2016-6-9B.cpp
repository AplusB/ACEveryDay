#include <bits/stdc++.h>
#define endl '\n'
#define max(a,b) (a > b ? a : b)
#define min(a,b) (a < b ? a : b)

using namespace std;

const int MAXN = 105;

int num[MAXN],n,a;

int judge(int x)
{
	int l = abs(x - a);
	int k1 = a + l,k2 = a - l;
	if(k1 == k2)return 1;
	if(k1 <= 0 || k1 > n)return 1;
	if(k2 <= 0 || k2 > n)return 1;
	if(num[k1] && num[k2])return 2;
	return 0;
}

int main()
{
	while(scanf("%d %d",&n,&a) == 2)
	{
		int i,ans = 0;
		for(i = 1;i <= n;i++)
		{
			scanf("%d",&num[i]);
		}
		
		for(i = 1;i <= n;i++)
		{
			int temp = judge(i);
			if(temp && num[i])
			{ 
				ans += temp;
				num[i] = 0;
			}
		}
		
		cout << ans << endl;
	}
}
