#include<bits/stdc++.h>
using namespace std;

const int maxn = 112345;
#define LL long long 
char arr[maxn];

int check(int n,LL x,LL y){
    for(int i = 0 ; i < n ; i++){
        if(arr[i] == 'S' && y < 0) y++;    
        if(arr[i] == 'N' && y > 0) y--;    
        if(arr[i] == 'W' && x < 0) x++;    
        if(arr[i] == 'E' && x > 0) x--;    
        if(x == 0 && y == 0) return i + 1;
    }
    return -1;
}

int main(){
    ios::sync_with_stdio(false);
    int n;
    LL sx,sy,ex,ey;
    cin>>n;
    cin>>sx>>sy>>ex>>ey;
    cin>>arr;
    ex -= sx,ey -= sy;
    cout<<check(n,ex,ey)<<endl;
    return 0;
}
