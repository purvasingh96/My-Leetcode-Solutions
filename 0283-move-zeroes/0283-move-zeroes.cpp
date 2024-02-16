class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        nums.insert(nums.begin(), 0);
        int zero, nonzero;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                zero=i;
                break;
            }
        }
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                nonzero=i;
                break;
            }
        }
        
        while(zero<nums.size() && nonzero<nums.size()){
            swap(nums[zero++], nums[nonzero++]);
            
            while(zero<nums.size() && nums[zero]!=0){
                zero+=1;
            }
            
            while(nonzero<nums.size() && nums[nonzero]==0){
                nonzero+=1;
            }
        }
        nums.pop_back();
        
    }
};