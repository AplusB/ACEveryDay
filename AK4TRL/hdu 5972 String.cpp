//*直接一个尺取法暴力出结果
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
int T,k,H[300];
char s[1000005];
int main(){
#ifdef ak4trl
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    scanf("%d",&T);
    while(T--) {
        scanf("%s%d",s+1,&k);
        int n = strlen(s+1);
        memset(H,0,sizeof(H));
        int  r = 0,cnt = 0;
        ll ans = 0 ;
        for(int l = 1;l<=n;l++) {
            while(cnt<k&&r<n) {
                ++r;
                if(++H[s[r]]==1) cnt++;
            }
            if(cnt<k) break;
            ans = ans+n-r+1;
            if(--H[s[l]] == 0) --cnt;
        }
        cout<<ans<<endl;
    }

    return 0;
}
