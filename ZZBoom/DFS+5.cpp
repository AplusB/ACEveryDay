POJ 2718 

#include<cstdio>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;

/*
int main()
{
	int a[3];
	for(int i=0;i<3;i++)
		cin>>a[i];
	while(next_permutation(a,a+3))
	{
		for(int i=0;i<3;i++)
		{
			printf("%d",a[i]);
		}
		puts("");
	}
}
*/

#define INF 0X3f3f3f3f
int a[15];
bool vis[15];
int b[15];
int n;
int ans;
char s[1010];

//另一半直接搞全排列，然后直接判断取小就行了
void solve(int aa)
{
    int len=0;
    int bb;
    for(int i=0; i<n; i++)
    {
        if(!vis[i])
        {
            b[len++]=a[i];
        }
    }
    bb=0;
    for(int i=0; i<len; i++)
        bb=bb*10+b[i];
    sort(b,b+len);
    if(len==1||b[0]!=0)
        ans=min(abs(bb-aa),ans);
    while(next_permutation(b,b+len))
    {
        bb=0;
        for(int i=0; i<len; i++)
            bb=bb*10+b[i];
        if(len==1||b[0]!=0)
            ans=min(abs(bb-aa),ans);
    }
}

//先搜出一个数；
void DFS(int k,int res)
{
    if(k==n/2)
    {
        solve(res);
        return;
    }
    for(int i=0; i<n; i++)
    {
        if(!vis[i])
        {
            if(a[i]==0&&k==0&&n>3)
                continue;
            vis[i]=1;
            DFS(k+1,res*10+a[i]);
            vis[i]=0;
        }
    }
}
//两个输入方式
void made1()
{
    gets(s);
    n=0;
    int len=strlen(s);
    for(int i=0; i<len; i++)
    {
        if(s[i]==' ')
            continue;
        else
        {
            a[n++]=s[i]-'0';
            //printf("%d ",a[n-1]);
        }
    }
}
void made2()
{
    n=0;
    char ch;
    while((ch=getchar())!='\n')
    {
        if(ch==' ')
            continue;
        a[n++]=ch-'0';
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    while(T--)
    {
        //made1();
        made2();

        memset(vis,0,sizeof(vis));
        ans=INF;
        DFS(0,0);
        printf("%d\n",ans);
    }
    return 0;
}

