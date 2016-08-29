#include<bits/stdc++.h>
using namespace std;

const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,-1,0,1};
const int maxn = 150;

char Map[maxn][maxn];

bool che(int x,int y){
    int cnt = 0;
    for(int d = 0;d < 4;d++)
        cnt += Map[x + dx[d]][y + dy[d]] == 'o';
    return cnt % 2 == 0;
}

bool check(int n,int m){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(che(i,j) == false) return false;
        }
    }
    return true;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s",Map[i]+1);
    }
    puts(check(n,n)?"YES":"NO");
    return 0;
}



