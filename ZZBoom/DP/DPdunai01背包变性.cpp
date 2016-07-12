//poj 1015
//DP[i][j]就是第i个人辩控差最小的辩控和最大


//#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const double eps=1e-5;
const double pi=acos(-1.0);
const int mod=1e9+7;
const int INF=0x3f3f3f3f;

const int N=1e2+7;

int n;
int m;
int dp[25][807];
int path[24][807];
int p[N*2];
int d[N*2];
int s[N*2];
int v[N*2];

bool select(int j,int k,int i,int *v)
{
	while(j>0&&path[j][k]!=i){
		k-=v[path[j][k]];
		j--;
	}
	return j?0:1;
}
int main()
{
	int time=1;
	while(cin>>n>>m&&n)
	{
		int j,k,i;
		int *p=new int[n+1];
		int *d=new int[n+1];
		int *s=new int[n+1];
		int *v=new int[n+1];
		memset(dp,-1,sizeof(dp));
		memset(path,0,sizeof(path));
		
		for(i=1;i<=n;i++)
		{
			cin>>p[i]>>d[i];
			
			s[i]=p[i]+d[i];
			v[i]=p[i]-d[i];
		}
		int fix=m*20;
		
		dp[0][fix]=0;
		for(j=1;j<=m;j++)
			for(k=0;k<=2*fix;k++)
			{
				if(dp[j-1][k]>=0)
				{
					for(i=1;i<=n;i++)
						if(dp[j][k+v[i]]<dp[j-1][k]+s[i])
						{
							if(select(j-1,k,i,v))
							{
								dp[j][k+v[i]]=dp[j-1][k]+s[i];
								path[j][k+v[i]]=i;
							}
						}
				}
			}
		
		for(k=0;k<=fix;k++)
			if(dp[m][fix-k]>=0||dp[m][fix+k]>=0)
				break;
		int div=dp[m][fix-k]>dp[m][fix+k]?(fix-k):(fix+k);
		
		cout<<"Jury #"<<time++<<endl;
	//	printf("Best jury has value %d for prosecution and value %d for defence\n",(dp[m][div]+div-fix)/2,(dp[m][div]-div+fix)/2);
		cout<<"Best jury has value ";
		cout<<(dp[m][div]+div-fix)/2<<" for prosecution and value ";
		cout<<(dp[m][div]-div+fix)/2<<" for defence:"<<endl;
		
		int id[N<<1];
		for(i=0,j=m,k=div;i<m;i++){
			id[i]=path[j][k];
			k-=v[id[i]];
			j--;
		}
		sort(id,id+m);
		for(i=0;i<m;i++)
			cout<<" "<<id[i];
		cout<<endl;
	}
	return 0;
}

