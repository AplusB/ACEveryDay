#include <bits/stdc++.h>
#define endl '\n'

using namespace std;

const int MAXN = 1e5 + 5;

char str[MAXN];
int target[MAXN];
int n,k;

int solve(char c)
{
	memset(target,0,sizeof(target));
	int res = 0;
	
	int i,j;
	for(i = 0;i < n;i++)
	{
		target[i + 1] = target[i] + (str[i] == c);
	}
	
	for(i = 1,j = 0;i <= n;i++)
	{
		while(target[i] - target[j] > k)j++;
		
		int temp = i - j;
		res = max(res,temp);
	}
	return res;
}

int main()
{
	while(scanf("%d %d",&n,&k) == 2)
	{
		scanf("%s",str);
		//solve('a');
		int ans = max(solve('a'),solve('b'));
		cout << ans << endl;
	}
	return 0;
}

