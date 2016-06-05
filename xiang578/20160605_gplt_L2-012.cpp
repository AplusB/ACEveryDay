#include<bits/stdc++.h>
using namespace std;
int a[1024],ans[10];
const int inf=0x3f3f3f3f;

/*void adjust(int x,int n)
{
  int k;
  for(;x<=n/2;)
  {
    k=x*2;
    if(k+1<=n&&a[k]>a[k+1])
      k++;
    
    if(a[x]>a[k])
    {
	   swap(a[x],a[k]);
    	x=k;
	}
	else return ;
  }
}
*/

void adjust(int i)
{
	int fa=i/2;
	if(a[fa]>a[i])
	{
		swap(a[i],a[fa]);
		adjust(fa);
	}
}
char s[1024];

void dfs(int t,int k,int n)
{
	for(int i=1;i<=n;i++)
	{
		if(a[i]==t)
		{
			ans[k]=a[i/2];
			return ;
		}
	}
}

int main()
{
  int n,m,f;
  scanf("%d%d",&n,&m);
  a[0]=-inf;
  for(int i=1;i<=n;i++)
  	{
		scanf("%d",a+i);
		adjust(i);
	}
  //getchar();
  int a1,a2;
  char s1[100],s2[100],s3[100],s4[100];
  for(int i=0;i<m;i++)
  {
    scanf("%d%s",&a1,s1);
    if(s1[0]=='i')
    {
    	scanf("%s%s",s2,s3);
    	if(s3[0]=='r')
    	{
    		if(a1==a[1]) f=1;
    		else f=0;
		}
		else if(s3[0]=='p')
		{
			scanf("%s%d",s4,&a2);
			dfs(a2,1,n);
			if(a1==ans[1]) f=1;
			else f=0;
		}
		else if(s3[0]=='c')
		{
			scanf("%s%d",s4,&a2);
			dfs(a1,0,n);
			if(a2==ans[0]) f=1;
			else f=0;
		}
	}
	else
	{
		scanf("%d%s%s",&a2,s2,s3);
		dfs(a1,0,n);
		dfs(a2,1,n);
		if(ans[0]==ans[1]) f=1;
		else f=0;
	}
    if(f) printf("T\n");
    else printf("F\n");
  }
  return 0;
}

