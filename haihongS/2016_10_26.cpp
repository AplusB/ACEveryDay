#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=3e5+9;
const int inf=2e9+9;
const ll mod=1e9+7;
const double eps=1e-9;

int a[maxn];

int main()
{
	int n,k;
	while(~scanf("%d%d",&n,&k))
	{
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		int lt=1,rt=1,cnt=1-a[1];
		int ans=0,fir=1;
		if(cnt<=k) ans=1;
		while(lt<=n)
		{
			while(lt==rt && lt+1<=n && cnt>k)
			{
				lt++,rt++;
				cnt=1-a[lt];
			}
			if(lt==rt && cnt>k && lt+1>n) break;
			while(rt+1<=n && cnt<k)
			{
				rt++;
				if(a[rt]==0) cnt++;
			}
			while(rt+1<=n && a[rt+1]==1) rt++;
			if(rt-lt+1>ans)
			{
				ans=rt-lt+1;
				fir=lt;
			}
			if(a[lt]==0) cnt--;
			lt++;
		}
		printf("%d\n",ans);
		for(int i=fir;i<fir+ans;i++)
		{
			a[i]=1;
		}
		for(int i=1;i<=n;i++)
		{
			if(i!=1) printf(" ");
			printf("%d",a[i]);
		}
		printf("\n");
	}
	return 0;
}
