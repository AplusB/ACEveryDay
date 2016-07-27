#include<bits/stdc++.h>
using namespace std;

const int maxn = 112345;
const double eps = 1e-8;

const double pi = acos(-1.0);
bool judge(int n,int R,int r){
    if(r > R) return false;
    if(r * 2 > R) return n <= 1;
    if(r * 2 == R) return n <= 2;
    double anc = asin(r * 1.0 / (R - r));
    return anc * n<= pi + eps;
}

int main(){
    int n,R,r;
    cin>>n>>R>>r;
    puts(judge(n,R,r)?"YES":"NO");
    return 0;
}
