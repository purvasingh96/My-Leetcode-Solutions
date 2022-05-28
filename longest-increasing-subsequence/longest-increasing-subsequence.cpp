class Solution {
private:
    int binarySearch(vector<int> sub, int target){
        int left=0, right=sub.size()-1;
        
        while(left<right){
            int mid = left+(right-left)/2;
            
            if(sub[mid] == target) return mid;
            else if(sub[mid] < target) left=mid+1;
            else right=mid;
        }
        
        return left;
    }
    
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        sub.push_back(nums[0]);
        
        for(int i=1;i<nums.size();i++){
            if(nums[i] > sub.back()){
                sub.push_back(nums[i]);
            } else{
                int j = binarySearch(sub, nums[i]);
                sub[j]=nums[i];
            }
        }
        
        return sub.size();
        
    }
};