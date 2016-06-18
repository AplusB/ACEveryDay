#include <bits/stdc++.h>
using namespace std;

string vowel = "aeiouy";
int main()
{
        string s;
        cin >> s;
        int n = s.length();
        string ret="";
        for(int i = 0; i < n; i++)
        {
                if(s[i] >= 'A' && s[i] <= 'Z') {
                        s[i] += 'a' - 'A';
                }
                bool flag = false;
                for(int j = 0; j < vowel.length(); j++) {
                        if(s[i] == vowel[j]) {
                                flag = true;
                        }
                }
                if(!flag) ret += s[i];
        }
        for(int i = 0; i < ret.length(); i++) 
        {
                printf(".%c", ret[i]);
        }
        
        return 0;
}
