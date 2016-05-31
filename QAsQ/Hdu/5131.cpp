#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;

const int maxn = 210;

struct Peo{
    string name;
    int val;
    void init(){
        cin>>name>>val;
    }
};

Peo peo[maxn];

bool cmp(Peo a,Peo b){
    if(a.val != b.val){
        return a.val > b.val;
    }
    return a.name < b.name;
}

int getid(string name,int n){
    for(int i=0;i<n;i++){
        if(peo[i].name == name)
            return i;
    }
    return -1;
}

int v[maxn];
int valer[maxn];

void getv(int n){
    int cnt;
    for(int i=0;i<n;i++){
        if(i==0 || peo[i].val != peo[i-1].val){
            cnt = 1;
        }
        v[i] = cnt;
        cnt++;
    }
}

int main(){
    int n;
    while(cin>>n && n){
        for(int i=0;i<n;i++){
            peo[i].init();
        }
        sort(peo,peo+n,cmp);
        getv(n);
        for(int i=0;i<n;i++){
            cout<<peo[i].name<<" "<<peo[i].val<<endl;
        }
        int m;
        cin>>m;
        string name;
        while(m--){
            cin>>name;
            int id = getid(name,n);
            cout<<id+2-v[id];
            if(v[id] != 1){
                cout<<" "<<v[id];
            }
            cout<<endl;
        }
    }
    return 0;
}
