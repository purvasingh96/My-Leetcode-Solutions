class Solution {
private:
    int feasible(int threshold, vector<int>& nums, int m){
        int total=0;
        int d=1;
        
        for(auto num:nums){
            total += num;
            if(total > threshold){
                total=num;
                d+=1;
                if(d>m) return false;
            }
        }
        
        return true;
    }
public:
    int splitArray(vector<int>& nums, int m) {
        int left = *max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);
        
        while(left<right){
            int mid = left + (right-left)/2;
            if(feasible(mid, nums, m)) right=mid;
            else left=mid+1;
        }
        
        return left;
    }
};