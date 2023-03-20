class Solution {
public:
    bool canPlaceFlowers(vector<int>& nums, int n) {
        vector<int> temp = {0};
        temp.insert(temp.end(), nums.begin(), nums.end());
        temp.push_back(0);
        nums = temp;
        
        
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i-1] == nums[i] && nums[i] == nums[i+1] && nums[i+1]==0){
                n-=1;
                nums[i]=1;
            }
            if(n<=0) return true;
        }
        
        return n<=0;
        
    }
};