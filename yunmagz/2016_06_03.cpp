//lightoj1092 - Lighted Panels
#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
char mp[10][10];
int n,m,state[10][10],flip[10][10];
void init(){
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++){
            state[i][j]=(mp[i][j]=='.');
            flip[i][j]=0;
        }
}
void change(int x,int y){
    int xx,yy;
    for(int i=-1;i<=1;i++)
        for(int j=-1;j<=1;j++){
            xx=x+i,yy=y+j;
            if(xx>=n||xx<0||yy>=m||yy<0) continue;
            flip[xx][yy]^=1;
        }
}
int calc(){
    int res=0;
    for(int i=1;i<n;i++)
        for(int j=1;j<m;j++)
            if(state[i-1][j-1]^flip[i-1][j-1]){
                change(i,j);
                res++;
            }
    for(int i=0;i<m;i++)
        if(state[n-1][i]^flip[n-1][i])
            return INF;
    for(int i=0;i<n;i++)
        if(state[i][m-1]^flip[i][m-1])
            return INF;
    return res;
}
void sol(){
    int ans=INF,tmp;
    for(int S=0;S<1<<(n+m-1);S++){
        memset(flip,0,sizeof flip);
        tmp=0;
        for(int i=0;i<n+m-1;i++){
            if(!(S&(1<<i))) continue;
            tmp++;
            if(i>=m) change(i-m+1,0);
            else change(0,i);
        }
        ans=min(ans,tmp+calc());
    }
    if(ans==INF) puts("impossible");
    else printf("%d\n",ans);
}
int main(){
    int t,cas=1;
    cin>>t;
    while(t--){
        cin>>n>>m;
        for(int i=0;i<n;i++)
            cin>>mp[i];
        init();
        printf("Case %d: ",cas++);
        sol();
    }
    return 0;
}
