#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#define endl '\n'

using namespace std;

const int MAXN = 1e5 + 5;
 
int a[MAXN],b[MAXN],p[MAXN];
int n;

int main()
{
	while(scanf("%d",&n) == 1)
	{
		int i;
		for(i = 0;i < n;i++)
		{
			scanf("%d",&a[i]);
		}
		
		for(i = 0;i < n;i++)
		{
			scanf("%d",&b[i]);
		}
		
		for(i = 0;i < n;i++)p[a[i]] = b[i];
		
		for(i = 1;i <= n;i++)
		{
			if(i != 1)cout << " ";
			cout << p[i];
		}
		cout << endl;
	}
	return 0;
}
