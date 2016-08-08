/* ***********************************************
Author        :guanjun
Created Time  :2016/8/8 14:04:46
File Name     :cf364c.cpp
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
map<char,int>mp;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int n,tot;
	string s;
	while(cin>>n){
		cin>>s;
		tot=0;
		mp.clear();
		for(int i=0;i<n;i++){
			if(!mp[s[i]])mp[s[i]]++,tot++;
		}
		mp.clear();
		int r=0,l=0;
		int ans=n,num=0;
		for(int l=0;l<n;l++){
			while(r<n&&num<tot){
				if(!mp[s[r++]]++)num++;
			}
			if(num<tot)break;
			ans=min(ans,r-l);
			if(--mp[s[l]]==0)num--;
		}
		cout<<ans<<endl;
	}
    return 0;
}
