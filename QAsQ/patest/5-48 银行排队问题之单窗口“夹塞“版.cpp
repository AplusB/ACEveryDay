#include<bits/stdc++.h>
using namespace std;
#define LL long long

const int maxn = 11234;
map<string,int> cir;
queue<int> ord;
queue<int> que[maxn];
string inp[maxn];
int come[maxn],use[maxn];
int len;

void adder(int st){
    int k = cir[inp[st]];
    if(k!=0){
        if(que[k].empty()) ord.push(k);
        que[k].push(st);
    }
    else{
        ord.push(len);
        que[len].push(st);
        len++;
    }
}

vector<string> ans;
int main(){
    ios::sync_with_stdio(false);
    int n,m;
    cin>>n>>m;
    len = m+1;
    string name;
    for(int i=1;i<=m;i++){
        int k;
        cin>>k;
        while(k--){
            cin>>name;
            cir[name] = i;
        }
    }
    for(int i=0;i<n;i++){
        cin>>inp[i]>>come[i]>>use[i];
        use[i] = min(use[i],60);
    }
    int pos = 0, npeo = 0;
    int anw = 0,tim = 0;
    while(pos < n || ord.empty()==false){
        if(ord.empty()==false){
            int v = ord.front();
            int k = que[v].front();
            anw += (npeo -1)* use[k];
            tim += use[k];
            while(pos < n && come[pos] <= tim){
                adder(pos),npeo++;
                anw += tim - come[pos];
                pos++; 
            }
            npeo--;
            que[v].pop();
            if(que[v].empty()) ord.pop();
            ans.push_back(inp[k]);
        }
        else{
            tim = come[pos];
            adder(pos),npeo++;
            pos++;
        }
    }
    for(auto x : ans){
        cout<<x<<endl;
    }
    cout.setf(ios::fixed);
    cout<< setprecision(1) << (n == 0 ? 0 : (anw * 1.0 / n) ) <<endl;
    return 0;
}

