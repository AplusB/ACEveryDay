#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=2e5+9;
const ll mod=1e9+7;
const int inf=2e9+9;
double eps=1e-9;
double pi=acos(-1.0);

char a[maxn],b[maxn];
int pre[maxn],suf[maxn];


int main()
{
	while(~scanf("%s %s",a+1,b+1))
	{
		int alen=strlen(a+1),blen=strlen(b+1);
		int pos=1;
		pre[0]=0,suf[blen+1]=0;
		for(int i=1;i<=blen;i++)
		{
			while(pos<=alen && a[pos]!=b[i]) pos++;
			if(pos>alen) pre[i]=inf;
			else 
			{
				pre[i]=pos;
				pos++;
			}
		}
		pos=alen;
		for(int i=blen;i>=1;i--)
		{
			while(pos>=1 && a[pos]!=b[i]) pos--;
			if(pos==0) suf[i]=inf;
			else
			{
				suf[i]=alen-pos+1;
				pos--;
			}
		}
		
		string ans="";
		int minn=inf,ll,rr,now=1;
		for(int i=0;i<=blen;i++)
		{
			now=max(now,i+1);
			while(now<=blen+1 && pre[i]+suf[now]>alen)
				now++;
			if(now<=blen+1 && now-i+1<minn)
			{
				minn=now-i+1;
				ll=i,rr=now;
			}
		}

		if(minn>blen+1) puts("-");
		else
		{
			for(int i=1;i<=ll;i++) printf("%c",b[i]);
			for(int i=rr;i<=blen;i++) printf("%c",b[i]);
			printf("\n");
		}
	}
	return 0;
}


