class Solution {
private:
    void swap(int i, int j, vector<int>& nums){
        int t = nums[i];
        nums[i] = nums[j];
        nums[j] = t;
    }
public:
    void sortColors(vector<int>& nums) {
        int l=0, r=nums.size()-1;
        int i=0;
        
        while(i<=r){
            if(nums[i]==0){
                swap(l, i, nums);
                l+=1;
            } else if(nums[i] == 2){
                swap(r, i, nums);
                r-=1;
                i-=1;
            } 
            i+=1;
        }
        
        
    }
};