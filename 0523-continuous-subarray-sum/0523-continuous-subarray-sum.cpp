class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        
        int sum=0;
        
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            
            // sum so far is the answer
            if(sum%k == 0 && i+1>=2) return true; 
            
            if(m.find(sum%k)!=m.end()){
                // length >=2 
                 if(i - m[sum%k] >=2){
                     return true;
                 }
            } else {
                // keeps farthest index in map
                m[sum%k]=i;    
            }
            
        }
        return false;
    }
};