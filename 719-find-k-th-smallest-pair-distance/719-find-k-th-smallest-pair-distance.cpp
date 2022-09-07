class Solution {
private:
    int feasible(int threshold, vector<int>& nums, int k){
        int i=0, j=0, count=0;
        int n = nums.size();
        while(i<n || j<n){
            while(j<n && nums[j] - nums[i] <= threshold){
                j+=1;
            }
            count+= (j-i-1);
            i+=1;
        }
        return count>=k;
    }
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left=0, right=(nums.back() - nums[0]);
        
        while(left<right){
            int mid = left + (right-left)/2;
            if(feasible(mid, nums, k)){
                right=mid;
            } else left=mid+1;
        }
        return left;
    }
};