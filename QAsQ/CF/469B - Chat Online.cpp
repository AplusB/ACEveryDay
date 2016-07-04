#include<bits/stdc++.h>
using namespace std;
#define LL long long 
 
const int maxn = 100;
int a[maxn],b[maxn],c[maxn],d[maxn];
int xn,yn;

bool touch(int s,int e,int l,int r){
    return !( e<l || r<s);
}

bool judge(int st){
    for(int i=0;i<xn;i++){
        for(int j=0;j<yn;j++){
            if(touch(a[i],b[i],c[j]+st,d[j]+st))
                return true;
        }
    }
    return false;
}

int main(){
    int st,ed;
    scanf("%d %d %d %d",&xn,&yn,&st,&ed);
    for(int i=0;i<xn;i++){
        scanf("%d %d",&a[i],&b[i]);
    }
    for(int i=0;i<yn;i++){
        scanf("%d %d",&c[i],&d[i]);
    }
    int ans = 0;
    for(int i=st;i<=ed;i++){
        ans+=judge(i);
    }
    printf("%d\n",ans);
    return 0;
}
    
