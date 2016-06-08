#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 35;
int arr[maxn];

int main(){
    int T;
    scanf("%d",&T);
    int n;
    while(T-- && ~scanf("%d",&n)){
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        sort(arr,arr+n);
        printf("%d\n",arr[n-1]);
    }
    return 0;
}
