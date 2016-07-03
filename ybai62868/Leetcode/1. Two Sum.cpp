//O(n^2)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>res;
        int len = nums.size();
        int flag = 0;
        if ( len <= 1 ) return res;
        for ( int i = 0;i < len-1;i++ ){
            for ( int j = i+1;j < len;j++ ){
                if ( nums[i]+nums[j]==target ){
                    res.push_back(i);
                    res.push_back(j);
                    flag = 1;
                    break;
                }
            }
            if ( flag ) break;
        }
        return res;
    }
};


//O(n)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>res;
        int len = nums.size();
        if ( len <= 1 ) return res;
        map<int,int>MP;
        for ( int i = 0;i < len;i++ ){
            if ( MP.count(target-nums[i]) ){
                res.push_back(i);
                res.push_back(MP[target-nums[i]]);
               // res.push_back(i);
            }
            else{
                MP[nums[i]] = i;
            }
        }
        return res;
    }
};
