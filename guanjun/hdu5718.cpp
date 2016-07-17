/* ***********************************************
Author        :guanjun
Created Time  :2016/7/17 18:53:46
File Name     :bc2nd_a.cpp
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

bool cmp(char a,char b){
    return a>b;
}
char s[10000010];
int a[10000010];
vector<int>v;
int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int t;

	cin>>t;
	while(t--){
		scanf("%s",s);
		v.clear();
		cle(a);
		int n=strlen(s);
		if(n==1)puts("Uncertain");
		else{
			sort(s,s+n);
			
				int num=0;
				int b,x;
				int mark=0;
				for(int i=0;i<n;i++){
					a[i]=s[i]-'0';
					if(a[i]>0)num++;
					if(a[i]>0&&!mark){
						b=a[i];mark=1;
						x=i;
					}
				}
				if(num==1){
					puts("Uncertain");continue;
				}
				//cout<<b<<endl;
				if(x!=0)a[0]+=b;
				else a[1]+=b;
				for(int i=0;i<n;i++){
					if(i==x)continue;
					if(a[i]>=10){
						a[i]=a[i]%10;
						if((i+1)!=x)a[i+1]++;
						else a[i+2]++;
					}
					v.push_back(a[i]);
				}
				if(a[n]!=0)v.push_back(a[n]);
				for(int i=v.size()-1;i>=0;i--){
					printf("%d",v[i]);
				}
				puts("");
			
		}
	}
    return 0;
}
