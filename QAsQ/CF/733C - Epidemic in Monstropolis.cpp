#include<bits/stdc++.h>
using namespace std;

const int maxn = 51234;

int a[maxn],b[maxn],an,bn;
vector<pair<int,char> > ans;

bool cantac(int st,int ed,int pos){
    if(st == ed) return true;
    int por = -1,ma = 0;
    for(int i = st ; i < ed;i++){
        if(a[i] != a[i+1] && ma < (a[i] + a[i+1])){
            ma = a[i] + a[i+1];
            por = i;
        }
    }
    if(por == -1) return false;
    int lsiz = por - st,rsiz = ed - por - 1;
    int npos = por - st + pos;
    if(a[por] > a[por+1]){
        ans.push_back(make_pair(npos,'R'));
    }
    else{
        ans.push_back(make_pair(npos+1,'L'));
    }
    while(lsiz--){
        ans.push_back(make_pair(npos,'L'));
        npos--;
    }
    while(rsiz--){
        ans.push_back(make_pair(npos,'R'));
    }
    return true;
}

bool judge(){
    if(an < bn) return false;
    int tsum = 0;
    int pos = 1;
    int rst = 1;
    for(int i = 1 ;i <= an;i++){
        tsum+=a[i];
        if(tsum == b[pos]){
            if(!cantac(rst,i,pos)) return false;
            tsum = 0;
            rst = i+1;
            pos++;
        }
        else{
            if(tsum > b[pos]) return false;
        }
    }
    return pos == bn + 1;
}

int main(){
    scanf("%d",&an);
    for(int i = 1;i<=an;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&bn);
    for(int i = 1;i<=bn;i++){
        scanf("%d",&b[i]);
    }
    if(judge()){
        puts("YES");
        for(auto it : ans){
            printf("%d %c\n",it.first,it.second);
        }
    }
    else{
        puts("NO");
    }
    return 0;
}

