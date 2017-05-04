#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=2e3+3;
const ll mod=1e9+7;
const int inf=2e9+9;
double eps=1e-9;
double pi=acos(-1.0);

typedef pair<int,int> P;

char a[maxn];

int main()
{
	while(~scanf("%s",a))
	{
		int len=strlen(a);
		int cnt=0;
		for(int i=0;i<len/2;i++)
		{
			if(i==len-i-1) continue;
			if(a[i]!=a[len-i-1]) cnt++;
		}
		if(cnt==1) puts("YES");
		else if(cnt==0 && len%2==1) puts("YES");
		else puts("NO");
	}
	return 0;
}
