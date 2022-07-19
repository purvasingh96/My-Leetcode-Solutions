class Solution {
private:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int> m;
        m[0] = 1;
        int sum=0, ans=0;
        
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(m.find((sum-k))!=m.end()){
                ans += m[(sum-k)];
            }
            m[sum] += 1;
        }
        
        return ans;
    }
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans=0;
        
        vector<int> ssum(n);
        
        for(int i=0;i<m;i++){
            
            for(int p=0;p<n;p++) ssum[p]=0;
            
            for(int j=i;j<m;j++){
                for(int k=0;k<n;k++){
                    ssum[k] += matrix[j][k];
                }   
                ans += subarraySum(ssum, target);
            }
        }
        
        return ans;
    }
};