class Solution {
private:
    bool possible(int mid, vector<int>& nums, int p){
        int c=0;
        for(int i=1;i<nums.size();i++){
                if(nums[i] - nums[i-1]<=mid){
                    c+=1;
                    i+=1;
                }
        }
          
        return c>=p;
    }
public:
    int minimizeMax(vector<int>& nums, int p) {
        if(p==0) return 0;
        
        sort(nums.begin(), nums.end());
        int l = 0, r=nums.back();
        int ans=-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(possible(mid, nums, p)){
                ans=mid;
                r=mid-1;
            } else l=mid+1;
        }
        
        return ans;
    }
};