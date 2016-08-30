/* ***********************************************
Author        :Maltub
Email         :xiang578@foxmail.com
Blog          :htttp://www.xiang578.com
************************************************ */

#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
//#include <bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<n;i++)
#define per(i,a,n) for(int i=n-1;i>=a;i--)
#define pb push_back
using namespace std;
typedef vector<int> VI;
typedef long long ll;
const ll mod=1000000007;
const int N=1000+10;
const int M=1e6+10;
struct node
{
    int x,y;
}p[N*N];
int n,m,b[M],cnt[M],mp[N][N],use[N][N],vis[N][N];
ll k,a[N][N];
int dx[]={0,0,-1,1};
int dy[]={-1,1,0,0};

int ok(int x,int y)
{
    if(x<0||x>=n||y<0||y>=m) return 0;
    else return 1;
}

int Find(int x)
{
    if(b[x]!=x) return b[x]=Find(b[x]);
    else return x;
}

int cmp(node n1,node n2)
{
    return a[n1.x][n1.y]>a[n2.x][n2.y];
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d%d%lld",&n,&m,&k);
    int tot=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%lld",&a[i][j]);
            p[tot].x=i;
            p[tot].y=j;
            mp[i][j]=tot;
            tot++;
        }
    }
    sort(p,p+tot,cmp);
    for(int i=0;i<tot;i++)
    {
        b[i]=i;
        cnt[i]=1;
    }
    int o=0;
    ll ans;
    for(int i=0;i<tot;i++)
    {
        int f=Find(mp[p[i].x][p[i].y]);
        ll tmp=a[p[i].x][p[i].y]*n*m;
        if(tmp<k) break;
        for(int j=0;j<4;j++)
        {
            int x=p[i].x+dx[j];
            int y=p[i].y+dy[j];
            if(ok(x,y)==1&&a[p[i].x][p[i].y]<=a[x][y])
            {
                int fn=Find(mp[x][y]);
                if(fn!=f)
                {
                    cnt[f]+=cnt[fn];
                    b[fn]=f;
                }
            }
        }
        if(k%a[p[i].x][p[i].y]==0)
        {
            int t=(int)(k/a[p[i].x][p[i].y]);
            if(t<=cnt[f])
            {
                ans=a[p[i].x][p[i].y];
                queue<int>qx;
                queue<int>qy;
                qx.push(p[i].x);
                qy.push(p[i].y);
                memset(vis,0,sizeof(vis));
                memset(use,0,sizeof(use));
                vis[p[i].x][p[i].y]=1;
                int x,y,tx,ty,w=0;
                while(!qx.empty())
                {
                    x=qx.front();
                    qx.pop();
                    y=qy.front();
                    qy.pop();
                    use[x][y]=1;
                    w++;
                    if(w==t) {o=1;break;}
                    for(int j=0;j<4;j++)
                    {
                        tx=x+dx[j];
                        ty=y+dy[j];
                        if(!ok(tx,ty)) continue;
                        if(vis[tx][ty]==1) continue;
                        vis[tx][ty]=1;
                        if(a[tx][ty]>=ans)
                        {
                            qx.push(tx);
                            qy.push(ty);
                        }
                    }
                }
            }
        }
        if(o) break;
    }
    if(!o) puts("NO");
    else
    {
        puts("YES");
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(use[i][j]) printf("%lld ",ans);
                else printf("0 ");
            }
            printf("\n");
        }
    }
    return 0;
}
