/* ***********************************************
Author        :guanjun
Created Time  :2016/5/26 22:17:48
File Name     :2222.cpp
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
#define ll long ling
#define mod 90001
#define INF 0x3f3f3f3f
#define maxn 250010
#define cle(a) memset(a,0,sizeof(a))
const ull inf = 1LL << 61;
const double eps=1e-5;
using namespace std;

struct ACauto{
    int ch[maxn][26];
    int sz;
    int f[maxn],last[maxn],val[maxn],cnt[maxn];
    void init(){
        sz=1;
        memset(ch[0],0,sizeof ch[0]);
        memset(cnt,0,sizeof cnt);
    }
    int idx(char c){
        return c-'a';
    }
    void add(char *s,int v){
        int u=0,len=strlen(s);
        for(int i=0;i<len;i++){
            int c=idx(s[i]);
            if(!ch[u][c]){
                memset(ch[sz],0,sizeof ch[sz]);
                val[sz]=0;
                ch[u][c]=sz++;
            }
            u=ch[u][c];
        }
        val[u]=v;
    }
    void getfail(){
        queue<int>q;
        f[0]=0;
        for(int c=0;c<26;c++){
            int u=ch[0][c];
            if(u){
                f[u]=0;
                q.push(u);
                last[u]=0;
            }
        }
        while(!q.empty()){
            int r=q.front();q.pop();
            for(int c=0;c<26;c++){
                int u=ch[r][c];
                if(!u){
                    ch[r][c]=ch[f[r]][c];
                    continue;
                }
                q.push(u);
                f[u]=ch[f[r]][c];
                last[u]=val[f[u]]?f[u]:last[f[u]];
            }
        }
    }
    void print(int j){
        if(j){
            cnt[val[j]]++;
            print(last[j]);
        }
    }
    void Find(char *T){
        int n=strlen(T);
        int j=0;
        for(int i=0;i<n;i++){
            int c=idx(T[i]);
            while(j&&!ch[j][c])j=f[j];
            j=ch[j][c];
            if(val[j])print(j);
            else if(last[j])print(last[j]);
        }
    }
}ac;
char s[10010][60],T[1000010];
int BKDRHash(char* s)
{
    long long seed=131;
    long long hash=0;
    while(*s=='0')s++;
    while(*s)
    {
        hash=hash*seed+(*s++);
    }
    return (hash & 0x7FFFFFFF);
}
map<int ,int>mp;
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int t,n;
	cin>>t;
	while(t--){
		ac.init();
		mp.clear();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%s",s[i]);
			ac.add(s[i],i);
			int x=BKDRHash(s[i]);
			mp[x]++;
		}
		ac.getfail();
		scanf("%s",T);
		ac.Find(T);
		int ans=0;
		for(int i=1;i<=n;i++){
			int x=ac.cnt[i];
			int y=BKDRHash(s[i]);
			if(x>0){
				ans+=mp[y];
			}
		}
		printf("%d\n",ans);
	}
    return 0;
}
