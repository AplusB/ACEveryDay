#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL long long
const LL INFF = 0x3f3f3f3f3f3f3f3fll;

const int maxn = 210;
int d[maxn],p[maxn];

int dif[maxn][30],sum[maxn][30];
prx[maxn][30],pry[maxn][30];

int main(){
    int n,m;
    int icase = 1;
    while(~scanf("%d %d",&n,&m) && (n||m)){
        for(int i=1;i<=n;i++){
            scanf("%d %d",&d[i],&p[i]);
        }
        memset(prx,-1,sizeof(prx));
        memset(pry,-1,sizeof(pry));
        memset(dif,0x3f,sizeof(dif));
        memset(sum,0,sizeof(sum));
        dif[0][0] = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m && j<=i;j++){



            }
        }
        stack<int> S;


    }
    return 0;
}
