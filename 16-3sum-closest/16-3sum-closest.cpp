class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(), nums.end());
        int n =nums.size();
        int diff=INT_MAX;
        int ans;
        
        for(int i=0;i<n;i++){
            if(i!=0 && nums[i] == nums[i-1]) continue;
            
            int left = i+1, right=n-1;
            
            while(left<right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum == target) return target;
                
                else if(sum < target){
                    if(abs(target - sum) < diff) {
                        diff = abs(target - sum);
                        ans = sum;
                    }
                    left += 1;
                } else {
                    if(abs(target - sum) < diff){
                        diff = abs(target - sum);
                        ans = sum;
                    }
                    
                    right-=1;
                }
            }
            
            
        }
        
        return ans;
        
    }
};