#include<bits/stdc++.h>
using namespace std;

int lb(int x){
    return x & (-x);
}

int len(int x){
    int ret = -1;
    while(x){
        ret++;
        x >>= 1;
    }
    return ret;
}

const int maxn = 112345;

vector<int> adder[32];

int main(){
    int sum,limit;
    for(int i=0;i<32;i++){
        adder[i].clear();
    }
    cin>>sum>>limit;
    int hug = 0;
    int rs = 0;
    for(int i=1;i<=limit;i++){
        hug = max(hug,len(lb(i)));
        adder[len(lb(i))].push_back(i);
        rs += lb(i);
    }
    if(rs < sum){
        puts("-1");
    }
    else{
        vector<int> ans;
        while(sum > 0 && hug>=0){
            for(auto x:adder[hug]){
                if(sum < (1<<hug)) break;
                sum -= 1<<hug;
                ans.push_back(x);
            }
            hug--;
        }
        printf("%d\n",ans.size());
        for(int i=0;i<ans.size();i++){
            printf(i<ans.size()-1?"%d ":"%d\n",ans[i]);
        }
    }
    return 0;
}
