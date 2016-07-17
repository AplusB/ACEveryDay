#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
#define LL long long

const int maxn = 112345;

LL arr[maxn];
pair<LL,LL> seg[maxn];

int main(){
    int n;
    LL L,R;
    int T;
    scanf("%d",&T);
    while(T-- && ~scanf("%d %I64d %I64d",&n,&L,&R)){
        for(int i=0;i<n;i++){
            scanf("%I64d",&arr[i]);
        }
        sort(arr,arr+n);
        int len = 0;
        for(int i=1;i<n;i++){
            seg[len++] = make_pair(max(L,arr[i] - arr[i-1]  + 1),min(R,arr[i] + arr[i-1]  - 1));
            if(seg[len-1].first > seg[len-1].second)
                len--;
        }
        sort(seg,seg+len);
        LL temp = 0;
        LL st=seg[0].first;
        LL ed=seg[0].second;
        for(int i=1;i<len;i++){
            if(seg[i].first > ed){
                temp += ed - st + 1;
                st = seg[i].first;
                ed = seg[i].second;
            }
            else{
                ed = max(ed,seg[i].second);
            }
        }
        if(len)
            temp += ed - st + 1;
        printf("%I64d\n",R - L + 1 - temp);
    }
    return 0;
}
