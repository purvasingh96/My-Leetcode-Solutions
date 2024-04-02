class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int n) {
        int c=0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                bool emptyLeft = i==0 || nums[i-1]==0;
                bool emptyRight = i==nums.size()-1 || nums[i+1]==0;

                if(emptyLeft && emptyRight){
                    c+=1;
                    nums[i]=1;
                    if(c>=n){
                        return true;
                    }
                }
            }
            
        }
        
        return c>=n;
    }
};