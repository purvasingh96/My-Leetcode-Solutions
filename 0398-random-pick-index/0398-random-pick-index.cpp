class Solution {
public:
    vector<int> _nums;
    Solution(vector<int>& nums) {
        _nums = nums;
    }
    
    int pick(int target) {
        int sz=0, res=-1;
        
        for(int i=0;i<_nums.size();i++){
            
            if(_nums[i]!=target){
                continue;
            } else {
                sz+=1;
                if(res==-1){
                    res = i;
                } else {
                    if(rand()%sz==0){
                        res = i;
                    }
                }
            }
        }
        
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */