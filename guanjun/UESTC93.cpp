/* ***********************************************
Author        :guanjun
Created Time  :2016/7/15 15:30:29
File Name     :uestc93.cpp
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
int x[5];
int y[5];
bool judge_Parallelogram(){
	//1,2   4,3
	int a=(x[2]-x[1])*(y[3]-y[4])-(x[3]-x[4])*(y[2]-y[1]);
	if(a!=0)return 0;
	a=(x[3]-x[2])*(y[4]-y[1])-(x[4]-x[1])*(y[3]-y[2]);
	if(a!=0)return 0;
	return 1;
}
bool judge_Rectangle(){
	int a=(x[3]-x[1])*(x[3]-x[1])+(y[3]-y[1])*(y[3]-y[1]);
	int b=(x[2]-x[4])*(x[2]-x[4])+(y[2]-y[4])*(y[2]-y[4]);
	if(a==b)return 1;
	return 0;
}
bool judge_Diamond(){
	int a=(x[2]-x[1])*(x[2]-x[1])+(y[2]-y[1])*(y[2]-y[1]);
	int b=(x[3]-x[2])*(x[3]-x[2])+(y[3]-y[2])*(y[3]-y[2]);
	if(a==b)return 1;
	return 0;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int t;
	cin>>t;
	int cas=0;
	while(t--){
		for(int i=1;i<=4;i++){
			cin>>x[i]>>y[i];
		}
		printf("Case #%d: ",++cas);
		if(judge_Parallelogram()){
			if(judge_Rectangle()&&judge_Diamond()){
				puts("Square");
			}
			else if(judge_Diamond()){
				puts("Diamond");
			}
			else if(judge_Rectangle()){
				puts("Rectangle");
			}
			else puts("Parallelogram");
		}
		else puts("Others");

	}
    return 0;
}
