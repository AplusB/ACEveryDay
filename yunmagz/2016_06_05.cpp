//计蒜客初赛1B
#include <bits/stdc++.h>
using namespace std;
#define LL long long
vector<int>mp[505];
LL dist[505],f[505][55],a[505];
int lca(int x, int y)
{
	if(dist[x]<dist[y]) swap(x,y);
	for(int i=19;i>=0;i--)
        if((1<<i)&(dist[x]-dist[y]))
            x=f[x][i];
	if(x==y) return x;
	for(int i=50;i>=0;i--)
        if(f[x][i]!=f[y][i])
            x=f[x][i], y=f[y][i];
	return f[x][0];
}
void dijk()
{
    memset(dist,-1, sizeof(dist));
    dist[1]=0;
    f[1][0]=1;
    queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=1;i<20;i++)
            f[u][i]=f[f[u][i-1]][i-1];
        for(int i=0;i<mp[u].size();i++)
        {
            int v=mp[u][i];
            if(dist[v]!=-1)continue;
            dist[v]=dist[u]+1;
            f[v][0]=u;
            q.push(v);
        }
    }
}
int main()
{
	int n;
	cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        mp[x].push_back(y);
        mp[y].push_back(x);
    }
    dijk();
    LL ans=0;
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            if(__gcd(a[i], a[j])==1)
                ans+=dist[i]+dist[j]-2*dist[lca(i,j)];
    cout<<ans<<endl;
	return 0;
}
//计蒜客初赛2A
#include <bits/stdc++.h>
using namespace std;
const double pi=acos(-1.0);
int main()
{
    double l1,l2,j;
    cin>>l1>>l2>>j;
    j=fabs(j);
    j=j/180*pi;
    l1/=2;
    l2/=2;
    double ans=sqrt(l1*l1+l2*l2-2*l1*l2*cos(j));
    ans+=l1+l2;
    ans/=2;
    printf("%.8lf\n",ans*ans*pi);
    return 0;
}
//计蒜客初赛2B
    #include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define pdd pair<double,double>
#define mp make_pair
pdd a[2000];
set<pdd>s;
void solve(int i,int j){
    double x=a[i].first;
    double xx=a[j].first;
    double y=a[i].second;
    double yy=a[j].second;
    double dx=x-xx;
    double dy=y-yy;
    if(dx==0||dy==0) return ;
    s.insert(mp(dy/dx,(dx*yy-dy*xx)/dx));
}
int main()
{
    int t,n,m;
    cin>>t;
    while(t--){
        cin>>n>>m;
        s.clear();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                a[i*m+j]=mp(i,j);
        for(int i=0;i<n*m;i++)
            for(int j=0;j<n*m;j++){
                solve(i,j);
            }
        cout<<s.size()+n+m<<endl;
    }
    return 0;
}
