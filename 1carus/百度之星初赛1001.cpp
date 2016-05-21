#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define endl '\n'
#define max(a,b) (a > b ? a : b)
#define min(a,b) (a > b ? b : a)

using namespace std;

const int MAXN = 10005;

int target[MAXN],a[MAXN];
long long x,m,c,k;

int main()
{
	int T,cont = 1;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%I64d %I64d %I64d %I64d",&x,&m,&k,&c);
		
		cout<<"Case #"<< cont++ <<":"<< endl;
		
		if(k == 0)
		{
			cout << (c == 0 ? "Yes" : "No") << endl;
			continue;
		}
		
		memset(target,-1,sizeof(target));
		
		a[0] = target[0] = 0;
		int cur = 1;
		int res = 0;
		while(m--)
		{
			res = (res * 10 + x) % k;
			if(target[res] != -1)break;
			target[res] = cur;
			a[cur++] = res;
		}
		
		if(m == 0)
		{
			cout << ((res == c) ? "Yes" : "No") << endl;
			continue;
		}
		
		int t = cur - target[res];
		if(a[m % t + target[res]] == c)
		{
			cout << "Yes" << endl;
		}
		else cout << "No" << endl;
	}
	return 0;
}
