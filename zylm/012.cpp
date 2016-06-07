//http://codeforces.com/problemset/problem/670/B
#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#define read freopen("q.in","r",stdin)
#define LL long long
#define maxn 200005
using namespace std;
int a[maxn];

int main()
{
	//std::ios::sync_with_stdio(false);
	long long n,k;
	while(~scanf("%I64d%I64d",&n,&k))
	{
		int i,j;
		for(i=1;i<=n;i++)scanf("%d",&a[i]);
		long long t=sqrt(2*k);
		long long tmp= t*(t+1)/2;
		if(k>tmp)cout<<a[k-tmp]<<endl;
		else cout<<a[t-(tmp-k)]<<endl;
	}
}
