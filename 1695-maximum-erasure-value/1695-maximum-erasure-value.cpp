class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        // sliding window
        int left=0, right=0, ans=INT_MIN, sum=0;
        int n = nums.size();
        map<int, int> m;
        
        for(int right=0;right<n;right++){
            sum += nums[right];
            m[nums[right]]+=1;
            
            while(left<right && m[nums[right]]>1){
                m[nums[left]]-=1;
                sum -= nums[left];
                left+=1;
            }
            
            ans = max(ans, sum);
        }
        
        return ans;
    }
};