#include<bits/stdc++.h>
using namespace std;

const int maxn = 3123;

int arr[maxn];

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++) scanf("%d",&arr[i]);
    int x = 0,all = n * ( n - 1 ) / 2;
    for(int i = 1; i <= n;i++){
        for(int j = i + 1; j <= n;j++){
            x += arr[i] > arr[j];
        }
    }
    printf("%d.000000\n", 2 * x - x % 2);
    return 0;
}

