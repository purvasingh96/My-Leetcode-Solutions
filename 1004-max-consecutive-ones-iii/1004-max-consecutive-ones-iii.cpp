class Solution {
private:
    bool enough(vector<int>& nums, int k, int mid){
        vector<int> c(2, 0);
        
        for(int i=0;i<mid;i++){
            c[nums[i]]+=1;
        }
        
        if(c[1]+k >= mid) return true;
        
        int j=0;
        for(int i=mid;i<nums.size();i++){
            c[nums[i]]+=1;
            c[nums[j]]-=1;
            j+=1;
            if(c[1]+k>=mid) return true;
        }
        
        return false;
    }
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right=nums.size();
        int ans=0;
        
        while(left<=right){
            int mid = left + (right-left)/2;
            int f = enough(nums, k, mid);
            //cout<<"mid: "<<mid<<" enough: "<<f<<"\n";
            
            if(f){
                ans=mid;
                left=mid+1;
            } else right=mid-1;
        }
        
        return ans;
    }
};