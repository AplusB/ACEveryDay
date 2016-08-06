/* ***********************************************
Author        :guanjun
Created Time  :2016/8/6 15:51:30
File Name     :hdu1848.cpp
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
int sg[1100];
int f[20];
int Hash[1100];
void init(){
	f[1]=1;
	f[2]=2;
	for(int i=3;i<=16;i++)f[i]=f[i-1]+f[i-2];
	cle(sg);
	sg[1]=1;
	for(int i=2;i<=1010;i++){
		cle(Hash);
        for(int j=1;f[j]<=i;j++) //k是f[]的有效长度            
			Hash[sg[i-f[j]]]=1; 

        for(int j=0;j<=20; j++){   //求mes{}中未出现的最小的非负整数    
            if(Hash[j]==0){ 
				sg[i]=j;    
				break;  
			}
        }
	}
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int a,b,c;
	init();
	while(~scanf("%d%d%d", &a, &b, &c)){
		if(a==0&&b==0&&c==0)break;
		if((sg[a]^sg[b]^sg[c])==0){
			puts("Nacci");
		}
		else puts("Fibo");
	}
    return 0;
}
