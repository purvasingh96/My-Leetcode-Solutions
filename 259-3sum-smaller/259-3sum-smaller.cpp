class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        if(nums.size()==0) return 0;
        int count=0, n = nums.size();
        sort(nums.begin(), nums.end());
        
        for(int i=0;i<n-2;i++){
            int left = i+1, right=n-1;
            
            while(left<right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum < target){ 
                    count += (right-left);
                    left+=1;
                } else right-=1;
                
            }
        }
        
        return count;
    }
};