/* ***********************************************
Author        :guanjun
Created Time  :2016/8/25 11:55:52
File Name     :hiho_offer6a.cpp
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
int vis[30];
int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    string s;
	cin>>s;
	cle(vis);
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]=='J'){
			s[i]='I';
		}
	}
	vector<char>v;
	for(int i=0;i<n;i++){
		if(!vis[s[i]-'A']){
			v.push_back(s[i]);
			vis[s[i]-'A']=1;
		}
	}
	vis['J'-'A']=1;
	for(int i=0;i<26;i++){
		if(!vis[i]){
			vis[i]=1;
			v.push_back('A'+i);
		}
	}
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cout<<v[i*5+j];
		}
		cout<<endl;
	}
    return 0;
}
