#include <iostream>
#include <string.h>
#include <stdio.h>
#include <cmath>
#include <vector>

#define LL long long
#define maxn 410

using namespace std;

bool map[maxn][maxn];
int ans[maxn];

inline void reverse(int s,int t)
{
    while(s<t)
	{
        swap(ans[s++],ans[t--]);
    }
}

void Hamilton(int n)
{
    int s=1,t;
    int ansi=2;
    int w,i,j;
    bool visit[maxn]={false};
    for(i=1;i<=n;i++){
        if (map[s][i]) break;
    }
    t=i;
    visit[s]=visit[t]=true;
    ans[0]=s;
    ans[1]=t;
    while(1){
        while(1){
            for(i=1;i<=n;i++){
                if (map[t][i] && !visit[i]){
                    ans[ansi++]=i;
                    visit[i]=true;
                    t=i;
                    break;
                }
            }
            if (i>n) break;
        }
        w=ansi-1;
    i=0;reverse(i,w);
    swap(s,t);
    while(1){
        for(i=1;i<=n;i++){
            if (map[t][i] && !visit[i]){
                ans[ansi++]=i;
                visit[i]=true;
                t=i;
                break;
            }
        }
        if (i>n) break;
    }
    if (!map[s][t]){
        for(i=1;i<ansi-2;i++) if (map[ans[i]][t] && map[s][ans[i+1]]) break;
        w=ansi-1;
        i++;
        t=ans[i];
        reverse(i,w);
    }
    if (ansi==n) return ;
    for(j=1;j<=n;j++){
        if (visit[j]) continue;
        for(i=1;i<ansi-2;i++) if (map[ans[i]][j]) break;
        if (map[ans[i]][j]) break;
    }
    s=ans[i-1];
    t=j;
    reverse(0,i-1);
    reverse(i,ansi-1);
    ans[ansi++]=j;
    visit[j]=true;
    }
}
int n,m;
int main(){
    while(cin>>n>>m){
        if (n==0 && m==0) break;
        memset(map,0,sizeof(map));
        for(int i=1;i<=m;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            map[u][v]=map[v][u]=true;
        }
        for(int i=1;i<=2*n;i++){
            for(int j=1;j<=2*n;j++)
            if (i==j) continue;
            else map[i][j]=!map[i][j];
        }
        Hamilton(2*n);
        for(int i=0;i<2*n;i++)
        if (i!=2*n-1) printf("%d ",ans[i]);else printf("%d\n",ans[i]);
    }
    return 0;
}
