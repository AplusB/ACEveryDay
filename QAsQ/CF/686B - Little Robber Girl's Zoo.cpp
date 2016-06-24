#include<bits/stdc++.h>
using namespace std;
#define LL long long 

const int maxn = 110;
int arr[maxn];

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=2;i<=n;i++){
        for(int j=n;j>=i;j--){
            if(arr[j] < arr[j-1]){
                swap(arr[j],arr[j-1]);
                cout<<j-1<<" "<<j<<endl;
            }
        }
    }
    return 0;
}
