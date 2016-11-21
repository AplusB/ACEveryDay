#include<bits/stdc++.h>
using namespace std;

bool judge(string a){
    string rev = a;
    reverse(a.begin(),a.end());
    return a == rev;
}

string cal(string v){
    for(int i = 0; i < v.size();i++){
        for(char c = 'a';c <= 'z'; c++){
        if(judge(v.substr(0,i) + string(1,c) + v.substr(i,v.size())))
            return v.substr(0,i) + string(1,c) + v.substr(i,v.size());
        }
    }
    for(char c = 'a';c <= 'z';c++) if(judge(v + string(1,c))) return v + string(1,c);
    return "NA";
}

int main(){
    string inp;
    cin>>inp;
    cout<<cal(inp)<<endl;
    return 0;
}
