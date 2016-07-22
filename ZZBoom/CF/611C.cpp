#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const double eps=1e-6;
const double pi=acos(-1.0);
const int mod=998244353;
const int INF=0x3f3f3f3f;

const int N=1e2+10;

char ma[N*5][N*5];
int n[N*5][N*5];
int m[N*5][N*5];

int main()
{
    int i,j,h,w;
    scanf("%d%d",&h,&w);
    for(i=0;i<h;i++)
        scanf("%s",ma[i]);
    memset(n,0,sizeof(n));
    memset(m,0,sizeof(m));

    for(i=0;i<h;i++)
    {
        for(j=0;j<w;j++){
            if(j>0&&ma[i][j]=='.'&&ma[i][j]==ma[i][j-1]) n[i][j]=n[i][j-1]+1;
            else n[i][j]=n[i][j-1];
            if(i>0&&ma[i][j]=='.'&&ma[i-1][j]==ma[i][j]) m[i][j]=m[i-1][j]+1;
            else m[i][j]=m[i-1][j];
        }
    }
    LL ans;
    int q;
    int x1,x2,y1,y2;
    scanf("%d",&q);
    while(q--){
        ans=0;
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        x1--;
        y1--;
        x2--;
        y2--;
        for(i=x1;i<=x2;i++)
            ans+=n[i][y2]-n[i][y1];
        for(j=y1;j<=y2;j++)
            ans+=m[x2][j]-m[x1][j];
        printf("%I64d\n",ans);
    }
    return 0;
}
