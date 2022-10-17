class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> nums(26, 0);
        for(auto c:sentence){
            nums[c-'a']+=1;
        }
        
        for(auto x:nums) if(x==0) return false;
        return true;
    }
};