#include<bits/stdc++.h>
using namespace std;

int g[150];
int n = 100;

int main(){
    memset(g,0,sizeof(g));
    g[1] = 1;
    for(int i=1;i<=n;i++){
        for(int j=i+i;j<=n;j+=i){
            g[j] -= g[i];
        }
    }
    for(int i=1;i<=10;i++){
        printf(i<10?"%d ":"%d\n",g[i]);
    }
    return 0;
}
