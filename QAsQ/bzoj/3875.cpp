#include<bits/stdc++.h>
using namespace std;

const int maxn = 212345;
#define LL long long 

LL mag[maxn],spi[maxn];
LL amax[maxn],spmax[maxn];
bool vis[maxn];
vector<int> edge[maxn],redge[maxn];
queue<int> Q;

int main(){
    int n;
    scanf("%d",&n);
    int len,x;
    for(int i = 1;i <= n;i++){
        scanf("%lld %lld",&spi[i],&mag[i]);
        scanf("%d",&len);
        while(len--){
            scanf("%d",&x);
            redge[i].push_back(x);
            edge[x].push_back(i);
        }
    }
    for(int i = 1;i <= n;i++){
        amax[i] = mag[i];
        spmax[i] = spi[i];
        for(vector<int>::iterator it = redge[i].begin();it != redge[i].end();it++){ int x = *it;
            spmax[i] += mag[x];
        }
        Q.push(i);
        vis[i] = true;
    }
    //for(int i = 1; i <= n;i++) printf("%lld %lld\n",amax[i],spmax[i]);

    while(Q.empty()==false){
        int st = Q.front();
        Q.pop();
        vis[st] = false;
        if(amax[st] <= spmax[st]) continue;
        for(vector<int>::iterator it = edge[st].begin();it != edge[st].end();it++){ int x = *it;
            spmax[x] -= amax[st] - spmax[st];
            if(vis[x] == false)
                vis[x] = true,Q.push(x);
        }
        amax[st] = spmax[st];
    }
    //for(int i = 1; i <= n;i++) printf("%lld _ %lld\n",amax[i],spmax[i]);
    printf("%lld\n",amax[1]);
    return 0;
}

