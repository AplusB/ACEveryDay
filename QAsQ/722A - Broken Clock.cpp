#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,h,m;
    scanf("%d",&n);
    scanf("%d:%d",&h,&m);
    if(n==12){
        if(h == 0) h = 1;
        if(h > 12){
            if(h % 10) h = h % 10;
            else h = 10;
        }
    }
    else{
        if(h > 23){
            h = h % 10;
        }
    }
    if(m > 59){
        m = m % 10;
    }
    printf("%02d:%02d",h,m);
    return 0;
}


