#include<iostream>
#include <cstdio>
#include<queue>
#include<string>
#include<algorithm>
#include<map>
#include <cstring>
#include<queue>
#include<vector>
#include<cmath>
#include<set>
using namespace std;
typedef long long ll;
const int maxn=405;

vector<int> a[maxn];
int p[maxn],q[maxn];
bool f[maxn][maxn],v[maxn];
int n,m,b,w,tot;

void dfs(int x)
{
     int i,y;
     v[x]=true;
     if (x<=n) w++;
     else b++;
     for (i=0;i<a[x].size();i++)
     {
         y=a[x][i];
         if (v[y]) continue;
         dfs(y);
     }
}

int main()
{
    int T;
    scanf("%d",&T);
    while (T--)
    {
          scanf("%d%d",&n,&m);
          for (int i=0;i<=2*n;i++)
              a[i].clear();
          memset(f,0,sizeof(f));
          memset(v,0,sizeof(v));
          tot=0;
          for (int i=1;i<=m;i++)
          {
              int x,y;
              scanf("%d%d",&x,&y);
              a[x].push_back(y+n);
              a[y+n].push_back(x);
          }
          for (int i=1;i<=n+n;i++)
          if (!v[i])
          {
             b=w=0;
             dfs(i);
             p[++tot]=w;q[tot]=b;
          }
          f[0][0]=true;
          for (int i=1;i<=tot;i++)
          {
              for (int j=n/2;j>=p[i];j--)
                  for (int k=n/2;k>=q[i];k--)
                  {
                      if (f[j-p[i]][k-q[i]])
                         f[j][k]=true;
                  }
          }
          for (int i=n/2;i>=0;i--)
          {
              if (f[i][i])
              {
                cout << i << endl;
                break;
              }
          }
    }
    return 0;
}
