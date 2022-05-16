class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        map<int,int> m;
        vector<int> arr;
        
        for(auto x:nums) {
            if(m[x]==0) arr.push_back(x);
            m[x]+=1;
        }
        
        sort(arr.begin(), arr.end());
        
        
        vector<int> dp(arr.size());
        
        dp[0] = arr[0]*m[arr[0]];
        
        for(int i=1;i<dp.size();i++) {
            
            if(arr[i-1]+1==arr[i]){
                if(i-2>=0) dp[i] = max(dp[i-1], (m[arr[i]]*arr[i] + dp[i-2]));
                else dp[i] = max(dp[i-1], (m[arr[i]]*arr[i]));
            } else{
                dp[i] = dp[i-1] + m[arr[i]]*arr[i];
            }            
        }
        
        return dp.back();
        
    }
};