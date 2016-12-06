#include<bits/stdc++.h>
using namespace std;

const int maxn = 3123;
int arr[maxn];
int fnd(int x){
    return x == arr[x] ? x : arr[x] = fnd(arr[x]);
}
void join(int x,int y){
    x = fnd(x),y = fnd(y);
    if(x != y) arr[x] = y;
}

int st[maxn],ed[maxn],l[maxn],r[maxn];
int m;

bool check(int n,int L,int R){
    for(int i = 0 ; i <= n ; i ++) arr[i] = i; 
    for(int i = 0 ; i < m ; i ++){
        if(l[i] <= L && R <= r[i]){
            join(st[i],ed[i]);
        }
    }
    return fnd(1) == fnd(n);
}

int getans(int n,int x){
    int s = x,e = 1123456;
    int best = -1;
    while(s <= e){
        int mid = (s + e) / 2;
        if(check(n,x,mid)){
            best = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }
    return best == -1 ? 0 : best - x + 1;
}



int main(){
    int n;
    scanf("%d %d",&n,&m);
    for(int i = 0 ; i < m ; i ++) 
        scanf("%d %d %d %d",&st[i],&ed[i],&l[i],&r[i]);
    int ans = 0;
    for(int i = 0 ; i < m ; i ++){
        ans = max(ans,getans(n,l[i]));
    }
    if(ans==0) puts("Nice work, Dima!");
    else printf("%d\n",ans);
    return 0;
}
