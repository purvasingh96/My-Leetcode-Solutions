class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        int diff =INT_MAX;
        
        for(int i=0;i<n-1;i++){
            int low=i+1, high=n-1;
            
            
            while(low<high){
                int sum = nums[i] + nums[low] + nums[high];
                
                if(abs(target-sum) < abs(diff)){
                    diff = target - sum;
                }
                int s1 = nums[i]+nums[low]+nums[high-1];
                int s2 = nums[i]+nums[low+1]+nums[high];
                
                if(abs(target-s1)<=abs(target-s2)){
                    high-=1;
                } else low+=1;
            }
            //cout<<"i: "<<i<<"diff: "<<diff<<"\n";
        }
        
        return target-diff;
    }
};