#include<bits/stdc++.h>
using namespace std;

const double Pi = acos(-1.0);

int main(){
    int n,d;
    while(~scanf("%d %d",&n,&d)){
        int x;
        double sum = 0;
        while(n--){
            scanf("%d",&x);
            sum += sin(x * 2 * Pi / 360);
        }
        sum = sum * d * d * 0.5;
        printf("%.3f\n",sum);
    }
    return 0;
}
