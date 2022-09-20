class Solution {
private:
    bool isEnough(vector<int>& nums1, vector<int>& nums2, int k){
        unordered_set<long long> st;
        int base=131, mod=1e9+7;
        long long h=1;
        
        long long hash1=0, hash2=0;
        
        for(int i=0;i<k-1;i++){
            h=h*base;
            h=h%mod;
        }
        
        
        for(int i=0;i<k;i++){
            hash1 = hash1*base + nums1[i];
            hash1 = hash1%mod;
        }
        
        
        
        for(int i=0;i<=(nums1.size()-k);i++){
            st.insert(hash1);
            
            if(i<(nums1.size()-k)){
                hash1 = ((hash1 - h*nums1[i])*base)%mod + nums1[i+k];
                if(hash1<0) hash1 += mod;
            }
            
        }
        
        
        
        for(int i=0;i<k;i++){
            hash2 = hash2*base + nums2[i];
            hash2%=mod;
        }
        
        for(int i=0;i<=(nums2.size()-k);i++){
            if(st.find(hash2)!=st.end()){
                return true;
            }
            
            if(i<(nums2.size()-k)){
                hash2 = ((hash2 - h*nums2[i])*base)%mod + nums2[i+k];
                if(hash2<0) hash2 += mod;
                
            }
        }
        
        
        
        return false;
    }
    
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        
        int l=0, r=min(nums1.size(), nums2.size());
        int ans=0;
        
        while(l<=r){
            int mid = l + (r-l)/2;
            if(isEnough(nums1, nums2, mid)){
                ans=mid;
                l=mid+1;
            } else {
                r=mid-1;
            }
        }
        
        return ans;
    }
};