/* ***********************************************
Author        :Eopxt
Created Time  :Fri 03 Jun 2016 09:05:31 PM CST
File Name     :D.cpp
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <sstream>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
using namespace std;
#define rep(i,n) for (int i=1; i<=(n); i++)
#define REP(i,n) for (int i=0; i<(n); i++)
#define For(i,s,t) for (int i=(s); i<=(t); i++)
#define FOR(i,s,t) for (int i=(s); i>=(t); i--)
#define foreach(j,x) for(int j=adj[x]; j>=0; j=E[j].nxt)
#define Foreach(it,v) for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); it++)
#define pb push_back
#define mp make_pair
#define INF 0x3f3f3f3f
#define mem(a,x) memset(a,x,sizeof(a))
#define X first
#define Y second
#define sqr(x) ((x)*(x))
#define C1(x) cout<<(x)<<endl
#define C2(x,y) cout<<(x)<<" "<<(y)<<endl
#define C3(x,y,z) cout<<(x)<<" "<<(y)<<" "<<(z)<<endl
typedef long long lld;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector< pair<int,int> > VPII;

const int N = 309, dx[4]={0,0,1,-1}, dy[4]={1,-1,0,0};
int n,m,p,dp[N][N],ex,ey,a[N][N],cnt[sqr(N)];
VPII ps[sqr(N)];

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    mem(dp,INF);
    scanf("%d%d%d",&m,&n,&p);
    rep(i,m) 
        rep(j,n) {
            scanf("%d",&a[i][j]);
            cnt[a[i][j]]++;
            ps[a[i][j]].pb(mp(i,j));
            if (a[i][j]==1) dp[i][j]=i+j-2;
            if (a[i][j]==p) ex=i, ey=j;
        }
    rep(k,p-1) {
        if (ps[k].size()*ps[k+1].size()<=n*m) {
            REP(i,ps[k].size())
                REP(j,ps[k+1].size()) {
                    int x1=ps[k][i].X, y1=ps[k][i].Y;
                    int x2=ps[k+1][j].X, y2=ps[k+1][j].Y;
                    dp[x2][y2]=min(dp[x2][y2],dp[x1][y1]+abs(x1-x2)+abs(y1-y2));
                    //if (k==2) printf("(%d,%d)-->(%d,%d)\n",x1,y1,x2,y2);
                }
        }
        else {
            queue<PII> Q;
            bool inQ[N][N]; mem(inQ,false);
            int dist[N][N]; mem(dist,INF);
            REP(i,ps[k].size()) {
                inQ[ps[k][i].X][ps[k][i].Y]=true;
                dist[ps[k][i].X][ps[k][i].Y]=dp[ps[k][i].X][ps[k][i].Y];
                Q.push(ps[k][i]);
            }
            while (!Q.empty()) {
                PII cur=Q.front(); 
                inQ[cur.X][cur.Y]=false;
                Q.pop();
                REP(i,4) {
                    PII t=mp(cur.X+dx[i],cur.Y+dy[i]);
                    if (t.X>=0 && t.Y>=0 && t.X<=m && t.Y<=n) {
                        int tmp=dist[cur.X][cur.Y]+abs(cur.X-t.X)+abs(cur.Y-t.Y);
                        if ((!inQ[t.X][t.Y]&&dist[t.X][t.Y]>=tmp) || dist[t.X][t.Y]>tmp) {
                            dist[t.X][t.Y]=tmp;
                            inQ[t.X][t.Y]=true;
                            Q.push(t);
                        }
                    }
                }
            }
            REP(i,ps[k+1].size())
                dp[ps[k+1][i].X][ps[k+1][i].Y]=dist[ps[k+1][i].X][ps[k+1][i].Y];
        
    printf("%d\n",dp[ex][ey]);
    //rep(i,m) {rep(j,n) printf("%11d ",dp[i][j]); printf("\n");}
    return 0;
}
