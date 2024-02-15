class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int sum=0;
        
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(sum%k==0 && i>=1){
                return true;
            }
            int idx = sum%k;
            if(m.find(idx)!=m.end()){
                if(i - m[idx] >= 2){
                    return true;
                }
            } else {
                m[idx] = i;
            }
        }
        
        return false;
    }
};