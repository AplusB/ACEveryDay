#include<bits/stdc++.h>
using namespace std;
#define LL long long 

const int maxn = 112345;

int bel[maxn];
vector<int> arr,brr;
vector<int> edge[maxn];

void Link(int st,int ed){
    edge[st].push_back(ed);
}

bool dfs(int st,int v){
    bel[st] = v;
    for(auto x : edge[st]){
        if(bel[x]==0){
            if(dfs(x,-1*v) == false)
                return false;
        }
        else if(bel[x] * v != -1)
            return false;
    }
    return true;
}

bool judge(int n){
    for(int i=1;i<=n;i++){
        if(bel[i]==0)
           if(dfs(i,1)==false){
                return false;
        }
    }
    return true;
}

int main(){
    int n,m;
    memset(bel,0,sizeof(bel));
    scanf("%d %d",&n,&m);
    int st,ed;
    while(m--){
        scanf("%d %d",&st,&ed);
        Link(st,ed);
        Link(ed,st);
    }
    if(judge(n)==false){
        puts("-1");
    }
    else{
        arr.clear();
        brr.clear();
        for(int i=1;i<=n;i++){
            if(bel[i] == 1){
               arr.push_back(i);
            }
            else{
               brr.push_back(i);
            }
        }
        printf("%d\n",arr.size());
        for(int i=0;i<arr.size();i++){
            printf(i<arr.size()-1?"%d ":"%d\n",arr[i]);
        }
        printf("%d\n",brr.size());
        for(int i=0;i<brr.size();i++){
            printf(i<brr.size()-1?"%d ":"%d\n",brr[i]);
        }
    }
    return 0;
}
        





