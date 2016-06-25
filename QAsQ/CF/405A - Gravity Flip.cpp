#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    scanf("%d",&n);
    vector<int> arr;
    int x;
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        arr.push_back(x);
    }
    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        printf(i<n-1?"%d ":"%d\n",arr[i]);
    }
    return 0;
}
