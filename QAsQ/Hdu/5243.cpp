#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#define LL long long

using namespace std;

double bn[5][5],x[5],y[5];
int kr;
int n,m;

int vis[5][5][5][5];

bool cro(int i,int j,int k,int l){
    if(i == 2 && j == 2)
        return false;
    if(i != 2 && j != 2){
        return i == k || j == l;
    }
    if(i != 2){
        return i == k;
    }
    if(j != 2){
        return j == l;
    }
}


double caler(int X,int Y){
    x[0] = X-1;
    x[1] = 1;
    x[2] = n - X;
    y[0] = Y-1;
    y[1] = 1;
    y[2] = m-Y;
    for(int i =0;i<3;i++){
        for(int j=0;j<3;j++){
            bn[i][j] = x[i] * y[j];
        }
    }
    double fm = n * m;
    fm *= fm;
    double fz = 0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            double mid = 0;
            for(int k=0;k<3;k++){
                for(int l=0;l<3;l++){
                    if(vis[i][j][k][l]){
                        mid += bn[k][l];
                    }
                }
            }
            fz += bn[i][j] * mid;
        }
    }
    double ans = fz;
    ans /= fm;
    double r = 1;
    for(int i=0;i<kr;i++){
        r *= ans;
    }
    return 1-r;
}

int main(){
    int T;
    for(int i=0;i<3;++i)
        for(int j=0;j<3;++j)
    for(int k=0;k<3;k++){
        for(int l=0;l<3;l++){
            if(cro(i+1,j+1,k+1,l+1)){
                vis[i][j][k][l] = true;
            }
            else{
                vis[i][j][k][l] = false;
            }
        }
    }
    scanf("%d",&T);
    int icase = 1;
    while(T-- && ~scanf("%d %d %d",&n,&m,&kr)){
        double ans = 0;
        for(int i=1;i<=n/2;i++){
            for(int j=1;j<=m/2;j++){
                ans += caler(i,j);
            }
        }
        ans *= 4;
        if(n%2){
            for(int j=1;j<=m;j++){
                ans += caler(n/2+1,j);
            }
        }
        if(m%2){
            for(int i=1;i<=n;i++){
                ans += caler(i,m/2+1);
            }
        }
        if(n%2 && m%2){
            ans -= caler(n/2+1,m/2+1);
        }
        printf("Case #%d: %.f\n",icase++,ans);
    }
    return 0;
}
