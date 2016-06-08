#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 112345;

int arr[maxn];

int cal(int n,int V){
    int ret = 0;
    for(int i=0;i<n;i++){
        if(arr[i] <= V){
            V -= arr[i];
            ret++;
        }
    }
    return ret;
}

int main(){
    int T;
    scanf("%d",&T);
    int n,V;
    while(T-- && ~scanf("%d %d",&n,&V)){
        for(int i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
        sort(arr,arr+n);
        printf("%d\n",cal(n,V));
    }
    return 0;
}
