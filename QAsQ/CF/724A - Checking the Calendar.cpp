#include<bits/stdc++.h>
using namespace std;

const int mon[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string wek[7] = {"monday", "tuesday", "wednesday", "thursday", "friday", "saturday", "sunday"};

int gid(string v){
    for(int i=0;i<7;i++){
        if(wek[i] == v) return i;
    }
    return -1;
}

bool check(int st,int ed){
    for(int i=0;i+1<12;i++){
        if((st+mon[i]) % 7 == ed) return true;
    }
    return false;
}

int main(){
    string st,ed;
    cin>>st>>ed;
    if(check(gid(st),gid(ed)))
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}

