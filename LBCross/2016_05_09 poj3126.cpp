#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
#include <ctime>
#include<queue>
#include<set>
#include<map>
#include<stack>
#include<iomanip>
#include<cmath>
#define mst(ss,b) memset((ss),(b),sizeof(ss))
#define maxn 0x3f3f3f3f
#define MAX 1000100
///#pragma comment(linker, "/STACK:102400000,102400000")
typedef long long ll;
typedef unsigned long long ull;
#define INF (1ll<<60)-1
using namespace std;
int mu[1000100],prime[1000100],vis[1000100],a[1000100];
struct node{
    int v,step;
    node(int v=0,int step=0):v(v),step(step){}
};
int used[1000100];
void BFS(int x,int y){
    mst(used,0);
    queue<node> qu;
    qu.push(node(x,0));
    used[x]=1;
    while(!qu.empty()){
        node now=qu.front();
        qu.pop();
        if(now.v==y){
            cout<<now.step<<endl;
            return ;
        }
        for(int i=0;i<4;i++){
            for(int j=0;j<=9;j++){
                if(i==0 && j==0) continue;
                if(i==0){
                    int tmp=now.v%1000+j*1000;
                    ///printf("%d %d %d %d\n",i,j,now.v,tmp);
                    if(!used[tmp] && vis[tmp]){
                        used[tmp]=1;
                        qu.push(node(tmp,now.step+1));
                    }
                } else if(i==1){
                    int tmp=now.v%100+j*100+(now.v/1000)*1000;
                    if(!used[tmp] && vis[tmp]){
                        used[tmp]=1;
                        qu.push(node(tmp,now.step+1));
                    }
                } else if(i==2){
                    int tmp=now.v/100*100+j*10+now.v%10;
                    if(!used[tmp] && vis[tmp]){
                        used[tmp]=1;
                        qu.push(node(tmp,now.step+1));
                    }
                } else {
                    int tmp=now.v/10*10+j;
                    if(!used[tmp] && vis[tmp]){
                        used[tmp]=1;
                        qu.push(node(tmp,now.step+1));
                    }
                }
            }
        }
    }
}
int main(){
    mu[1]=1;
    int cnt=0,num=0;
    for(int i=2;i<=100000;i++){
        if(!vis[i]){
            prime[cnt++]=i;
            mu[i]=-1;
            if(i>=1000 && i<10000) a[num++]=i;
        }
        for(int j=0;j<cnt;j++){
            if(i*prime[j]>100000) break;
            vis[i*prime[j]]=1;
            if(i%prime[j]==0){
                mu[i*prime[j]]=0;
                break;
            } else mu[i*prime[j]]=-mu[i];
        }
    }
    mst(vis,0);
    for(int i=0;i<num;i++) vis[a[i]]=1;
    int T;
    scanf("%d",&T);
    while(T--){
        int x,y;
        scanf("%d%d",&x,&y);
        BFS(x,y);
    }
    return 0;
}
