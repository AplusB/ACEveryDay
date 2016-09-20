//Codeforces Round #368 (Div. 2)
//D - Persistent Bookcase
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
const int mod=772002;
const double eps=1e-8;
const int inf=0x3f3f3f3f;
const double pi=acos(-1.0);
//LL powmod(LL a,LL b) {LL res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
struct Node
{
    int opt,i,j,next,id;
};

struct Edge
{
    int v,next;
};

Node nd[111111];
Edge eg[111111];
int ans[111111];
int mat[1111][1111];
int sum = 0;
int tp,etp,now;

int NewNode(int id = -1,int opt = -1,int i = -1,int j = -1)
{
    nd[tp].id = id;
    nd[tp].opt = opt;
    nd[tp].i = i;
    nd[tp].j = j;
    nd[tp].next = -1;
    return tp++;
}

void Add(int pos)
{
    eg[etp].v = pos;
    eg[etp].next = nd[now].next;
    nd[now].next = etp++;
    now = pos;
}

int m;
void dfs(int u)
{
    int x,y;
    bool f = 0;
    if(u != 0)
    {
        x = nd[u].i;
        y = nd[u].j;
        if(nd[u].opt == 1)
        {
            if(!mat[x][y])
            {
                f = 1;
                sum++;
                mat[x][y] = 1;
            }
        }
        else if(nd[u].opt == 2)
        {
            if(mat[x][y])
            {
                f = 1;
                sum--;
                mat[x][y] = 0;
            }
        }
        else if(nd[u].opt == 3)
        {
            for(int i = 1; i <= m; ++i)
            {
                if(mat[x][i])
                {
                    mat[x][i] = 0;
                    sum--;
                }
                else
                {
                    mat[x][i] = 1;
                    sum++;
                }
            }
        }
    }

    ans[nd[u].id] = sum;

    for(int i = nd[u].next; i != -1; i = eg[i].next)
    {
        dfs(eg[i].v);
    }

    if(u != 0)
    {
        if(nd[u].opt == 1)
        {
            if(f)
            {
                sum--;
                mat[x][y] = 0;
            }
        }
        else if(nd[u].opt == 2)
        {
            if(f)
            {
                sum++;
                mat[x][y] = 1;
            }
        }
        else if(nd[u].opt == 3)
        {
            for(int i = 1; i <= m; ++i)
            {
                if(mat[x][i])
                {
                    mat[x][i] = 0;
                    sum--;
                }
                else
                {
                    mat[x][i] = 1;
                    sum++;
                }
            }
        }
    }
}

int main()
{
    int n,q,opt,x,y;

    scanf("%d%d%d",&n,&m,&q);

    tp = 0;
    int root = NewNode(0);
    etp = 0;
    now = 0;

    for(int i = 1; i <= q; ++i)
    {
        scanf("%d",&opt);
        if(opt <= 2)
        {
            scanf("%d%d",&x,&y);
            Add(NewNode(i,opt,x,y));
        }
        else if(opt == 3)
        {
            scanf("%d",&x);
            Add(NewNode(i,opt,x));
        }
        else
        {
            scanf("%d",&x);
            now = x;
            Add(NewNode(i,opt));
        }
    }

    memset(mat,0,sizeof(mat));
    dfs(0);

    for(int i = 1; i <= q; ++i)
    {
        printf("%d\n",ans[i]);
    }

    return 0;
}
