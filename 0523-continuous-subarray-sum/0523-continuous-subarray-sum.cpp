class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int ps=0;
        
        for(int i=0;i<nums.size();i++){
            ps += nums[i];
            if(ps%k==0){
                if(i+1 >= 2){
                    return true;
                }
            }
            
            if(m.find(ps%k)!=m.end()){
                if(i - m[ps%k] >= 2){
                    return true;
                }
            } else {
                m[ps%k] = i;
            }
        }
        
        return false;
    }
};