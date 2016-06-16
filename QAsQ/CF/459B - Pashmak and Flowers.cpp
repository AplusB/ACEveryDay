#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
#include<vector>
using namespace std;
#define LL long long 

const int maxn = 212345;
int arr[maxn];
map<int,LL> M;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        M[arr[i]]++;
    }
    sort(arr,arr+n);
    int ans = arr[n-1]-arr[0];
    LL cnt = M[arr[0]]*M[arr[n-1]];
    if(arr[n-1] == arr[0]){
        cnt = 1ll*n*(n-1)/2;
    }
    cout<<ans<<" "<<cnt<<endl;    
    return 0;
}

