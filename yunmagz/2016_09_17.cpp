//2016 ACM/ICPC Asia Regional Qingdao Online
//1001	I Count Two Three
#include <bits/stdc++.h>
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


LL a2[55],a3[55],a5[55],a7[55];
int ans[60010];
int main(){
    int t,n;
    a2[0]=a3[0]=a5[0]=a7[0]=1;
    for(int i=1;i<=30;i++)
        a2[i]=a2[i-1]*2;
    for(int i=1;i<=20;i++)
        a3[i]=a3[i-1]*3;
    for(int i=1;i<=15;i++)
        a5[i]=a5[i-1]*5;
    for(int i=1;i<=11;i++)
        a7[i]=a7[i-1]*7;
    int cnt=0;
    for(int i=0;i<=29;i++){
        if(a2[i]>1000000000) continue;
        for(int j=0;j<=18;j++){
            if(a2[i]*a3[j]>1000000000) continue;
            for(int k=0;k<=12;k++){
                if(a2[i]*a3[j]*a5[k]>1000000000) continue;
                for(int l=0;l<=10;l++){
                    if(a2[i]*a3[j]*a5[k]*a7[l]<=1000000000){
                        ans[cnt++]=a2[i]*a3[j]*a5[k]*a7[l];
                    }
                }
            }
        }
    }
    sort(ans,ans+cnt);
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int x=lower_bound(ans,ans+cnt,n)-ans;
        printf("%d\n",ans[x]);
    }
    return 0;
}
//1002	Cure
#include <bits/stdc++.h>
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
double PI=acos(-1.0);
double sum[1000010];
int main()
{
    sum[0]=0;
    for(int i=1; i<=1000000; i++)
        sum[i]=sum[i-1]+1.0/i/i;
    string s;
    while(cin>>s)
    {
        int n=0;
        int l=SZ(s);
        if(l<=6){
            for(int i=0;i<l;i++)
                n=n*10+s[i]-'0';
            printf("%.5lf\n",sum[n]);
        }
        else
            printf("%.5lf\n",(PI*PI)/6.0);
    }
    return 0;
}
//1004	Tea
#include <bits/stdc++.h>
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


int main()
{
    LL l,r;
    while (~scanf("%lld%lld", &l, &r))
    {
        if(l==r && l==0)
        {
            cout<<"0"<<endl;
            continue;
        }
        if(l==r && l==1)
        {
            cout<<"0"<<endl;
            continue;
        }
        if(l==0 && r==1)
        {
            cout<<"0"<<endl;
            continue;
        }
        if(l==1 && r==2)
        {
            cout<<"1"<<endl;
            continue;
        }
        if(l==0 && r==2)
        {
            cout<<"1"<<endl;
            continue;
        }
        
        if(l==r  && l==2)
        {
            cout<<"1"<<endl;
        }
        else
        {
           cout<<max((r-max(l,1LL))/2+1,(LL)2)<<endl;
        }
    }

    return 0;
}
//1005	Balanced Game
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define showtime fprintf(stderr,"time = %.15f\n",clock() / (double)CLOCKS_PER_SEC)
#define lld %I64d
#define REP(i,k,n) for(int i=k;i<n;i++)
#define REPP(i,k,n) for(int i=k;i<=n;i++)
#define scan(d) scanf("%d",&d)
#define scanl(d) scanf("%I64d",&d)
#define scann(n,m) scanf("%d%d",&n,&m)
#define scannl(n,m) scanf("%I64d%I64d",&n,&m)
#define mst(a,k)  memset(a,k,sizeof(a))
#define LL long long
#define N 1005
inline int read()
{
    int s=0;
    char ch=getchar();
    for(; ch<'0'||ch>'9'; ch=getchar());
    for(; ch>='0'&&ch<='9'; ch=getchar())s=s*10+ch-'0';
    return s;
}
int ans,res;
char str[1000500];
const int mod=1e9+7;
int main()
{
    int n;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a;
        cin>>a;
        if(a%2==0)
            cout<<"Bad"<<endl;
        else
            cout<<"Balanced"<<endl;
    }
    return 0;
}
//1006	The Best Path
#include <bits/stdc++.h>
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
int a[100010],d[100010];
#define MAX_SIZE 100005
int pa[MAX_SIZE];        //存储有向图的边
void init(int n)
{
    for(int i=0;i<=n;i++)
        pa[i]=i;
}
int findset(int v)      //找元素所在集合的代表元(因为用了路径压缩，路径压缩的主要目的是为了尽快的确定元素所在的集合）
{
    int t1,t2=v;
    while(v!=pa[v])
        v=pa[v];
    while(t2!=pa[t2])        //这里优化的思路还是路径压缩（进一步的在查找函数执行的过程中压缩路径），很神奇!
    {
        t1=pa[t2];
        pa[t2]=v;
        t2=t1;
    }
    return v;
}

void union_nodes(int a, int b)      //集合合并
{
    int a1 = findset(a);
    int b1 = findset(b);
    if(a1 != b1)        //这个判定条件可选，主要是为了防止findset路径压缩的时候出现死循环
    {
        pa[a1] = b1;        //如果存的是有向图，并且做题时集合中元素的顺序很重要，不能忽略，那么这里应该用"pa[a] = b;"
    }
}
int vis[100010];
int main(){
    int t,n,m;
    scanf("%d",&t);
    while(t--){
        memset(d,0,sizeof d);
        memset(vis,0,sizeof vis);
        scanf("%d%d",&n,&m);
        init(n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        while(m--){
            int u,v;
            scanf("%d%d",&u,&v);
            union_nodes(u,v);
            d[u]++;
            d[v]++;
            vis[u]=vis[v]=1;
        }

        int cnt=0,flag=-1;
        int res=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]) continue;
            int gg=findset(i);
            if(flag==-1) flag=gg;
            else if(flag!=gg){
                res=-1;
                break;
            }
            if(d[i]%2){
                cnt++;
            }
            if((d[i]+1)/2%2) res^=a[i];
            if(cnt>2){
                res=-1;
                break;
            }
        }
        if(res!=-1&&cnt!=1){
            if(cnt==0){
                int mx=0;
                for(int i=1;i<=n;i++){
                    if(vis[i]) mx=max(mx,res^a[i]);
                }
                printf("%d\n",mx);
            }
            else printf("%d\n",res);
        }
        else puts("Impossible");
    }
    return 0;
}
//1007	Sort
#include <bits/stdc++.h>
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
template <class T> inline bool scan_d(T &ret)
{
    char c;
    int sgn;
    if(c=getchar(),c==EOF) return 0; //EOF
    while(c!='-'&&(c<'0'||c>'9')) c=getchar();
    sgn=(c=='-')?-1:1;
    ret=(c=='-')?0:(c-'0');
    while(c=getchar(),c>='0'&&c<='9') ret=ret*10+(c-'0');
    ret*=sgn;
    return 1;
}
int T, n, c;
LL a[100005];
bool jg(int k)
{
    int i = 0;
    LL cost = 0, cur = 0;
    queue<LL> q;
    while (a[i] == 0 && i < n) i++;
    if (i > 0) i--;
    int tn = (n - i - 1) % (k - 1);
    if (tn)
    {
        tn++;
        while (tn--) cur += a[i++];
        cost += cur;
        q.push(cur);
    }

    while (i < n || q.size() > 1)
    {
        cur = 0;
        for (int j = 0; j < k; ++j)
        {
            if (i == n && q.empty()) break;
            if (i == n)
            {
                cur += q.front();
                q.pop();
            }
            else if (q.empty()) cur += a[i++];
            else if (a[i] < q.front()) cur += a[i++];
            else
            {
                cur += q.front();
                q.pop();
            }
        }
        cost += cur;
        q.push(cur);
    }
    return cost <= c;
}
void init()
{
    scan_d(n),scan_d(c);
    for (int i = 0; i < n; i++)
        scan_d(a[i]);
}
void solve()
{
    sort(a,a+n);
    int l = 2, r = n;
    while(l<r)
    {
        int mid=(l+r)>>1;
        if (jg(mid)) r=mid;
        else l = mid + 1;
    }
    printf("%d\n",l);
}
int main()
{
    scan_d(T);
    while (T--)
    {
        init();
        solve();
    }
    return 0;
}
//1011	Barricade
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stdio.h>
#define oo 1<<29
#define MAXN 10005
#define MAXM 221005
using namespace std;
struct Dinic
{
    struct node
    {
        int c,u,v,next;
    } edge[MAXM];
    int ne,head[MAXN];
    int cur[MAXN], ps[MAXN], dep[MAXN];
    void initial()
    {
        ne=2;
        memset(head,0,sizeof(head));
    }
    void addedge(int u, int v,int c)
    {
        edge[ne].u=u,edge[ne].v=v,edge[ne].c=c,edge[ne].next=head[u];
        head[u]=ne++;
        edge[ne].u=v,edge[ne].v=u,edge[ne].c=0,edge[ne].next=head[v];
        head[v]=ne++;
    }
    int MaxFlow(int s,int t)
    {
        int tr, res = 0;
        int i,j,k,f,r,top;
        while(1)
        {
            memset(dep, -1, sizeof(dep));
            for(f=dep[ps[0]=s]=0,r=1; f!= r;)
                for(i=ps[f++],j=head[i]; j; j=edge[j].next)
                    if(edge[j].c&&dep[k=edge[j].v]==-1)
                    {
                        dep[k]=dep[i]+1;
                        ps[r++]=k;
                        if(k == t)
                        {
                            f=r;
                            break;
                        }
                    }
            if(dep[t]==-1) break;
            memcpy(cur,head,sizeof(cur));
            i=s,top=0;
            while(1)
            {
                if(i==t)
                {
                    for(tr=oo,k=0; k<top; k++)
                        if(edge[ps[k]].c<tr)
                            tr=edge[ps[f=k]].c;
                    for(k=0; k<top; k++)
                    {
                        edge[ps[k]].c-=tr;
                        edge[ps[k]^1].c+=tr;
                    }
                    i=edge[ps[top=f]].u;
                    res+= tr;
                }
                for(j=cur[i]; cur[i]; j=cur[i]=edge[cur[i]].next)
                    if(edge[j].c && dep[i]+1==dep[edge[j].v]) break;
                if(cur[i])  ps[top++]=cur[i],i=edge[cur[i]].v;
                else
                {
                    if(!top) break;
                    dep[i]=-1;
                    i=edge[ps[--top]].u;
                }
            }
        }
        return res;
    }
} T;
struct node
{
    int u,v,d,c,next;
} edge[MAXM];
int _next[MAXN],En,dis[2][MAXN];
queue<int> Q;
bool inQ[MAXN];
void addedge(int u,int v,int d,int c)
{
    edge[++En].next=_next[u],_next[u]=En;
    edge[En].u=u,edge[En].v=v,edge[En].d=d,edge[En].c=c;
}
void SPFA(int n,int s,int tp)
{
    int k,u,v;
    memset(inQ,false,sizeof(inQ));
    memset(dis[tp],0x7f,sizeof(dis[tp]));
    Q.push(s),dis[tp][s]=0;
    while (Q.size())
    {
        u=Q.front();
        Q.pop(),inQ[u]=false;
        for (k=_next[u]; k; k=edge[k].next)
        {
            v=edge[k].v;
            if (dis[tp][v]<=dis[tp][u]+edge[k].d) continue;
            dis[tp][v]=dis[tp][u]+edge[k].d;
            if (!inQ[v])
                Q.push(v),inQ[v]=true;
        }
    }
}
int main()
{
    int n,m,s,t,v,u,d,c,i,cases=0,MinDis;
    int asd;
    scanf("%d",&asd);
    while(asd--)
    {
    scanf("%d%d",&n,&m);
    //    printf("(m-n)/2+1")
        s=1;
        t=n;
        memset(_next,0,sizeof(_next)),En=0;
        while (m--)
        {
            scanf("%d%d%d",&u,&v,&c);
            addedge(u,v,1,c);
            addedge(v,u,1,c);
        }
        SPFA(n,s,0);
        SPFA(n,t,1);
        MinDis=dis[0][t];
        T.initial();
        for (i=1; i<=En; i++)
            if (dis[0][edge[i].u]+dis[1][edge[i].v]+edge[i].d==MinDis)
                T.addedge(edge[i].u,edge[i].v,edge[i].c);
        printf("%d\n",T.MaxFlow(s,t));
    }
    return 0;
}
