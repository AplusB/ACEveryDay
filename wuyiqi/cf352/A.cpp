#include <bits/stdc++.h>

using namespace std;

int main() 
{
        string ret = "";
        for(int i = 1; ; i++) {
                int num = i;
                string tmp="";
                for(;num;num/=10) tmp += num%10 + '0';
                reverse(tmp.begin(), tmp.end());
                ret += tmp;
                if(ret.length() > 1000) break;
        }
        int n;
        cin >> n;
        cout << ret[n-1] << endl;
        return 0;
}
