//hdoj 5327
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
const double eps=1e-6;
const double pi=acos(-1.0);
const int mod=998244353;
const int INF=0x3f3f3f3f;

const int N=1e5+10;

bool vis[15];
int d[N];

int shi(int x)
{
    int k;
    memset(vis,0,sizeof(vis));
    for(int i=1;;i++){
        k=x%10;
        if(!vis[k])
            vis[k]=1;
        else
            return 0;
        x/=10;
        if(!x)
            break;
    }
    return 1;
}
void init()
{
    memset(d,0,sizeof(d));
    for(int i=1;i<=N;i++){
        if(shi(i))
            d[i]=1;
        else
            d[i]=0;
    }
    for(int i=2;i<=N;i++)
        d[i]+=d[i-1];
}

int main()
{
    int t;
    cin>>t;
    init();
    while(t--){
        int a,b;
        scanf("%d%d",&a,&b);
        printf("%d\n",d[b]-d[a-1]);
    }
    return 0;
}
