class Solution {
public:
    vector<int> _nums;
    Solution(vector<int>& nums) {
        _nums = nums;
    }
    
    int pick(int target) {
        int ans=-1, count=0;
        for(int i=0;i<_nums.size();i++){
            if(_nums[i]!=target){
                continue;
            } else {
                if(count==0){
                    count+=1;
                    ans=i;
                } else {
                    count+=1;
                    if(rand()%count == 0){
                        ans = i;
                    }
                }
            }
        }
        
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */