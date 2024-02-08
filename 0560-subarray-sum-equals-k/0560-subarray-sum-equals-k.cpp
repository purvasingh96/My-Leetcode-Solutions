class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        int sum=0, c=0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            
            if(sum == k) c+=1;
            if(m.find(sum - k)!=m.end()) {
                c += m[(sum-k)];
            }
            m[sum]+=1;
        }
        
        return c;
    }
};