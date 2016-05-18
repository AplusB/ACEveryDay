/* ***********************************************
Author        :guanjun
Created Time  :2016/5/14 16:17:31
File Name     :baidu1c.cpp
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
struct node
{
	int next[27];
	int v;
	void init(){
		v=0;
		memset(next,-1,sizeof(next));
	}
};
node L[1200500];
int tot=0;
void add(char s[],int len){
	int now=0;
	for(int i=0;i<len;i++){
		int t=s[i]-'a';
		int next=L[now].next[t];
		if(next==-1){
			next=++tot;
			L[next].init();
			L[now].next[t]=next;
		}
		now=next;
		L[now].v=1;
	}
}
int query(char s[],int len){
	int now=0;
	for(int i=0;i<len;i++){
		int t=s[i]-'a';
		int next=L[now].next[t];
		if(next==-1)return 0;
		now=next;
	}
	return L[now].v;
}
void _(char s[],int len,int cnt){
	int now=0;
	for(int i=0;i<len;i++){
		int t=s[i]-'a';
		int next=L[now].next[t];
		if(next==-1)return ;
		if(i==len-1)L[now].v=0;
		now=next;
		//L[now].v-=cnt;

	}
	//L[now].v=0;
	for(int i=0;i<26;i++)L[now].next[i]=-1;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int n;
	char t[100],s[100];
	while(cin>>n){
		L[0].init();
		for(int i=1;i<=n;i++){
			scanf("%s %s",s,t);
			int len=strlen(t);
			if(s[0]=='i')add(t,len);
			else if(s[0]=='s'){
				if(query(t,len)>0)puts("Yes");
				else puts("No");
			}
			else if(s[0]=='d'){
				int cnt=query(t,len);
				if(cnt) _(t,len,cnt);
			}
		}
	}
    return 0;
}
