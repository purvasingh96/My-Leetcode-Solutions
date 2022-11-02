class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        m[0]=1;
        int pre=0, ans=0;
        
        for(int i=0;i<nums.size();i++){
            int next = pre+nums[i];
            if(m.find(next - k)!=m.end()) ans+=m[next - k];
            m[next]+=1;
            pre=next;
        }
        
        return ans;
        
    }
};