class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int prefixSum =0, ans=0;
        
        for(int i=0;i<nums.size();i++){
            prefixSum += nums[i];
            if(prefixSum == k) ans+=1;
            
            int target = prefixSum - k;
            
            if(m.find(target)!=m.end()){
                ans += m[target];
            } 
            
            m[prefixSum]+=1;
        }
        
        return ans;
    }
};