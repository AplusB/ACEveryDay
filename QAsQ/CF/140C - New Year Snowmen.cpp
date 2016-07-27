#include<bits/stdc++.h>
using namespace std;

priority_queue<pair<int,int> > Q;
map<int,int> M;
struct node{
    int x,y,z;
    node(){}
    node(int a,int b,int c){
        x = max(a,max(b,c));
        z = min(a,min(b,c));
        y = a + b + c - x - z;
    }
    void out(){
        printf("%d %d %d\n",x,y,z);
    }
};

void inr(pair<int,int> x){
    x.first --;
    if(x.first){
        Q.push(x);
    }
}

vector<node> V;
int main(){
    int n,x;
    scanf("%d",&n);
    while(n--){
        scanf("%d",&x);
        M[x]++;
    }
    for(auto x : M){
        Q.push(make_pair(x.second,x.first));
    }
    while(Q.size() >= 3){
        auto p = Q.top();Q.pop();
        auto q = Q.top();Q.pop();
        auto r = Q.top();Q.pop();
        V.push_back(node(p.second,q.second,r.second));
        inr(p),inr(q),inr(r);
    }
    printf("%d\n",V.size());
    for(auto x : V){
        x.out();
    }
    return 0;
}
