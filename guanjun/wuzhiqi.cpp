/* ***********************************************
Author        :guanjun
Created Time  :2016/6/21 19:15:58
File Name     :1.cpp
************************************************ */
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
#include <list>
#include <deque>
#include <stack>
#define ull unsigned long long
#define ll long long
#define mod 90001
#define INF 0x3f3f3f3f
#define maxn 10010
#define cle(a) memset(a,0,sizeof(a))
const ull inf = 1LL << 61;
const double eps=1e-5;
using namespace std;
priority_queue<int,vector<int>,greater<int> >pq;
struct Node{
	int x,y;
};
struct cmp{
    bool operator()(Node a,Node b){
        if(a.x==b.x) return a.y> b.y;
        return a.x>b.x;
	}
};

bool cmp(int a,int b){
    return a>b;
}
int a[26][26];
bool check(int x,int y,int d){
	int cnt=-1;
	int i,j;
	i=x;j=y;
	while(i<=25&&a[i][j]==d){
		i++;cnt++;
	}
	i=x;j=y;
	while(i>=1&&a[i][j]==d){
		i--;cnt++;
	}
	if(cnt>=5)return true;
	cnt=-1;
	i=x;j=y;
	while(j<=25&&a[i][j]==d){
		j++;cnt++;
	}
	i=x;j=y;
	while(j>=1&&a[i][j]==d){
		j--;cnt++;
	}
	if(cnt>=5)return true;
	
	i=x;j=y;
	cnt=-1;
	while(i<=25&&j<=25&&a[i][j]==d){
		i++;j++;cnt++;
	}
	i=x;j=y;
	while(i>=1&&j>=1&&a[i][j]==d){
		i--;j--;cnt++;
	}
	if(cnt>=5)return true;

	i=x;j=y;
	cnt=-1;
	while(i<=25&&j>=1&&a[i][j]==d){
		i++;j--;cnt++;
	}
	i=x;j=y;
	while(i>=1&&j<=25&&a[i][j]==d){
		i--;j++;cnt++;
	}
	if(cnt>=5)return true;
	return false;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
	for(int i=1;i<=25;i++)
		for(int j=1;j<=25;j++)
			a[i][j]=-1;
	int x,y,sum=0,mark=0;
	while(scanf("%d%d",&x,&y)!=EOF){
		sum++;
		if(mark)continue;
		if(x<1||x>25||y<1||y>25){
			if(sum&1)puts("White");
			else puts("Black");
			mark=1;
		}
		else if(a[x][y]!=-1){
			if(sum&1)puts("White");
			else puts("Black");
			mark=1;
		}
		else{
			if(sum&1){
				a[x][y]=0;
				if(check(x,y,0)){puts("Black");mark=1;}
			}
			else{
				a[x][y]=1;
				if(check(x,y,1)){puts("White");mark=1;}
			}
		}
	}
	if(!mark)puts("Gray");
    return 0;
}
