#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;

const int maxn = 100;

struct Rect{
    int x,y,z;
    void init(int X,int Y,int Z){
        x = X,y = Y,z = Z;
    }
};

Rect rect[maxn];

int dp[maxn];

bool cmp(Rect a,Rect b){
    return a.x * a.y < b.x * b.y;
}

bool les(Rect a,Rect b){
    return (a.x < b.x && a.y < b.y) || (a.x < b.y && a.y < b.x);
}

int main(){
    int n;
    int icase = 1;
    while(~scanf("%d",&n) && n){
        memset(dp,0,sizeof(dp));
        int len = 0;
        int v[3];
        while(n--){
            scanf("%d %d %d",&v[0],&v[1],&v[2]);
            for(int i=0;i<3;i++){
                rect[len++].init(v[i],v[(i+1)%3],v[(i+2)%3]);
            }
        }
        sort(rect,rect+len,cmp);
        memset(dp,0,sizeof(dp));
        for(int i=0;i<len;i++){
            dp[i] = rect[i].z;
            for(int j=0;j<i;j++){
                if(les(rect[j],rect[i]))
                    dp[i] = max(dp[i],dp[j]+rect[i].z);
            }
        }
        printf("Case %d: maximum height = %d\n",icase++,*max_element(dp,dp+len));
    }
    return 0;
}

