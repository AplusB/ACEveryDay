//模拟题
//记录每次操作和所做操作处于第几个操作
//若该命令没有，输出0，若存在，比较行和列的操作看哪个为最后操作（cnt），则为该color
#include<iostream>
#include<cstdio>
using namespace std;
struct node{
    int color, k;
}g[3][5005];
int cnt;
int main(){
#ifdef _CONSOLE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int n, m, k;
    cnt = 0;
    scanf("%d%d%d",&n,&m,&k);
    int tmp1, tmp2;
    for(int i = 0; i < k; ++i) {
        scanf("%d%d",&tmp1,&tmp2);
        scanf("%d",&g[tmp1][tmp2].color);
        g[tmp1][tmp2].k=cnt++;
    } 
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j){
            if(!g[1][i].color && !g[2][j].color)
                cout<<0<<" ";
            else if(!g[2][j].color || g[1][i].k > g[2][j].k)
                cout<<g[1][i].color<<" ";
            else
                cout<<g[2][j].color<<" ";
        }
        puts("");
    }
    
    return 0;
}
