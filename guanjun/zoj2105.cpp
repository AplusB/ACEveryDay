/* ***********************************************
Author        :guanjun
Created Time  :2016/6/3 22:21:50
File Name     :zoj2105.cpp
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
#define mod 7
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
struct node{
	int m[2][2];
};
node mul(node a,node b){
	node t;
	memset(t.m,0,sizeof t.m);
	for(int i=0;i<2;i++){
		for(int k=0;k<2;k++){
			if(a.m[i][k]){
				for(int j=0;j<2;j++){
					t.m[i][j]+=a.m[i][k]*b.m[k][j];
					t.m[i][j]%=mod;
				}
			}
		}
	}
	return t;
}
node expo(node p,int k){
	if(k==1)return p;
	node e;
	memset(e.m,0,sizeof e.m);
	for(int i=0;i<2;i++)e.m[i][i]=1;
	if(k==0)return e;
	while(k){
		if(k&1)e=mul(p,e);
		p=mul(p,p);
		k>>=1;
	}
	return e;
}
int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int a,b,y;
	while(cin>>a>>b>>y&&(a||b||y)){
		if(y<3){
			cout<<1<<endl;
			continue;
		}
		else{
			node x,ans;
			x.m[0][0]=a;
			x.m[0][1]=b;
			x.m[1][0]=1;
			x.m[1][1]=0;
			ans=expo(x,y-2);
			cout<<(ans.m[0][0]+ans.m[0][1])%mod<<endl;
		}
	}
    return 0;
}
