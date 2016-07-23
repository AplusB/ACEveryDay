#include<bits/stdc++.h>
using namespace std;

#define LL long long
const double eps = 1e-8;
double l,v1,v2;
int n,k;
int p;

bool check(double tim){
    double t = l - tim * v1;
    t /= v2 - v1;
    double all = t * p;
    double rev = (v2 - v1) * t / (v2 + v1);
    return all + rev * (p-1) <= tim;
}

double judge(){
    double ed= l * 1.0 / v1;
    double st= l * 1.0 / v2;
    int t = 10000;
    while(t--){
        double mid = (st + ed)/2;
        if(check(mid)){
            ed = mid;
        }
        else{
            st = mid;
        }
    }
    return st;
}

int main(){
    cin>>n>>l>>v1>>v2>>k;
    p = n / k + (n%k!=0);
    printf("%.10f\n",judge());
}
