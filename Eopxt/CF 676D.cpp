#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
#define sqr(x) ((x)*(x))
#define mem(a,x) memset(a,x,sizeof(a))
#define REP(i,n) for (int i=0; i<(n); i++)
#define rep(i,n) for (int i=1; i<=(n); i++)
#define For(i,s,t) for (int i=(s); i<=(t); i++)
#define FOR(i,s,t) for (int i=(s); i>=(t); i--)
#define foreach(j,x) for (int j=adj[x]; j>=0; j=E[j].nxt)
#define Foreach(it,v) for (__typeof((v).begin()) it=(v).begin(); it!=(v).end(); it++)
typedef long long lld;
typedef pair<int,int> pii;
typedef set<int>::iterator setIter;

pii U=mp(-1,0),D=mp(1,0),L=mp(0,-1),R=mp(0,1);
struct State {
    int x,y,k;
    State() {}
    State(int x,int y,int k):x(x),y(y),k(k) {}
};
int n,m,dp[1009][1009][4],sx,sy,tx,ty,con[300][300][5][10];
char st[1009][1009];
vector<pii> all,hor,ver,nul;

void init() {
    all.pb(U); all.pb(D); all.pb(L); all.pb(R);
    hor.pb(L); hor.pb(R); ver.pb(U); ver.pb(D);
}

vector<pii> dirs(char ch,int rot) {
    if (ch=='*') return nul;
    if (ch=='+') return all;
    if (ch=='-') return (rot%2==0)?hor:ver;
    if (ch=='|') return (rot%2==1)?hor:ver;

    vector<pii> ret;
    if (ch=='^' || ch=='>' || ch=='<' || ch=='v')
    {
        if (ch=='^') {
            if (rot==0) ret.pb(U);
            if (rot==1) ret.pb(R);
            if (rot==2) ret.pb(D);
            if (rot==3) ret.pb(L);
        }
        if (ch=='>') {
            if (rot==0) ret.pb(R);
            if (rot==1) ret.pb(D);
            if (rot==2) ret.pb(L);
            if (rot==3) ret.pb(U);
        }
        if (ch=='v') {
            if (rot==0) ret.pb(D);
            if (rot==1) ret.pb(L);
            if (rot==2) ret.pb(U);
            if (rot==3) ret.pb(R);
        }
        if (ch=='<') {
            if (rot==0) ret.pb(L);
            if (rot==1) ret.pb(U);
            if (rot==2) ret.pb(R);
            if (rot==3) ret.pb(D);
        }
    }
    if (ch=='L' || ch=='R' || ch=='U' || ch=='D')
    {
        if (ch=='U') {
            if (rot!=0) ret.pb(U);
            if (rot!=1) ret.pb(R);
            if (rot!=2) ret.pb(D);
            if (rot!=3) ret.pb(L);
        }
        if (ch=='R') {
            if (rot!=0) ret.pb(R);
            if (rot!=1) ret.pb(D);
            if (rot!=2) ret.pb(L);
            if (rot!=3) ret.pb(U);
        }
        if (ch=='D') {
            if (rot!=0) ret.pb(D);
            if (rot!=1) ret.pb(L);
            if (rot!=2) ret.pb(U);
            if (rot!=3) ret.pb(R);
        }
        if (ch=='L') {
            if (rot!=0) ret.pb(L);
            if (rot!=1) ret.pb(U);
            if (rot!=2) ret.pb(R);
            if (rot!=3) ret.pb(D);
        }
    }
    return ret;
}

bool connected(char c1,char c2,int k,pii d) {
    int &ret=con[c1][c2][k][(d.X+1)*3+(d.Y+1)];
    if (ret!=0) return (ret>0);
    vector<pii> dir=dirs(c2,k);
    REP(i,dir.size())
        if (d.X+dir[i].X==0 && d.Y+dir[i].Y==0) return (ret=1);
    ret=-1; return false;
}

int BFS() {
    queue<State> Q; Q.push(State(sx,sy,0));
    mem(dp,-1); dp[sx][sy][0]=0;
    while (!Q.empty()) {
        State cur=Q.front(); Q.pop();
        int cx=cur.x, cy=cur.y, ck=cur.k;
        int curT=dp[cx][cy][ck];
        if (cx==tx && cy==ty) return curT;
        if (dp[cx][cy][(ck+1)%4]<0) {
            dp[cx][cy][(ck+1)%4]=curT+1;
            Q.push(State(cx,cy,(ck+1)%4));
        }
        vector<pii> d=dirs(st[cx][cy],ck);
        REP(i,d.size()) {
            int nx=cx+d[i].X, ny=cy+d[i].Y;
            if (nx<1 || ny<1 || nx>n || ny>m) continue;
            if (!connected(st[cx][cy],st[nx][ny],ck,d[i])) continue;
            if (dp[nx][ny][ck]<0) {
                dp[nx][ny][ck]=curT+1;
                Q.push(State(nx,ny,ck));
            }
        }
    }
    return -1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
#endif
    init();
    scanf("%d%d",&n,&m);
    rep(i,n) scanf("%s",st[i]+1);
    scanf("%d%d",&sx,&sy);
    scanf("%d%d",&tx,&ty);
    printf("%d\n",BFS());
    return 0;
}
