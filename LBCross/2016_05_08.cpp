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
int vis[200100],n,k;
struct node{
    int x,step;
    node(int x=0,int step=0):x(x),step(step){}
};
void bfs(){
    mst(vis,0);
    queue<node> qu;
    qu.push(node(n,0));
    vis[n]=1;
    while(!qu.empty()){
        node now=qu.front();
        qu.pop();
        if(!vis[now.x+1] && now.x+1<100001){
            if(now.x+1==k) {
                cout<<now.step+1<<endl;
                return ;
            }
            vis[now.x+1]=1;
            qu.push(node(now.x+1,now.step+1));
        }
        if(!vis[now.x-1] && now.x-1>=0){
                if(now.x-1==k) {
                cout<<now.step+1<<endl;
                return ;
            }
            vis[now.x-1]=1;
            qu.push(node(now.x-1,now.step+1));
        }
        if(!vis[now.x*2] && now.x*2<100001){
            if(now.x*2==k) {
                cout<<now.step+1<<endl;
                return ;
            }
            vis[now.x*2]=1;
            qu.push(node(now.x*2,now.step+1));
        }
    }
}
int main(){
    while(scanf("%d%d",&n,&k)!=EOF){
        if(n==k) cout<<0<<endl;
        else bfs();
    }
    return 0;
}
