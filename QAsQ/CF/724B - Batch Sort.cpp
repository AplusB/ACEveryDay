#include<bits/stdc++.h>
using namespace std;

const int maxn = 25;
int arr[maxn][maxn];
int n,m;

bool can(int *s){
    int ret = 0;
    for(int i=0;i<m;i++){
        ret += s[i] != i + 1;
    }
    return ret <= 2;
}

bool check(int sa,int sb){
    for(int i=0;i<n;i++) swap(arr[i][sa],arr[i][sb]);
    for(int i=0;i<n;i++){
        if(!can(arr[i])){
            for(int j=0;j<n;j++) swap(arr[j][sa],arr[j][sb]);
            return false;
        } 
    }
    return true;
}

bool judge(){
    for(int i=0;i<m;i++){
        for(int j=i;j<m;j++){
            if(check(i,j)) return true;
        }
    }
    return false;
}

int main(){
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    puts(judge()?"YES":"NO");
    return 0;
}

