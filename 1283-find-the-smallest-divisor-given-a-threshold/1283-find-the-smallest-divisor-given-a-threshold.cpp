class Solution {
private:
    bool feasible(int mid, vector<int>& nums, int threshold){
        int sum=0;
        for(auto x:nums){
            sum += ((x-1)/mid)+1;
            if(sum > threshold) return false;
        }
        cout<<"\n";
        return true;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left=1, right = *max_element(nums.begin(), nums.end());
        
        while(left<right){
            int mid = left + (right-left)/2;
            if(feasible(mid, nums, threshold)) right=mid;
            else left=mid+1;
        }
        
        return left;
    }
};