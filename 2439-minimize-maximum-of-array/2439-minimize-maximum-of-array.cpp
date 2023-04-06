class Solution {
private:
    bool isPossible(int mid, vector<long long> nums){
        if(nums[0] > mid) return false;
       
        
        for(int i=nums.size()-1;i>=1;i--){
            if(nums[i]<=mid) continue;
            long long diff = nums[i] - mid;
            nums[i-1]+=diff;
        }
        
        return nums[0] <= mid;
    }
public:
    int minimizeArrayValue(vector<int>& nums) {
        int l = nums[0], r = *max_element(nums.begin(), nums.end());
        int ans;
        vector<long long> temp(nums.begin(), nums.end());
        while(l<=r){
            int mid = l + (r-l)/2;
            if(isPossible(mid, temp)){
                ans=mid;
                r=mid-1;
            } else {
                l = mid+1;
            }
        }
        return ans;
    }
};