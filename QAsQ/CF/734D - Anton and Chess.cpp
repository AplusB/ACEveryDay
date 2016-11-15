#include<bits/stdc++.h>
using namespace std;

const int maxn = 512345;

#define LL long long 
LL a,b;

struct pic{
    LL x,y;
    char typ;
    void input(){
        cin>>typ;
        cin>>x>>y;
        x -= a, y -= b;
    }
    LL v(){
        return abs(x) + abs(y);
    }
    bool is(char c){
        return typ == 'Q' || typ == c;
    }
}arr[maxn];

bool lr[2],ud[2],dir[4];

bool check(int n){
    sort(arr,arr+n,[](pic a,pic b){return a.v() < b.v();});
    lr[0] = lr[1] = ud[0] = ud[1] = dir[0] = dir[1] = dir[2] = dir[3] = false;
    for(int i = 0 ; i < n ;i ++){
        if(arr[i].x == 0){
            if(arr[i].is('R') && ud[arr[i].y > 0] == false) return true;
            else ud[arr[i].y > 0] = true;
        }
        if(arr[i].y == 0){
            if(arr[i].is('R') && lr[arr[i].x > 0] == false) return true;
            else lr[arr[i].x > 0] = true;
        }
        if(abs(arr[i].x) == abs(arr[i].y)){
            int way = (arr[i].x > 0 ) * 2 + (arr[i].y > 0);
            if(arr[i].is('B') && dir[way] == false) return true;
            else dir[way] = true;
        }
    }
    return false;
}

int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    cin>>a>>b;
    for(int i = 0 ; i < n; i ++){
        arr[i].input();
    }
    cout<<(check(n)?"YES":"NO")<<endl;
    return 0;
}
