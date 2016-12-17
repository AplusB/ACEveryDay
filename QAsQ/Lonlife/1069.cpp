#include<bits/stdc++.h>
using namespace std;

const int maxn = 1123;

int lowbit(int x){
    return x & (-x);
}

int arr[maxn][maxn];

void upd(int x,int y,int v){
    for(int i = x ; i < maxn ; i += lowbit(i)){
        for(int j = y ; j < maxn ; j += lowbit(j)){
            arr[i][j] += v;
        }
    }
}

int que(int x,int y){
    int ret = 0;
    for(int i = x ; i ; i -= lowbit(i)){
        for(int j = y ; j ; j -= lowbit(j)){
            ret += arr[i][j];
        }
    }
    return ret;
}

int main(){
    int T;
    scanf("%d",&T);
    int n,q;
    bool fir = true;
    while(T-- && ~scanf("%d %d",&n,&q)){
        if(fir) fir = false;
        else puts("");
        memset(arr,0,sizeof(arr));
        char ord[3];
        int x,y,x1,y1;
        while(q-- && ~scanf("%s %d %d",ord,&x,&y)){
            if(*ord == 'C'){
                scanf("%d %d",&x1,&y1);
                x1++,y1++;
                upd(x,y,1);
                upd(x1,y1,1);
                upd(x,y1,-1);
                upd(x1,y,-1);
            }
            else{
                printf("%d\n",que(x,y));
            }
        }
    }
    return 0;
}
