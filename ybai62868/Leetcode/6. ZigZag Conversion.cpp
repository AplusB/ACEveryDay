class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length(), diff = 2*numRows - 2, aux = diff;
        string ret="";
        if(n <= 1 || numRows <= 1) return s;
        for(int i=0;i<numRows;i++, aux -= 2){
            if(i == 0 || i + 1 == numRows){
                for(int j=i;j<n;j+=diff) ret += s[j];
            }else{
                for(int j=i, aux2=aux;j<n;j+=aux2, aux2=diff-aux2) ret += s[j];
            }
        }
        return ret;
    }
};
