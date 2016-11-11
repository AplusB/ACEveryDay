#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

const int maxn = 220;
const int N = 101;
int dis[maxn][maxn];
int g[N][N];
int nx,ny;//两边的点数
int linker[N],lx[N],ly[N];//y中各点匹配状态，x,y中的点标号
int slack[N];
bool visx[N],visy[N];

bool DFS(int x)
{
    visx[x] = true;
    for(int y = 0; y < ny; y++)
    {
        if(visy[y])continue;
        int tmp = lx[x] + ly[y] - g[x][y];
        if(tmp == 0)
        {
            visy[y] = true;
            if(linker[y] == -1 || DFS(linker[y]))
            {
                linker[y] = x;
                return true;
            }
        }
        else if(slack[y] > tmp)
            slack[y] = tmp;
    }
    return false;
}

int KM()
{
    memset(linker,-1,sizeof(linker));
    memset(ly,0,sizeof(ly));
    for(int i = 0;i < nx;i++)
    {
        lx[i] = -INF;
        for(int j = 0;j < ny;j++)
            if(g[i][j] > lx[i])
                lx[i] = g[i][j];
    }
    for(int x = 0;x < nx;x++)
    {
        for(int i = 0;i < ny;i++)
            slack[i] = INF;
        while(true)
        {
            memset(visx,false,sizeof(visx));
            memset(visy,false,sizeof(visy));
            if(DFS(x))break;
            int d = INF;
            for(int i = 0;i < ny;i++)
                if(!visy[i] && d > slack[i])
                    d = slack[i];
            for(int i = 0;i < nx;i++)
                if(visx[i])
                    lx[i] -= d;
            for(int i = 0;i < ny;i++)
            {
                if(visy[i])ly[i] += d;
                else slack[i] -= d;
            }
        }
    }
    int res = 0;
    for(int i = 0;i < ny;i++)
        if(linker[i] != -1)
            res += g[linker[i]][i];
    return res;
}

int main(){
    int T;
    scanf("%d",&T);
    int n,m;
    while(T-- && ~scanf("%d %d",&n,&m)){
        int all = n + m;
        for(int i = 1 ; i <= all; i ++){
            for(int j = 1 ; j <= all; j ++){
                scanf("%d",&dis[i][j]);
                if(dis[i][j] == -1) dis[i][j] = INF;
            }
        }
        for(int k = 1 ; k <=all;k++){
            for(int i = 1 ; i <=all;i++){
                for(int j = 1 ; j <=all;j++){
                    dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
                }
            }
        }
        for(int i = 0; i < n;i++){
            for(int j = 0; j < m ;j++){
                g[i][j] = dis[i+1][n+j+1];
                if(g[i][j] == INF) 
                    g[i][j] = 0;
            }
        }
        nx = n,ny = m;
        if(n > m){
            for(int i = 0; i < n;i++){
                for(int j = 0; j < m ;j++){
                    swap(g[i][j],g[j][i]);
                }
            }
            swap(nx,ny);
        }
        printf("%d\n",KM());
    }
    return 0;
}
