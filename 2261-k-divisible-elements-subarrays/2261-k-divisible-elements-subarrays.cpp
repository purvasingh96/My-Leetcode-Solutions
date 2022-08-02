class Solution {
private:
    bool checkCollision(vector<int>& ids, vector<int>& nums, int sz, int j){
        for(auto i:ids){
            if(equal(nums.begin()+i, nums.begin()+i+sz+1, nums.begin()+j)) {
                return true;
            }
        }
        
        return false;
    }
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size(), res=0;
        vector<int> cnt(n, 0);
        vector<int> hash(n, 0);
        int mod = 1e9+7;
        
        for(int sz=0;sz<n;sz++){
            
            unordered_map<int, vector<int>> s;
            
            for(int i=0;i+sz<n;i++){
                cnt[i] += (nums[i+sz]%p==0);
                
                if(cnt[i] <= k){
                    
                    hash[i] = ((long long)hash[i]*200 + nums[i+sz]);
                    if(!checkCollision(s[hash[i]], nums, sz, i)){
                        s[hash[i]].push_back(i);
                        res+=1;
                    }
                    
                }
            }
            
        }
        
        return res;
        
    }
};