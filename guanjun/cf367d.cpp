/* ***********************************************
Author        :guanjun
Created Time  :2016/8/12 10:36:45
File Name     :cf367d.cpp
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
struct node{
	int next[2];
	int v;
	void init(){
		v=0;
		memset(next,-1,sizeof next);
	}
};
node L[210000*32];
int tot=0;
void add(char s[],int len){
	int now=0;
	for(int i=0;i<len;i++){
		int t=s[i]-'0';
		int next=L[now].next[t];
		if(next==-1){
			next=++tot;
			L[next].init();
			L[now].next[t]=next;
		}
		now=next;
		L[now].v++;
	}
	//L[now].v++;
}

void dele(char s[],int len){
	int now=0;
    for(int i=0;i<len;i++){
        int t=s[i]-'0';
        int next=L[now].next[t];
        now=next;
        L[now].v--;
    }
//	L[now].v--;
    for(int i=0;i<2;i++)L[now].next[i]=-1;
}
int query(char s[],int len){
	int now=0;
	int ans=0;
	for(int i=0;i<len;i++){
		int t=s[i]-'0';
		int next=L[now].next[1-t];
		if(next==-1||L[next].v<=0){
			//这个点不存在或者已经删除了
			next=L[now].next[t];
		}
		else{
			ans+=pow(2.0,32-i-1);; 
		}
		now=next;
	}
	return ans;
}
void cha(int x,char *s){
	for(int i=0;i<=31;i++){
		s[i]=x%2+'0';
		x/=2;
	}
	s[32]='\0';
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    char s[32],c;
	int n,d;
	cin>>n;
	L[0].init();
	cha(0,s);
	add(s,32);
	for(int i=1;i<=n;i++){	
		cin>>c>>d;
		cha(d,s);
		reverse(s,s+32);
		if(c=='+'){
			add(s,32);
		}
		else if(c=='-'){
			dele(s,32);
		}
		else{
			printf("%d\n",query(s,32));
		}
	}
    return 0;
}
