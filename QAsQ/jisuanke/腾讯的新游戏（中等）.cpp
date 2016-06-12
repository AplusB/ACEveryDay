#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1010;

vector<int> node[maxn];

int callow(int st){
    int ret = 0;
    int now = 0;
    for(auto x : node[st]){
        if(now >= x){
            now++;
        }
        else{
            ret += x - now;
            now = x+1;
        }
    }
    return ret;
}
int low[maxn];

void swaper(int x,int a,int y,int b){
    vector<int> tx,ty;
    for(int i=0;i<a;i++){
        tx.push_back(node[x][i]);
    }
    for(int i=0;i<b;i++){
        ty.push_back(node[y][i]);
    }
    node[x].erase(node[x].begin(),node[x].begin()+a);
    node[y].erase(node[y].begin(),node[y].begin()+b);
    for(int i=a-1;i>=0;i--){
        node[y].insert(node[y].begin(),tx[i]);
    }
    for(int i=b-1;i>=0;i--){
        node[x].insert(node[x].begin(),ty[i]);
    }
    low[x] = callow(x);
    low[y] = callow(y);
}

struct nodes{
    int many;
    int lower;
};
nodes arr[maxn];



int getans(int n){
    for(int i=0;i<n;i++){
        arr[i].many = node[i].size();
        arr[i].lower = low[i];
    }
    sort(arr,arr+n,[](nodes a,nodes b){return a.lower < b.lower;});
    int ret = 0;
    int now = 0;
    for(int i=0;i<n;i++){
        if(now >= arr[i].lower){
            now+=arr[i].many;
        }
        else{
            ret += arr[i].lower - now;
            now = arr[i].lower+arr[i].many;
        }
    }
    return ret;
}

int main(){
    int n;
    while(~scanf("%d",&n)){
        int len,x;
        for(int i=0;i<n;i++){
            node[i].clear();
        }
        for(int i=0;i<n;i++){
            scanf("%d",&len);
            while(len--){
                scanf("%d",&x);
                node[i].push_back(x);
            }
        }
        for(int i=0;i<n;i++){
            low[i] = callow(i);
        }
        scanf("%d",&len);
        while(len--){
            int y,a,b;
            scanf("%d %d %d %d",&x,&a,&y,&b);
            x--,y--;
            swaper(x,a,y,b);
            printf("%d\n",getans(n));
        }
    }
    return 0;
}
