/* ***********************************************
Author        :guanjun
Created Time  :2016/6/24 22:49:21
File Name     :1020.cpp
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
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int T,n;
	cin>>T;
	string s1,s2;
	for(int t=1;t<=T;t++){
		cin>>n>>s1;
		printf("Case %d: ",t);
		if(s1=="Alice"){
			if(n%3==1)puts("Bob");
			else puts("Alice");
		}
		else{
			if(n%3==0)puts("Alice");
			else puts("Bob");
		}
	}
    return 0;
}
