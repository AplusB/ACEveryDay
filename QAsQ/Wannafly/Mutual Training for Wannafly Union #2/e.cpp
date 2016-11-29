#include<bits/stdc++.h>
using namespace std;

const int maxn = 112345;
int arr[maxn],ans[maxn];
map<int,int> gap;

int getans(int n){
    if(n == 1) return -1;
    for(int i = 1; i < n ; i ++){
        gap[arr[i] - arr[i-1]]++;
    }
    int ret = 0;
    if(gap.size() == 1){
        int v = gap.begin()->first;
        ans[ret++] = arr[0] - v;
        ans[ret++] = arr[n-1] + v;
        if(n == 2 && (arr[0] + arr[1]) % 2 == 0){
            ans[ret++] = (arr[0] + arr[1]) / 2;
        }
    }
    else if(gap.size() == 2){
        if(n == 3){
            if( (arr[1] - arr[0]) * 2 ==  arr[2] - arr[1]) ans[ret++] = (arr[2] + arr[1]) / 2;
            if( (arr[2] - arr[1]) * 2 ==  arr[1] - arr[0]) ans[ret++] = (arr[1] + arr[0]) / 2;
        }
        else{
            pair<int,int> va = *gap.begin(),vb = *gap.rbegin();
            if(va.second < vb.second) swap(va,vb);
            //printf("%d %d\n%d %d\n",va.first,va.second,vb.first,vb.second);
            if(vb.second == 1 && va.first  * 2 == vb.first ){
                for(int i = 1 ;i < n ; i ++){
                    if(arr[i] - arr[i-1] == vb.first){
                        ans[ret++] = (arr[i] + arr[i-1]) / 2;
                        break;
                    }
                }
            }
        }
    }
    sort(ans,ans+ret);
    ret = unique(ans,ans+ret) - ans;
    return ret;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i ++){
        scanf("%d",&arr[i]);
    }
    sort(arr,arr+n);
    int len = getans(n);
    if(len <= 0){
        printf("%d\n",len);
    }
    else{
        printf("%d\n",len);
        for(int i = 0 ; i < len ; i ++){
            printf(i < len - 1 ? "%d ":"%d\n",ans[i]);
        }
    }
    return 0;
}
