/* ***********************************************
Author        :guanjun
Created Time  :2016/5/28 7:40:53
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
int a[110];
int dp[110][110];
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int n;
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)
			for(int j=i;j<=n;j++){
				if(i==j)dp[i][j]=1;
				else dp[i][j]=INF;
			}
		for(int x=1;x<=n;x++){
			for(int i=1;i<=n;i++){
				int j=i+x;
				if(j>n)break;
				if(a[i]==a[j])dp[i][j]=dp[i][j-1];
				for(int k=i;k<=j;k++)
					if(a[i]==a[k])dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
				}
		}
		 printf("%d\n",dp[1][n]); 

	}
    return 0;
}
/*
Problem Description
大明在服装店工作，负责给服装店的橱窗上的模特换衣服，模特每天穿什么衣服按照一个给定的顺序，大明为了偷懒，可以选择在已经穿了衣服的模特身上继续套衣服，或者从模特身上脱下来衣服，例如模特身上穿了1号衣服，1号衣服外面已经套了2号衣服，今天要展示1号衣服，大明可以选择在2号衣服外面再套另一件1号衣服，也可以选择脱下来2号衣服，把1号衣服露出来。要注意，从模特身上脱下来的衣服就脏了，不能再用，要穿同样类型的衣服只能新拿一件穿，并且如果1号衣服外面套着2号，再套着3号，要露出1号衣服只能先脱掉3号，再脱掉2号。
现在给你n天和每天展示的衣服的型号，问最少需要几件衣服才能完成工作。
Input
输入有多组数据，处理到EOF
每组数据第一行输入一个整数n（1 ≤ n ≤ 100），表示展示的天数，接下来一行输入n个整数ai，由空格分隔开，表示每天穿的衣服的型号（1 ≤ ai ≤ 100）。按顺序从左到右展示。
Output
对于每组数据，输出最少需要几件衣服。
Sample Input
4
1 2 1 2
7
1 2 1 1 3 2 1
Sample Output
3
4

*/
