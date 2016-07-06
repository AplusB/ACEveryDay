#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int maxn=10;

char board[maxn][maxn];
int place[maxn]; 
int n,k;
int cnt,num;

void DFS(int i){
    if(k==num){
        cnt++;
        return ;
    }
    if(i>=n)
        return ;
    for(int j=0;j<n;j++)
        if(!place[j] && board[i][j]=='#'){
            place[j]=1;
            num++;
            DFS(i+1);
            place[j]=0;
            num--;
        }
    DFS(i+1); 
}

int main(){

    //freopen("input.txt","r",stdin);

    int i,j;
    while(scanf("%d%d",&n,&k)){
        getchar();
        if(n==-1 && k==-1)
            break;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++)
                scanf("%c",&board[i][j]);
            getchar();
        }
        memset(place,0,sizeof(place));
        cnt=0;
        num=0;
        DFS(0);
        printf("%d\n",cnt);
    }
    return 0;
}
