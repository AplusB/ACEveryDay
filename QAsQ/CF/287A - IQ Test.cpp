#include<bits/stdc++.h>
using namespace std;

char arr[10][10];

const int dx[4] = {0,0,1,1};
const int dy[4] = {0,1,0,1};

int cnt(int x,int y){
    int ret = 0;
    for(int d=0;d<4;d++){
        if(arr[x+dx[d]][y+dy[d]] == '.')
            ret++;
        else
            ret--;
    }
    return ret;
}

bool judge(){
    for(int i=1;i<4;i++){
        for(int j=1;j<4;j++){
            if(abs(cnt(i,j)) >= 2)
                return true;
        }
    }
    return false;
}

int main(){
    for(int i=1;i<=4;i++) scanf("%s",arr[i]+1);
    puts(judge()?"YES":"NO");
    return 0;
}

    
