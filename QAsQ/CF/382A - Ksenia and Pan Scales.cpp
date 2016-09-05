#include<bits/stdc++.h>
using namespace std;

string judge(string a,string b){
    int pos = a.find('|');
    string l = a.substr(0,pos);
    string r = a.substr(pos+1);
    for(auto c : b){
        if(l.size() < r.size())
            l = l + string(1,c);
        else
            r = r + string(1,c);
    }
    if(l.size() != r.size())
        return "";
    return l + "|" + r;
}

int main(){
    string a,b;
    cin>>a>>b;
    a = judge(a,b);
    if(a == "")
        cout<<"Impossible";
    else
        cout<<a<<endl;
    return 0;
}

    

