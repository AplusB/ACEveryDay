#include<bits/stdc++.h>
using namespace std;

const int maxn = 120;

int arr[maxn];

int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n;i++) cin>>arr[i];
    int v = arr[0];
    for(int i = 1;i<n;i++) v = __gcd(v,arr[i]);
    int siz = *max_element(arr,arr+n) / v - n;
    cout<<((siz&1)?"Alice":"Bob")<<endl;
    return 0;
}
