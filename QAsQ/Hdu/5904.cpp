#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn = 1123456;

int arr[maxn],brr[maxn];
int vrr[maxn],trr[maxn];

int main(){
    int T;
    scanf("%d",&T);
    int n,m;
    while(T-- && ~scanf("%d %d",&n,&m)){
        for(int i=0;i<n;i++){
            scanf("%d",&vrr[i]);
            brr[vrr[i]-1] = brr[vrr[i]] = arr[vrr[i]-1] = arr[vrr[i]] = 0;
        }
        for(int i=0;i<m;i++){
            scanf("%d",&trr[i]);
            brr[trr[i]-1] = brr[trr[i]] = arr[trr[i]-1] = arr[trr[i]] = 0;
        }
        for(int i=0;i<n;i++) arr[vrr[i]] = max(arr[vrr[i]],arr[vrr[i]-1]+1);
        int ans = 0;
        for(int i=0;i<m;i++){
            brr[trr[i]] = max(brr[trr[i]],brr[trr[i]-1]+1);
            ans = max(ans,min(arr[trr[i]],brr[trr[i]]));
        }
        printf("%d\n",ans);
    }
    return 0;
}
        
