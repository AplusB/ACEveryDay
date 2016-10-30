#include<bits/stdc++.h>
using namespace std;

const int maxn = 112345;

vector<pair<int,pair<char,int> > > ans;

pair<int,pair<char,int> > npair(int st,char c = 'E',int tim = 0){
    return make_pair(st,make_pair(c,tim));
}

void solve(int x,int y){
    if(x != 0){
        char c = x > 0 ? 'R' : 'L';
        ans.push_back(npair(1,c,abs(x)));
    }
    if(y != 0){
        char c = y > 0 ? 'U' : 'D';
        ans.push_back(npair(1,c,abs(y)));
    }
    ans.push_back(npair(2));
    if(y != 0){
        char c = y < 0 ? 'U' : 'D';
        ans.push_back(npair(1,c,abs(y)));
    }
    if(x != 0){
        char c = x < 0 ? 'R' : 'L';
        ans.push_back(npair(1,c,abs(x)));
    }
    ans.push_back(npair(3));
}

pair<int,int> brr[maxn];
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        scanf("%d %d",&brr[i].first,&brr[i].second);
    }
    sort(brr,brr+n,[](pair<int,int> a,pair<int,int> b){
                        if(abs(a.first) != abs(b.first)) return abs(a.first) < abs(b.first);
                        else return abs(a.second) < abs(b.second);});
    for(int i = 0;i < n;i++){
        solve(brr[i].first,brr[i].second);
    }
    printf("%d\n",ans.size());
    for(auto x : ans){
        if(x.first != 1){
            printf("%d\n",x.first);
        }
        else{
            printf("%d %d %c\n",x.first,x.second.second,x.second.first);
        }
    }
    return 0;
}
