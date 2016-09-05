/* ***********************************************
Author        :guanjun
Created Time  :2016/9/4 19:25:30
File Name     :spoj_roads.cpp
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

int n,m,k;
struct Edge{
    int next,y,l,c;
}edge[maxn];
int pre[maxn],L;
void add(int u,int y,int l,int c){
    edge[L].y=y;
    edge[L].l=l;
    edge[L].c=c;
    edge[L].next=pre[u];
    pre[u]=L++;
}

struct node{
    int y,l,c;
};
struct cmp{
    bool operator()(node a,node b){
        if(a.l==b.l) return a.c>b.c;
        return a.l>b.l;
    }
};

int bfs(){
    priority_queue<node,vector<node>,cmp>q;
    q.push({1,0,0});
    while(!q.empty()){
        node u=q.top();q.pop();
        if(u.y==n){
            return u.l;
        }
        node tmp;
        //cout<<"y "<<u.y<<endl;
        for(int i=pre[u.y];i+1;i=edge[i].next){
            int y=edge[i].y;
            int c=edge[i].c;
            int l=edge[i].l;
            if(u.c+c<=k){
                tmp.y=y;
                tmp.l=u.l+l;
                tmp.c=u.c+c;
                q.push(tmp);
            }
        }
    }
    return INF;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    #endif
    //freopen("out.txt","w",stdout);
    int t,x,y,z,w;
    cin>>t;
    while(t--){
        cin>>k>>n>>m;
        L=0;
        memset(pre,-1,sizeof pre);
        for(int i=1;i<=m;i++){
            scanf("%d %d %d %d",&x,&y,&z,&w);
            add(x,y,z,w);
        }
        int w=bfs();
        if(w==INF){
            puts("-1");
        }
        else cout<<w<<endl;
    }
    return 0;
}
