#include<bits/stdc++.h>
using namespace std;

const int maxn = 1123;

int inp[maxn][maxn];
int n,m;
int id(int x,int y){
    return x * (m+1) + y;
}

struct node{
    int v;
    int d,r;
}arr[maxn*maxn];

int getst(int x,int y){
    x--,y--;
    int st = id(x,0);
    while(y--) st = arr[st].r;
    return st;
}

void geter(int x,int y,int h,int w,int se[][4]){
    int S = getst(x,y);
    int toper = 0;
    int rst = arr[S].d ,dst = arr[S].r;
    for(int i=0;i<h;i++){ 
        if(i) rst = arr[rst].d;
        se[i][0] = rst,se[i][1] = arr[rst].r;
    }
    for(int i=0;i<w;i++){
        if(i) dst = arr[dst].r;
        se[i][2] = dst,se[i][3] = arr[dst].d;
    }
    rst = arr[rst].r, dst= arr[dst].d;
    swap(rst,dst);
    for(int i=h;i<h*2;i++) se[i][0] = rst,se[i][1] = arr[rst].r,  rst = arr[rst].d;
    for(int i=w;i<w*2;i++) se[i][2] = dst,se[i][3] = arr[dst].d,  dst = arr[dst].r;
}
int fir[maxn*4][4];
int sec[maxn*4][4];
int main(){
    int oper;
    scanf("%d %d %d",&n,&m,&oper);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%d",&inp[i][j]);
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i != n) arr[id(i,j)].d = id(i+1,j); else arr[id(i,j)].d = -1;
            if(j != m) arr[id(i,j)].r = id(i,j+1); else arr[id(i,j)].r = -1;
            arr[id(i,j)].v = inp[i][j];
        }
    }
    while(oper--){
        int a,b,c,d,h,w;
        scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&h,&w);
        memset(fir,-1,sizeof(fir));
        geter(a,b,h,w,fir);
        geter(c,d,h,w,sec);
        for(int i=0;i<h*2;i++){
            arr[fir[i][0]].r = sec[i][1];
            arr[sec[i][0]].r = fir[i][1];
        }
        for(int i=0;i<w*2;i++){
            arr[fir[i][2]].d = sec[i][3];
            arr[sec[i][2]].d = fir[i][3];
        }
    }
    for(int i=1;i<=n;i++){
        int st = getst(i+1,2);
        for(int j=1;j<=m;j++){
            printf(j<m?"%d ":"%d\n",arr[st].v);
            st = arr[st].r;
        }
    }
    return 0;
}
