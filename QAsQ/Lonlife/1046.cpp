#include<bits/stdc++.h>
using namespace std;

const int maxn = 1123;

int arr[maxn][maxn];
int rea[maxn];

int main(){
    int T;
    scanf("%d",&T);
    int n,m,q;
    while(T-- && ~scanf("%d %d %d",&n,&m,&q)){
        memset(arr,-1,sizeof(arr));
        for(int i = 1 ; i <= n ; i ++) rea[i] = i;
        int p,x,y;
        int c;
        while(q--){
            scanf("%d",&p);
            if(p == 2){
                scanf("%d %d",&x,&y);
                swap(rea[x],rea[y]);
            }
            else{
                scanf("%d %d %d",&c,&x,&y);
                c--;
                x = rea[x];
                if(arr[x][y] == -1) arr[x][y] = c;
            }
        }
        for(int i = 1 ; i <= n;i++){
            for(int j = 1 ; j <= m;j++){
                int x = rea[i], y = j ;
                if(arr[x][y] == -1)
                    printf(".");
                else 
                    printf(arr[x][y] == 1 ? "b" : "w");
            }
            puts("");
        }
    }
    return 0;
}
