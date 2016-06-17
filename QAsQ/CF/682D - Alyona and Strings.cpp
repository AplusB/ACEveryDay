#include<cstdio>
#include<set>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
#define LL long long 

const int maxn = 1123;

char a[maxn],b[maxn];
int g[maxn][maxn],s[maxn][maxn][15],f[maxn][maxn][15];

int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    scanf("%s %s",a+1,b+1);
    memset(g,0,sizeof(g));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i] == b[j])
                g[i][j] = g[i-1][j-1]+1;
        }
    }
    memset(s,0,sizeof(s));
    memset(f,0,sizeof(f));
    for(int l=1;l<=k;l++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                f[i][j][l] = s[i-g[i][j]][j-g[i][j]][l-1]+g[i][j];
                s[i][j][l] = max(s[i-1][j][l],s[i][j-1][l]);
                s[i][j][l] = max(s[i][j][l],f[i][j][l]);
            }
        }
    }
    printf("%d\n",s[n][m][k]);
    return 0;
}

