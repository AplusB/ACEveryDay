//2016CCPC东北地区大学生程序设计竞赛 - 重现赛
//1001	Minimum’s Revenge
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<double,double> PDD;
const int mod=1e9+7;
const double eps=1e-8;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

int main()
{
    int t,cas=1;
    LL n;
    cin>>t;
    while(t--){
        cin>>n;
        printf("Case #%d: %lld\n",cas++,n*(n+1)/2-1);
    }
    return 0;
}
//1003	Mr. Frog’s Problem
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define vecotr vector
typedef vector<int> VI;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int mod=1e9+7;
const double eps=1e-8;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
const int MAXN = 200010;
const int M = MAXN * 100;

int main()
{
    int t;
    cin>>t;
    LL a,b;
    int casee=1;
    while(t--)
    {
        cin>>a>>b;
        printf("Case #%d:\n",casee++);
        if(a==b)
        {
            cout<<"1"<<endl;
            cout<<a<<" "<<b<<endl;
            continue;
        }
        else
        {
            cout<<"2"<<endl;
            cout<<a<<" "<<b<<endl;
            cout<<b<<" "<<a<<endl;
            continue;

        }

    }

    return 0;
}
//1005	Mr. Frog’s Game
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<double,double> PDD;
const int mod=1e9+7;
const double eps=1e-8;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int g[35][35];
int main()
{
    int t,cas=1;
    int n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>g[i][j];
            }
        }
        int f=0;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                if(g[i][0]==g[j][0]||g[i][m-1]==g[j][m-1]) f=1;
        for(int i=0;i<m;i++)
            for(int j=i+1;j<m;j++)
                if(g[0][i]==g[0][j]||g[n-1][i]==g[n-1][j]) f=1;
        for(int i=0;i<n;i++)
            for(int j=0;j<m-1;j++)
                if(g[i][j]==g[i][j+1]) f=1;
        for(int i=0;i<n-1;i++)
            for(int j=0;j<m;j++)
                if(g[i][j]==g[i+1][j]) f=1;
        if(f) printf("Case #%d: Yes\n",cas++);
        else printf("Case #%d: No\n",cas++);
    }
    return 0;
}
//1006	Auxiliary Set
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <queue>
#include <map>
#include <vector>
#include <string>
using namespace std;
const int maxn = 1e5 + 100;
int head[maxn*4];
vector<int>ga[maxn*4];
map<int,int>vis;
int cnt;
int cur[maxn*4];
int son[maxn*4];
int x[maxn*4];
void init()
{
    cnt=0;
    memset(head,-1,sizeof(head));
}
struct node
{
    int u,v;
    int next;
} edge[4*maxn];
void addage(int u,int v)
{
    edge[cnt].u=u;
    edge[cnt].v=v;
    edge[cnt].next=head[u];
    head[u]=cnt++;
}
void dfs(int u,int father)
{
    son[u]=0;
    cur[u]=father;
    for(int i=head[u]; ~i; i=edge[i].next)
    {
        int v=edge[i].v;
        if(v==father)
            continue;
        dfs(v,u);
        son[u]++;
    }
}
int solve(int u)
{
    int sz=0;
    int sc=0;
    for(int i=0; i<int(ga[u].size()); i++)
    {
        int v=ga[u][i];
        if(solve(v)>=2)
            sc++;
        sz++;
    }
    if(son[u]-sz+sc>=2)   //这个点的儿子个数减掉不重要的儿子个数大于等于2.显然可以
        return 3;
    if(son[u]-sz+sc>=1)   //这个点的儿子个数减掉不重要的儿子个数小于2，sc为这个点的不重要点的重要儿子个数。
        return 2;
    return 0;
}
int main()
{
    int t;
    scanf("%d",&t);
    int Case=0;
    while(t--)
    {
        int n,q;
        init();
        printf("Case #%d:\n",++Case);
        scanf("%d%d",&n,&q);
        for(int i=1; i<n; i++)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            addage(a,b);
            addage(b,a);
        }
        dfs(1,0);
        while(q--)
        {
            vis.clear();
            int m;
            scanf("%d",&m);
            int res=n-m;
            for(int i=1; i<=m; i++)
            {
                scanf("%d",&x[i]);
                ga[x[i]].clear();
                vis[x[i]]=-1;
            }
            for(int i=1; i<=m; i++)
            {
                if(vis[cur[x[i]]]==-1)
                    ga[cur[x[i]]].push_back(x[i]);
            }
            for(int i=1; i<=m; i++)
            {
                if(solve(x[i])==3)
                    res++;
            }
            printf("%d\n",res);
        }
    }
    return 0;
}
//1008	Basic Data Structure
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define vecotr vector
typedef vector<int> VI;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int mod=1e9+7;
const double eps=1e-8;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
deque<int>q;
const int MAXN = 200010;
int a[MAXN*2],p[MAXN*2];
int main()
{
    int t;
    scanf("%d",&t);
    int casee=1;
    int n,x;
    char op[10];
    while(t--) {
        int l=200005,r=200004,y;
        scanf("%d",&n);
        printf("Case #%d:\n",casee++);
        int f=0;// 0 左  1 右
        q.clear();
        for(int i=0; i<n; ++i) {
            scanf("%s",op);
            if(op[0]=='P' &&op[1]=='U') {
                scanf("%d",&x);
                if(l>r){
                    l=r=200005;
                    a[l]=x;
                    if(!x) q.push_front(l);
                }
                else {
                    if(!f){
                        l--;
                        a[l]=x;
                        if(!x) q.push_front(l);
                    }
                    else {
                        r++;
                        a[r]=x;
                        if(!x) q.push_back(r);
                    }
                }
            }
            else if(op[0]=='P'&&op[1]=='O') {
                if(!f){
                    if(!a[l]) q.pop_front();
                    l++;
                }
                else {
                    if(!a[r]) q.pop_back();
                    r--;
                }
            }
            else if(op[0]=='R') {
                f^=1;
            }
            else {
                if(l>r)
                {
                    printf("Invalid.\n");
                    continue;
                }
                if(q.empty()) printf("%d\n",(r-l+1)&1?1:0);
                else {
                    if(f){
                        y=q.front();
                        if(y==r) printf("%d\n",((y-l)%2==1)?1:0);
                        else printf("%d\n",((y-l)%2==1)?0:1);
                    }
                    else{
                        y=q.back();
                        if(y==l) printf("%d\n",((r-y)%2==1)?1:0);
                        else printf("%d\n",((r-y)%2==1)?0:1);
                    }
                }
            }

        }
    }
    return 0;
}
