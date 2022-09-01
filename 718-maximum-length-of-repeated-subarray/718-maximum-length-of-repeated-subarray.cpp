class Solution {
private:
    bool check(vector<int>& nums1, vector<int>& nums2, int k){
        unordered_set<int> st;
        int n1 = nums1.size(), n2=nums2.size();
        int base = 131, mod=1e9+9;
        long long h=1;
        
        for(int i=0;i<k-1;i++){
            h = (h*base);
            h = h%mod;
        }
        
        long long shash=0;
        for(int i=0;i<k;i++){
            shash = (shash*base + nums1[i]);
            shash = shash%mod;
        }
        
        for(int i=0;i<=(n1-k);i++){
            st.insert(shash);
            if(i<(n1-k)){
                shash = ((shash - nums1[i]*h)*base)%mod + nums1[i+k];
                if(shash<0) shash+=mod;
            }
        }
        
        shash=0;
        for(int i=0;i<k;i++){
            shash = (shash*base + nums2[i]);
            shash = shash%mod;
        }
        
        for(int i=0;i<=(n2-k);i++){
            if(st.find(shash)!=st.end()) return true;
            if(i<(n2-k)){
                shash = ((shash - nums2[i]*h)*base)%mod + nums2[i+k];
                if(shash<0) shash+=mod;
            }
        }
        
        return false;
    }
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int left=1, right=min(nums1.size(), nums2.size());
        int ans=0;
        
        while(left<=right){
            int mid = left + (right-left)/2;
            
            if(check(nums1, nums2, mid)){
                ans=mid;
                left=mid+1;
            } else right=mid-1;
        }
        
        return ans;
    }
};