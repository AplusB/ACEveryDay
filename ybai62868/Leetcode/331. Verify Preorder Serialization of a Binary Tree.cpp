class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<char> stk;
        bool isNum = false;
        preorder.push_back(','); // dummy tail

        for(auto c: preorder){
            if(c == '#'){
                // absorb: search for pattern `#, number` backward
                while(!stk.empty() && stk.top() == '#'){ 
                    stk.pop(); // pop `#`
                    if(stk.empty() || stk.top() == '#') return false; // pattern `#,#,#`
                    stk.pop(); // pop `number`
                }
                stk.push('#'); // replace `number` with `#` since it has been fully explored/validated
            }else if(c == ','){
                if(isNum) stk.push('n'); // indicate this is a number instead of using the real number
                isNum = false;
            }else{
                isNum = true;
            }
        }

        return stk.size() == 1 && stk.top() == '#';
    }
};
