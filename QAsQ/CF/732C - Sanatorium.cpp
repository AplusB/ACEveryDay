#include<bits/stdc++.h>
using namespace std;
#define LL long long 

LL cal(LL x,LL y,LL z){
    LL ans = max(x,max(y,z)) * 3 - x - y - z;
    LL v[3];
    for(int st = 0;st < 4;st ++){
        for(int ed = 0;ed < 4;ed++){
            v[0] = x,v[1] = y,v[2] = z;
            for(int i = st;i<3;i++) v[i]--;
            for(int i = 0;i<ed;i++) v[i]--;
            if(v[0] >= 0 && v[1] >= 0 && v[2] >= 0){
                LL ma = max(v[0],max(v[1],v[2]));
                ans = min(ans,ma * 3 - v[0]-v[1]-v[2]);
            }
            if(st < ed){
                v[0] = x,v[1] = y,v[2] = z;
                for(int i = st ;i < ed;i++) v[i] --;
                if(v[0] >= 0 && v[1] >= 0 && v[2] >= 0){
                    LL ma = max(v[0],max(v[1],v[2]));
                    ans = min(ans,ma * 3 - v[0]-v[1]-v[2]);
                }
            }
        }
    }
    return ans;
}

int main(){
    LL x,y,z;
    cin>>x>>y>>z;
    cout<<cal(x,y,z);
    return 0;
}
