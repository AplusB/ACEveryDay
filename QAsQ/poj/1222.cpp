#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 112;
#define LL long long 
const int dx[5] = {1,0,-1,0,0};
const int dy[5] = {0,1,0,-1,0};
LL coe[maxn];
int arr[10][10];

int id(int x,int y){ return (x-1)*6 + y; }
LL bit(int x){return 1ll<<x;}
bool in(int x,int y){return 1<=x && x<=5 && 1<=y && y<=6;}
bool cmp(LL x,LL y){return x > y;}
bool hav(LL v,int st){return v & bit(st);}

void build(){
    memset(coe,0,sizeof(coe));
    for(int i=1;i<=5;i++) for(int j=1;j<=6;j++){
        for(int d = 0;d < 5;d++){
            int x = dx[d] + i, y = dy[d] + j;
            if(in(x,y)) coe[id(i,j)] |= bit(id(x,y));
        }
        coe[id(i,j)] |= arr[i][j];
    }
}

void out(LL x){
    while(x){
        printf("%d",x&1);
        x>>=1;
    }
    puts("");
}
int ans[maxn];
void Guess(){
    int st = 31;
    memset(ans,0,sizeof(ans));
    for(int i=1;i<=30;i++){
        sort(coe+i,coe+1+30,cmp);
        while(!hav(coe[i],st) && st > 0) st--;
        ans[st] = i;
        for(int j=i+1;j<=30;j++)
            if(hav(coe[j],st))
                coe[j] ^= coe[i];
    }
    for(int i=1;i<=30;i++){
        if(ans[i] == 0) continue;
        int pos = ans[i];
        ans[i] = coe[pos] & 1;
        for(int j = 1;j<i;j++){
            if((coe[pos]>>j)&1)
                ans[i] ^= ans[j];
        }
    }
}

int main(){
    int T;
    scanf("%d",&T);
    int icase = 1;
    while(T--){
        for(int i=1;i<=5;i++){
            for(int j=1;j<=6;j++){
                scanf("%d",&arr[i][j]);
            }
        }
        build();
        Guess();
        printf("PUZZLE #%d\n",icase++);
        for(int i=1;i<=5;i++){
            for(int j=1;j<=6;j++){
                printf(j<6?"%d ":"%d\n",ans[id(i,j)]);
            }
        }
    }
    return 0;
}






