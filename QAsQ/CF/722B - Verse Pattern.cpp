#include<bits/stdc++.h>
using namespace std;

char ei[]="aeiouy";

bool check(char c){
    for(int i=0;ei[i];i++)
        if(c == ei[i]) return true;
    return false;
}

int cnt(string v){
    int ret = 0;
    for(auto x : v){
        ret += check(x);
    }
    return ret;
}

int arr[1123];

int main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>arr[i];
    string v;
    getline(cin,v);
    bool flag = false;
    for(int i=0;i<n;i++){
        getline(cin,v);
        if(cnt(v) != arr[i]){
            flag = true;
        }
    }
    if(flag)
        cout<<"NO";
    else
        cout<<"YES";
    return 0;

}
