#include<bits/stdc++.h>
using namespace std;
#define LL long long

int k,n;
bool check(int x,int y){
    int cnt = 0;
    for(int i=0;i<n;i++){
        cnt += x%2 != y%2;
        x /= 2,y /= 2;
    }
    return cnt <= k;
}

const int maxn = 1213;
int arr[maxn];

int main(){
    int m;
    cin>>n>>m>>k;
    for(int i=0;i<=m;i++){
        cin>>arr[i];
    }
    int ret = 0;
    for(int i=0;i<m;i++){
        ret += check(arr[m],arr[i]);
    }
    cout<<ret<<endl;
    return 0;
}



