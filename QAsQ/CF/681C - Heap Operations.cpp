#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<functional>
using namespace std;

priority_queue<int,vector<int>,greater<int> > Q;
vector<pair<string,int> > ans;

int main(){
    int n;
    ios::sync_with_stdio(false);
    cin>>n;
    string ord;
    int x;
    string ins = "insert",rem = "removeMin",get = "getMin";
    while(n--){
        cin>>ord;
        if(ord != rem){
            cin>>x;
        }
        if(ord == ins){
            ans.push_back(make_pair(ins,x));
            Q.push(x);
        }
        else if(ord == rem){
            if(Q.empty()){
                ans.push_back(make_pair(ins,1));
                Q.push(1);
            }
            ans.push_back(make_pair(rem,0));
            Q.pop();
        }
        else{
            while(Q.empty()==false && Q.top() < x){
                ans.push_back(make_pair(rem,0));
                Q.pop();
            }
            if(Q.empty() || Q.top() > x){
                ans.push_back(make_pair(ins,x));
                Q.push(x);
            }
            ans.push_back(make_pair(get,x));
        }
    }
    cout<<ans.size()<<endl;
    for(auto v:ans){
        cout<<v.first;
        if(v.first != rem){
            cout<<" "<<v.second;
        }
        cout<<endl;
    }
    return 0;
}

