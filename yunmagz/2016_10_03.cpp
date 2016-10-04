//JAG Practice Contest for ACM-ICPC Asia Regional 2016
//A -	Best Matched Pair
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
LL a[1010];
bool ok(LL x){
    int p=x%10;
    x/=10;
    while(x){
        if(x%10!=p-1) return 0;
        p=x%10;
        x/=10;
    }
    return 1;
}
int main()
{
    int n;
    cin>>n;
    LL ans=-1;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(ok(a[i]*a[j])) ans=max(a[i]*a[j],ans);
        }
    }
    cout<<ans<<endl;
    return 0;
}
//B	- Help the Princess!
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PI;
typedef pair< PI, int> PII;
const double eps=1e-5;
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
#define Key_value ch[ch[root][1]][0]
const int MAXN = 100000+100;
const int MAXM = 10100;
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1

char mp[250][250];
int dir[][2]={1,0,-1,0,0,-1,0,1};
bool vis[250][250]{false};
int h,w;

struct pi
{
    int x,y,step;
    pi(){}
    pi(int a,int b,int c):x(a),y(b),step(c){}
}s,tmp,nex;
int gz=INF;
int sb=INF;

void bfs(int x,int y)
{
    queue<pi>q;
    s.step=0;
    s.x=x;
    s.y=y;
    q.push(s);
    vis[x][y]=1;
    while(!q.empty())
    {
        tmp=q.front();
        q.pop();
        for(int i=0;i<4;++i)
        {
            int xx=dir[i][0]+tmp.x;
            int yy=dir[i][1]+tmp.y;
            if(xx<0||xx>=h ||yy<0||yy>=w)
                continue;
            if(vis[xx][yy]|| mp[xx][yy]=='#')
                continue;
           // cout<<xx<<" "<<yy<<endl;
            if(mp[xx][yy]=='@')
            {
                vis[xx][yy]=1;
                gz=tmp.step;
                q.push(pi(xx,yy,tmp.step+1));
                continue;
            }
            if(mp[xx][yy]=='$')
            {
                vis[xx][yy]=1;
                sb=min(sb,tmp.step);
                q.push(pi(xx,yy,tmp.step+1));
                continue;
            }
            vis[xx][yy]=1;
            q.push(pi(xx,yy,tmp.step+1));
        }
    }

}


int main()
{

    cin>>h>>w;
    memset(vis,0,sizeof(vis));
    int sx,sy;
    for(int i=0;i<h;++i)
    {
        cin>>mp[i];
        for(int j=0;j<w;++j)
        {
            if(mp[i][j]=='%')
            {
                sx=i;
                sy=j;
            }
        }
    }

    bfs(sx,sy);
    if(gz<sb)
        puts("Yes");
    else
        puts("No");

    return 0;
}
//D	- Parentheses
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
LL a[50010];
int main()
{
    for(LL i=1;i<=50000;i++){
        a[i]=(i+1)*i/2;
    }
    int n;
    while(cin>>n){
        string ans="";
        LL l=lower_bound(a+1,a+50001,n)-a;
        for(int i=0;i<l;i++) ans.pb(')');
        for(int i=l;i<l*2;i++) ans.pb('(');
        LL r=(l+1)*l/2-n;
        ans[l]=')';
        ans[l-r]='(';
        cout<<ans<<endl;
    }
    return 0;
}
//E	 -Similarity of Subtrees
#pragma comment(linker, "/STACK:1024000000,1024000000")
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
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int mod=1e9+7;
const double eps=1e-8;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ULL pri;
map<ULL,int>p;
VI g[100010];
ULL dfs(int x){
    int m=SZ(g[x]);
    ULL ans=1;
    for(int i=0;i<m;i++){
        ans+=dfs(g[x][i])*pri;
    }
    p[ans]++;
    return ans;
}
int main()
{
    pri=mod;
    map<ULL,int>::iterator it;
    int n,u,v;
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>u>>v;
        g[u].pb(v);
    }
    dfs(1);
    LL ans=0;
    for(it=p.begin();it!=p.end();it++){
        LL a=(*it).se;
        ans+=a*(a-1)/2;
    }
    cout<<ans<<endl;
    return 0;
}


//Codeforces Round #375 (Div. 2)
//A - The New Year: Meeting Friends
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
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int mod=1e9+7;
const double eps=1e-8;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int mn=min(a,min(b,c));
    int mx=max(a,max(b,c));
    cout<<mx-mn<<endl;
    return 0;
}
//B - Text Document Analysis
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
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int mod=1e9+7;
const double eps=1e-8;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}

int main()
{
    int n;
    cin>>n;
    string s;
    cin>>s;
    int f=0,mx=0,ans=0,cnt=0;
    for(int i=0;i<n;i++){
        if(s[i]=='_'){
            if(cnt){
                if(f){
                    ans++;
                }
                else mx=max(mx,cnt);
            }
            cnt=0;
        }
        else if(s[i]=='('){
            if(cnt){
                mx=max(mx,cnt);
            }
            cnt=0;
            f=1;
        }
        else if(s[i]==')'){
            if(cnt){
                ans++;
            }
            cnt=0;
            f=0;
        }
        else cnt++;
    }
    if(cnt) mx=max(mx,cnt);
    cout<<mx<<" "<<ans<<endl;
    return 0;
}
//C - Polycarp at the Radio
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
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int mod=1e9+7;
const double eps=1e-8;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
//priority_queue<PII>q;
int a[2010],v[2010];
int vis[2010];
VI g;
int main()
{
    int n,m;
    cin>>n>>m;
    int mx=n/m;
    int x=n%m,cnt=0,ans=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]<=m){
            v[a[i]]++;
        }
    }
    for(int i=1;i<=m;i++)
        if(v[i]<mx){
            ans+=mx-v[i];
            for(int j=0;j<mx-v[i];j++) g.pb(i);
        }
    int yy=0;
    for(int i=0,j=0;i<n&&j<ans;i++){
        if(a[i]>m) a[i]=g[j++];
        else if(v[a[i]]>mx){
            if(yy>=x){
                v[a[i]]--;
                a[i]=g[j++];
            }
            else yy++;
        }
    }
    cout<<mx<<" "<<ans<<endl;
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    return 0;
}
//D - Lakes in Berland
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
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int mod=1e9+7;
const double eps=1e-8;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int f[4][2]={1,0,0,1,0,-1,-1,0};
char s[55][55];
int v[55][55],n,m,res;
struct node{
    int x,y;
};
struct oo{
    int x,y,num;
}o[5050];
bool cmp(oo a,oo b){
    return a.num<b.num;
}
int bfs(int x,int y){
    queue<node>q;
    while(!q.empty()) q.pop();
    node a,b;
    a.x=x;
    a.y=y;
    q.push(a);
    v[x][y]=1;
    int ans=1,ff=1;
    while(!q.empty()){
        a=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            b.x=a.x+f[i][0];
            b.y=a.y+f[i][1];
            if(b.x<0||b.x>=n||b.y<0||b.y>=m){
                ff=0;
            }
            if(!v[b.x][b.y]&& s[b.x][b.y]=='.'){
                v[b.x][b.y]=1;
                ans++;
                q.push(b);
            }
        }
    }
    return ans*ff;
}
void dfs(int x,int y){
    s[x][y]='*';
    res++;
    for(int i=0;i<4;i++){
        int xx=x+f[i][0];
        int yy=y+f[i][1];
        if(s[xx][yy]=='.') dfs(xx,yy);
    }
}
int main(){
    res=0;
    int k;
    cin>>n>>m>>k;
    for(int i=0;i<n;i++) cin>>s[i];
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(s[i][j]=='.'&& !v[i][j]){
                int kk=bfs(i,j);
                if(kk){
                    o[cnt].num=kk;
                    o[cnt].x=i;
                    o[cnt].y=j;
                    cnt++;
                }

            }
        }
    }
    sort(o,o+cnt,cmp);
    for(int i=0;i<cnt-k;i++) dfs(o[i].x,o[i].y);
    cout<<res<<endl;
    for(int i=0;i<n;i++) cout<<s[i]<<endl;
    return 0;
}
