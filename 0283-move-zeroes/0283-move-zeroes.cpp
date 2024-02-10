class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        nums.insert(nums.begin(), 0);
        int i=0, j=0;
        while(j<nums.size()){
            if(nums[j]!=0){
                if(nums[i]==0){
                    swap(nums[i], nums[j]);
                    while(i<j && nums[i]!=0){
                        i+=1;
                    }
                }
            }
            
            j+=1;
        }
        nums.pop_back();
    }
};