#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int INF = 0x3f3f3f3f;

int lis[24][4];

void initp(){
    for(int i=0;i<4;i++){
        lis[0][i] = i + 1;
    }
    for(int j=1;j<24;j++){
        for(int i=0;i<4;i++){
            lis[j][i] = lis[j-1][i];
        }
        next_permutation(lis[j],lis[j]+4);
    }
}

const int maxn = 5123;
int arr[maxn][8];

bool legal(int *cho,int *fig){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(fig[i] > fig[j] && cho[i*2+1] < cho[j*2+1])
                return false;
        }
    }
    return true;
}

int calcost(int *bcho,int *bfig,int *acho,int *afig){
    int ret = 0;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(bfig[i] == afig[j]){
                ret += abs(bcho[i*2]-acho[j*2]);
                ret += abs(bcho[i*2+1]-acho[j*2+1]);
            }
        }
    }
    return ret;
}

int dp[maxn][24];

int main(){
    initp();
    int T,icase = 1;
    for(int i=0;i<8;i++){
        arr[0][i] = i%2?i/2+1:0;
//        printf(i<7?"%d ":"%d\n",arr[0][i]);
    }

    scanf("%d",&T);
    int n;
    while(T-- && ~scanf("%d",&n)){
        memset(dp,0x3f,sizeof(dp));
        dp[0][0] = 0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<8;j++) scanf("%d",&arr[i][j]);
            for(int j=0;j<24;j++){
                if(!legal(arr[i],lis[j])) continue;
//                for(int l = 0;l<4;l++){
//                    printf(l<3?"%d ":"%d\n",lis[j][l]);
//                }
//                printf("at = %d fing = %d\n",i,j);
                for(int k=0;k<24;k++){
                    dp[i][j]=min(dp[i][j],dp[i-1][k]+calcost(arr[i-1],lis[k],arr[i],lis[j]));
//                    printf("sta = %d af = %d bef = %d\n",i,j,k);
//                    getchar();
                }
            }
        }
        int ans = INF;
        for(int i=0;i<24;i++){
            ans = min(dp[n][i],ans);
        }
        printf("Case #%d:\n%d\n",icase++,ans);
    }
    return 0;
}
