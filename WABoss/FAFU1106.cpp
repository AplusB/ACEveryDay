#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define INF (1<<29)
#define MAXN 111

int n,G[MAXN][MAXN],d[MAXN][MAXN],cnt[MAXN][MAXN];
int ans_d,ans_cnt;
void floyd(){
    ans_d=INF; ans_cnt=0;
    for(int i=0; i<n; ++i){
        for(int j=0; j<n; ++j){
            d[i][j]=G[i][j];
            if(d[i][j]==INF) cnt[i][j]=0;
            else cnt[i][j]=2;
        }
    }
    for(int k=0; k<n; ++k){
        for(int i=0; i<k; ++i){
            for(int j=0; j<i; ++j){
                if(d[i][j]==INF || G[i][k]==INF || G[k][j]==INF) continue;
                if(ans_d>d[i][j]+G[i][k]+G[k][j]){
                    ans_d=d[i][j]+G[i][k]+G[k][j];
                    ans_cnt=cnt[i][j]+1;
                }else if(ans_d==d[i][j]+G[i][k]+G[k][j]){
                    ans_cnt=max(ans_cnt,cnt[i][j]+1);
                }
            }
        }
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                if(d[i][k]==INF || d[k][j]==INF) continue;
                if(d[i][j]>d[i][k]+d[k][j]){
                    d[i][j]=d[i][k]+d[k][j];
                    cnt[i][j]=cnt[i][k]+cnt[k][j]-1;
                }else if(d[i][j]==d[i][k]+d[k][j]){
                    cnt[i][j]=max(cnt[i][j],cnt[i][k]+cnt[k][j]-1);
                }
            }
        }
    }
}
int main(){
    int m,a,b,c;
    while(~scanf("%d%d",&n,&m)){
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                G[i][j]=INF;
            }
        }
        while(m--){
            scanf("%d%d%d",&a,&b,&c);
            G[a][b]=G[b][a]=min(G[a][b],c);
        }
        floyd();
        if(ans_d==INF) puts("Sorry, I can't help you!");
        else printf("%d %d\n",ans_d,ans_cnt);
    }
    return 0;
}
