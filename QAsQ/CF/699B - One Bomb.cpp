#include<bits/stdc++.h>
using namespace std;

const int maxn = 1123;

char Map[maxn][maxn];
int h[maxn],l[maxn];

void getans(int &x,int &y,int n,int m,int sum){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(h[i] + l[j] - (Map[i][j] == '*' ) == sum){
                x = i,y = j;
                return;
            }
        }
    }
    x = y = -1;
}

int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%s",Map[i]+1);
    }
    memset(h,0,sizeof(h));
    memset(l,0,sizeof(l));
    int sum = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(Map[i][j] == '*'){
                sum++;
                h[i]++,l[j]++;
            }
        }
    }
    int x,y;
    getans(x,y,n,m,sum);
    if(x == -1){
        puts("NO");
    }
    else{
        puts("YES");
        printf("%d %d\n",x,y);
    }
    return 0;
}

        

