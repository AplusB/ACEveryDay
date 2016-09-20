//UVALive 6837 - There is No Alternative
//#include <bits/stdc++.h>
//#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <time.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int mod=1e9+7;
const double eps=1e-8;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
const int MAXN=510;//最大点数
const int MAXM=50010;//最大边数
int F[MAXN];//并查集使用
struct Edge
{
    int u,v,w;
} edge[MAXM]; //存储边的信息，包括起点/终点/权值
int tol;//边数，加边前赋值为0
void addedge(int u,int v,int w)
{
    edge[tol].u=u;
    edge[tol].v=v;
    edge[tol++].w=w;
}
bool cmp(Edge a,Edge b)
{
    //排序函数，讲边按照权值从小到大排序
    return a.w<b.w;
}
int find(int x)
{
    if(F[x]==-1)return x;
    else return F[x]=find(F[x]);
}
int f[510];
int Kruskal(int n,int no)//传入点数，返回最小生成树的权值，如果不连通返回-1
{
    memset(F,-1,sizeof(F));
//    sort(edge,edge+tol,cmp);
    int cnt=0;//计算加入的边数
    int ans=0;
    for(int i=0; i<tol; i++)
    {
        if(i==no) continue;
        int u=edge[i].u;
        int v=edge[i].v;
        int w=edge[i].w;
        int t1=find(u);
        int t2=find(v);
        if(t1!=t2)
        {
            ans+=w;
            F[t1]=t2;
            if(no==-1) f[cnt]=i;
            cnt++;
        }
        if(cnt==n-1)break;
    }
    if(cnt<n-1)return -1;//不连通
    else return ans;
}
int main(){
    int n,m,u,v,w;
    while(cin>>n>>m){
        tol=0;
        for(int i=0;i<m;i++){
            cin>>u>>v>>w;
            addedge(u,v,w);
        }
        sort(edge,edge+tol,cmp);
        int ans=Kruskal(n,-1),res=0,sum=0;
        for(int i=0;i<n-1;i++){
            int x=Kruskal(n,f[i]);
//            cout<<x<<endl;
            if(x!=ans){
                res++;
                sum+=edge[f[i]].w;
            }
        }
        cout<<res<<" "<<sum<<endl;
    }
    return 0;
}
