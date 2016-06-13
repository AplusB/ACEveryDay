//set一下，若type == 1，则上线，判断达到K个显示状态是否，是 删除第一个 ， 否 直接插入。 最后判断
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
set<int>s;
int a[200005];
int main(){
#ifdef _CONSOLE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int n, k, q;
    cin >> n >> k >> q;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
        
    while(q--){
        int type, id;
        cin >> type >> id;
        if(type == 1){
            s.insert(a[id]);
            if(s.size() > k)
                s.erase(s.begin());
        }
        else{
            if(s.find(a[id]) == s.end())
                puts("NO");
            else
                puts("YES");
        }
    }
}
