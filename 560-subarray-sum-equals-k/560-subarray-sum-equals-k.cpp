class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> m;
        m[0] = 1;
        int sum=0, ans=0;
        
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(m.find((sum-k))!=m.end()){
                ans += m[(sum-k)];
            }
            m[sum] += 1;
        }
        
        return ans;
    }
};