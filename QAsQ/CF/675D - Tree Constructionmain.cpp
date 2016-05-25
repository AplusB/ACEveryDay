#include<bits/stdc++.h>
using namespace std;

set<pair<int,int> > S;
set<pair<int,int> >::iterator it;

int main(){
    int n;
    cin>>n;
    int x;
    S.clear();
    for(int i=1;i<=n;i++){
        cin>>x;
        S.insert(make_pair(x,i));
        if(i!=1){
            it = S.find(make_pair(x,i));
            int st = -1,ed = -1;
            int sx,sy;
            if(it!=S.begin()){
                it--;
                st = it->second;
                sx = it->first;
                it++;
            }
            it++;
            if(it!=S.end()){
                ed = it->second;
                sy = it->first;
            }
            int ans;
            if(st!=-1 && ed!=-1){
                if(st > ed){
                    ans = sx;
                }
                else{
                    ans = sy;
                }
            }
            else{
                 if(st == -1){
                    ans = sy;
                 }
                 else{
                    ans = sx;
                 }
            }
            cout<<ans;
            if(i!=n){
                cout<<" ";
            }
        }
    }
    cout<<endl;
    return 0;
}


