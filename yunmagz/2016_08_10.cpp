//hdu5327 Olympiad
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
const int mod=1e7+7;
const double eps=1e-9;
const int inf=0x3f3f3f3f;
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int pre[100010],v[15];
int main(){
    for(int i=1;i<=100000;i++){
        memset(v,0,sizeof v);
        int j=i;
        int flag=1;
        while(j&&flag){
            v[j%10]++;
            if(v[j%10]>1) flag=0;
            j/=10;
        }
        pre[i]=pre[i-1]+flag;
    }
    int t,n,m;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        printf("%d\n",pre[m]-pre[n-1]);
    }
	return 0;
}
//5328 Problem Killer
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
const int mod=1e7+7;
const double eps=1e-9;
const int inf=0x3f3f3f3f;
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
double a[1000010];
int main(){
    int t,n,m;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        scanf("%lf",&a[0]);
        int ans=1,cnt1=1,cnt2=1,b;
        double q;
        for(int i=1;i<n;i++){
            scanf("%lf",&a[i]);
            if(i==1){
                b=a[i]-a[i-1];
                q=a[i]/a[i-1];
                cnt1=cnt2=2;
                ans=2;
            }
            else {
                if(a[i]-a[i-1]==b){
                    cnt1++;
                    ans=max(ans,cnt1);
                }
                else {
                    b=a[i]-a[i-1];
                    cnt1=2;
                }
                if(a[i]/a[i-1]==q){
                    cnt2++;
                    ans=max(ans,cnt2);
                }
                else {
                    q=a[i]/a[i-1];
                    cnt2=2;
                }
            }
        }
        printf("%d\n",ans);
    }
	return 0;
}
//5335 Walk Out
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define x first
#define y second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int mod=1e7+7;
const double eps=1e-9;
const int inf=0x3f3f3f3f;
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
int T, N, M;
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
int a[1010][1010], len[1010][1010];
bool vis[1010][1010], has[1010][1010], is[1010][1010];
char str[1010];
vector<PII> gao()
{
    vector<PII> point;
    if (a[1][1] == 0)
    {
        vis[1][1] = true;
        queue<PII> Q;
        Q.push(mp(1, 1));
        while (!Q.empty())
        {
            PII now = Q.front();
            Q.pop();
            for (int i = 0; i < 4; i ++)
            {
                PII next = now;
                next.x += dir[i][0];
                next.y += dir[i][1];
                if (next.x >= 1 && next.x <= N && next.y >= 1 && next.y <= M)
                {
                    if (!vis[next.x][next.y])
                    {
                        if (a[next.x][next.y])
                        {
                            if (!has[next.x][next.y])
                            {
                                has[next.x][next.y] = true;
                                point.push_back(next);
                            }
                        }
                        else
                        {
                            vis[next.x][next.y] = true;
                            Q.push(next);
                        }
                    }
                }
            }
        }
    }
    else
    {
        point.push_back(mp(1, 1));
    }
    return point;
}

int bfs1(vector<PII> &point)
{
    queue<PII> Q;
    Q.push(mp(N, M));
    len[N][M] = 1;
    vis[N][M] = true;
    while (!Q.empty())
    {
        PII now = Q.front();
        Q.pop();
        for (int i = 0; i < 4; i ++)
        {
            PII next = now;
            next.x += dir[i][0];
            next.y += dir[i][1];
            if (next.x >= 1 && next.x <= N && next.y >= 1 && next.y <= M)
            {
                if (!vis[next.x][next.y])
                {
                    len[next.x][next.y] = len[now.x][now.y] + 1;
                    vis[next.x][next.y] = true;
                    Q.push(next);
                }
            }
        }
    }
    int minlen = N * M + 1;
    for (int i = 0; i < point.size(); i ++)
    {
        minlen = min(minlen, len[point[i].x][point[i].y]);
    }
    return minlen;
}

void bfs(vector<PII> &point, int minlen)
{
    queue <PII> Q;
    for (int i = 0; i < point.size(); i ++)
    {
        if (len[point[i].x][point[i].y] == minlen)
        {
            Q.push(point[i]);
            is[point[i].x][point[i].y] = true;
        }
    }
    while (!Q.empty())
    {
        vector<PII> tmp;
        int c = 1;
        while (!Q.empty())
        {
            PII now = Q.front();
            c = min(a[now.x][now.y], c);
            Q.pop();
            tmp.push_back(now);
        }
        printf("%d", c);
        if (minlen == 1)
        {
            tmp.clear();
            break;
        }
        for (int i = 0; i < tmp.size(); i ++)
        {
            if (a[tmp[i].x][tmp[i].y] == c)
            {
                for (int j = 0; j < 4; j ++)
                {
                    PII next = tmp[i];
                    next.x += dir[j][0];
                    next.y += dir[j][1];
                    if (len[next.x][next.y] + 1 == len[tmp[i].x][tmp[i].y])
                    {
                        if (!is[next.x][next.y])
                        {
                            is[next.x][next.y] = true;
                            Q.push(next);
                        }
                    }
                }
            }
        }
        tmp.clear();
        minlen --;
    }
}

void work()
{
    memset(vis, 0, sizeof(vis));
    memset(has, 0, sizeof(has));
    memset(is, 0, sizeof(is));
    scanf("%d %d", &N, &M);
    for (int i = 0; i <= N + 1; i ++)
        fill(len[i], len[i] + 1010, inf);
    for (int i = 1; i <= N; i ++)
    {
        scanf("%s", str + 1);
        for (int j = 1; j <= M; j ++)
            a[i][j] = str[j] == '1' ? 1 : 0;
    }
    vector<PII>
    Point = gao();
    if (vis[N][M]) printf("0\n");
    else
    {
        int clen = bfs1(Point);
        bfs(Point, clen);
        printf("\n");
    }
}

int main()
{

    scanf("%d", &T);
    while (T --)
    {
        work();
    }
    return 0;
}
//hdu5336 XYZ and Drops
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define x first
#define y second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
const int mod=1e7+7;
const double eps=1e-9;
const int inf=0x3f3f3f3f;
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
struct node
{
    int x;
    int y;
    int dx;
    int dy;
    int st;
    void Node(int xx, int yy, int ddxx, int ddyy, int step)
    {
        x = xx;
        y = yy;
        dx = ddxx;
        dy = ddyy;
        st = step;
    }
};

int v[105][105], n, m, s;
int step[105][105];
int xx[105];
int yy[105];

void BFS(int sx, int sy)
{
    node a;
    queue<node> q;
    a.Node(sx, sy, 1, 0, 0);
    q.push(a);
    a.Node(sx, sy, 0, 1, 0);
    q.push(a);
    a.Node(sx, sy, 0, -1, 0);
    q.push(a);
    a.Node(sx, sy, -1, 0, 0);
    q.push(a);
    while (!q.empty())
    {
        node f = q.front();
        q.pop();
        if (f.st >= s)
            break;
        if (f.x <= 0 || f.y <= 0 || f.x>n || f.y>m)
            continue;
        f.x = f.x + f.dx;
        f.y = f.y + f.dy;
        f.st++;
        if (v[f.x][f.y]>4 && f.st == step[f.x][f.y])
            continue;
        if (v[f.x][f.y] == 0 || v[f.x][f.y]>4)
        {
            q.push(f);
            continue;
        }

        if (v[f.x][f.y] == 4)
        {
            v[f.x][f.y]++;
            step[f.x][f.y] = f.st;
            a.Node(f.x, f.y, 1, 0, f.st);
            q.push(a);
            a.Node(f.x, f.y, 0, 1, f.st);
            q.push(a);
            a.Node(f.x, f.y, 0, -1, f.st);
            q.push(a);
            a.Node(f.x, f.y, -1, 0, f.st);
            q.push(a);
        }
        else
            v[f.x][f.y]++;
    }
}

int main()
{
    int t, x, y, p, q;
    while (~scanf("%d%d%d%d", &n, &m, &q, &s))
    {
        memset(v, 0, sizeof(v));

        for (int i = 0; i<q; i++)
        {
            scanf("%d%d%d", &x, &y, &p);
            v[x][y] = p;
            xx[i] = x;
            yy[i] = y;
        }
        scanf("%d%d", &x, &y);
        if (v[x][y]>0)
        {
            v[x][y] = 5;
            step[x][y] = 0;
        }
        BFS(x, y);
        for (int i = 0; i<q; i++)
        {
            x = xx[i];
            y = yy[i];
            if (v[x][y] <= 4)
                printf("%d %d\n", 1, v[x][y]);
            else
                printf("%d %d\n", 0, step[x][y]);
        }
    }
    return 0;
}
