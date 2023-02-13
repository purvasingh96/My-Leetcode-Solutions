class Solution {
private:
    bool isPossible(int val, vector<int>&nums, int k){
        int i=0;
        while(i<nums.size()){
            if(nums[i]<=val){
                i+=2;
                k-=1;
            } else{
                i+=1;
            }
            if(k==0) return true;
        }
        return false;
    }
public:
    int minCapability(vector<int>& nums, int k) {
        int l= *min_element(nums.begin(), nums.end());
        int r = *max_element(nums.begin(), nums.end());
        int ans=0;
        while(l<=r){
            int m = l+(r-l)/2;
            if(isPossible(m, nums, k)){
                ans = m;
                r=m-1;
            } else l=m+1;
        }
        
        return ans;
    }
};