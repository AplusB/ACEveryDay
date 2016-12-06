#include<bits/stdc++.h>
using namespace std;

const int maxn = 3123;

int arr[maxn * maxn];
bool side[maxn * maxn]; //0 sameside 1 notsameside

int fnd(int x){
    if(arr[x] == x) return x;
    int fa = arr[x];
    arr[x] = fnd(fa);
    side[x] ^= side[fa];
    return arr[x];
}

void join(int x,int y,bool sam){
    int fx = x,fy = y;
    x = fnd(x),y = fnd(y);
    sam ^= side[fx];
    sam ^= side[fy];
    if(x == y) return;
    arr[x] = y;
    side[x] = sam;
}

bool check(int x,int y,int sam){
    int fx = x,fy = y;
    x = fnd(x),y = fnd(y);
    sam ^= side[fx];
    sam ^= side[fy];
    if(x != y) return true;
    return sam == 0;
}
int id[maxn][maxn];
bool use[maxn][maxn];
int r,c;

int idlist[9];
bool idsa[9];

const int dx[8] = { -1,-1,0,1,1,1,0,-1};
const int dy[8] = { 0,1,1,1,0,-1,-1,-1};

bool jud(int x,int y){
    int len = 0;
    for(int d = 0 ; d < 8 ; d ++){
        int nx = x + dx[d];
        int ny = ((y - 1) + dy[d] + c) % c + 1;
        if(use[nx][ny]){
            idlist[len] = id[nx][ny];
            idsa[len++] = (y == 1 && dy[d] == -1) || ( y == c && dy[d] == 1);
        }
    }
    for(int i = 0 ; i < len ; i ++){
        for(int j = i + 1; j < len ; j ++){
            if(check(idlist[i],idlist[j],idsa[i] ^ idsa[j]) == false) return false;
        }
    }
    for(int i = 0 ; i < len ; i ++){
        join(id[x][y],idlist[i],idsa[i]);
    }
    use[x][y] = true;
    return true;
}

int x[312345],y[312345];

int cal(int n){
    if(c == 1) return 0;
    int ret = 0;
    for(int i = 0 ; i < n; i ++){
        ret += jud(x[i],y[i]);
    }
    return ret;
}


int main(){
    int n;
    scanf("%d %d %d",&r,&c,&n);
    for(int i = 0 ; i <= r * c + 1;i++) arr[i] = i,side[i] = 0;
    int len = 1;
    for(int i = 1; i <= r; i ++){
        for(int j = 1; j <= c ; j ++){
            id[i][j] = len++;
        }
    }
    memset(use,0,sizeof(use));
    for(int i = 0 ; i < n ; i ++){
        scanf("%d %d",&x[i],&y[i]);
    }
    printf("%d\n",cal(n));
    return 0;
}
