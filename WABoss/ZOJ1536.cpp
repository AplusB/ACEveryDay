#include<cstdio>
#include<cstring>
using namespace std;
#define MOD 1000000000000000000LL

struct Num{
    unsigned long long a[11];
    bool flag;
    Num(int n=0){
        memset(a,0,sizeof(a));
        a[0]=n;
        flag=0;
    }
    Num operator+(const Num &n) const {
        Num res;
        unsigned long long carry=0;
        for(int i=0; i<11; ++i){
            unsigned long long tmp=a[i]+n.a[i]+carry;
            res.a[i]=tmp%MOD;
            carry=tmp/MOD;
        }
        return res;
    }
};
void output(Num n){
    int i=10;
    while(i>=0 && n.a[i]==0) --i;
    if(i==-1){
        puts("0");
        return;
    }
    printf("%llu",n.a[i]);
    while(i>0){
        --i;
        printf("%018llu",n.a[i]);
    }
    putchar('\n');
}

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int n,a[22][22];
Num d[22][22][55];

Num dp(int x,int y,int t){
    if(x==0 && y==0 && t==0) return Num(1);
    if(t==0) return Num(0);
    if(d[x][y][t].flag) return d[x][y][t];
    Num res;
    for(int i=0; i<4; ++i){
        int nx=x+dx[i],ny=y+dy[i];
        if(nx<0 || nx>=n || ny<0 || ny>=n || a[nx][ny]) continue;
        res=res+dp(nx,ny,t-1);
    }
    d[x][y][t]=res;
    d[x][y][t].flag=1;
    return d[x][y][t];
}

int main(){
    int k;
    while(~scanf("%d%d",&n,&k)){
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; ++j){
                scanf("%1d",&a[i][j]);
            }
        }
        memset(d,0,sizeof(d));
        output(dp(n-1,n-1,k));
    }
    return 0;
}
