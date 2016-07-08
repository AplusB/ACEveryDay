#include<bits/stdc++.h>
using namespace std;

const int maxn  = 20;
int sta[maxn][maxn];

void init(){
    memset(sta,-1,sizeof(sta));
    int sx = 5,sy = 5;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            sta[sx+i][sy+j] = i*3+j+1;
        }
    }
    sta[sx+3][sy+1] = 0;
}

void getsta(char c,int &x,int &y){
    int v = c - '0';
    for(int i=0;i<maxn;i++){
        for(int j=0;j<maxn;j++){
            if(sta[i][j] == v){
                x = i,y = j;
                return;
            }
        }
    }
}


int x[maxn],y[maxn];
bool judge(int n,int i,int j){
    for(int k=1;k<n;k++){
        i+=x[k],j+=y[k];
        if(sta[i][j] == -1) return false;
    }
    return true;
}

bool judge(int n){
    int cnt = 0;
    for(int i=0;i<maxn;i++){
        for(int j=0;j<maxn;j++){
            if(sta[i][j]!=-1){
                cnt += judge(n,i,j);
            }
        }
    }
    return cnt == 1;
}

int main(){
    init();
    int n;
    char arr[maxn];
    cin>>n;
    cin>>arr;
    for(int i=0;i<n;i++)
        getsta(arr[i],x[i],y[i]);
    for(int i=n-1;i>0;i--){
        x[i] -= x[i-1],y[i]-=y[i-1];
    }
    puts(judge(n)?"YES":"NO");
    return 0;
}
