#include<stack>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
#define LL long long
const int INF = 0x3f3f3f3f;
const int maxn = 212;
int D[maxn],J[maxn];

const int offset = 410;
int dp[30][offset*2];
int ver[maxn][30][offset*2];
int pv[30][offset*2];

int getpos(int m){
    for(int i=0;i<offset;i++){
        int l = dp[m][offset-i],r = dp[m][offset+i];
        if(l<0 && r<0) continue;
        if(l>=0 && r>=0){
            if(l > r) return offset-i;
            else      return offset+i;
        }
        if(l<0)
            return offset+i;
        else
            return offset-i;
    }
}

bool in(int x){
    return 0<x && x<offset*2;
}

int main(){
    int icase = 1;
    int n,m;
    while(~scanf("%d %d",&n,&m) && (n||m)){
        for(int i=1;i<=n;i++){
            scanf("%d %d",&D[i],&J[i]);
        }
        for(int i=0;i<offset*2;i++){
            for(int j=0;j<=m;j++)
                dp[j][i] = -INF;
        }
        memset(ver,-1,sizeof(ver));
        memset(pv,-1,sizeof(pv));
        dp[0][offset] = 0,pv[0][offset] = 0;
        for(int i=1;i<=n;i++){
            for(int k=m-1;k>=0;k--){
                for(int j=0;j<offset*2;j++){
                    int nex = j + D[i] - J[i];
                    if(in(nex) && dp[k][j]>=0){
                        int v = dp[k][j] + D[i] + J[i];
                        if(dp[k+1][nex] < v){
                            dp[k+1][nex] = v,pv[k+1][nex] = i;
                            ver[i][k+1][nex] = pv[k][j];
                       }
                    }
                }
            }
        }
        int ans = getpos(m);
        int sd,sj;
        sd = sj = 0;
        stack<int> S;
        int v = pv[m][ans];
        for(int i=m;i>=1;i--){
            S.push(v);
            sd += D[v],sj += J[v];
            int k = v;
            v = ver[v][i][ans];
            ans += J[k],ans -=D[k];
        }
        printf("Jury #%d\n",icase++);
        printf("Best jury has value %d for prosecution and value %d for defence:\n"
               ,sd,sj);
        while(S.empty()==false){
            printf(" %d",S.top());
            S.pop();
        }
        puts("\n");
    }
    return 0;
}
