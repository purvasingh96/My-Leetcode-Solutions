class Solution {

public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // O(N) // every step 
        map<int, int> m;
        int prefixSum =0, n = nums.size(), ans=INT_MAX;
        
        for(int right=0;right<n;right++){
            prefixSum += nums[right];
            
            if(prefixSum >= target){
                auto it = m.upper_bound(prefixSum-target);
                if(it!=m.begin()){
                    ans = min(ans, (right - prev(it)->second));
                } else {
                    ans = min(ans, right+1);
                }
            }
            
            m[prefixSum] = right;
        }
        
        return ans==INT_MAX?0:ans;
    }
};