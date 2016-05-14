#include<bits/stdc++.h>
using namespace std;
#define LL long long
const LL INFF = 0x3f3f3f3f3f3f3f3fll;

const int maxn = 512345;

LL arr[maxn];

LL calans(int n,LL k){
    LL sum = 0;
    for(int i=1;i<=n;i++){
        sum+=arr[i];
    }
    LL down = sum / n;
    LL up = down;
    if(sum%n)
        up++;
    sort(arr+1,arr+n+1);
    if(k == 0){
        return arr[n] - arr[1];
    }
    LL rd = down,ru = up;
    if(n == 2){
        LL ned = down - arr[1] + arr[2] - up;
        if(ned <= k){
            return ru - rd;
        }
        else{
            return arr[2]-k-(arr[1]+k);
        }
    }
    LL use = 0;
    for(int i=2;i<=n;i++){
        LL nu = (arr[i]-arr[i-1])*(i-1);
        if(use + nu < k)
            use += nu;
        else{
            rd = arr[i-1] + (k - use) / (i-1);
            break;
        }
    }
    use = 0;
    for(int i = n-1;i>=1;i--){
        LL nu = (arr[i+1]-arr[i]) * (n-i);
        if(use + nu < k){
            use += nu;
        }
        else{
            ru = arr[i+1] - (k-use)/(n-i);
            break;
        }
    }
    ru = max(ru,up);
    rd = min(rd,down);
    return ru - rd;
}

int main(){
    ios::sync_with_stdio(false);
    int n;
    LL k;
    cin>>n>>k;
    LL sum = 0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    cout<<calans(n,k)<<endl;
    return 0;
}
