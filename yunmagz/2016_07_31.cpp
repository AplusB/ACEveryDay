//hdu5023 A Corrupt Mayor's Performance Art
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
const LL mod=1e9+7;
const double eps=1e-9;
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
#define lson l , mid , rt << 1
#define rson mid + 1 , r , rt << 1 | 1
const int maxn = 1100017;
LL add[maxn<<2];
LL sum[maxn<<2];
void PushUp(int rt)
{
    sum[rt] = sum[rt<<1] | sum[rt<<1|1];
}
void PushDown(int rt,int m)
{
    if(add[rt])
    {
        add[rt<<1] = add[rt];
        add[rt<<1|1] = add[rt];
        sum[rt<<1] = add[rt] ;
        sum[rt<<1|1] = add[rt] ;
        add[rt] = 0;
    }
}
void build(int l,int r,int rt)
{
    add[rt] = 0;
    if (l == r)
    {
        sum[rt]=2;
        return ;
    }
    int mid = (l + r) >> 1;
    build(lson);
    build(rson);
    PushUp(rt);
}
void update(int L,int R,int c,int l,int r,int rt)
{
    if (L <= l && r <= R)
    {
        add[rt] =1<<(c-1);
        sum[rt] =1<<(c-1);
        return ;
    }
    PushDown(rt , r - l + 1);
    int mid = (l + r) >> 1;
    if (L <= mid)
        update(L , R , c , lson);
    if (mid < R)
        update(L , R , c , rson);
    PushUp(rt);
}
LL query(int L,int R,int l,int r,int rt)
{
    if (L <= l && r <= R)
    {
        return sum[rt];
    }
    PushDown(rt , r - l + 1);
    int mid = (l + r) >> 1;
    LL ret = 0;
    if (L <= mid)
        ret |= query(L , R , lson);
    if (mid < R)
        ret |= query(L , R , rson);
    return ret;
}
int main()
{
    int N , Q;
    int a , b , c;
    while(scanf("%d%d",&N,&Q))
    {
        if(N==0 && Q==0)
            break;
        build(1 , N , 1);
        while(Q--)
        {
            char op[2];
            scanf("%s",op);
            if(op[0] == 'Q')
            {
                scanf("%d%d",&a,&b);
                LL tt=query(a , b , 1 , N , 1);
                LL flag = 0;
                for(int i=1; i<=30; i++)
                {
                    if(tt>>(i-1)&1 && flag==0)
                    {
                        printf("%d",i);
                        flag = 1;
                    }
                    else if(tt>>(i-1)&1)
                        printf(" %d",i);
                }
                printf("\n");
            }
            else
            {
                scanf("%d%d%d",&a,&b,&c);
                update(a , b , c , 1 , N , 1);
            }
        }
    }
    return 0;
}
//hdu5024 Wang Xifeng's Little Plot 
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
const LL mod=1e9+7;
const double eps=1e-9;
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
const int N = 105;
char g[N][N];
int n;
int dir[8][2] = {{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1},{1,0},{1,1},{0,1}};
int dp[N][N][8];

int main() {
	while(scanf("%d",&n) && n) {
		memset(dp, 0, sizeof(dp));
		for(int i = 1; i <= n; i++) {
			getchar();
			for(int j = 1; j <= n; j++) {
				scanf("%c",&g[i][j]);
				if(g[i][j] == '.') {
					for(int k = 0; k < 8; k++) {
						dp[i][j][k] = 1;
					}
				}
			}
		}
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				if(g[i][j] == '#')
					continue;
				for(int k = 0; k < 4; k++) {
					int x = i + dir[k][0];
					int y = j + dir[k][1];
					if(x > 0 && y > 0 && x <= n && y <= n && g[x][y] != '#') {
						dp[i][j][k] += dp[x][y][k];
					}
				}
			}
		}
		for(int i = n; i >= 1; i--) {
			for(int j = n; j >= 1; j--) {
				if(g[i][j] == '#')
					continue;
				for(int k = 4; k < 8; k++) {
					int x = i + dir[k][0];
					int y = j + dir[k][1];
					if(x > 0 && y > 0 && x <= n && y <= n && g[x][y] != '#') {
						dp[i][j][k] += dp[x][y][k];
					}
				}
			}
		}
		int m = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				for(int k = 0; k < 8; k++) {
					if(dp[i][j][k] + dp[i][j][(k + 2)%8] > m)
						m = dp[i][j][k] + dp[i][j][(k + 2)%8];
				}
			}
		}
		printf("%d\n",m - 1);
	}
}
//hdu5025 Saving Tang Monk
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
const LL mod=1e9+7;
const double eps=1e-9;
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
struct node
{
    int x,y,step,key;
    int kill;
}a,b;
int d[110][110][10][50],n,m,Min,flag;
char g[110][110];
int dir[4][2]={0,1,0,-1,1,0,-1,0};
int bfs(int sx,int sy)
{
    a.x=sx;
    a.y=sy;
    a.step=0;
    a.key=0;
    a.kill=0;
    memset(d,127,sizeof(d));
    d[a.x][a.y][a.key][a.kill]=0;
    queue<node>q;
    q.push(a);
    while(!q.empty())
    {
        b=q.front();
        q.pop();
        if(g[b.x][b.y]=='T'&&b.key==m)
        {
            if(b.step<Min)
            Min=b.step;
            flag=1;
            continue;
        }
        for(int i=0;i<4;i++)
        {
            a.x=b.x+dir[i][0];
            a.y=b.y+dir[i][1];
            a.step=b.step+1;
            a.key=b.key;
            a.kill=b.kill;
            if(a.x<0||a.x>=n||a.y<0||a.y>=n) continue;
            if(g[a.x][a.y]=='#') continue;
            if(g[a.x][a.y]>='a'&&g[a.x][a.y]<='z')
            {
                int t=g[a.x][a.y]-'a';
                if((a.kill&(1<<t))==0)
                {
                    a.kill=a.kill|(1<<t);
                    a.step++;
                }
            }
            else if(g[a.x][a.y]>='1'&&g[a.x][a.y]<='9'){
                int x=g[a.x][a.y]-'0';
                if(a.key==x-1)
                a.key=x;
            }
            if(a.step<d[a.x][a.y][a.key][a.kill]){
                d[a.x][a.y][a.key][a.kill]=a.step;
                q.push(a);
            }
        }
    }
    return 0;
}
int main()
{
    int i,j;
    while(~scanf("%d%d",&n,&m),n+m)
    {
        for(i=0;i<n;i++)
        scanf("%s",g[i]);
        char t='a';
        int sx,sy,ex,ey;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(g[i][j]=='K'){
                    sx=i;
                    sy=j;
                }
                else if(g[i][j]=='S')
                {
                    g[i][j]=t++;
                }
                else if(g[i][j]=='T')
                {
                    ex=i;
                    ey=j;
                }
            }
        }
        Min=INT_MAX;
        flag=0;
        bfs(sx,sy);
        if(!flag) printf("impossible\n");
        else printf("%d\n",Min);
    }
    return 0;
}
