/* ***********************************************
Author        :guanjun
Created Time  :2016/8/16 16:50:30
File Name     :hdu4006.cpp
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
    bool operator()(int a,int b){
		return a>b;
	}
};

multiset<int>s;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
	int n,k,d;
	char c[3];
	while(scanf("%d%d",&n,&k)!=EOF){
		s.clear();
		for(int i=1;i<=n;i++){
			scanf("%s",c);
			if(c[0]=='I'){
				scanf("%d",&d);
				s.insert(d);
				while(s.size()>k){
					auto x=s.begin();
					s.erase(x);
				}
			}
			else{
				auto x=*s.begin();
				printf("%d\n",x);
			}
		}
	}
    return 0;
}
