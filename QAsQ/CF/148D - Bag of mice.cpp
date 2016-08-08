#include<bits/stdc++.h>
using namespace std;
#define fuck(x) cout<<"["<<x<<"]";

const int maxn = 1123;
double dp[maxn][maxn][2];
bool vis[maxn][maxn][2];

double gp(int s,int v){
    if(s<0 || v<0 || s+v<=0) return 0;
    return s * 1.0 / (s + v);
}
double dfs(int w,int b,bool pfir){
    if(b<0 || w<0) return 0;
    if(w<=0) return 0;
    if(vis[w][b][pfir]) return dp[w][b][pfir];
    vis[w][b][pfir] = true;
    double & ndp = dp[w][b][pfir];
    ndp = 0;
    if(pfir){
        ndp += gp(w,b);
        ndp += gp(b,w) * dfs(w,b-1,false);
    }
    else{
        ndp += gp(b,w) * gp(w,b-1) * dfs(w-1,b-1,true);
        ndp += gp(b,w) * gp(b-1,w) * dfs(w  ,b-2,true);
    }
    return ndp;
}

int main(){
    memset(vis,0,sizeof(vis));
    int w,b;
    scanf("%d %d",&w,&b);
    printf("%.10f\n",dfs(w,b,true));
    return 0;
}


