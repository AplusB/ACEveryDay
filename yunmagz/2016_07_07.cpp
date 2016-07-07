//CF#361 (Div. 2)
//A - Mike and Cellphone
#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int tx[10]={3,0,0,0,1,1,1,2,2,2};
const int ty[10]={1,0,1,2,0,1,2,0,1,2};
const int d[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
char s[15];
int x[15],y[15],nx[15],ny[15];
bool check(int n,int k)
{
    for(int i=0;i<n;i++)
    {
        nx[i]=x[i]+d[k][0];
        ny[i]=y[i]+d[k][1];
    }
    for(int i=0;i<n;i++)
    {
        if(nx[i]==3)
        {
            if(ny[i]!=1)return 0;
        }
        else if(nx[i]>=0 && nx[i]<=2)
        {
            if(ny[i]<0 || ny[i]>=3)return 0;
        }
        else return 0;
    }
    return 1;
}
int main()
{
    int n;
    scanf("%d",&n);
    scanf("%s",s);
    for(int i=0;i<n;i++)
    {
        x[i]=tx[s[i]-'0'];
        y[i]=ty[s[i]-'0'];
    }
    for(int i=0;i<4;i++)
        if(check(n,i))return 0*printf("NO\n");
    return 0*printf("YES\n");
}
//B - Mike and Shortcuts
#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int MAXN=300010;
const int INF=0x3f3f3f3f;
int a[MAXN];
struct Edge
{
    int v;
    int cost;
    Edge(int _v=0,int _cost=0):v(_v),cost(_cost) {}
};
vector<Edge>E[MAXN];
void addedge(int u,int v,int w)
{
    E[u].push_back(Edge(v,w));
}
bool vis[MAXN];//在队列标志
int cnt[MAXN];//每个点的入队列次数
int dist[MAXN];
bool SPFA(int start,int n)
{
    memset(vis,false,sizeof(vis));
    for(int i=1; i<=n; i++)dist[i]=INF;
    vis[start]=true;
    dist[start]=0;
    queue<int>que;
    while(!que.empty())que.pop();
    que.push(start);
    memset(cnt,0,sizeof(cnt));
    cnt[start]=1;
    while(!que.empty())
    {
        int u=que.front();
        que.pop();
        vis[u]=false;
        for(int i=0; i<E[u].size(); i++)
        {
            int v=E[u][i].v;
            if(dist[v]>dist[u]+E[u][i].cost)
            {
                dist[v]=dist[u]+E[u][i].cost;
                if(!vis[v])
                {
                    vis[v]=true;
                    que.push(v);
                    if(++cnt[v]>n)return false;
                }
            }
        }
    }
    return true;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        addedge(i,a[i],1);
        if(i!=n) addedge(i,i+1,1);
        if(i!=1) addedge(i,i-1,1);
    }
    SPFA(1,n);
    for(int i=1; i<=n; i++) cout<<dist[i]<<" ";
    return 0;
}
//C - Mike and Chocolate Thieves
#include <bits/stdc++.h>
using namespace std;
#define LL long long
LL n;
LL solve(LL x){
    LL ans=0;
    for(LL i=2;i*i*i<=x;i++){
        ans+=x/(i*i*i);
    }
    return ans;
}
LL ddd(){
    LL l=1,r=1ULL<<63-1;
	while(l<r){
        LL mid=(l+r)>>1;
        if(solve(mid)>=n) r=mid;
        else l=mid+1;
	}
	if(solve(l)!=n) return -1;
    return l;
}
int main() {
	cin>>n;
	cout<<ddd()<<endl;
	return 0;
}
