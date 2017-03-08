#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=2e3+3;
const ll mod=1e9+7;
const int inf=2e9+9;
double eps=1e-9;
double pi=acos(-1.0);

typedef pair<int,int> P;

string a,b;
int dp[maxn][maxn],apre[maxn],bpre[maxn];


int main()
{
	freopen("mm.in","r",stdin);
	freopen("mm.out","w",stdout);
	int t;
	scanf("%d",&t);
	int cas=1;
	while(t--)
	{
		cin>>a>>b;
		printf("Case #%d: ",cas++);
		memset(dp,0,sizeof(dp));
		a='!'+a;
		b='!'+b;
		int alen=a.size(),blen=b.size();
		for(int i=0;i<alen;i++)
		{
			if(a[i]=='*') apre[i]=apre[i-1];
			else apre[i]=i;
		}
		for(int i=0;i<blen;i++)
		{
			if(b[i]=='*') bpre[i]=bpre[i-1];
			else bpre[i]=i;
		}

		for(int i=0;i<alen;i++)
		{
			for(int j=0;j<blen;j++)
			{
				if(i==0 && j==0) dp[i][j]=1;
				else if(i==0)
				{
					if(b[j]=='*') dp[i][j]=dp[i][j-1];
					else dp[i][j]=0;
				}
				else if(j==0)
				{
					if(a[i]=='*') dp[i][j]=dp[i-1][j];
					else dp[i][j]=0;
				}
				else
				{
					if(a[i]==b[j]) dp[i][j]=dp[i-1][j-1];
					if(a[i]=='*')
					{
						dp[i][j] |= dp[i-1][j];
						for(int k=0,pos=bpre[j];k<4 && pos>0;k++,pos=bpre[pos-1])
						{
							dp[i][j] |= dp[i-1][pos-1];
						}
					}

					if(b[j]=='*')
					{
						dp[i][j] |= dp[i][j-1];
						for(int k=0,pos=apre[i];k<4 && pos>0;k++,pos=apre[pos-1])
						{
							dp[i][j] |= dp[pos-1][j-1];
						}
					}
				}
			}
		}
		if(dp[alen-1][blen-1]==1) puts("TRUE");
		else puts("FALSE");
	}
	return 0;
}

