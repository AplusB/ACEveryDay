#include<bits/stdc++.h>
using namespace std;

int cnt[5];

int cal(){
    int ret = 0;
    int mi = min(cnt[1],cnt[2]);
    ret += mi;
    cnt[1] -= mi,cnt[2] -= mi;
    cnt[3] += mi;
    if(cnt[1]){
        int add = cnt[1] / 3;
        ret += add * 2;
        cnt[3] += add;
        cnt[1] %= 3;
        if(cnt[1] == 1){
            if(cnt[3]){
                cnt[3]++,cnt[1]--;
                ret++;
            }
            else if(cnt[4] >= 2){
                cnt[4]-=2,cnt[1]--,cnt[3]++;
                ret += 2;
            }
            else return -1;
        }
        if(cnt[1] == 2){
            if(cnt[4] >= 1){
                cnt[4]--,cnt[1]-=2,cnt[3]+=2;
                ret+=2;
            }
            else if(cnt[3] >= 2){
                cnt[2] -= 2,cnt[3]-=2,cnt[4]+=2;
                ret += 2;
            }
            else{
                return -1;
            }
        }
    }
    //printf("%d %d %d %d %d",cnt[0],cnt[1],cnt[2],cnt[3],cnt[4]);
    if(cnt[2]){
        int add = cnt[2] / 3;
        ret += add * 2;
        cnt[3] += add * 2;
        cnt[2] %= 3;
        if(cnt[2] == 1){
            if(cnt[4] >= 1){
                cnt[4]--,cnt[2]--,cnt[3]++;
                ret++;
            }
            else if(cnt[3] >= 2){
                cnt[2] -= 2,cnt[3]-=2,cnt[4]+=2;
                ret += 2;
            }
            else{
                return -1;
            }
        }
        else if(cnt[2] == 2){
            cnt[4]++,cnt[2] -= 2;
            ret += 2;
        }
    }
    return ret;
}

int main(){
    int n,x;
    scanf("%d",&n);
    memset(cnt,0,sizeof(cnt));
    while(n--){
        scanf("%d",&x);
        cnt[x]++;
    }
    printf("%d\n",cal());
    return 0;
}
