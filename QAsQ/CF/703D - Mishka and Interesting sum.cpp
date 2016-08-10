#include<bits/stdc++.h>
using namespace std;

const int maxn = 1123456;
int arr[maxn];
int lowbit(int x){return x & -x;}
void upd(int x,int v){
    while(x < maxn){
        arr[x] ^= v;
        x += lowbit(x);
    }
}
int sum(int x){
    int ret = 0;
    while(x){
        ret ^= arr[x];
        x -= lowbit(x);
    }
    return ret;
}
map<int,int> last;
int inp[maxn],ans[maxn];

void upd(int pos){
    int & hav = last[inp[pos]];
    if(hav != 0) upd(hav,inp[pos]);
    upd(pos,inp[pos]);
    hav = pos; 
}

pair<int,pair<int,int> > que[maxn];
int main(){
    int n;
    scanf("%d",&n);
    arr[0] = 0;
    for(int i=1;i<=n;i++){
        scanf("%d",&inp[i]);
        arr[i] = arr[i-1] ^ inp[i];
    }
    int m;
    scanf("%d",&m);
    int l,r;
    for(int i=0;i<m;i++){
        scanf("%d %d",&l,&r);
        ans[i] = arr[r] ^ arr[l-1];
        que[i] = make_pair(r,make_pair(l,i));
    }
    sort(que,que+m);
    memset(arr,0,sizeof(arr));
    int pos = 1;
    for(int i=0;i<m;i++){
        while(pos <= que[i].first){
            upd(pos++);
        }
        ans[que[i].second.second] ^= sum(que[i].first) ^ sum(que[i].second.first-1);
    }
    for(int i=0;i<m;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}

