class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        bool found=false;
        
        for(int i=n-2;i>=0;i--){
            
            if(nums[i] < nums[i+1]) {
                
                for(int k=n-1;k>=i+1;k--) {
                    if(nums[k]>nums[i]){
                        swap(nums[i], nums[k]);
                        sort(nums.begin()+i+1, nums.end());
                        found=true;
                        return;
                    }
                }
                
                
            }
            
        }
        if(!found){
            sort(nums.begin(), nums.end());
            return;
        }
    }
};