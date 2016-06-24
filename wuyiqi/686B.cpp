#include <bits/stdc++.h>
using namespace std;

int a[110];
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j < i; j++) {
            if(a[j] > a[j+1]) {
                cout << j+1 << " " << j+2 << endl;
                swap(a[j], a[j + 1]);
            }
        }
    }
    return 0;
}
