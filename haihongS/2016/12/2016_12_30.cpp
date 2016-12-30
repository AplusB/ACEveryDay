#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn=2e4+60;
const ll inf=2e9+9;

char a[maxn],sum[maxn],bb[maxn];
char g1[maxn],g2[maxn];

void pplus(char x[],char y[]);
char* rev(char x[]);
int judge(char x[]);

int main()
{
	int k;
	while(~scanf("%s %d",a,&k))
	{
		if(judge(a)==1)
		{
			printf("%s\n0\n",a);
			continue;
		}
		int flag=0;
		strcpy(g1,a);
		strcpy(g2,rev(g1));
		for(int i=1;i<=k;i++)
		{
			pplus(g1,g2);
			if(judge(sum))
			{
				flag=1;
				printf("%s\n%d\n",rev(sum),i);
				break;
			}
			strcpy(g1,sum);
			strcpy(g2,rev(g1));
		}
		if(flag==0)
			printf("%s\n%d\n",rev(sum),k);
	}
	return 0;
}

int judge(char x[])
{
	int len=strlen(x);
	for(int i=0;;i++)
	{
		int lt=i,rt=len-i-1;
		if(lt>rt) break;
		if(x[lt]!=x[rt]) return 0;
	}
	return 1;
}

char* rev(char x[])
{
	int len=strlen(x);
	memset(bb,0,sizeof(bb));
	int pos=0;
	for(int i=len-1;i>=0;i--)
	{
		bb[pos++]=x[i];
	}
	return bb;
}

void pplus(char x[],char y[])
{
	memset(sum,0,sizeof(sum));
	int xlen=strlen(x),ylen=strlen(y);
	int px=xlen-1,py=ylen-1,pos=0,f=0;
	while(px>=0 && py>=0)
	{
		int tmp=x[px]-'0'+y[py]-'0';
		tmp+=f;
		sum[pos++]=tmp%10+'0';
		f=tmp/10;
		px--,py--;
	}
	while(px>=0)
	{
		int tmp=x[px]-'0'+f;
		sum[pos++]=tmp%10+'0';
		f=tmp/10;
		px--;
	}
	while(py>=0)
	{
		int tmp=y[py]-'0'+f;
		sum[pos++]=tmp%10+'0';
		f=tmp/10;
		py--;
	}
	if(f!=0) 
		sum[pos++]=f+'0';
}
