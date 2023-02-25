class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left=0, right=0, ans=0;
        vector<int> count(2, 0);
        
        for(;right<nums.size();right++){
            count[nums[right]]+=1;
            
            if(count[0]>k){
                
                while(left<=right && count[0]>k){
                    count[nums[left]]-=1;
                    left+=1;
                }
                //cout<<ans<<" "; 
            }
            
            ans = max(ans, right-left+1);
        }
        
        return ans;
    }
};