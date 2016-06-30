//POJ 1564

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
#define ls 2*i
#define rs 2*i+1
#define up(i,x,y) for(i=x;i<=y;i++)
#define down(i,x,y) for(i=x;i>=y;i--)
#define mem(a,x) memset(a,x,sizeof(a))
#define w(a) while(a)
#define LL long long
const double pi = acos(-1.0);
#define Len 200005
#define mod 19999997
const int INF = 0x3f3f3f3f;
#define exp 1e-6

#define N 1010

int n,flag,ss;
int st[N];
int pt[N];

void DFS(int x,int num,int sum)
{
	if(sum>n)
		return;
	if(sum==n)
	{
		flag=1;
		printf("%d",pt[0]);
		for(int i=1;i<num;i++)
		{
			printf("+%d",pt[i]);
		}
		puts("");
		return;
	}
	int k;
	for(int i=x;i<ss;i++)
	{
		pt[num]=st[i];
		DFS(i+1,num+1,sum+st[i]);
		while(i+1<ss&&st[i]==st[i+1])
			i++;
	}
}

int main()
{
	while(~scanf("%d%d",&n,&ss))
	{
		if(!n&&!ss)
			break;
		
		for(int i=0;i<ss;i++)
		{
			scanf("%d",&st[i]);
		}
		printf("Sums of %d:\n",n);
		
		flag=0;
		
		DFS(0,0,0);  //编号，数目，总和
	
		if(!flag)
			printf("NONE\n");
	
	}
	return 0;
}


