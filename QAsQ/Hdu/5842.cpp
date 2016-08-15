#include<bits/stdc++.h>
using namespace std;

const int maxn = 112345;

char arr[maxn];
set<char> S;

int main(){
    int icase = 1;
    int T;
    scanf("%d",&T);
    while(T-- && ~scanf("%s",arr)){
        S.clear();
        for(int i=0;arr[i];i++)
            S.insert(arr[i]);
        printf("Case #%d: %d\n",icase++,S.size());
    }
    return 0;
}
